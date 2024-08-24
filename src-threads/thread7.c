#include <stdio.h>       
#include <pthread.h>     
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define N 5

pthread_mutex_t lock;
pthread_cond_t empty, full;
int buffer[N];
int qtd_buffer = 0;


void* produtor(void *id)
{
   int item = 1;

   while (1){
    sleep(rand() % 5); //Produzindo o item;
    pthread_mutex_lock(&lock);
    if (qtd_buffer ==  N) pthread_cond_wait(&full,&lock);
    buffer[qtd_buffer] = item;
    qtd_buffer++;
    printf("Produtor: adicionado %d item(s)\n",qtd_buffer);
    if (qtd_buffer == 1) pthread_cond_signal(&empty);
    pthread_mutex_unlock(&lock); 
   }
   
   pthread_exit(NULL);         
}


void* consumidor(void *id)
{
   int item; 

    while(1){
        sleep(rand() % 5);
        
        pthread_mutex_lock(&lock);
        if (qtd_buffer ==  0) pthread_cond_wait(&empty,&lock);
        item = buffer[qtd_buffer-1];
        qtd_buffer--;
        printf("Consumidor: consumido um item. %d item(s) restantes\n",qtd_buffer);
        if (qtd_buffer == N-1) pthread_cond_signal(&full);

        pthread_mutex_unlock(&lock); 

    }
   

   pthread_exit(NULL);         
}



int main(int argc, char* argv[])
{
    pthread_t t_produtor,t_consumidor; 
    srand(time(NULL));
   
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&empty,NULL);
    pthread_cond_init(&full,NULL);

    pthread_create(&t_produtor, NULL,produtor ,NULL);     
    pthread_create(&t_consumidor, NULL,consumidor ,NULL);

    pthread_join(t_produtor, NULL);
    pthread_join(t_consumidor, NULL);
    

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&empty);
    pthread_cond_destroy(&full);

    pthread_exit(NULL); 

}

