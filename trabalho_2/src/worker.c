#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <stdint.h>
#include <ctype.h>
#include "worker.h"
#include "globals.h"

/**
 * @brief Function executed by worker threads to process files and count occurrences of a term.
 * 
 * @param arg Pointer to the worker ID.
 * @return void* Always returns NULL.
 */
void* worker_function(void* arg){
    int worker_id = (intptr_t)arg;

    while (1){
        // Lock the mutex to access shared resources
        pthread_mutex_lock(&lock);
        // Wait for a signal to start processing
        pthread_cond_wait(&cond, &lock);
        pthread_mutex_unlock(&lock);

        // Process each file in the file_counts array
        for (int i = worker_id; i < file_count; i += MAX_WORKERS){
            FILE* file = fopen(file_counts[i].filename, "r");
            if (file == NULL){
                printf("ERROR: Falha ao abrir o Arquivo\n");
                continue;
            }

            int local_count = 0; // Local variable for counting occurrences

            char line[1024];
            while (fgets(line, sizeof(line), file)){
                char* ptr = line;
                while ((ptr = strcasestr(ptr, term)) != NULL){
                    local_count++;
                    ptr += strlen(term);
                }
            }
            fclose(file);

            // Update the global count
            pthread_mutex_lock(&lock);
            file_counts[i].count = local_count;
            pthread_mutex_unlock(&lock);
        }

        // Mark the worker as available
        worker_available[worker_id] = 1;
    }
    return NULL;
}

/**
 * @brief Case-insensitive string search function.
 * 
 * @param haystack The string to search in.
 * @param needle The string to search for.
 * @return char* Pointer to the first occurrence of needle in haystack, or NULL if not found.
 */
char* strcasestr(const char* haystack, const char* needle){
    if (!*needle) return (char*)haystack;
    for (const char* p = haystack; *p; p++){
        if (tolower((unsigned char)*p) == tolower((unsigned char)*needle)){
            const char* h = p, *n = needle;
            while (*h && *n && tolower((unsigned char)*h) == tolower((unsigned char)*n)){
                h++;
                n++;
            }
            if (!*n) return (char*)p;
        }
    }
    return NULL;
}