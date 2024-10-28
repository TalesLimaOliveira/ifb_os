# Programa de Processos com fork, execv e execve

Este projeto em C cria um programa que demonstra a criação e controle de processos usando as funções `fork()`, `execv()`, `execve()`, `getpid()`, `getppid()`, e `wait()`. O programa divide a execução em duas partes distintas: uma para o processo pai e outra para o processo filho. 

O processo **pai** utiliza `execve()` para executar um comando, enquanto o **filho** utiliza `execv()` para executar um comando diferente.

Feito Por:
[David Caldas.](https://github.com/caldasdv)
[Tales L. Oliveira.](https://github.com/TalesLimaOliveira)

## Requirements
> GCC/G++ (MinGW.org GCC Build-2) - Versão 9.2.0

> GNU Make - Versão 3.82.90

### Comandos para Compilar e Executar

Este projeto usa um `Makefile` para simplificar a compilação e execução. 

- Para compilar o programa, utilize:
```bash
  make all
```

## Estrutura do Código

O código foi modularizado em três partes principais:
1. **main.c**: Função principal que inicializa o programa e cria o novo processo.
2. **parent.c** e **parent.h**: Contêm a lógica do processo pai.
3. **child.c** e **child.h**: Contêm a lógica do processo filho.

### Funcionalidades

1. **main.c**: 
   - Realiza o `fork()` para criar um novo processo.
   - Se o processo criado é o **pai**, ele chama a função `executar_comando_pai()` para executar o comando específico do pai.
   - Se o processo criado é o **filho**, ele chama a função `executar_comando_filho()` para executar o comando específico do filho.

2. **parent.c / parent.h**:
   - Função `executar_comando_pai()`:
     - Imprime o PID do processo pai.
     - Executa um comando `echo` usando `execve()` para exibir a mensagem "Olá do processo pai!".
     - Utiliza um ambiente vazio (`char *envp[] = {NULL};`) para simplificação.
     - Aguarda o término do processo filho caso `execve()` falhe.
   - Função `aguardar_filho()`:
     - O processo pai utiliza `wait()` para aguardar a finalização do processo filho.
     - Imprime o status de saída do processo filho.

3. **child.c / child.h**:
   - Função `executar_comando_filho()`:
     - Imprime o PID do processo filho e o PID do processo pai.
     - Executa o comando `ls -l` usando `execv()` para listar os arquivos do diretório atual.
     - Utiliza `execv()` sem ambiente adicional, assumindo que o processo herda o ambiente do pai.


