#include <stdio.h>
#include <stdlib.h>

struct ELEMENT {
	int id ;
	int prio ;
	struct ELEMENT* suiv ;
	struct ELEMENT* prec ;
} ;
typedef struct ELEMENT element ;
