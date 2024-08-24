#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(void)
{
    //Creating 4 proccess:
    int id1 = fork();
    int id2 = fork();

    if(id1 == 0){
        if(id2 == 0)
            printf("CLONE 1.1: %d from CLONE 1: %d\n", getpid(), getppid());
        else
            printf("CLONE 1: %d  from MAIN: %d\n", getpid(), getppid());
    }
    else{
        if (id2 == 0)
            printf("CLONE 2: %d  from MAIN: %d\n", getpid(), getppid());
        else
            printf("MAIN PROCESS | ID: %d\n", getpid());
    }

    //Wait for all children finish.. before parent finish it self..
    //We have 3 Child(CLONES).. So it should print 3x

    // int res;
    // while ((res = wait(NULL)) != -1 || errno != ECHILD)
    //     printf("Waited for child: %d.\n", res);

    return 0;
}