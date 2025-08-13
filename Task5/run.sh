#!/bin/bash
rm -f a.out
rm -f lex.yy.c
rm -f y.tab.c
rm -f y.tab.h

# Run flex on the calculator lexer file
lex test.l

# Run yacc on the calculator parser file and generate the header file
yacc -d test.y

# Compile the generated C files with GCC, suppressing warnings
gcc lex.yy.c y.tab.c -ll

# Run the compiled calculator program
./a.out
