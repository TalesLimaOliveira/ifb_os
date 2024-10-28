#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include "parent.h"

/**
 * @brief Função que executa: "echo 'Olá do processo pai!'"
 *          no processo pai  utilizando execve().
 *          O processo pai espera o término do processo filho.
 */
void executar_pai(void){
    printf("  PAI: PID do pai: %d\n", getpid());

    char *args[] = {"/bin/echo", "Olá do processo pai!", NULL};  // Comando echo
    char *envp[] = {NULL};  // Ambiente vazio para simplificação

    //Espera o término do processo filho
    aguardar_filho(); 
    printf("  PAI: Aguardou filho terminar...\n");
    printf("  PAI: Executando comando 'echo' com execve...\n");

    //Substitui o processo pai pelo comando 'echo'
    execve(args[0], args, envp);  

    //Se execve falhar, imprime erro
    perror("  Erro ao executar execve no pai");
}

/**
 * @brief Aguardar o término do processo filho. O status de término
 *          do filho é impresso após o término.
 */
void aguardar_filho(void) {
    int status;

    //Pai espera o término do filho
    wait(&status); 

    if (WIFEXITED(status)) {
        printf("  PAI: Filho terminou com status: %d\n", WEXITSTATUS(status));
    } else {
        printf("  PAI: Filho terminou de forma anormal.\n");
    }

    printf("  PAI: continua após o término do filho.\n");
}
