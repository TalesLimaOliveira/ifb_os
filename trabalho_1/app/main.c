/**
 * @file main.c
 * 
 * @author David Caldas (github.com/caldasdv)
 * @author Tales L. Oliveira (github.com/TalesLimaOliveira)
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "pai.h"
#include "filho.h"


/**
 * @brief Ao Inicia o programa cria um novo processo.
 *      O processo pai executa seu código em pai.c,
 *      e o processo filho executa o código em filho.c.
 */
int main(void){
    //Cria um novo processo
    pid_t pid = fork();

    if (pid < 0){
        printf("  Erro ao criar o processo");
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
    printf("-> Pai e filho executaram essa linha!\n");

    //Trasforma processo filho
    if (pid == 0){ 
        transformar_filho();
    }
    //Trasforma processo pai
    else{
        transformar_pai(); 
    }
    printf("-> Nem o pai ou filho executarão essa linha\n");
    printf("   Pois irão se torna outro programa com EXECV!\n");
    printf("   Há não ser que ocorra um erro!\n");

    return 0;
}
