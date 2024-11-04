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
        printf("Fork falhou");
        return 1;
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
    
    return 0;
}



int waitpid_example(void){
    pid_t pid = fork();

    if (pid < 0){
        printf("Fork falhou");
        return 1;
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
            return 0;
        }

        printf("Filho 2 com PID %d não terminou normalmente.\n", waited_pid);
        return 1;
    }

    printf("Erro ao esperar pelo filho 2.\n");
    return 1;
}