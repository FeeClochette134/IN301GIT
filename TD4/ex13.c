#include <stdio.h>
#include <stdlib.h>

void plusum(int a, int *F) {
	printf("void1 a : %p\n",&a) ;
	printf("void1 T[0] : %p\n\n",&F[0]) ;
	a = a+1 ;
	F[0] = F[0] + 1 ;
	printf("void2 a : %p\n",&a) ;
	printf("void2 T[0] : %p\n\n",&F[0]) ;
}

int main() {
	
	int a ; int T[10] ;
	a = 7 ; T[0] = 12 ;
	printf("main a : %p\n",&a) ;
	printf("main T[0] : %p\n\n",&T[0]) ;
	plusum(a,T) ;
	printf("main2 a : %p\n",&a) ;
	printf("main2 T[0] : %p\n",&T[0]) ;
}
