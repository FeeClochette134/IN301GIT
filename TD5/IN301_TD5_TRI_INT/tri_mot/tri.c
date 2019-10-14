#include "tableau.h"
#include <string.h>

//associe à chaque caractere un indice dans le tableau des frequences
//les caractes possible sont les caracteres alphabetiques en minuscules et le caractere de fin de chaine '\0'
int indice(char c){
	if(c=='\0') return 0 ;
	else return c - 'a' + 1 ;
}


//tri le tableau  selon la composante i
void tri_base_indice(Tableau t, int i){
	int f[27] ; int cumul,temp,j ;
	Tableau t_temp = copy_tab(t) ;
	for(j=0;j<27;j++) {
		f[j] = 0 ;
	}
	for(j=0;j<t.n;j++) {
		f[indice(t.tab[j][i])] ++ ;
	}
	cumul = f[0] ;
	f[0] = 0 ;
	for(j=1;j<27;j++) {
		temp = f[j] ;
		f[j] = cumul ;
		cumul += temp ;
	}
	int ind ;
	for(j=0;j<t.n;j++) {
		ind = indice(t_temp.tab[j][i]) ;
		t.tab[f[ind]] = t_temp.tab[j] ;
		f[ind] ++ ;
	}
}



 
//tri par base 
void tri_base(Tableau t){
  int i ;
  for(i=t.taille-1; i>=0; i--)
    tri_base_indice(t, i);
    affiche_tab(t) ;
}




//tri le tableau entre indices g et d compris
/*int partition(Tableau t,int g, int d) {
	int p = g ;	//pivot 
	for(int i=g+1;i<d;i++) {
		char *tmp = t.tab[p] ;
		if(strcmp(t.tab[i],t.tab[p])<0) {
			t.tab[p] = t.tab[i] ;
			p++ ;
			for(int j=i;j>p;j--) {
				t.tab[j] = t.tab[j-1] ;
			}
			t.tab[p] = tmp ;
		}
	}
	return p ;
}*/

int partition(Tableau t,int g, int d) {
	int cmp = g ;
	char *tmp ;
	for(int i=g+1;i<=d;i++) {
		if(strcmp(t.tab[i],t.tab[g])<0) {
			cmp ++ ;
			tmp = t.tab[i] ;
			t.tab[i] = t.tab[cmp] ;
			t.tab[cmp] = tmp ;
		}
	}
	tmp = t.tab[g] ;
	t.tab[g] = t.tab[cmp] ;
	t.tab[cmp] = tmp ;
	return cmp ;
}

void tri_rapide(Tableau t, int g, int d){
	//strcmp(g,d) = si valeur négative alors plus grand que pivot sinon plus petit ???
	// Si négatif : alors avant dans l'ordre alphabétique
  //a ecrire
	if(g<d) {
		int p = partition(t,g,d) ; // Partitionne le tableau en fonction du pivot
		tri_rapide(t,g,p-1) ;
		tri_rapide(t,p+1,d) ;
	}
}


//tri par comparaison en utilisant la fonction strcmp
void tri_cmp(Tableau t){
	tri_rapide(t, 0, t.n-1);
	//affiche_tab(t) ;
}
