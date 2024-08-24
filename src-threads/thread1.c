#include <stdio.h>       
#include <pthread.h>    
#include <stdlib.h>


void* PrintHello(void* data)
{
    int *my_data = (int *)data;

    pthread_detach(pthread_self());
    printf("Ola, sou a nova thread! Recebi o dado %d\n", *my_data);
    pthread_exit(NULL);	
}


int main(int argc, char* argv[])
{
    int        rc;      
    pthread_t  thread_id;
    int        t = 10;  

    rc = pthread_create(&thread_id, NULL, PrintHello, (void *) &t);  
    if(rc){	/* Erro na criação da thread */
        printf("\n Erro! Código: %d \n", rc);
        exit(1);
    }

    printf("\n Foi criada a thread (%lu) ... \n", thread_id);
    pthread_exit(NULL);	

    return 0;
}

