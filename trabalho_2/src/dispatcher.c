#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/inotify.h>
#include "dispatcher.h"
#include "globals.h"

#define EVENT_SIZE (sizeof (struct inotify_event))
#define EVENT_BUF_LEN (1024 * (EVENT_SIZE + 16))

/**
 * @brief Function executed by the dispatcher thread to assign files to worker threads.
 * 
 * @param arg Unused parameter.
 * @return void* Always returns NULL.
 */
void* dispatcher_function(void* arg){
    (void)arg; // Supress unused variable warnings
    int initial_search_done = 0;

    // Initialize inotify
    int fd = inotify_init();
    if (fd < 0) {
        printf("ERROR: Inizilizar inoti\n");
        exit(EXIT_FAILURE);
    }

    // Add watch on the directory
    int wd = inotify_add_watch(fd, "resources/fileset", IN_MODIFY | IN_CREATE | IN_DELETE);
    if (wd == -1) {
        printf("ERROR: Não foi possivel adicionar um observador em 'resources/fileset'\n");
        exit(EXIT_FAILURE);
    }

    while (1){
        // Verify if the term is empty
        if (strlen(term) == 0) {
            sleep(5);
            continue;
        }

        // Open the directory containing the files
        DIR* dir_fileset = opendir("resources/fileset");
        if (dir_fileset == NULL){
            printf("ERROR: Falha ao abrir diretorio\n");
            exit(EXIT_FAILURE);
        }

        struct dirent* entry;
        struct stat st;
        
        // Read each entry in the directory
        while ((entry = readdir(dir_fileset)) != NULL){
            // Skip "." and ".." entries
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            char filepath[MAX_FILENAME+21];
            snprintf(filepath, sizeof(filepath), "resources/fileset/%s", entry->d_name);

            if (stat(filepath, &st) == 0 && S_ISREG(st.st_mode)){
                // Lock the mutex to access shared resources
                pthread_mutex_lock(&lock);
                int found = 0;
                // Check if the file has already been processed
                for (int i = 0; i < file_count; i++){
                    if (strcmp(file_counts[i].filename, filepath) == 0){
                        found = 1;
                        break;
                    }
                }
                // If the file is new, add it to the list and assign it to a worker
                if (!found){
                    strcpy(file_counts[file_count].filename, filepath);
                    file_count++;
                    for (int i = 0; i < MAX_WORKERS; i++){
                        if (worker_available[i]){
                            worker_available[i] = 0;
                            pthread_cond_signal(&cond);
                            break;
                        }
                    }
                }
                pthread_mutex_unlock(&lock);
            }
        }
        closedir(dir_fileset);

        if (!initial_search_done) {
            // Signal that the initial search is complete
            pthread_mutex_lock(&lock);
            pthread_cond_signal(&search_complete_cond);
            pthread_mutex_unlock(&lock);
            initial_search_done = 1;
        }

        // Notify workers to start processing
        pthread_cond_broadcast(&cond);

        // Wait for changes in the directory
        char buffer[EVENT_BUF_LEN];
        int length = read(fd, buffer, EVENT_BUF_LEN);
        if (length < 0) {
            printf("ERROR: Leitura\n");
        } else {
            pthread_mutex_lock(&lock);
            pthread_cond_signal(&cond);
            pthread_mutex_unlock(&lock);
        }

        // Sleep for a while before checking the directory again
        sleep(5);
    }

    // Clean up inotify
    inotify_rm_watch(fd, wd);
    close(fd);

    return NULL;
}