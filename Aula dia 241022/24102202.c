#include <stdio.h>
#include <stdlib.h>

int main(){
	int *p;
	//Se o realloc o ponteiro for null ele ira agir como malloc normal
	p = (int *) realloc(NULL,5*sizeof(int));
	//é ingual
	p = (int *) malloc(5*sizeof(int));
	return 0;
}

/*int main(){
	int *p = (int *) malloc(50*sizeof(int));
	//Se no realloc a alocação for 0, ele irá agir como a função free()
	p=(int *) realloc(p,0);
	//é ingual
	free(p);
	return 0;
*/
