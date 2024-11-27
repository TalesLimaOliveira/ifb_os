#include <pthread.h>
#include "master.h"

extern int waiting;
extern pthread_mutex_t mutex;
extern pthread_cond_t cond;
extern std::unordered_set<std::string> q_urls;

/**
 * @brief Master thread function that coordinates the worker threads.
 * 
 * @param arg Argument passed to the thread.
 * @return void* 
 */
void* master(void* arg){
    long thr_id = (long)arg;
    bool doit = true;
    while (doit){
        pthread_mutex_lock(&mutex);
        while (q_urls.empty()){
            if (waiting == N_THR){
                // Signal all worker threads to stop if all are waiting
                for (int i = 0; i < N_THR; i++){
                    pthread_cond_signal(&cond);
                }
                doit = false;
                break;
            } else {
                break;
            }
        }
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}