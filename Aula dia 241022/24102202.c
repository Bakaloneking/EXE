#include <stdio.h>
#include <stdlib.h>

int main(){
	int *p;
	//Se o realloc o ponteiro for null ele ira agir como malloc normal
	p = (int *) realloc(NULL,5*sizeof(int));
	//� ingual
	p = (int *) malloc(5*sizeof(int));
	return 0;
}

/*int main(){
	int *p = (int *) malloc(50*sizeof(int));
	//Se no realloc a aloca��o for 0, ele ir� agir como a fun��o free()
	p=(int *) realloc(p,0);
	//� ingual
	free(p);
	return 0;
*/
