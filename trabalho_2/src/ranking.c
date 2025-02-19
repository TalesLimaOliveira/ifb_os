#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/stat.h>
#include "ranking.h"
#include "globals.h"

/**
 * @brief Function executed by the ranking thread to update and display the ranking of files.
 * 
 * @param arg Unused parameter.
 * @return void* Always returns NULL.
 */
void* ranking_function(void* arg){
    (void)arg; // Supress unused variable warnings

    while (1){
        // Lock the mutex to access shared resources
        pthread_mutex_lock(&lock);
        // Wait for a signal to update the ranking
        pthread_cond_wait(&cond, &lock);
        // Verify if the term is empty
        if (strlen(term) == 0) {
            pthread_mutex_unlock(&lock);
            continue;
        }

        // Check if all workers are available
        int all_workers_available = 1;
        for (int i = 0; i < MAX_WORKERS; i++) {
            if (!worker_available[i]) {
                all_workers_available = 0;
                break;
            }
        }

        if (all_workers_available) {
            update_ranking();
        }
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

/**
 * @brief Comparison function for qsort to sort FileCount in descending order.
 */
int compare_file_counts(const void* a, const void* b){
    return ((FileCount*)b)->count - ((FileCount*)a)->count;
}

/**
 * @brief Updates the ranking of files based on the count of term occurrences and prints the top results.
 */
void update_ranking(){
    // Sort the file counts in descending order
    qsort(file_counts, file_count, sizeof(FileCount), compare_file_counts);

    // Clear the terminal
    printf("\033[H\033[J");

    // Print the search term and the top N files
    printf("Busca pelo termo: %s\n", term);
    for (int i = 0; i < TOP_N && i < file_count; i++){
        // Check if the file still exists
        struct stat st;
        if (stat(file_counts[i].filename, &st) != 0) {
            continue;
        }
        printf("%s: %d\n", file_counts[i].filename, file_counts[i].count);
    }
}