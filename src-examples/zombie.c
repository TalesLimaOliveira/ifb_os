#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int pid;
    int *status;

    if ((pid = fork()) < 0) {
        printf("erro no fork\n");
        exit(1);
    }

    if (pid == 0){
        printf("sou o processo %d filho\n", getpid()); 
    }
    
    else{ //processo pai
        wait(status); //espera o processo filho encerrar
        printf("sou o processo %d pai\n", getpid());
        sleep(10);
        return 0;
    }
}
