#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <stdint.h> // Add this line
#include "worker.h"
#include "dispatcher.h"
#include "ranking.h"
#include "globals.h"

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
char term[256];
FileCount file_counts[MAX_FILES];
int file_count = 0;
int worker_available[MAX_WORKERS];
pthread_t workers[MAX_WORKERS];
pthread_t dispatcher_thread;
pthread_t ranking_thread;

/**
 * @brief Main function to initialize and start the dispatcher, worker, and ranking threads.
 * 
 * @param argc Argument count.
 * @param argv Argument vector containing the search term.
 * @return int Returns 0 on success, 1 on failure.
 */
int main(int argc, char const *argv[]){
    if (argc != 2){
        printf("ERROR: args\nUse: make run <term>\n");
        return 1;
    }

    // Copy the search term
    strcpy(term, argv[1]);

    // Initialize worker threads
    for (int i = 0; i < MAX_WORKERS; i++){
        worker_available[i] = 1;
        pthread_create(&workers[i], NULL, worker_function, (void*)(intptr_t)i);
    }

    // Initialize dispatcher and ranking threads
    pthread_create(&dispatcher_thread, NULL, dispatcher_function, NULL);
    pthread_create(&ranking_thread, NULL, ranking_function, NULL);

    // Wait for the dispatcher and worker threads to finish
    pthread_join(dispatcher_thread, NULL);
    for (int i = 0; i < MAX_WORKERS; i++){
        pthread_join(workers[i], NULL);
    }
    pthread_join(ranking_thread, NULL);

    return 0;
}
