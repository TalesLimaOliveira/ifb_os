#ifndef WORKER_H
#define WORKER_H

/**
 * @brief Function executed by worker threads to process files and count occurrences of a term.
 * 
 * @param arg Pointer to the worker ID.
 * @return void* Always returns NULL.
 */
void* worker_function(void* arg);

/**
 * @brief Case-insensitive string search function.
 * 
 * @param haystack The string to search in.
 * @param needle The string to search for.
 * @return char* Pointer to the first occurrence of needle in haystack, or NULL if not found.
 */
char* strcasestr(const char* haystack, const char* needle);

#endif // WORKER_H