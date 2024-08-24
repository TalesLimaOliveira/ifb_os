#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <semaphore.h>

int main(void)
{
    int pid, pidneto;
    int *status;
    sem_t mutex; 
    sem_init(&mutex, 1, 1);  //compartilhado entre processos

    if (( pid = fork()) < 0) {
        printf("erro no fork\n");
        exit(1);
    }

    if (pid == 0){ //processo filho
        printf("Processo Filho\n");
        sem_wait(&mutex);

        printf("Processo Filho em regiao critica\n");
        sleep(1);

        printf("Processo Filho saindo de regiao critica\n");
        sem_post(&mutex);
    }
    else{ //processo pai
        printf("Processo Pai\n");
        sem_wait(&mutex);

        printf("Processo Pai em regiao critica\n");
        sleep(1);

        printf("Processo Pai saindo de regiao critica\n");
        sem_post(&mutex);
        wait(status); 
    }

    return 0;
}