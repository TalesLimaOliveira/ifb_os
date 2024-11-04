/**
 * @file exemplos_wait.c
 * @brief Exemplos de como utilizar as funções:
 *          wait e waitpid;
 * 
 * @author David Caldas (github.com/caldasdv)
 * @author Tales L. Oliveira (github.com/TalesLimaOliveira)
 */

#include <exemplos_wait.h>

int wait_example(void){
    pid_t pid = fork();

    if (pid < 0){
        perror("Fork falhou");
        return 1;
    }
    
    //Processo Filho
    if (pid == 0) {
        sleep(2); // Simula Trabalho
        return 0; // Fim do Filho
    }
    
    //Processo Pai
    int status;
    pid_t waited_pid = wait(&status);
    printf("Filho com PID %d terminou.\n", waited_pid);
    
    return 0;
}