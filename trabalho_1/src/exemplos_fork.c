/**
 * @file exemplos_fork.c
 * @brief Exemplos de como utilizar a função:
 *          fork();
 * 
 * @author David Caldas (github.com/caldasdv)
 * @author Tales L. Oliveira (github.com/TalesLimaOliveira)
 */

#include <exemplos_fork.h>

int fork_example(void){
    pid_t pid = fork();

    if (pid < 0){
        perror("Fork falhou");
        return 1;
    }
    
    //Processo Filho
    if (pid == 0){
        printf("PROCESSO FILHO com PID: %d", getpid());
        printf(" e Pai   com PID: %d\n", getppid());
        exit(0); //Termina o filho para nao haver duplicatas
    }

    //Processo Pai
    printf("PROCESSO PAI   com PID: %d", getpid());
    printf(" e Filho com PID: %d\n", pid);

    return 0;
}