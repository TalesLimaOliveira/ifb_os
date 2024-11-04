# Programa de Processos

Este projeto em C cria um programa que demonstra a criação e controle de processos usando as funções:

> `getpid()`, `getppid()`, `fork()`, `execv()`, `execve()`, `wait()`, e `waitpid()`.

Um manual explicando as funçoes pode ser visto juntamente com o projeto.

### Feito Por: [David Caldas](https://github.com/caldasdv), [Tales L. Oliveira](https://github.com/TalesLimaOliveira).


### Compilar e Executar

Este projeto usa um `Makefile` para simplificar a compilação e execução. 

O Programa `main.c` conta com todos os exemplos sendo usados de uma só vez!

O Programa `exemplo.c` são os exemplos utilizados no **Manual**.pdf

- Para **compilar** os programas `main.c` e `exemplos.c`, utilize:
```bash
  make all
```

- Para **executar** o programa **main**, utilize:
```bash
  make run-main
```

- Para **executar** apenas os programas **exemplos**, utilize:
```bash
  make run-exemplos
```
