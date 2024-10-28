#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define KEY 123

int main(void)
{
    struct msqid_ds buf ;
    int msqid ;
    /* recuperacao do ID da fila de mensagens associada a chave 123 */
    if (( msqid = msgget(0x1234,0)) == -1 ) {
        perror ("Error msgget()") ;
        exit(1) ;
    }

    /* recuperacao na estrutura buf dos parametros da fila */
    if (msgctl(msqid,IPC_STAT,&buf) == -1){
        perror("Error msgctl()") ;
        exit(1) ;
    }

    else{
        printf("id da fila de mensagens     : %d\n",msqid) ;
        printf("id do proprietario          : %d\n",buf.msg_perm.uid) ;
        printf("id do grupo do proprietario : %d\n",buf.msg_perm.gid) ;
        printf("id do criador               : %d\n",buf.msg_perm.cuid) ;
        printf("id do grupo do criador      : %d\n",buf.msg_perm.cgid) ;
        printf("direitos de acesso          : %d\n",buf.msg_perm.mode) ;
        printf("nb atual de bytes na fila   : %ld\n",buf.msg_cbytes) ;
        printf("nb de mensagens na fila     : %ld\n",buf.msg_qnum) ;
        printf("nb maximal de bytes na fila : %ld\n",buf.msg_qbytes) ;
        printf("pid do ultimo escritor      : %d\n",buf.msg_lspid) ;
        printf("pid do ultimo leitor        : %d\n",buf.msg_lrpid) ;
        printf("data da ultima escrita      : %s\n",ctime(&buf.msg_stime)) ;
        printf("data da ultima leitura      : %s\n",ctime(&buf.msg_rtime)) ;
        printf("data da ultima modificacao  : %s\n",ctime(&buf.msg_ctime)) ;
    }
    exit(0);
}