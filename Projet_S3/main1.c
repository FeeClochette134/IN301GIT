#include <stdlib.h>
#include <stdio.h>
#include "sequence.h"
#include "distance.h"

int main(int argc,char **argv) {
	SEQUENCE *S = creer_seq() ;
	S = inserer_deb(S,'A') ;
	S = inserer_deb(S,'G') ;
	S = inserer_deb(S,'C') ;
	affiche_seq(S) ;
	
	
	
	exit(0) ;
}
