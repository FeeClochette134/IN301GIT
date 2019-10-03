#include <stdio.h>
#include <stdlib.h>

int main() {
	
	float tab[10] ;
	for(int i=0;i<10;i++) {
		tab[i] = i+10 ;
	}
	printf("%p\n",&tab[0]) ;
	int a = sizeof(&tab[0]) ;
	printf("&tab[0] : %d\n\n",a) ;
	
	printf("%p\n",tab) ;
	a = sizeof(tab) ;
	printf("tab : %d\n\n",a) ;
	
	printf("%p\n",*&tab) ;
	a = sizeof(*&tab) ;
	printf("*&tab : %d\n\n",a) ;
	
	printf("%f\n",*&tab[0]) ;
	a = sizeof(*&tab[0]) ;
	printf("*&tab[0] : %d\n\n",a) ;
}
















