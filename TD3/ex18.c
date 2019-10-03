#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int iteratif(char *s) {
	int j = 0 ;
	while(s[j]!='\0') {
		j++ ;
	}
	return j ;
}

int recursif(char*s) {
	if(*s=='\0') return 0 ;
	else return 1+recursif(s+1) ;
}

int iterative(char*s, char*p) {
	int i = 0 ; int diff =0 ;
	while(s[i]==p[i]) {
		if(s[i]=='\0') return 0 ;
		i++ ;
	} 
	diff = s[i] - p[i] ;
	return diff ;
}

int recursive(char*s, char*p, int diff) { // il faut initialiser diff dans le main
	if(*s!=*p) { diff = *s - *p ; return diff ; }
	if(*s=='\0') { diff = *s - *p ; return diff ; }
	return recursive(s+1,p+1,diff) ;
}

int iteration(char*s, char*p, int a) {
	int i = 0 ; int diff = 0 ;
	while(s[i]==p[a-i]) {
		if(s[i]=='\0' && a-i<0) return 0 ;
		i++ ;
	} 
	diff = s[i] - p[a-i] ;
	return diff ;
}

int nombre_caractere(char*p) {
	int i=0 ;
	while(p[i]!='\0') {
		i++ ;
	}
	return i-1 ;
}

int recursion(char*s,char*p) {
	int miroir = 0 ; 
	if(*s!=*p) { miroir = *s-*p ; return miroir ; }
	if(*s=='\0') return miroir ;
	return recursion(s+1,p-1) ;
}

int main(int argc, char** argv) {
	/*//strlen
	int somme1 = iteratif(argv[1]) ;
	int somme2 = iteratif(argv[2]) ;
	int somme3 = recursif(argv[1]) ;
	int somme4 = recursif(argv[2]) ;
	
	printf("La premiere chaine a %d caracteres\n",somme1) ;
	printf("La seconde  chaine a %d caracteres\n\n",somme2) ;
	
	printf("La premiere chaine a %d caracteres\n",somme3) ;
	printf("La seconde  chaine a %d caracteres\n\n",somme4) ; */
	
	/*//strcmp
	int diff1 = iterative(argv[1],argv[2]) ;
	if(diff1==0) printf("Il n'y a pas de difference felicitation\n") ;
	if(diff1!=0) printf("Tu vas te faire assassiner par des patates\n") ;
	
	int diff = 0 ;
	int diff2 = recursive(argv[1],argv[2],diff) ;
	if(diff2==0) printf("Il n'y a pas de difference felicitation\n") ;
	if(diff2!=0) printf("Tu vas te faire assassiner par des patates\n") ; */
	
	// Miroir
	int a = nombre_caractere(argv[2]) ;
	int miroir1 = iteration(argv[1],argv[2],a) ;
	if(miroir1==0) printf("C'est en miroir felicitation\n") ;
	if(miroir1!=0) printf("Qui etes vous ? Que faites vous dans ma maison ? AU VOLEUR !!!\n") ;
	
	//*argv[2] += a ;	// Ca ne va pas du tout cette merde
	printf("%d\n",*argv[2]) ;
	int miroir2 = recursion(argv[1],argv[2]) ;
	if(miroir2==0) printf("C'est en miroir felicitation\n") ;
	if(miroir2!=0) printf("Qui etes vous ? Que faites vous dans ma maison ? AU VOLEUR !!!\n") ;
	
	exit(0) ;
	
}
