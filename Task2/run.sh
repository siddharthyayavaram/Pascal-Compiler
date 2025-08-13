#!/bin/bash

# Run flex on the calculator lexer file
lex BGSASAS.l

# Run yacc on the calculator parser file and generate the header file
yacc -d BGSASAS.y -Wno

# Compile the generated C files with GCC, suppressing warnings
gcc lex.yy.c y.tab.c -w

# Run the compiled calculator program
./a.out
