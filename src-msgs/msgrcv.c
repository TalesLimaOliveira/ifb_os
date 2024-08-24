#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>

#define MSG_SIZE_TEXT 256

/* estrutura msg associada as mensagens */
struct msgtext {
    long mtype ;
    char mtext[MSG_SIZE_TEXT];
}msg ;         

int main(void)
{
    int lg ;            /* tamanho da mensagem recebida */
    long type = 1 ;     /* tipo de mensagem buscado */
    int size_msg = 19 ; /* tamanho maximo do texto a ser recuperado */
    int msqid ;         /* identificador da fila */

    /* recuperacao do identificador da fila de mensagens */
    if (( msqid = msgget(0x1234,0)) == -1 ) {
        perror ("Erro msgget()") ;
        exit(1) ;
    }

    /* o programa vai ler na fila enquanto existirem mensagens
    * se as mensagens sao maiores que o tamanho maximo size_msg,
    * elas serao truncadas
    * quando a fila estiver vazia, o processo nao se bloqueia */
    while((lg=msgrcv(msqid,&msg,size_msg,type,IPC_NOWAIT|MSG_NOERROR)) != -1){ 
        printf("texto da mensagem (tamanho %d) recebido: %s\n",
        lg,msg.mtext) ;
    }

    perror("nao ha mais mensagens") ;
    exit(-1) ;
}