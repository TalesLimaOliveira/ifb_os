/**
 * @file parent.h
 * 
 * @author David Caldas (github.com/caldasdv)
 * @author Tales L. Oliveira (github.com/TalesLimaOliveira)
 */

#ifndef PARENT_H
#define PARENT_H

/**
 * @brief Função que executa: "echo 'Olá do processo pai!'"
 *          no processo pai  utilizando execve().
 *          O processo pai espera o término do processo filho.
 */
void executar_pai(void);

/**
 * @brief Aguardar o término do processo filho. O status de término
 *          do filho é impresso após o término.
 */
void aguardar_filho(void);

#endif