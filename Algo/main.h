#include <stdio.h>
#include <stdlib.h>

struct File {
	int val ; // la valeur stockée
	struct File *prec ; // pointe ce su'il y a avant
	struct File *suiv ; // pointe ce qu'il y a après
} ;
typedef struct File file ;

file *creer_file() {
	file *f ;
	f = malloc(sizeof(file)) ;
	f = NULL ;
	return f ;
}

int file_vide(file *f) {
	if(f==NULL) return 1 ;
	else return 0 ;
}

file *enfiler(file *f,int x) {
	
	
}

int *defiler(file **f) {
	file *e,*a ;
	e = malloc(sizeof(file)) ;
	a = malloc(sizeof(file)) ;
	e = a = *f ;
	e = e->suiv ;
	*f = e ;
	a->suiv = NULL ;
	int x = a->val ;
	free(a) ;
	return x ;
}


