/**
 * @file pai.h
 * @brief Header file for pai.c
 * 
 * @author David Caldas (github.com/caldasdv)
 * @author Tales L. Oliveira (github.com/TalesLimaOliveira)
 */

#ifndef PAI_H
#define PAI_H

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * @brief 
 */
void executar_pai(void);

/**
 * @brief Função que executa: "echo 'Olá do processo pai!'"
 *          no processo pai  utilizando execve().
 *          O processo pai espera o término do processo filho.
 */
void transformar_pai(void);

/**
 * @brief Aguardar o término do processo filho. O status de término
 *          do filho é impresso após o término.
 */
void aguardar_filho(void);

#endif//PAI_H