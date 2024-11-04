/**
 * @file exemplos.c
 * @brief Exemplos de como utilizar as funções:
 *          wait, waitpid, fork, getpid, getppid, execv e execve;
 * 
 * @author David Caldas (github.com/caldasdv)
 * @author Tales L. Oliveira (github.com/TalesLimaOliveira)
 */

#include <stdio.h>
#include <exemplos_ids.h>
#include <exemplos_fork.h>
#include <exemplos_wait.h>
#include <exemplos_exec.h>

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
