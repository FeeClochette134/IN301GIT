#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int T[7][3] ;
	printf("T : %p\n",T) ;
	printf("T[0][0] : %p\n",&T[0][0]) ;
	printf("T[0][1] : %p\n",&T[0][1]) ;
	printf("T[0][2] : %p\n",&T[0][2]) ;
	printf("T[1][0] : %p\n",&T[1][0]) ;
	printf("T[1][1] : %p\n\n\n\n\n\n",&T[1][1]) ;
	
	printf("T[6][2] : %p\n",&T[6][2]) ;
	
}
