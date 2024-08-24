#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{   
    //PROCESS = fork^2
    //2 forks = 4 Process.. 4 forks = 16 process.

    // fork();
    // fork();
    // printf("Hello, world!\n");

    //We can use the return of the fork to create a more control space..
    //Creating only 3 procces exaple:

    int id = fork();

    if (id != 0){
        printf("Parent PID: %d, Fork ID: %d\n", getpid(), id);
        fork();
    }
        

    printf("Hello from PID: %d\n", getpid());
    return 0;
}