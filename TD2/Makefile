all : genere

genere : constantes.h genere.o
	gcc -o genere genere.o
	
genere.o : genere.c
	gcc -c genere.c -o genere.o -Wall

clean : 
	rm *.o
	rm genere
