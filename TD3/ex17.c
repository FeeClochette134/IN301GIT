#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int test_arg(char *mot) {
	int i = 0 ;
	//if(isdigit(mot[0]) == 0) return 5 ;
	while(isdigit(mot[i])!=0) {
		i++ ;
	}
	if(mot[i] != '.') return 2 ;
	i++ ;
	if(mot[i]=='\0') return 4 ;

	/*while(isdigit(mot[i])!=0) {
		if(mot[i]=='\0') return 1 ;
		i++ ;
	}*/

	while(mot[i]!= '\0') {
		if(isdigit(mot[i])==0) return 3 ;
		i ++ ;
	}
	return 1 ;
	
}

int main(int argc, char** argv) {
	int i ; float somme = 0 ; int test ;
	printf("argc = %d\n", argc) ;
	for(i=1;i<argc; i++) {
		test = test_arg(argv[i]) ;
		if(test==2 || test==3 || test==4 || test==5) break ;
		
		printf("%s\n", argv[i]) ;
		somme += atof(argv[i]) ;
	}
	printf("la somme est de : %3.3f\n", somme) ;
	printf("%d\n",test) ;
	return 0 ;
}
