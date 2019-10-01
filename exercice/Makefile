
nombres_uniq.data : nombres_tries.data
	uniq nombres_tries.data nombres_uniq.data

nombres_tries.data : nombres.data
	sort -n nombres.data nombres_tries.data

nombres.data : compiler
	./compiler

compiler : 3.c
	gcc -o compiler -Wall 3.c
