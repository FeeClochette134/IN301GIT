#include "constantes.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv){
	if(argc==1) { printf("DONNE MOI UN FICHIER CONNARD !!!\n") ; exit(0) ; }
	char *s ;
	s=argv[1] ; int blarg = -338 ;
	int a = 0 ; int cmp = 0 ;
	FILE *f = fopen(s,"r") ;
	while(blarg !=EOF) {
		blarg = fscanf(f,"%c",&a) ;
		if(blarg!=EOF) cmp ++ ;
	}
	fclose(f) ;
	
	printf("%d\n",cmp) ;
	exit(0) ;
}
