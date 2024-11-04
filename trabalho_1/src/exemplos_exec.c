/**
 * @file exemplos_exec.c
 * @brief Exemplos de como utilizar as funções:
 *          execv e execve;
 * 
 * @author David Caldas (github.com/caldasdv)
 * @author Tales L. Oliveira (github.com/TalesLimaOliveira)
 */

#include <exemplos_exec.h>

int exec_example(void){
    // Comando para listar arquivos (ls -l)
    char *args[] = {"/bin/ls", "-l", NULL};

    //Substitui o processo pelo comando 'ls -l'
    execv(args[0], args);

    //Em caso de sucesso o programa não executara essa linha
    //Mas em caso de erro...
    printf("execv falhou");
    return 1;
}