#include <stdio.h>       
#include <pthread.h>     
#include <stdlib.h>
#include <unistd.h>

#define N_THREADS 5
int count = 0;

void* contador(void *id)
{
    int * i = (int *) id;
    unsigned long delay = 0xCAFEBABE; 
    
    count = count + 1;
    printf("Thread %d: count = %d\n",*i, count);
    for (int j=0; j<delay; j++);
    count = count + 1;
    printf("Thread %d: count = %d\n",*i, count);
    
    pthread_exit(NULL);         
}


int main(int argc, char* argv[])
{
    pthread_t  thread_ids[N_THREADS]; 
    int i;
    for (i=0;i<N_THREADS; i++){
        pthread_create(&thread_ids[i], NULL, contador, &i);     
    }
    for (int j=0;j<N_THREADS; j++){
        pthread_join(thread_ids[j], NULL);
    }
    printf("Fim!\n");

    pthread_exit(NULL); 
}

