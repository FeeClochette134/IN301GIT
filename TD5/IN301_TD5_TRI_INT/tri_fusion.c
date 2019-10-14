#include "tabint.h"
#include "stat.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

TABINT tri_fusion(TABINT T,int g,int d) {
	if(g<d) {
		int m = (g+d)/2 ;
		tri_fusion(T,g,m) ;
		tri_fusion(T,m+1,d) ;
		fusionner(T,g,m,d) ;
	}
	return T ;
}

struct stat stat_moy (int N, int A) {
	NBCOMP = 0 ; // nombre de comparaisons entre cases
	int K = 30 ;
	struct stat stats ;
	for(int i=0;i<A;i++) {
		TABINT T = gen_alea_tabint(N,K) ;
		tri_fusion(T,0,N-1) ;
		sup_tabint(T) ;
	}
	stats.N = N ;
	stats.nb_moy_comp = (NBCOMP*1.0)/(A*1.0) ;
	return stats ;
}

int main() {
	/*printf("tableau cree :\n") ;
	aff_tabint(T) ;
	tri_fusion(T,0,N-1) ;
	printf("tableau trie :\n") ;
	aff_tabint(T) ;*/
	
	FILE *F ;
	struct stat stats ;
	F = fopen("test_tri_fusion.data","w") ;
	if(F==NULL) printf("erreur_ouverture_fichier") ;
	for(int i=10;i<1000;i=i*1.2) {
		printf("%d\n",i) ;
		stats = stat_moy(i,1000) ;
		fprintf(F,"   %d           %2f           %2f\n",stats.N,stats.nb_moy_comp,stats.nb_moy_ech) ;
	}
	fclose(F) ;
	
	exit(0) ;
}
