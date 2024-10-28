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
void executa_filho(void){
    printf("  FILHO: PID do filho: %d\n", getpid());
    printf("  FILHO: PID do pai: %d\n", getppid());

    sleep(1);
}

/**
 * @brief Executa um comando "ls -l" no processo filho utilizando
 *          execv(), que lista os arquivos do diretório atual.
 */
void transformar_filho(void){
    printf("  FILHO: PID do filho: %d\n", getpid());
    printf("  FILHO: PID do pai: %d\n", getppid());

    // Comando para listar arquivos (ls -l)
    char *args[] = {"/bin/ls", "-l", NULL}; 

    printf("  FILHO: executando comando 'ls -l' com execv...\n");
    execv(args[0], args);  //Substitui o processo filho pelo comando 'ls -l'

    //Se execv falhar, imprime erro
    perror("  FILHO: Erro ao executar execv no filho");
}
