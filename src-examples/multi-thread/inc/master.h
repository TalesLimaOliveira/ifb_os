#ifndef MASTER_H
#define MASTER_H

/**
 * @brief Master thread function that coordinates the worker threads.
 * 
 * @param arg Argument passed to the thread.
 * @return void* 
 */
void* master(void* arg);

#endif // MASTER_H