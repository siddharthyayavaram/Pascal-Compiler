flex tac.l
yacc -d tac.y -Wno
gcc lex.yy.c y.tab.c -w
./a.out