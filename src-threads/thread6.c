#include <stdio.h>       
#include <pthread.h>     
#include <stdlib.h>
#include <unistd.h>

#define N_THREADS 5
int count = 0;
pthread_mutex_t lock;

void* contador(void *id)
{
    int * i = (int *) id;
    unsigned long delay = 0xCAFEBABE; 
    
    pthread_mutex_lock(&lock);

    count = count + 1;
    printf("Thread %lu: count = %d\n",pthread_self(), count);
    for (int j=0; j<delay; j++);
    count = count + 1;
    printf("Thread %lu: count = %d\n",pthread_self(), count);
    
    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);         
}


int main(int argc, char* argv[])
{
    pthread_t  thread_ids[N_THREADS]; 
    int i;

    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n Erro na inicialização do mutex\n");
        return 1;
    }

    for (i=0;i<N_THREADS; i++){
        pthread_create(&thread_ids[i], NULL, contador, &i);     
    }
    for (int j=0;j<N_THREADS; j++){
        pthread_join(thread_ids[j], NULL);
    }
    printf("Fim!\n");
    pthread_mutex_destroy(&lock);
    pthread_exit(NULL); 
}

