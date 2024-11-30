#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include "dispatcher.h"
#include "globals.h"

/**
 * @brief Function executed by the dispatcher thread to assign files to worker threads.
 * 
 * @param arg Unused parameter.
 * @return void* Always returns NULL.
 */
void* dispatcher_function(void* arg){
    (void)arg; // Supress unused variable warnings
    while (1){
        // Open the directory containing the files
        DIR* dir = opendir("resources/fileset");
        if (!dir){
            printf("ERROR: opendir");
            exit(2);
        }

        struct dirent* entry;
        struct stat st;
        // Read each entry in the directory
        while ((entry = readdir(dir)) != NULL){
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
        closedir(dir);
        // Sleep for a while before checking the directory again
        sleep(5);
    }
    return NULL;
}