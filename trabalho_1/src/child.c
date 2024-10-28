/**
 * @file child.c
 * 
 * @author David Caldas (github.com/caldasdv)
 * @author Tales L. Oliveira (github.com/TalesLimaOliveira)
 */

#include <stdio.h>
#include <unistd.h>
#include "child.h"

/**
 * @brief 
 */
void executar_filho(void){
    printf("  E - FILHO PID: %d\n", getpid());
    printf("  E -   PAI PID: %d\n", getppid());

    sleep(1);
}

/**
 * @brief Executa um comando "ls -l" no processo filho utilizando
 *          execv(), que lista os arquivos do diretório atual.
 */
void transformar_filho(void){
    printf("  T - FILHO PID: %d\n", getpid());
    printf("  T -   PAI PID: %d\n", getppid());

    // Comando para listar arquivos (ls -l)
    char *args[] = {"/bin/ls", "-l", NULL}; 

    printf("  T - FILHO: executando comando 'ls -l' com execv...\n\n");
    //Substitui o processo filho pelo comando 'ls -l'
    execv(args[0], args);  

    //Se execv falhar, imprime erro
    perror("  T - FILHO: Erro ao executar execv no filho");
}
