#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a=10, b=5;
	printf("Soma = %d\n", soma(a,b));
	printf("Subtacao = %d\n", subtracao(a,b));
	printf("Multiplicacao = %d\n", multiplicacao(a,b));
	printf("Divisao = %.2f\n", divisao(b,a));
	return 0;
}
