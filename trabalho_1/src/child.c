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
 * @brief Executa um comando "ls -l" no processo filho utilizando
 *          execv(), que lista os arquivos do diretório atual.
 */
void executar_filho(void){
    printf("Processo FILHO:\n");
    printf("  PID do filho: %d\n", getpid());
    printf("  PID do pai: %d\n", getppid());

    // Comando para listar arquivos (ls -l)
    char *args[] = {"/bin/ls", "-l", NULL}; 

    printf("  Filho executando comando 'ls -l' com execv...\n");
    execv(args[0], args);  //Substitui o processo filho pelo comando 'ls -l'

    //Se execv falhar, imprime erro
    perror("Erro ao executar execv no filho");
}
