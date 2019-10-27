#include <stdio.h>
#include <stdlib.h>

struct liste {
	int val ; 	// valeur stockée
	struct liste *suiv ; 	// Pointeur vers le suivant
};
typedef struct liste LISTE ;

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
	if(l==NULL) return l ;
	struct liste *temp = l ;
	if(l->val == val) {
		return l->suiv ;
	}
	if(temp->suiv!=NULL) {
		
	}
	return l ;
}

int main() {
	LISTE *l ;
	l = liste_vide() ;
	LISTE* a = malloc(sizeof(LISTE)) ;
	LISTE* b = malloc(sizeof(LISTE)) ;
	LISTE* c = malloc(sizeof(LISTE)) ;
	
	a->val = 23 ; a->suiv = b ;
	b->val = 42 ; b->suiv = c ;
	c->val = 17 ;
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
	printf("Suppression de la première occurence d'une valeur donnée (iteratif) :\n") ;
	val = 37 ;
	a = supprimer_mil_iter(a,val) ;
	affiche_rec(a) ;
		//Recursif
	
	exit(0) ;
}
