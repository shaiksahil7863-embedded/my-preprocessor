# C Preprocessor Mini Project

## Project Description

This project implements a simple C preprocessor in C. It processes a C source file and generates an output file with the `.i` extension.

## Features

- **Comment Removal:** Removes single-line ('//') and multi-line ('/* ... */') comments.
- **Header File Inclusion:** Reads and inserts the contents of a user-defined header file.
- **Macro Substitution:** Replaces macros defined using `#define`.

## Files Included

- 'main.c' — Main program that coordinates the preprocessing steps.
- 'comment_removal.c' — Handles comment removal.
- 'header_inclusion.c' — Handles header file inclusion.
- 'macro_substitution.c' — Handles macro substitution.
- 'test.c' — Test source file.
- 'my_header.h' — Example header file used for testing.

## Technologies Used

- C programming language
- Standard C libraries
- GCC compiler

## Compilation

Compile all the source files together using GCC:


gcc main.c comment_removal.c header_inclusion.c macro_substitution.c -o preprocessor


## Execution

On Linux or a Unix-like terminal, run:


./preprocessor test.c


On Windows PowerShell, run:


.\preprocessor.exe test.c


The program generates a processed output file named 'test.i'.

## Learning Objectives

- Understand basic C preprocessing concepts.
- Practice string handling and file handling in C.
- Learn to use functions such as 'strstr()', 'memmove()', and 'memcpy()', along with file operations.

## Project Status

This is an educational mini project developed for learning and practice.
