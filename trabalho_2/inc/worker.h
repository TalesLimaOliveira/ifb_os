#ifndef WORKER_H
#define WORKER_H

/**
 * @brief Function executed by worker threads to process files and count occurrences of a term.
 * 
 * @param arg Pointer to the worker ID.
 * @return void* Always returns NULL.
 */
void* worker_function(void* arg);

#endif // WORKER_H