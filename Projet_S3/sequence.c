#include <stdlib.h>
#include <stdio.h>
#include "sequence.h"

SEQUENCE *creer_seq() {
	SEQUENCE *S ;
	S = malloc(sizeof(SEQUENCE)) ;
	S->deb = NULL ;
	S->fin = NULL ;
	return S ;
}

int sequence_vide(SEQUENCE *S) {
	if(S==NULL) return 1 ;
	if(S->deb == NULL && S->fin == NULL) return 1 ;
	return 0 ;
}

void affiche_seq(SEQUENCE *S) {
	if (sequence_vide(S))	{
		printf("La sequence est vide\n");
	}
	else	{
		AA *a = S->deb;
		while (a->suiv != NULL)	{
			printf("%c",a->aa);
			a = a->suiv;
		}
		printf("%c\n",a->aa);
	}
}


SEQUENCE *inserer_deb(SEQUENCE *S,char acgt) {
	AA *acide = malloc(sizeof(AA)) ;
	// Si la séquence était vide
	if(sequence_vide(S)) {
		acide->aa = acgt ;
		acide->prec = NULL ;
		acide->suiv = NULL ;
		S->deb = acide ;
		S->fin = acide ;
		return S ;
	}
	// Si la séquence n'était pas vide
	acide->aa = acgt ;
	acide->prec = NULL ;
	acide->suiv = S->deb ;
	S->deb->prec = acide ;
	S->deb = acide ;
	return S ;
}



/*

SEQUENCE *lecture(FILE *F) {
	if(F==NULL) {
		printf("erreur ouverture fichier\n") ;
		exit(2) ;
	}
	char i = fgetc(F) ; // Le caractère qui est lu
	SEQUENCE *S = creer_seq() ;
	
	
	while(i!=EOF) {
		
	}
}

*/
