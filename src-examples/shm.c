#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int pid, idshm,  estado;
    struct shmid_ds buf;
    int *pshm;

    /* cria memoria*/
    if ((idshm = shmget(0x1223, sizeof(int), IPC_CREAT|0x1ff)) < 0){
        printf("erro na criacao da fila\n");
        exit(1);
    }

    /* cria processo filho */
    pid = fork();
    if (pid == 0){
        /* codigo do filho */
        pshm = (int *) shmat(idshm, (char *)0, 0);
        if (pshm == (int *)-1){
            printf("erro no attach\n");
            exit(1);
        }

        printf("Filho: vou escrever\n");
        *pshm = 334;
        exit(0);
    }

    /* codigo do pai */
    pshm = (int *) shmat(idshm, (char *)0, 0);
    if (*pshm == -1){
        printf("erro no attach\n");
        exit(1);
    }

    sleep(1);
    wait(&estado);
    printf("Pai - numero lido = %d\n", *pshm);


    if ((shmctl(idshm, IPC_RMID, NULL)) == -1){
        perror("Erro shmctl()") ;
        exit(1) ;
    }

    exit (0);
}