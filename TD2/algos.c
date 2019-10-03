#include "constantes.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int T[N+15] ;
int moy ;

void lecture() {
	FILE *f = fopen(NOMFIC,"r") ;
	if(f==NULL) {
		printf("erreur/n") ;
		exit(0) ;
	}
	
	int i,a,blarg ; a=-30 ; blarg = 42 ; i=0 ;
	while(blarg != EOF) {
		blarg = fscanf(f,"%d",&a) ;
		T[i] = a ;
		i++ ;
	}
	fclose(f) ;
}

void retranscription() {
	FILE *f =fopen(PATATE,"w") ;
	if(f==NULL) {
		printf("erreur/n") ;
		exit(0) ;
	}
	
	int i ;
	for(i=0; i<N;i++) {
		fprintf(f,"%6d\n",T[i]) ;
	}
	fclose(f) ;
}

int recherche(int x) {
	int cmp=0 ;
	for(int i=0;i<N;i++) {
		cmp++ ;
		if(T[i] == x) {
			printf("nombre de comparaison : %6d\n",cmp) ;
			return 1 ;
		}
	}
	printf("nombre de comparaison : %6d\n", cmp) ;
	return 0 ;
}

int stat_recherche(int x) {
	int cmp = 0 ;
	for(int i=0;i<N;i++) {
		cmp++ ;
		if(T[i] == x) {
			printf("nombre de comparaison : %6d\n",cmp) ;
			moy += cmp ;
			return cmp ;
		}
	}
	printf("nombre de comparaison : %6d\n", cmp) ;
	moy += cmp ;
	return cmp ;
}

int main() {	moy = 0 ;
	lecture() ;
	retranscription() ;
	//int x = 36 ;
	//recherche(x) ;
	
	srand(getpid()) ;
	int a = 0 ;
	for(int i=0;i<N;i++) {
		a = rand() %(MAX*5) ;
		stat_recherche(a) ;
	}
	moy = moy / N ;
	printf("%d\n",moy) ;
	
	
	return 0 ;
}
