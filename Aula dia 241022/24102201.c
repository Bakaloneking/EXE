#include <stdio.h>
#include <stdlib.h>

int main(){
	int i;
	int *pm, *pc;
	pm = (int *) malloc(5 * sizeof(int));
	pc = (int *) calloc(5,sizeof(int));
	printf("Malloc \t\t Calloc\n");
	for(i=0;i<5;i++){
		printf("pm[%d]: %d \t", i, pm[i]);
		printf("pc[%d]: %d\n", i, pc[i]);
	}
	free(pm);
	free(pc);
	return 0;
}

