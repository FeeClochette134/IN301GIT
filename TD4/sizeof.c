#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int a = sizeof(char) ;
	printf("char : %d\n",a) ;
	a = sizeof(int) ;
	printf("int : %d\n",a) ;
	a = sizeof(double) ;
	printf("double : %d\n",a) ;
	a = sizeof(char*) ;
	printf("char* : %d\n",a) ;
	a = sizeof(void*) ;
	printf("void* : %d\n",a) ;
	a = sizeof(int*) ;
	printf("int* : %d\n",a) ;
	a = sizeof(double*) ;
	printf("double* : %d\n",a) ;
	a = sizeof(int**) ;
	printf("int** : %d\n",a) ;
	a = sizeof(int[10]) ;
	printf("int[10] : %d\n",a) ;
	a = sizeof(char[7][3]) ;
	printf("char[7][3] : %d\n",a) ;
	//a = sizeof(int[]) ;
	//printf("int[] : %d\n",a) ;
	a = sizeof(float) ;
	printf("float : %d\n",a) ;
	
}
