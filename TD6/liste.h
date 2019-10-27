#include <stdio.h>
#include <stdlib.h>

struct liste {
	int val ; 	// valeur stockée
	struct liste *suiv ; 	// Pointeur vers le suivant
};
typedef struct liste LISTE ;

struct liste *liste_vide() ;
// Afficher liste
void affiche_iter(struct liste *l) ;
void affiche_rec(struct liste *l) ;

// Nombre d'élément dans la chaîne
int nb_elem_iter(struct liste *l) ;
int nb_elem_rec(struct liste *l,int x) ;

// L'entier val est-il présent dans la liste ?
int est_present_iter(struct liste *l, int val) ;
int est_present_rec(struct liste *l, int val) ;

// Insérer une valeur donnée au début de la chaine
struct liste *inserer_deb(struct liste *l,int val) ;
void inserer_deb2(struct liste **l,int val) ;

// Supprimer la première valeur de la liste
struct liste *supprimer_deb(struct liste *l) ;
void supprimer_deb2(struct liste **l) ;

// Insérer une valeur à la fin de la liste
struct liste *inserer_fin_iter(struct liste *l,int val) ;
struct liste *inserer_fin_rec(struct liste *l,int val) ;

// Supprimer la dernière valeur de la liste
struct liste *supprimer_fin_iter(struct liste *l) ;
struct liste *supprimer_fin_rec(struct liste *l) ;

// Supprimer la première occurence d'une valeur donnée dans la liste
struct liste *supprimer_mil_iter(struct liste *l,int val) ;
struct liste *supprimer_mil_rec(struct liste *l,int val) ;

// Insertion d'un élément dans une liste triée
struct liste *inserer_trie_iter(struct liste *l,int val) ;
struct liste *inserer_trie_rec(struct liste *l,int val) ;

