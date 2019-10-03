#include "constantes.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void ecrire() {
	srand(getpid()) ;
	FILE *f = fopen(NOMFIC,"w") ;
	if(f==NULL) {
		printf("erreur/n") ;
		exit(0) ;
	}
	
	int i,a ;
	for(i=0;i<N;i++) {
		a = rand() %MAX ;
		fprintf(f,"%6d\n",a) ;
	}
	fclose(f) ;
}

int main() {
	ecrire() ;
	return 0 ;
}
