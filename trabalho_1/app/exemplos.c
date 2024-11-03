/**
 * @file exemplos.c
 * @brief Exemplos de como utilizar as funções:
 *          wait, waitpid, fork, getpid, getppid, execv e execve;
 * 
 * @author David Caldas (github.com/caldasdv)
 * @author Tales L. Oliveira (github.com/TalesLimaOliveira)
 */

#include <stdio.h>
#include "fork.h"
#include "ids.h"
#include "wait.h"
#include "exec.h"

int main(void){
    printf("\nRunning ids_example:\n");
    ids_example();

    printf("\nRunning fork_example:\n");
    fork_example();

    printf("\nRunning wait_example:\n");
    wait_example();

    printf("\nRunning exec_example:\n");
    exec_example();

    return 0;
}
