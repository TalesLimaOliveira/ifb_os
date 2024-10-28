/**
 * @author Tales Oliveira (github.com/TalesLimaOliveira)
 * @brief FORK WITH PIPES
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

/**
 * @brief Display where the erro ocurred and exit te program
 * @param msg where the erro ocurred.
 */
void my_erro(char msg[])
{
    printf("ERRO: %s", msg);
    exit(1);
}

/**
 * @brief Genarate a number for the parent.
 * @param sf The share_file of process, create by the pipe().
 */
void child_funtion(int sf[])
{
    close(sf[0]); //Close the read buffer of the pipe

    srand(time(NULL)); // Gera seed para numero aletorio
    int x = rand() % 100 + 1;

    write(sf[1], &x, sizeof(x));
    printf("C: X = %d\n", x);
    close(sf[1]);
}

/**
 * @brief Mutiply x2 the number of the child.
 * @param sf The share_file of process, create by the pipe().
 */
void parent_funtion(int sf[])
{
    close(sf[1]); //Close the write buffer of the pipe

    int x;
    read(sf[0], &x, sizeof(x));
    printf("P: %d*2 = %d\n", x, x*2);
    close(sf[0]);
}

int main(void)
{
    int share_file[2];
    //sf[0] - read
    //sf[1] - write

    if(pipe(share_file) == -1)
        my_erro("PIPE");

    int id = fork();
    if(id == -1)
        my_erro("FORKING");

    if(id == 0)
        child_funtion(share_file);
    else
        parent_funtion(share_file);

    wait(NULL);
    return 0;
}
