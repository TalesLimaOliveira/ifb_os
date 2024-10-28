# Choose Language / Elija Idioma / Escolha o Idioma

Please choose your preferred language:

1. [English](#english)
2. [Español](#spanish)
3. [Português (Brasil)](#portuguese)

---


## English

# Generic File Compilation
This project consists of a generic Makefile that can be used on any operating system to compile C/C++ programs. It provides an organized folder structure and automates the process of compiling and cleaning temporary binary files.

By [Tales L. Oliveira.](https://github.com/TalesLimaOliveira)

## Requirements
> GCC/G++ (MinGW.org GCC Build-2) - Versão 9.2.0

> GNU Make - Versão 3.82.90


## Compilation and File Cleaning

To compile and run the project, use the following command:

```go
make APP=<app_name>
```

Replace **<app_name>** with the name of the file located in the app folder that you want to compile.

By default, **<app_name>** is set to **app**.

The project will create the **bin** and **obj** folders to store temporary binary files generated during compilation.

The project will automatically remove temporary files.

If you want to force cleaning, use this command:

```go
make clean
```

<br>

Feel free to explore the source code and adapt the Makefile according to your specific needs.

[How to Organize Your Project](#howtoorganizeyourproject)

[Additional Links](#additionallinks)

<br>

---


## Spanish

# Compilación Genérica de Archivos
Este proyecto consiste en un Makefile genérico que se puede utilizar en cualquier sistema operativo para compilar programas en C/C++. Ofrece una estructura de carpetas organizada y automatiza el proceso de compilación y limpieza de archivos binarios temporales.

Por [Tales L. Oliveira.](https://github.com/TalesLimaOliveira)

## Requisitos
> GCC/G++ (MinGW.org GCC Build-2) - Versão 9.2.0

> GNU Make - Versão 3.82.90

<br>

# Compilación y Limpieza de Archivos

```go
make APP=<nombre_del_app>
```

Reemplaza **<nombre_del_app>** por el nombre del archivo ubicado en la carpeta app que deseas compilar.

Por defecto, **<nombre_del_app>** es **app**.

El proyecto creará las carpetas **bin** y **obj** para almacenar archivos binarios temporales generados durante la compilación.

El proyecto eliminará automáticamente los archivos temporales.

Si deseas forzar la limpieza, utiliza el siguiente comando:

```go
make clean
```

<br>

Siéntete libre de explorar el código fuente y adaptar el Makefile según tus necesidades específicas.

[Cómo Organizar tu Proyecto](#howtoorganizeyourproject)

[Enlaces Adicionales](#additionallinks)

<br>

---


## Portuguese

# Compilação Genérica de Arquivos
Este projeto consiste em um Makefile genérico que pode ser utilizado em qualquer sistema operacional para compilar programas em C/C++. Ele oferece uma estrutura de pastas organizada e automatiza o processo de compilação e limpeza dos arquivos binários temporários.

Por [Tales L. Oliveira.](https://github.com/TalesLimaOliveira)

## Requisitos
> GCC/G++ (MinGW.org GCC Build-2) - Versão 9.2.0

> GNU Make - Versão 3.82.90

<br>

## Compilação e Limpeza de Arquivos

Para compilar e executar o projeto, utilize o seguinte comando:

```go
make APP=<nome_do_app>
```

Substitua **<nome_do_app>** pelo nome do arquivo localizado na pasta app que deseja compilar.

Por padrao o **<nome_do_app>** vem **app**.

O projeto irá criar as pastas **bin** e **obj** para armazenar os arquivos binários temporários gerados durante a compilação.

O projeto irá remover os arquivos temporários automaticamente.

Mas caso queira forçar a limpeza, utilize este comando:

```go
make clean
```

<br>

Sinta-se à vontade para explorar o código-fonte e adaptar o Makefile de acordo com suas necessidades específicas.

[Como Organizar seu Projeto](#howtoorganizeyourproject)

[Links Adicionais](#additionallinks)

<br>

---


## AdditionalLinks

- https://github.com/TalesLimaOliveira/GenericMakeFile

## HowToOrganizeYourProject

``` bash
    /project-root
    ├── app
    │    └── main.c
    ├── inc
    │    └── *.h
    ├── lib
    │    └── *.a
    ├── res
    │    └── resource-file.*
    ├── src
    │    └── *.c
    ├── build
    │    ├── bin
    │    │    └── app
    │    └── obj
    │         └── *.o
    ├── Makefile
    └── README.md
```
