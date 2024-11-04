/**
 * @file filho.c
 * 
 * @author David Caldas (github.com/caldasdv)
 * @author Tales L. Oliveira (github.com/TalesLimaOliveira)
 */


#include <filho.h>


void executar_filho(void){
    printf("  PROCESSO FILHO com PID: %d e Pai com PID: %d\n", getpid(), getppid());
}

/**
 * @brief Executa um comando "ls -l" no processo filho utilizando
 *          execv(), que lista os arquivos do diretório atual.
 */
void transformar_filho(void){
    //Vetor para listar arquivos (ls -l)
    char *args[] = {"/bin/ls", "-l", NULL}; 

    printf("  PROCESSO FILHO transforma em 'ls -l' com execv...\n\n");
    execv(args[0], args);  //Substitui o processo filho pelo comando 'ls -l'

    //Se execv falhar, imprime erro
    perror("  PROCESSO FILHO: Erro ao executar execv no filho");
}
