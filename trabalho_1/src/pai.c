/**
 * @file pai.c
 * 
 * @author David Caldas (github.com/caldasdv)
 * @author Tales L. Oliveira (github.com/TalesLimaOliveira)
 */


#include <pai.h>


void executar_pai(void){
    printf("  PROCESSO PAI com PID: %d e \"Avo\" com PID: %d\n", getpid(), getppid());
}


/**
 * @brief Função que Transforma: "echo 'Olá do processo pai!'"
 *          no processo pai  utilizando execve().
 *          O processo pai espera o término do processo filho.
 */
void transformar_pai(void){
    //Vetor para listar arquivos (ls -l)
    char *args[] = {"/bin/echo", "--> Ola do processo pai!", NULL};
    char *envp[] = {NULL};  //Ambiente vazio

    //Espera o término do processo filho
    aguardar_filho(); 
    printf("  PROCESSO PAI Executando comando 'echo' com execve...\n\n");

    //Substitui o processo pai pelo comando 'echo'
    execve(args[0], args, envp);  

    //Se execve falhar, imprime erro
    perror("  PROCESSO PAI: Erro ao executar execve no pai");
}

/**
 * @brief Aguardar o término do processo filho. O status de término
 *          do filho é impresso após o término.
 */
void aguardar_filho(void) {
    int status;

    //Pai espera o término do filho
    pid_t waited_pid = wait(&status);
    printf("  PROCESSO PAI aguardou filho com PID %d terminar.\n", waited_pid);
}
