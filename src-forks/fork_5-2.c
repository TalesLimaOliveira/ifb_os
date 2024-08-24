/**
 * @author Tales Oliveira (github.com/TalesLimaOliveira)
 * @brief Sum of array using 3 forks
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define DIV 3

int main(void)
{
    //Array for sum!
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int fd[2]; //File Descriptor = Shared File
    int sum = 0, id1, id2;

    if(pipe(fd) == -1) exit(1);
    id1 = fork();
    if(id1 == -1) exit(1);

    //CHILD 1
    if(id1 == 0){
        int start = 0;
        int end = (sizeof(arr) / sizeof(arr[0])) / DIV;

        for (int i = start; i < end; i++)
            sum += arr[i];
    }

    //PARENT
    else{
        id2 = fork();
        if(id2 == -1) exit(1);

        //CHILD 2
        if(id2 == 0){
            int start = (sizeof(arr) / sizeof(arr[0])) / DIV;
            int end = (sizeof(arr) / sizeof(arr[0])) - ((sizeof(arr) / sizeof(arr[0])) / DIV);

            for (int i = start; i < end; i++)
                sum += arr[i];
        }
        
        //PARENT
        else{
            int start = (sizeof(arr) / sizeof(arr[0])) - ((sizeof(arr) / sizeof(arr[0])) / DIV);
            int end = sizeof(arr) / sizeof(arr[0]);

            for (int i = start; i < end; i++)
                sum += arr[i];
        }
    }
    
    printf("Partial sum = %d\n", sum);

    //CHILD 1
    if(id1 == 0){
        close(fd[0]);
        write(fd[1], &sum, sizeof(sum));
        close(fd[1]);
    }

    //PARENT
    else{
        //CHILD 2
        if(id2 == 0){
            int sum2;
            read(fd[0], &sum2, sizeof(sum2));
            sum += sum2;
            write(fd[1], &sum, sizeof(sum));
            close(fd[0]);
            close(fd[1]);
        }

        //PARENT
        else{
            close(fd[1]);
            wait(NULL);//WAIT CHILD WRITE
            int sum2;
            read(fd[0], &sum2, sizeof(sum2));
            close(fd[0]);
            printf("TOTAL SUM: %d\n", sum2 + sum);
        }
    }

    wait(NULL);//If has child.. wait..
    return 0;
}
