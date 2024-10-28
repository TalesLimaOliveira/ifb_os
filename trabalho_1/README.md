# Programa de Processos

Este projeto em C cria um programa que demonstra a criação e controle de processos usando as funções:

> `fork()`, `execv()`, `execve()`, `getpid()`, `getppid()`, `wait()`, e `waitpid()`.

### Feito Por: [David Caldas](https://github.com/caldasdv), [Tales L. Oliveira](https://github.com/TalesLimaOliveira).


### Compilar e Executar

Este projeto usa um `Makefile` para simplificar a compilação e execução. 

- Para compilar o programa, utilize:
```bash
  make all
```

- Para executar o programa, utilize:
```bash
  make run
```

<br>

---

<br>

## Manual

### 1. fork()

A função `fork()` cria um novo processo duplicando o processo que a chamou. O processo original é chamado de processo pai, e o novo processo é chamado de processo filho.

**Retorno:**

No processo *pai*, `fork()` retorna o PID (Process ID) do *filho*.
No processo *filho*, retorna 0.
Se ocorrer um erro, retorna -1.

**Exemplo:**
```c
#include <stdio.h>
#include <unistd.h>

int main(void){
    pid_t pid = fork();

    if (pid < 0){
        perror("Fork failed");
        return 1;
    }
    
    // Child process
    if (pid == 0){
        printf("This is the child process with PID: %d\n", getpid());
    }

    //Parent process
    else{
        printf("This is the parent process with PID: %d and child PID: %d\n", getpid(), pid);
    }

    return 0;
}
```


### 2. wait() e waitpid()

A função `wait()` faz com que o processo *pai* aguarde a finalização de um processo *filho*.
A função `waitpid()` é uma versão mais flexível, permitindo especificar qual processo filho aguardar.

**Retorno:**

Retorna o PID do *filho* que terminou ou -1 em caso de erro.

**Exemplo:**

```c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
    pid_t pid = fork();

    if (pid < 0){
        perror("Fork failed");
        return 1;
    }
    
    // Child process
    if (pid == 0) {
        sleep(2); // Simulate work
        return 0; // Child exits
    }
    
    //Parent process
    int status;
    pid_t waited_pid = wait(&status);
    printf("Child with PID %d terminated.\n", waited_pid);

    if (WIFEXITED(status)) {
        printf("Child exited with status %d.\n", WEXITSTATUS(status));
    }
    
    return 0;
}
```

### 3. getpid() e getppid()

**Retorno:**

`getpid()` retorna o PID do processo chamador.
`getppid()` retorna o PID do processo pai.

**Exemplo:**

```c
#include <stdio.h>
#include <unistd.h>

int main(void){
    printf("Current Process ID (PID): %d\n", getpid());
    printf("Parent Process ID (PPID): %d\n", getppid());
    return 0;
}
```

### 4. execv() e execve()

A função `execv()` substitui o processo atual por um novo processo. Recebe como argumentos o caminho do executável e um vetor de argumentos.
A função `execve()` é semelhante, mas aceita um vetor de *variáveis de ambiente*.

**Retorno:**

Em caso de sucesso, não retorna. Em caso de erro, retorna -1.

**Exemplo:**
```c
#include <stdio.h>
#include <unistd.h>

int main(void){
    char *args[] = {"ls", "-l", NULL}; // Command and arguments
    execv("/bin/ls", args); // Execute ls command
    perror("execv failed"); // If execv fails
    return 1;
}
```
