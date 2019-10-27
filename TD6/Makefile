run : main
	./main

main : liste.o main.o 
	gcc -o main -Wall main.o liste.o

main.o : main.c liste.h
	gcc -Wall -c main.c

liste.o : liste.h liste.c
	gcc -Wall -c liste.c
	
clean :
	rm -f liste.o
	rm -f main.o
	
	
run2 : ex26
	./ex26

ex26 : ex26.c
	gcc -o ex26 -Wall ex26.c
