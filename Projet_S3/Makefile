

partie1 : main1
	./main1

main1 : sequence.o distance.o main1.o
	gcc -Wall -o main1 sequence.o distance.o main1.o

sequence.o : sequence.c sequence.h
	gcc -Wall -c sequence.c

distance.o : distance.c distance.h
	gcc -Wall -c distance.c

main1.o : main1.c sequence.h distance.h
	gcc -Wall -c main1.c
