#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    int pid, status;
    int fd[2];
    char buf[30];

    if ((pipe(fd)) < 0)   {
        printf("erro no pipe\n");
        exit(1);
    }

    if ((pid = fork()) < 0)   {
        printf("erro no fork\n");
        exit(1);
    }

    if (pid == 0) {
        strcpy(buf, "mensagem do filho");
        write(fd[1], buf, sizeof(buf));
        exit(0);
    }

    wait(&status);
    read(fd[0], buf, sizeof(buf));
    printf("mensagem lida: %s\n",buf);

    return 0;
}