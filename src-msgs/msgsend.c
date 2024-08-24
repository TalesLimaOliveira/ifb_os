#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MSG_SIZE_TEXT 256

int main(void)
{
     int i = 1 ;
     int msqid ; 

     /* estrutura msg associada as mensagens */
     struct msgtext {
          long mtype ;
          char mtext[MSG_SIZE_TEXT] ;
     } msg ;         

     /* recuperacao do identificador da fila de mensagens */
     if ( msqid = msgget(0x1234,0)) {
               perror ("Erro msgget()") ;
               exit(1) ;
     }
     
     printf("fila %d\n", msqid);
     msg.mtype = 1 ; /* tipo das mensagens */
     while(i<=10)  
     {
          /* escreve o texto da mensagem */
          sprintf(msg.mtext,"mensagem de numero %d de tipo %ld",i,msg.mtype) ;
          /* envia a mensagem a fila */
          if(msgsnd(msqid,&msg,strlen(msg.mtext),IPC_NOWAIT) == -1)
          {
               perror("Envio de mensagem impossivel") ;
               exit(-1) ;
          }
          printf("mensagem de numero %d de tipo %ld enviada a fila %d\n", i,msg.mtype,msqid) ;
          printf("-->texto da mensagem: %s\n",msg.mtext) ;
          i++ ;
     } 
     exit(0);
}