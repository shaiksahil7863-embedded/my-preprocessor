# C Preprocessor Mini Project

## Project Description
This project implements a simple C preprocessor using the C programming language. It processes a C source file and generates an output file with the '.i' extension.

## Features
- **Comment Removal:** Removes single-line ('//') and multi-line ('/* ... */') comments.
- **Header File Inclusion:** Reads and inserts the contents of user-defined header files.
- **Macro Substitution:** Replaces macros defined using `#define`.

## Files Included
- 'main.c' – Main program that coordinates the preprocessing steps.
- 'comment_removal.c' – Handles comment removal.
- 'header_inclusion.c' – Handles header file inclusion.
- 'macro_substitution.c' – Handles macro substitution.
- 'test.c' – Test source file.
- 'myheader.h' – Example header file used for testing.

## Technologies Used
- C Programming Language
- Standard C libraries

## Compilation
Compile all the source files together using GCC:


gcc main.c comment_removal.c header_inclusion.c macro_substitution.c -o preprocessor


## Execution
Run the program with a C source file as the argument:


./preprocessor test.c


The program generates a processed output file named 'test.i'.

## Learning Objectives
- Understand basic preprocessing concepts in C.
- Practice string handling and file handling in C.
- Learn to use functions such as 'strstr()', 'memmove()', 'memcpy()', and file operations.

## Project Status
This is an educational mini project developed for learning and practice.: