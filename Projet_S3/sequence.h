#include <stdlib.h>
#include <stdio.h>

struct acide_amine {
	char aa ; // Correspond à l'acide aminé à cet position
	struct acide_amine *prec ;	// Pointeur vers l'acide aminé précédent
	struct acide_amine *suiv ;	// Pointeur vers l'acide aminé suivant
	
} ;
typedef struct acide_amine AA ;

struct sequence {
	struct acide_amine *deb ;	// Pointeur sur le début de la séquence d'AA
	struct acide_amine *fin ;	// Pointeur sur la fin de la séquence d'AA
} ;
typedef struct sequence SEQUENCE ;

//////////////////// Manipulation de sequences
SEQUENCE *creer_seq() ;
int sequence_vide(SEQUENCE *S) ;
void affiche_seq(SEQUENCE *S) ;
SEQUENCE *inserer_deb(SEQUENCE *S,char acgt) ;






// Lire un fichier
SEQUENCE *lecture(FILE *F) ;
SEQUENCE *insertion_fin(SEQUENCE *S) ;
