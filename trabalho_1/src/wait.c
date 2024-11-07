/**
 * @file wait.c
 * @brief Exemplos de como utilizar as funções:
 *          wait e waitpid;
 * 
 * @author David Caldas (github.com/caldasdv)
 * @author Tales L. Oliveira (github.com/TalesLimaOliveira)
 */

#include "wait.h"

/**
 * @brief Exemplo da função wait(), que spera qualquer filho do mesmo
 *          grupo de processor terminar. Inclusive os que ele não criou.
 */
void wait_example(void){
    int status;
    pid_t waited_pid = wait(&status);
    printf("WAIT: Filho não especifico com PID %d terminou\n", waited_pid);
}


/**
 * @brief Exemplo da função waitpid(), que espera por um processo filho especifico.
 */
void waitpid_example(void){
    pid_t pid = fork();

    if (pid < 0){
        printf("Fork falhou");
        return;
    }
    
    //Processo Filho
    if (pid == 0) {
        printf("WAITPID:  Filho Trabalhando... PID %d\n", getpid());
        sleep(2); // Simula Trabalho
        exit(0); // Termina o filho para nao haver duplicatas
    }
    
    // Processo Pai
    int status;
    // Espera pelo processo filho específico
    pid_t waited_pid = waitpid(pid, &status, 0);

    if (waited_pid > 0) {
        if (WIFEXITED(status)) {
            printf("WAITPID:  Filho especifico com PID %d terminou com status %d.\n", waited_pid, WEXITSTATUS(status));
            return;
        }

        printf("WAITPID:  Filho especifico com PID %d não terminou normalmente.\n", waited_pid);
        return;
    }

    printf("WAITPID: Erro ao esperar pelo filho.\n");
}