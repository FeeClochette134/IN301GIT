#include <stdio.h>
#include <stdlib.h>
#include "file.h"

int file_vide(file *f) {
	if(f==NULL) return 1 ;
	if(f->deb == NULL && f->fin == NULL) return 1 ;
	return 0 ;
}

file *creer_file() {
	file *f ;
	f = (file*) malloc(sizeof(file)) ;
	f->deb = NULL ;
	f->fin = NULL ;
	return f ;
}

void afficher_file(file *f) {
	int cmp = 0 ;
	printf("FILE :\n") ;
	element *e_temp = f->deb ;
	if(e_temp==NULL) printf("la file est vide\n") ;
	while(e_temp!=NULL) {
		cmp++ ;
		printf("%d\nid : %d\nprio : %d\n",cmp,e_temp->id,e_temp->prio) ;
		e_temp = e_temp->suiv ;
	}
}

void enfiler(file *f,int id,int prio) {
	element *e = malloc(sizeof(element)) ;
	e->id = id ;
	e->prio = prio ;
	
	if(file_vide(f)) {
		f->deb = e ;
		f->fin = e ;
		e->suiv = NULL ;
		e->suiv = NULL ;
	}
	else {
		// On insère au début
		e->suiv = NULL ;
		e->prec = f->fin ;
		f->fin->suiv = e ;
		f->fin = e ;
	}
}

element *defiler(file **f) {
	if(file_vide(*f)) {
		printf("y avaiit rien dans ta file pourquoi tu la defile ???\n") ;
		exit(2) ;
	}
	/*if((*f)->deb->suiv == NULL) {
		element *e = malloc(sizeof(element)) ;
		e = (*f)->deb ;
		(*f) = NULL ;
		printf("y a rien\n") ;
		return e ;
	}*/
	
	element *e = malloc(sizeof(element)) ;
	e = (*f)->deb ;
	(*f)->deb = (*f)->deb->suiv ;
	(*f)->deb->prec = NULL ;
	return e ;
}

void liberer_file(file **f) {
	if(*f != NULL) {
		element *e = (*f)->deb ;
		while(e!=NULL) {
			element *e_del = e ;
			e = e->suiv ;
			free(e_del) ;
		}
		free(*f) ;
		*f = NULL ;
	}
}

file *enfiler_prio(file *f,int id,int prio) {
	element *e = malloc(sizeof(element)) ;
	e->id = id ;
	e->prio = prio ;
	if(file_vide(f)) {
		f->deb = e ;
		f->fin = e ;
		e->suiv = NULL ;
		e->prec = NULL ;
		return f ;
	}
	else {
		// On doit trouver l'endroit où l'insérer
		element *e_temp = f->deb ;
		if(e->prio > e_temp->prio) {
			// On l'insère au début
			e->suiv = e_temp ;
			e_temp->prec = e ;
			f->deb = e ;
			return f ;
		}
		else {
			while(e->prio < e_temp->prio) {
				if(e_temp->suiv == NULL) {
					// On l'insère à la fin
					e->prec = e_temp ;
					e->suiv = NULL ;
					e_temp->suiv = e ;
					f->fin = e ;
					return f ;
				}
				e_temp = e_temp->suiv ;	
			}
			// On l'insère dans la file au mileu
			e->prec = e_temp->prec ;
			e->suiv = e_temp ;
			e_temp->prec->suiv = e ;
			e_temp->prec = e ;
			return f ;
		}
	}
}












