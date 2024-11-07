/**
 * @file wait.h
 * @brief Header file for wait.c
 * 
 * @author David Caldas (github.com/caldasdv)
 * @author Tales L. Oliveira (github.com/TalesLimaOliveira)
 */

#ifndef WAIT_H
#define WAIT_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int wait_example(void);
int waitpid_example(void);

#endif//WAIT_H