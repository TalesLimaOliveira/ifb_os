/**
 * @file exec.c
 * @brief Exemplos de como utilizar as funções:
 *          execv e execve;
 * 
 * @author David Caldas (github.com/caldasdv)
 * @author Tales L. Oliveira (github.com/TalesLimaOliveira)
 */

#include "exec.h"

/**
 * @brief Exemplo do uso da função execv(), que substitui o processo atual
 *          por outro processo, em caso de sucesso o programa não retorna,
 *          pois foi substituido pelo novo processo.
 */
void exec_example(void){
    // Comando para listar arquivos (ls -l)
    char *args[] = {"/bin/ls", "-l", NULL};

    printf("Substituindo o programa atual por: 'ls -l'\n");
    execv(args[0], args);

    //Em caso de sucesso o programa não executara essa linha
    //Mas em caso de erro...
    printf("execv falhou");
}