#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int m=5, n=m, i,j;
	float v;
	printf("[0] Voce quer informar o tamanho da matriz\n[1] deseja que ela seja automatica?\n"); scanf("%d", &i);
	switch(i){
		case 0: printf("Me informe M e N:\n"); scanf("%d %d", &m, &n);
			printf("A matriz e de tamanho %d por %d", m, n);
			break;
		case 1:	printf("A matriz e de tamanho %d por %d", m, n);
			break;
		default: printf("ERRO");
			break;
	}
	i=m; j=n;
	Matriz* mat;
	cria (m,n);
	atribui (mat, i, j, v);
	printf("%d",acessa(mat,i,j));
	
	return 0;
}
