#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	int i =0 ;
	int a ;
	
	srand(getpid()) ;
	for(i=0;i<100;i++) {
		a = rand() % 1000 ;
		printf("%d\n",a) ;
	}

}
