#!/bin/bash

# Run flex on the calculator lexer file
lex BGSASAS.l

gcc lex.yy.c -ll

# Run the compiled calculator program
./a.out
