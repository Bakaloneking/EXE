#include <stdio.h>

struct Ponto{
	int x;
	
	int y;
}pontos;

int main(){
	int p;
	printf("Me informe o valor de P: "); scanf("%d", &p); getchar();
	if(p>pontos.x&&p<pontos.y){
		printf("Ponto dentro do retangulo");
	}
	
}
