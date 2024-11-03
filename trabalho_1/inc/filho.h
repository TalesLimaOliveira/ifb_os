/**
 * @file filho.h
 * @brief Header file for filho.c
 * 
 * @author David Caldas (github.com/caldasdv)
 * @author Tales L. Oliveira (github.com/TalesLimaOliveira)
 */

#ifndef FILHO_H
#define FILHO_H

#include <stdio.h>
#include <unistd.h>

/**
 * @brief
 */
void executar_filho(void);

/**
 * @brief Executa um comando "ls -l" no processo filho utilizando
 *          execv(), que lista os arquivos do diretório atual.
 */
void transformar_filho(void);

#endif//FILHO_H
