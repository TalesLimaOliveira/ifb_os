#include <stdio.h>       
#include <pthread.h>     
#include <stdlib.h>
#include <unistd.h>

void* PrintHello(void* data)
{
    pthread_t *tpai = (pthread_t *)data;     	
    pthread_t tid;
    
    tid = pthread_self();
    pthread_join(*tpai, NULL);

    printf("Sou a thread (%lu) e fui criado por (%lu)\n",tid,*tpai);
    pthread_exit(NULL);			
}


int main(int argc, char* argv[])
{
    pthread_t  thread_id; 
    pthread_t tid;
   
    tid = pthread_self();
    pthread_create(&thread_id, NULL, PrintHello, (void *) &tid);     
    

    //pthread_join(thread_id, NULL);
    printf("\nSou a thread (%lu) e criei a thread (%lu) ... \n",tid, thread_id);

    pthread_exit(NULL);	

    return 0;
}

