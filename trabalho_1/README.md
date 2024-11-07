# Programas de processos em C

Este projeto em C cria um programa que demonstra a criação e controle de processos usando as funções:

> `getpid()`, `getppid()`, `fork()`, `execv()`, `execve()`, `wait()`, e `waitpid()`.

<br>

### Um [manual.pdf](./Manual.pdf) explicando as funções pode ser visto juntamente com o projeto.

## Feito Por: [David Caldas](https://github.com/caldasdv), [Tales L. Oliveira](https://github.com/TalesLimaOliveira).

<br>

### Compilação, Execução e Limpeza dos Programas

Este projeto usa um `Makefile` para simplificar a compilação e execução.

O Programa `app\exemplos.c` são os exemplos utilizados no `**Manual**.pdf`

- Para **compilar** os programas `exemplos`, utilize:
```bash
  make all
```

- Para **executar** os programas **exemplos**, utilize:
```bash
  make run
```

- Para **limpar** os arquivos binarios criados pela compilação, utilize:
```bash
  make clean
```

### Organização das pastas

      /project-root
      ├── app -> Pasta contendo o app principal
      │    └── exemplos.c
      ├── inc  -> Pasta contendo todos os arquivos cabeçalhos
      │    └── *.h  
      ├── src -> Pasta contendo todos os arquivos fontes
      │    └── *.c
      ├── build -> Pasta contendo todos os arquivos binarios
      │    ├── bin
      │    │    └── app -> Binario do app final
      │    └── obj
      │         └── *.o -> Binario do arquirvos objs
      │  
      ├── Makefile
      └── README.md
