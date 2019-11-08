#include <stdio.h>
#include <stdlib.h>
#include "file.h"

int main() {
	file *f ;
	f = creer_file() ;
	int x = file_vide(f) ;
	printf("%d\n",x) ;
	enfiler_prio(f,4,4) ;
	enfiler_prio(f,4,6) ;
	enfiler_prio(f,4,5) ;
	enfiler_prio(f,4,2) ;
	enfiler_prio(f,4,3) ;
	enfiler_prio(f,4,3) ;
	
	afficher_file(f) ;
	//defiler(&f) ;
	//afficher_file(f) ;
	
	
	exit(0) ;
}


/*
 * Pour le projet 
 * 		n'utilisez pas uvsqgraphics
 * 		Sinon vous pouveze utiliser les fonctions vues en cours
 * 			Ex : opendir pour lire les fichiers d'un répertoire
*/
