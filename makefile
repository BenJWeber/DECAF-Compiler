# Ben Weber
# Lab 9
# 10/31/2022
# Generating assembly

all:	lab9

lab9:   lab9.l lab9.y ast.c ast.h symtable.c symtable.h emit.c
	   lex lab9.l
	   yacc -d lab9.y
	   gcc lex.yy.c y.tab.c ast.c symtable.c emit.c -o lab9

clean:	
	rm -f lab9

emit: lab9
	./lab9 -o small < small.decaf
	gcc small.s
	./a.out
