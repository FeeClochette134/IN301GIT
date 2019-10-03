#include <stdio.h>
#include <stdlib.h>

void echange(int *a,int *b) {
	int tmp = *a ;
	printf("void1 a : %d\n",*a) ;
	printf("void1 b : %d\n",*b) ;
	*a = *b ;
	*b = tmp ;
	printf("void2 a : %d\n",*a) ;
	printf("void2 b : %d\n",*b) ;
	
}

int main() {
	int a = 8 ;
	int b = 9 ;
	printf("main a : %d\n",a) ;
	printf("main b : %d\n",b) ;
	echange(&a,&b) ;
	
}
