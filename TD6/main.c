#include "liste.h"

int main() {
	LISTE *l ;
	l = liste_vide() ;
	LISTE* a = malloc(sizeof(LISTE)) ;
	LISTE* b = malloc(sizeof(LISTE)) ;
	LISTE* c = malloc(sizeof(LISTE)) ;
	
	a->val = 17 ; a->suiv = b ;
	b->val = 23 ; b->suiv = c ;
	c->val = 42 ;
	affiche_rec(a) ;
	
	// Nb elements dans la liste
	int x = nb_elem_iter(a) ;
	printf("nb_elem_inter : %d\n",x) ;
	x = nb_elem_rec(a,0) ;
	printf("nb_elem_rec : %d\n",x) ;
	
	// Recherche d'un élément
	int val = 17 ;
	int y = est_present_rec(a,val) ;
	if(y) printf("La valeur %d est présente dans la liste\n",val) ;
	else printf("La valeur %d n'est pas présente dans la liste\n",val) ;
	
	// Ajouter une valeur en début de liste
	/*val = 54 ;
	a = inserer_deb(a,val) ;
	affiche_rec(a) ; */
		// Sans return
	printf("ajout d'une valeur au début : \n") ;
	val = 54 ;
	inserer_deb2(&a,val) ;
	affiche_rec(a) ;
	
	//Supprimer le premier élément d'une liste
	/*printf("Suppression du premier élément d'une liste: \n") ;
	a = supprimer_deb(a) ;
	affiche_iter(a) ;
	l = supprimer_deb(l) ;
	affiche_iter(l) ;*/
		//Sans return
	printf("Suppression du premier élément d'une liste: \n") ;
	supprimer_deb2(&a) ;
	affiche_iter(a) ;
	supprimer_deb2(&l) ;
	affiche_iter(l) ;
	
	// Insérer à la fin un élément
		//Iteratif
	printf("Inserere un élément à la fin d'une liste : \n") ;
	val = 65 ;
	a = inserer_fin_iter(a,val) ;
	affiche_rec(a) ;
	printf("(était vide)\n") ;
	//l = inserer_fin_iter(l,val) ;
	//affiche_iter(l) ;
		//Recursif
	val = 12 ;
	printf("Inserere un élément à la fin d'une liste (recursif) : \n") ;
	a = inserer_fin_rec(a,val) ;
	affiche_rec(a) ;
	printf("(était vide)\n") ;
	l = inserer_fin_rec(l,val) ;
	affiche_iter(l) ;
	
	//Supprimer le dernier élément d'une liste
		//iteratif
	printf("Supprimer le dernier élément (itératif)\n") ;
	a = supprimer_fin_iter(a) ;
	affiche_rec(a) ;
	l = supprimer_fin_iter(l) ;
	affiche_iter(l) ;
		//récursif
	printf("Supprimer le dernier élément (récursif)\n") ;
	a = supprimer_fin_rec(a) ;
	affiche_rec(a) ;
	l = supprimer_fin_rec(l) ;
	affiche_iter(l) ;
	
	//Supprimer la première occurence d'une valeur donnée
		// Iteratif
	val = 37 ;
	printf("Suppression de la première occurence d'une valeur donnée (iteratif) : %d\n",val) ;
	a = supprimer_mil_iter(a,val) ;
	affiche_rec(a) ;
		//Recursif
	val = 37 ;
	printf("Suppression de la première occurence d'une valeur donnée (récursif) : %d\n",val) ;
	a = supprimer_mil_rec(a,val) ;
	affiche_rec(a) ;
	l = supprimer_mil_rec(l,val) ;
	affiche_rec(l) ;
	
	//Insérer une valeur donnée ans une liste triée
	val = 37 ;
	printf("Insérer une valeur donnée dans une liste triée : %d\n",val) ;
	a = inserer_trie_iter(a,val) ;
	affiche_rec(a) ;
	
	exit(0) ;
}
