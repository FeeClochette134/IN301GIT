#include <stdio.h>
#include <stdlib.h>

struct ELEMENT {
	int id ;
	int prio ;
	struct ELEMENT* suiv ;
	struct ELEMENT* prec ;
} ;
typedef struct ELEMENT element ;

struct File {
	element* deb ;
	element* fin ;
} ;
typedef struct File file ;

int file_vide(file *f) ;
file *creer_file() ;
void afficher_file(file *f) ;
void enfiler(file *f,int id,int prio) ;
element *defiler(file **f) ;
void liberer_file(file **f) ;

//Insérer en prenant compte de la priorité
file *enfiler_prio(file *f,int id,int prio) ;
