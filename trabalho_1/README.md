# Programas exemplos de processos em C

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue" alt="Linguagem">
  <img src="https://img.shields.io/badge/Status-Active-success" alt="Status">
</p>

## 👨‍💻 Autores

- [David Caldas](https://github.com/caldasdv)
- [Tales Oliveira](https://github.com/TalesLimaOliveira)

---

## 📖 Visão Geral
Este projeto em C cria um programa que demonstra a criação e controle de processos usando as funções:

> `getpid()`, `getppid()`, `fork()`, `execv()`, `execve()`, `wait()`, e `waitpid()`.

Um **[manual.pdf](./Manual.pdf)** explicando as funções pode ser visto juntamente com o projeto.

---

## 📂 Estrutura do Projeto

| **Diretório/Arquivo** | **Descrição**                               |
|-----------------------|---------------------------------------------|
| `app/`                |                                             |
| └── `exemplos.c`      | Ponto de entrada da aplicação.              |
| `src/`                |                                             |
| └── `exec.c`          | Exemplos da função execv()                  |
| └── `fork.c`          | Exemplos da função fork()                   |
| └── `ids.c`           | Exemplos das funções getpid() e getppid()   |
| └── `wait.c`          | Exemplos das funções wait() e waitpid()     |
| `inc/`                |                                             |
| └── `*.h`             | Arquivos de cabeçalho para declarações.     |
| `Makefile`            | Script de automação de build.               |
| `README.md`           | Este arquivo, contendo a documentação do projeto. |

---

## 🚀 Como Rodar

### 🔨 Construir o Projeto

> make

### ▶️ Rodar a Aplicação

> make run

### 🧹 Limpar Arquivos de Build

> make clean
