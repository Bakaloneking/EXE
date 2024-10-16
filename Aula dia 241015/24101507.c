#include <stdio.h>

struct ponto{
	int x,y;
};

void imprime(int n){
	printf("%d\n", n);
}
void imprimeref(int *n){
	*n = *n+1;
	printf("%d\n", *n);
}

int main(){
	/*Por Valor*/
	struct ponto p ={10,20};
	imprime(p.y);
	imprime(p.x);
	/*Por Referencia*/
	imprimeref(&p.y);
	imprimeref(&p.x);
	
}
