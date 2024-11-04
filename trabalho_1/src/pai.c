/**
 * @file pai.c
 * 
 * @author David Caldas (github.com/caldasdv)
 * @author Tales L. Oliveira (github.com/TalesLimaOliveira)
 */


#include <pai.h>


void executar_pai(void){
    printf("  EP -   PAI PID: %d\n", getpid());
    printf("  EP -   AVO PID: %d\n", getppid());
}


/**
 * @brief Função que Transforma: "echo 'Olá do processo pai!'"
 *          no processo pai  utilizando execve().
 *          O processo pai espera o término do processo filho.
 */
void transformar_pai(void){
    printf("  TP -   PAI PID: %d\n", getpid());

    char *args[] = {"/bin/echo", "Olá do processo pai!", NULL};  // Comando echo
    char *envp[] = {NULL};  // Ambiente vazio para simplificação

    //Espera o término do processo filho
    aguardar_filho(); 
    printf("  TP - Aguardou filho terminar...\n");
    printf("  TP - Executando comando 'echo' com execve...\n\n");

    //Substitui o processo pai pelo comando 'echo'
    execve(args[0], args, envp);  

    //Se execve falhar, imprime erro
    perror("  TP - Erro ao executar execve no pai");
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
        printf("  WP - Filho terminou com status: %d\n", WEXITSTATUS(status));
    } else {
        printf("  WP - Filho terminou de forma anormal.\n");
    }
}
