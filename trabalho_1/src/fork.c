/**
 * @file fork.c
 * @brief Exemplos de como utilizar a função:
 *          fork();
 * 
 * @author David Caldas (github.com/caldasdv)
 * @author Tales L. Oliveira (github.com/TalesLimaOliveira)
 */

#include "fork.h"

void fork_example(void){
    pid_t pid = fork();

    if (pid < 0){
        printf("Fork falhou\n");
        return;
    }
    
    //Processo Filho
    if (pid == 0){
        printf("PROCESSO FILHO com PID: %d e Pai   com PID: %d\n", getpid(), getppid());
        exit(0); //Termina o filho para nao haver duplicatas
    }

    //Processo Pai
    sleep(1); //"Dorme" por 1s p/ garantir que o filho print primeiro ("Não é necessario, apenas por estetica visual!")
    printf("PROCESSO PAI   com PID: %d e Filho com PID: %d\n", getpid(), pid);
}