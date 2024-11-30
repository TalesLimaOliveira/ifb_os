#ifndef DISPATCHER_H
#define DISPATCHER_H

/**
 * @brief Function executed by the dispatcher thread to assign files to worker threads.
 * 
 * @param arg Unused parameter.
 * @return void* Always returns NULL.
 */
void* dispatcher_function(void* arg);

#endif // DISPATCHER_H