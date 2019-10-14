
#include "tabint.h"
#include "stat.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void tri_bulle_tabint(TABINT T) {
	int a = 1 ; int b = 0 ; int pas = 0 ;
	while(a) {
		b = T.N - pas ;
		a = scan_ech_tabint(T,b) ;
		pas++ ;
	}
}

struct stat stat_moy (int N, int A) {
	NBECH = 0 ; // Compteur d'échange de contenu
	NBCOMP = 0 ; // nombre de comparaisons entre cases
	int K = 30 ;
	struct stat stats ;
	for(int i=0;i<A;i++) {
		TABINT T = gen_alea_tabint(N,K) ;
		tri_bulle_tabint(T) ;
		sup_tabint(T) ;
	}
	stats.N = N ;
	stats.nb_moy_comp = (NBCOMP*1.0)/(A*1.0) ;
	stats.nb_moy_ech = (NBECH*1.0)/(A*1.0) ;
	return stats ;
}

/*TABINT gen_croissant_tabint(int N,int K) {
	TABINT T ; int a = 0 ;
	T.T = malloc(N*sizeof(int)) ;
	T.N = N ;
	srand(getpid()) ;
	a = rand() % (K+1) ;
	while(a>(K-T.N)) a = rand() % (K+1) ;
	T.T[0] = a ;
	// Vérification que l'espace a bien pu être alloué
	if(T.T==NULL) exit(0) ;
	for(int i=1;i<T.N;i++) {
		a = rand() % (K+1) ;
		if(a>=T.T[i-1] && a<(K-T.N+i)) T.T[i] = a ;
		else i-- ;
	}
	return T;
}*/

/*void ecrire_dans_test_tri_bulle() {
	int i;
	FILE *F ;
	F = fopen("test_tri_bulle.data","w") ;
	for(i=10;i<1000;i=i*1.2) {
		printf("%d\n",i) ;
		stats = stat_moy(i,10000) ;
		fprintf(F,"... %d ... %2f ... %2f\n",stats.N,stats.nb_moy_comp,stats.nb_moy_ech) ;
	}
	fclose(F) ;
}*/


int main() {
	
	NBECH = 0 ; // Compteur d'échange de contenu
	NBCOMP = 0 ; // nombre de comparaisons entre cases
	int N = 10 ; int K = 30 ;
	TABINT T = gen_alea_tabint(N,K) ;
	aff_tabint(T) ;
	printf("trié\n") ;
	tri_bulle_tabint(T) ;
	aff_tabint(T) ;
	//ecrire_dans_test_tri_bulle() ;
	
	printf("nombre de comparaisons de cases : %lld\n",NBCOMP) ;
	printf("nombre d'echange de contenu : %lld\n",NBECH) ;
	
	
	int i;
	FILE *F ;
	struct stat stats ;
	F = fopen("test_tri_bulle.data","w") ;
	for(i=10;i<1000;i=i*1.2) {
		printf("%d\n",i) ;
		stats = stat_moy(i,1000) ;
		fprintf(F,"   %d           %2f           %2f\n",stats.N,stats.nb_moy_comp,stats.nb_moy_ech) ;
	}
	fclose(F) ;
	
	exit(0);
}
