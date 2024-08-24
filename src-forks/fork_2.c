#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{   
    //MAIN ID == PARENT ID
    //printf("MAIN ID: %d\n", getpid());

    //OBESERVESION: Some times the wait or fork
    //can return pid+1 or Child ID... depending of OS.

    int id = fork();
    //ERRO -> fork() return < 0 when fail.
    if (id < 0){
        printf("Fork ERRO\n");
        exit(1);
    }

    int n = 0;
    //CHILD -> fork() return 0 when is in the child.
    if (id == 0){
        //printf("Child: Current ID: %d, Parent ID: %d\n", getpid(), getppid());
        n = 1;
    }

    //PARENT -> fork() return > parent pid when is in the parent.
    else if (id > 0){ 
        //printf("Parent: Current ID: %d, Parent ID: %d\n", getpid(), getppid());
        printf("Current ID: %d, Fork ID: %d\n", getpid(), id);
        n = 6;
    }

    //Wait -> return -1 when has no child, pid otherwise.
    int res = wait(NULL);
    if(res == -1){
        printf("No child to wait for...\n");
    }else{
        printf("%d finished execution\n", res);
    }

    //Every one execute this... (Child and parent)
    for (int i = n; i < n+5; i++){
        printf("%d ", i);
    }

    //If is not the child...
    if(id != 0)
        printf("\n");
        
    return 0;
}
