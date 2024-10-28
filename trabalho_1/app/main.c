/**
 * @file main.c
 * @author David Caldas (github.com/caldasdv)
 * @author Tales L. Oliveira (github.com/TalesLimaOliveira)
 *
 * @brief Exemplos de como utilizar as funções:
 *          fork, getpid, getppid, wait, waitpid, execv e execve;
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "parent.h"
#include "child.h"


/**
 * @brief Ao Inicia o programa cria um novo processo.
 *      O processo pai executa seu código em parent.c,
 *      e o processo filho executa o código em child.c.
 */
int main(void){
    //Cria um novo processo
    pid_t pid = fork();

    if (pid < 0){
        perror("Erro ao criar o processo");
        return 1;
    }

    //Executa processo filho
    if (pid == 0){ 
        executar_filho();
    }
    //Executa processo pai
    else{
        executar_pai(); 
    }
         
    return 0;
}
