/**
 * @file exemplos_ids.c
 * @brief Exemplos de como utilizar as funções:
 *          getpid e getppid;
 * 
 * @author David Caldas (github.com/caldasdv)
 * @author Tales L. Oliveira (github.com/TalesLimaOliveira)
 */

#include "exemplos_ids.h"

void ids_example(void) {
    printf("Processo atual ID (PID): %d\n", getpid());
    printf("Processo Pai  ID (PPID): %d\n", getppid());
}