# Programas exemplos de processos em C

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue" alt="Linguagem">
  <img src="https://img.shields.io/badge/Status-Active-success" alt="Status">
</p>

## 👨‍🏫 Professor
- **João Victor A. Oliveira**

## 👨‍💻 Autores

- [David Caldas](https://github.com/caldasdv)
- [Tales Oliveira](https://github.com/TalesLimaOliveira)

---

## 📖 Visão Geral

- [Repositorio Github do Projeto](https://github.com/TalesLimaOliveira/ifb_os/tree/main/trabalho_2)

Este projeto em C cria um programa que utiliza threads para processar arquivos em um diretório, contando as ocorrências de um termo de busca específico. O programa é composto por três tipos de threads: `dispatcher`, `worker` e `ranking`.

O dispatcher atribui arquivos para os workers processarem, os workers contam as ocorrências do termo de busca nos arquivos e o ranking atualiza e exibe os resultados dos arquivos com mais ocorrências.

---

## 📂 Estrutura do Projeto

| **Diretório/Arquivo**  | **Descrição**                               |
|------------------------|---------------------------------------------|
| `app/`                 |                                             |
| └── `main.c`           | Ponto de entrada da aplicação.              |
| `src/`                 |                                             |
| └── `worker.c`         | Implementação das funções de worker.        |
| └── `dispatcher.c`     | Implementação das funções de dispatcher.    |
| └── `ranking.c`        | Implementação das funções de ranking.       |
| `inc/`                 |                                             |
| └── `worker.h`         | Declarações das funções de worker.          |
| └── `dispatcher.h`     | Declarações das funções de dispatcher.      |
| └── `ranking.h`        | Declarações das funções de ranking.         |
| `resources/`           |                                             |
| └── `fileset/`         | Diretorio com os arquivos termos            |
| └── `generate_files.py`| Script para criação dos arquivos termos     | 
| └── `problem.pdf`      | Desafio proposto para a atividade           |
| `Makefile`             | Script de automação de build.               |
| `README.md`            | Documentação do projeto. (Este arquivo)     |

---

## 🚀 Como Rodar

### 🔨 Construir o Projeto

> make

### ▶️ Rodar a Aplicação

> make run `termo`

### 🧹 Limpar Arquivos de Build

> make clean

---

## 🗂️ Gerar Arquivos para o Programa (Opcional)

**Obs: Certifique-se de que a pasta `fileset` esteja dentro da pasta `resources` (resources/fileset).**

Caso precise, use o script `generate_files.py` para gerar arquivos .txt para o uso do programa.

> python resources/generate_files.py
