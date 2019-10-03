#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int *alloue() {
	int *T = malloc(10*sizeof(int)) ;
	srand(getpid()) ;
	for(int i=0;i<10;i++) {
		*(T+i) = rand() % 20 ;
		printf("%d\n",*(T+i)) ;
	}
	//for(int *p =T; p<T+10; p++)
	return T ;
}

int produit(int *T) {
	int produits = 1 ;
	for(int i=0;i<10;i++) {
		produits = produits * (*(T+i)) ;
	}
	return produits ;
}

int valeur_minimale(int *T) {
	int min = *T ;
	for(int *p=T;p<T+10;p++) {
		if(*p<min) min = *p ;
	}
	return min ;
}

int main() {
	
	int *T = alloue() ;
	int produits = 0 ;
	produits = produit(T) ;
	printf("produit : %d\n",produits) ;
	int min = valeur_minimale(T) ;
	printf("valeur min du tableau : %d\n",min) ;
}
