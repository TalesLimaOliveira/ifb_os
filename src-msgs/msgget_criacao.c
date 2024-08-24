#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int msqid ;  /* ID da fila de mensagens */
    /*
    * criacao de uma fila de mensagens para leitura se
    * ela ainda nao existe
    */
    if (( msqid = msgget(0x1234, IPC_CREAT | 0600)) == -1) {
        perror("Erro de msgget") ;
        exit(1) ;
    }

    printf("identificador da fila: %d\n",msqid) ;
    exit(0);
}
//#ipcs -q