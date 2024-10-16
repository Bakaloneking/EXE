#include <stdio.h>

void somaMaisUm(int *n){
	*n = *n +1;
	printf("Dentro da funcao: %d\n", *n);
}

int main(){
	int x =7;
	printf("Antes da Funcao: %d\n", x);
	somaMaisUm(&x);
	printf("Depois da funcao: %d\n", x);
	return 0;
}
