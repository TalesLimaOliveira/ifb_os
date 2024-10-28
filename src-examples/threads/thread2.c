#include <stdio.h>       
#include <pthread.h>     
#include <stdlib.h>
#include <unistd.h>

void* PrintHello(void* data)
{
    int *my_data = (int *)data;     	
    pthread_t tid;
    tid = pthread_self();
    sleep(2);
    pthread_detach(pthread_self());
    printf("Sou a thread (%lu) e recebi o dado %d\n",tid, *my_data);
    pthread_exit(NULL);			
}

int main(int argc, char* argv[])
{
    int        rc;      
    pthread_t  thread_id; 
    int        t = 10; 
    pthread_t tid;
   
    tid = pthread_self();
    rc = pthread_create(&thread_id, NULL, PrintHello, (void *) &t);
    printf("\nSou a thread (%lu) e criei a thread (%lu)\n",tid, thread_id);
    
    pthread_exit(NULL);	
    return 0;
}


