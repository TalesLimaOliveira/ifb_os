#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "worker.h"
#include "globals.h"

/**
 * @brief Function executed by worker threads to process files and count occurrences of a term.
 * 
 * @param arg Pointer to the worker ID.
 * @return void* Always returns NULL.
 */
void* worker_function(void* arg){
    int id = (int)arg;
    char filename[MAX_FILENAME];
    while (1){
        // Lock the mutex to access shared resources
        pthread_mutex_lock(&lock);
        // Wait until the worker is assigned a file
        while (worker_available[id]){
            pthread_cond_wait(&cond, &lock);
        }
        // Copy the filename to process
        strcpy(filename, file_counts[file_count - 1].filename);
        worker_available[id] = 1;
        pthread_mutex_unlock(&lock);

        // Open the file for reading
        FILE* file = fopen(filename, "r");
        if (!file) continue;

        int count = 0;
        char buffer[1024];
        // Read the file line by line
        while (fgets(buffer, sizeof(buffer), file)){
            char* ptr = buffer;
            // Count occurrences of the term in the line
            while ((ptr = strstr(ptr, term)) != NULL){
                count++;
                ptr += strlen(term);
            }
        }
        fclose(file);

        // Lock the mutex to update shared resources
        pthread_mutex_lock(&lock);
        file_counts[file_count - 1].count = count;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}