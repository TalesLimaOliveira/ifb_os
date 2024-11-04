/**
 * @file exemplos.c
 * @brief Exemplos de como utilizar as funções:
 *          wait, waitpid, fork, getpid, getppid, execv e execve;
 * 
 * @author David Caldas (github.com/caldasdv)
 * @author Tales L. Oliveira (github.com/TalesLimaOliveira)
 */

#include <stdio.h>
#include <fork.h>
#include <ids.h>
#include <wait.h>
#include <exec.h>

int main(void){
    printf("\n========== Executando exemplos_ids  ==========\n");
    ids_example();

    printf("\n========== Executando exemplos_fork ==========\n");
    fork_example();

    printf("\n========== Executando exemplos_wait ==========\n");
    wait_example();

    printf("\n========== Executando exemplos_exec ==========\n");
    exec_example();

    return 0;
}