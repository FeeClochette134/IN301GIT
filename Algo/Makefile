

run : main
	./main

main : main.o file.o
	gcc main.o file.o -o main

file.o : file.c file.h
	gcc -Wall -c file.c

main.o : main.c file.h
	gcc -Wall -c main.c

clean:
	rm -f *.o
	rm -f main
