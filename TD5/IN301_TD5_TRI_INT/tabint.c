#include "tabint.h"
#include "stat.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


// #####
// 1. Génération, suppression et affichage de tableaux
// #####
TABINT gen_alea_tabint (int N, int K) {
	TABINT T ; 
	T.T = malloc(N*sizeof(int)) ;
	T.N = N ;
	srand(getpid()) ;
	// Vérification que l'espace a bien pu être alloué
	if(T.T==NULL) exit(0) ;
	for(int i=0;i<N;i++) {
		T.T[i] = rand() % (K+1) ;
	}
	return T;
}

TABINT sup_tabint (TABINT T) {
	free(T.T) ;
	return T;
}

void aff_tabint (TABINT T) {
	for(int i=0;i<T.N;i++) {
		printf("case %d : %d\n",i,T.T[i]) ;
	}
}

// #####
// 2. Manipulation des valeurs du tableau
// #####

// Echange la case i et la case i+1 si la case i est > à la case i+1
int ech_tabint (TABINT T, int i) {
	NBCOMP++ ;
	if(T.T[i]>T.T[i+1]) {
		int tmp = T.T[i] ;
		T.T[i] = T.T[i+1] ;
		T.T[i+1] = tmp ;
		NBECH++ ;
		return 1 ;
	}
	return 0 ;
}

//
int scan_ech_tabint (TABINT T, int fin)  {
	int a = 0 ;
	for(int i=0;i<fin;i++) {
		a = a + ech_tabint(T,i) ;
	}
	return a ;
}

void fusionner(TABINT T,int deb,int mil,int fin) {
	int cmp1 = deb ; int cmp2 = mil+1 ; int i = 0 ;
	int* tab_temp = malloc((mil-deb+1)*sizeof(int)) ;
	
	// On recopie les éléments du début du tableau
	for(i=deb;i<=mil;i++) {
		tab_temp[i-deb] = T.T[i] ;
	}
	i = deb ;
	
	while(i<=fin && cmp1 != mil+1) {
		if(cmp2==(fin+1)) {
			// le tableau 2 est fini : on recopie le 1 à la suite
			T.T[i] = tab_temp[cmp1-deb] ;
			cmp1++ ;
		}
		
		else if(tab_temp[cmp1-deb]<T.T[cmp2]) {
			NBCOMP++ ;
			//on ajoute un élément du premier tableau
			T.T[i] = tab_temp[cmp1-deb] ;
			cmp1++ ;
		}
		else {
			T.T[i] = T.T[cmp2] ;
			cmp2++ ;
		}
		i++ ;
	}
	free(tab_temp) ;
}

/*void tri_bulle_tabint(TABINT T) {
	int a = 1 ; int b = 0 ; int pas = 0 ;
	while(a) {
		b = T.N - pas ;
		a = scan_ech_tabint(T,b) ;
		pas++ ;
	}
} */

/*TABINT gen_croissant_tabint() {
	TABINT T ; int a = 0 ;
	T.T = malloc(N*sizeof(int)) ;
	T.N = N ;
	srand(getpid()) ;
	// Vérification que l'espace a bien pu être alloué
	if(T.T==NULL) exit(0) ;
	for(int i=0;i<N;i++) {
		a = rand() % (K+1) ;
	}
	return T;
}*/


/*int main() {
	NBECH = 0 ; // Compteur d'échange de contenu
	NBCOMP = 0 ; // nombre de comparaisons entre cases
	int N = 10 ; int K = 30 ;
	TABINT T = gen_alea_tabint(N,K) ;
	aff_tabint(T) ;
	printf("trié\n") ;
	tri_bulle_tabint(T) ;
	aff_tabint(T) ;
	
	printf("nombre de comparaisons de cases : %lld\n",NBCOMP) ;
	printf("nombre d'echange de contenu : %lld\n",NBECH) ;
}*/









