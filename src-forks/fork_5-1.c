/**
 * @author Tales Oliveira (github.com/TalesLimaOliveira)
 * @brief Sum of array using 2 forks
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    //Array for sum!
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int fd[2]; //File Descriptor = Shared File
    int sum = 0;

    if(pipe(fd) == -1)
        exit(1);

    int id = fork();
    if(id == -1)
        exit(1);

    //CHILD
    if(id == 0){
        int start = 0;
        int end = (sizeof(arr) / sizeof(arr[0])) / 2; //Half of the array

        for (int i = start; i < end; i++)
            sum += arr[i];
    }

    //PARENT
    else{
        int start = (sizeof(arr) / sizeof(arr[0])) / 2; //Half of the array + 1
        int end = sizeof(arr) / sizeof(arr[0]); //Size of the array

        for (int i = start; i < end; i++)
            sum += arr[i];
    }
    
    printf("Partial sum = %d\n", sum);

    if(id == 0){
        close(fd[0]); //Child will not read
        write(fd[1], &sum, sizeof(sum));
        close(fd[1]);//Close the write buffer of the pipe
    }

    else{
        int child_sum;

        close(fd[1]); //Parent will not write
        read(fd[0], &child_sum, sizeof(child_sum));
        close(fd[0]); //Close the read buffer of the pipe

        printf("TOTAL SUM: %d\n", child_sum + sum);
    }

    wait(NULL);//If has child.. wait..
    return 0;
}
