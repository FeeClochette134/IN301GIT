#include "liste.h"


// La liste est vide
struct liste * liste_vide() {
	return NULL ;
}

// Afficher une liste
void affiche_iter(struct liste *l) {
	while(l!=NULL) {
		printf("valeur : %d\n",l->val) ;
		l = l->suiv ;
	}
}

void affiche_rec(struct liste *l) {
	if(l!=NULL) {
		printf("valeur : %d\n",l->val) ;
		l = l->suiv ;
		return affiche_rec(l) ;
	}
}

// Nombre d'éléments d'une liste
int nb_elem_iter(struct liste *l) {
	int x = 0 ;
	while(l!=NULL) {
		l = l->suiv ;
		x++ ;
	}
	return x ;
}

int nb_elem_rec(struct liste *l,int x) {
	if(l!=NULL) {
		l = l->suiv ;
		return nb_elem_rec(l,x+1) ;
	}
	return x ;
}

// Recherche d'un élément dans une liste
int est_present_iter(struct liste *l, int val) {
	while(l!=NULL) {
		if(l->val == val) return 1 ;
		l = l->suiv ;
	}
	return 0 ;
}

int est_present_rec(struct liste *l, int val) {
	if(l!=NULL) {
		if(l->val == val) return 1 ;
		l = l->suiv ;
		return est_present_rec(l,val) ;
	}
	return 0 ;
}

//Ajouter une valeur donnée en début de liste
struct liste *inserer_deb(struct liste *l,int val) {
	struct liste *e ;
	e = malloc(sizeof(LISTE)) ;
	e->val = val ;
	e->suiv = l ;
	return e ;
}

void inserer_deb2(struct liste **l,int val) {
	struct liste *e ;
	e = malloc(sizeof(LISTE)) ;
	e->val = val ;
	e->suiv = *l ;
	*l = e ;
}

// Supprimer l'élément au début de la liste
struct liste *supprimer_deb(struct liste *l) {
	if(l==NULL) {
		printf("la liste est deja vide imbecile\n") ;
		return l ;
	}
	struct liste *e ; 
	e = malloc(sizeof(LISTE)) ;
	e->suiv = l ;
	l = l->suiv ;
	free(e) ;
	return l ;
}

void supprimer_deb2(struct liste **l) {
	if(*l==NULL) printf("la liste est deja vide imbecile\n") ;
	else {
		struct liste *e ; 
		e = malloc(sizeof(LISTE)) ;
		e->suiv = *l ;
		*l = (*l)->suiv ;
		free(e) ;
	}
}

// insérer un élément à la fin de la liste
struct liste *inserer_fin_iter(struct liste *l,int val) {
	struct liste *e ;
	struct liste *temp = l ;
	e = malloc(sizeof(LISTE)) ;
	e->val = val; e->suiv = NULL ;
	if(l==NULL) { 
		l = e ;
		return l ;
	}
	while (temp->suiv!=NULL) {
		temp = temp->suiv ;
	}
	temp->suiv = e ;
	return l ;
}

struct liste *inserer_fin_rec(struct liste *l,int val) {
	struct liste *e ;
	if(l==NULL) {
		e = malloc(sizeof(LISTE)) ;
		e->val = val; e->suiv = NULL ;
		return e ;
	}
	
	if(l->suiv==NULL) {
		e = malloc(sizeof(LISTE)) ;
		e->val = val ;
		e->suiv = NULL ;
		l->suiv = e ;
		return l ;
	}
	l->suiv = inserer_fin_rec(l->suiv,val) ;
	return l ;
}

// Supprimer le dernier élément d'une liste
struct liste *supprimer_fin_iter(struct liste *l) {
	if(l==NULL) {
		printf("c'était déjà vide patate\n") ;
		return l ;
	}
	if(l->suiv==NULL) {
		printf("Y avait qu'un élément idiot\n") ;
		l = liste_vide() ;
		return l ;
	}
	struct liste *e ;
	struct liste *temp = l ;
	e = malloc(sizeof(LISTE)) ;
	while (temp->suiv->suiv!=NULL) {
		temp= temp->suiv ;
	}
	e = temp->suiv ;
	temp->suiv = NULL ;
	free(e) ;
	return l ;
}

struct liste *supprimer_fin_rec(struct liste *l) {
	if(l==NULL) {
		printf("c'était déjà vide patate\n") ;
		return l ;
	}
	if(l->suiv==NULL) {
		printf("Y avait qu'un élément idiot\n") ;
		l = liste_vide() ;
		return l ;
	}
	
	if(l->suiv->suiv==NULL) {
		struct liste *e ;
		e = malloc(sizeof(LISTE)) ;
		e = l->suiv ;
		l->suiv = NULL ;
		free(e) ;
		return l ;
	}
	
	l->suiv->suiv = supprimer_fin_rec(l->suiv->suiv) ;
	return l ;
}

// Suppression de la première occurence d'une valeur donnée
struct liste *supprimer_mil_iter(struct liste *l,int val) {
	if(l==NULL) return l ;
	if(l->val==val) {
		l = l->suiv ;
		return l ;
	}
	struct liste *temp = l ;
	while(temp->suiv!=NULL) {
		if(temp->suiv->val==val) {
			struct liste *e ;
			e = malloc(sizeof(LISTE)) ;
			e = temp->suiv ;
			temp->suiv = temp->suiv->suiv ;
			e->suiv = NULL ;
			free(e) ;
			return l ; 
		}
		else temp = temp->suiv ;
	}
	return l ;
}

struct liste *supprimer_mil_rec(struct liste *l,int val) {
	if(l==NULL) {
		printf("cette liste est vide idiot\n") ;
		return l ;
	}
	struct liste *temp = l ;
	if(l->val == val) return l->suiv ;
	if(l->suiv==NULL) return l ;
	if(temp->suiv!=NULL) {
		if(temp->suiv->val==val) {
			struct liste *e = temp ;
			e = temp->suiv ;
			temp->suiv = temp->suiv->suiv ;
			e->suiv = NULL ;
			free(e) ;
		}
		supprimer_mil_rec(temp->suiv,val) ;
	}
	return l ;
}

// Insertion d'un élément dans une liste triée
struct liste *inserer_trie_iter(struct liste *l,int val) {
	if(l==NULL) {
		struct liste *a ;
		a = malloc(sizeof(LISTE)) ;
		a->val = val ;
		a->suiv = NULL ;
		return a ;
	}
	if(l->val>val) {	//Insérer début
		struct liste *a ;
		a = malloc(sizeof(LISTE)) ;
		a->val = val ; 
		a->suiv = l ;
		return a ;
	}
	struct liste *temp ;
	while(temp->suiv!=NULL) {
		if(temp->suiv->val>val) { // Insertion de l'élément
			struct liste *a ;
			a = malloc(sizeof(LISTE)) ;
			a->val = val ;
			a->suiv = temp->suiv->suiv ;
			temp->suiv = a ;
			return l ;
		}
		temp = temp->suiv ;
	}
	// insertion à la fin si le plus grand
	struct liste *a ;
	a = malloc(sizeof(LISTE)) ;
	a->val = val ; 
	a->suiv = NULL ;
	temp->suiv = a ;
	return l ;
}

struct liste *inserer_trie_rec(struct liste *l,int val) {
	return l ;
}





















