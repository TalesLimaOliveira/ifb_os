/**
 * @file filho.c
 * 
 * @author David Caldas (github.com/caldasdv)
 * @author Tales L. Oliveira (github.com/TalesLimaOliveira)
 */


#include "filho.h"


void executar_filho(void){
    printf("  EC - FILHO PID: %d\n", getpid());
    printf("  EC -   PAI PID: %d\n", getppid());
}

/**
 * @brief Executa um comando "ls -l" no processo filho utilizando
 *          execv(), que lista os arquivos do diretório atual.
 */
void transformar_filho(void){
    printf("  TC - FILHO PID: %d\n", getpid());
    printf("  TC -   PAI PID: %d\n", getppid());

    // Comando para listar arquivos (ls -l)
    char *args[] = {"/bin/ls", "-l", NULL}; 

    printf("  TC - FILHO: executando comando 'ls -l' com execv...\n\n");
    //Substitui o processo filho pelo comando 'ls -l'
    execv(args[0], args);  

    //Se execv falhar, imprime erro
    perror("  TC - FILHO: Erro ao executar execv no filho");
}
