/**
 * @file ids.c
 * @brief Exemplos de como utilizar as funções:
 *          getpid e getppid;
 * 
 * @author David Caldas (github.com/caldasdv)
 * @author Tales L. Oliveira (github.com/TalesLimaOliveira)
 */

#include "ids.h"

/**
 * @brief Exemplo de uso das funções getpid() e getppid(),
 *          que mostra o ID do processo atual e do processo pai.
 */
void ids_example(void) {
    printf("Processo atual ID (PID): %d\n", getpid());
    printf("Processo Pai  ID (PPID): %d\n", getppid());
}