/**
 * @file wait.c
 * @brief Exemplos de como utilizar as funções:
 *          wait e waitpid;
 * 
 * @author David Caldas (github.com/caldasdv)
 * @author Tales L. Oliveira (github.com/TalesLimaOliveira)
 */

#include "wait.h"

void wait_example(void){
    pid_t pid = fork();

    if (pid < 0){
        printf("Fork falhou");
        return;
    }
    
    //Processo Filho
    if (pid == 0) {
        printf("Filho 1 Trabalhando...\n");
        sleep(2); // Simula Trabalho
        exit(0); // Termina o filho para nao haver duplicatas
    }
    
    //Processo Pai
    int status;
    pid_t waited_pid = wait(&status);
    printf("Filho com PID %d terminou.\n", waited_pid);
}



void waitpid_example(void){
    pid_t pid = fork();

    if (pid < 0){
        printf("Fork falhou");
        return;
    }
    
    //Processo Filho
    if (pid == 0) {
        printf("Filho 2 Trabalhando...\n");
        sleep(2); // Simula Trabalho
        exit(0); // Termina o filho para nao haver duplicatas
    }
    
    // Processo Pai
    int status;
    // Espera pelo processo filho específico
    pid_t waited_pid = waitpid(pid, &status, 0);

    if (waited_pid > 0) {
        if (WIFEXITED(status)) {
            printf("Filho 2 com PID %d terminou com status %d.\n", waited_pid, WEXITSTATUS(status));
            return;
        }

        printf("Filho 2 com PID %d não terminou normalmente.\n", waited_pid);
        return;
    }

    printf("Erro ao esperar pelo filho 2.\n");
}