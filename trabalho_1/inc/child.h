/**
 * @file child.h
 * 
 * @author David Caldas (github.com/caldasdv)
 * @author Tales L. Oliveira (github.com/TalesLimaOliveira)
 */

#ifndef CHILD_H
#define CHILD_H

/**
 * @brief
 */
void executa_filho(void);

/**
 * @brief Executa um comando "ls -l" no processo filho utilizando
 *          execv(), que lista os arquivos do diretório atual.
 */
void transformar_filho(void);

#endif
