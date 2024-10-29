#include <stdio.h>

struct Vetor{
	float x;
	float y;
	float z;
};

int main(){
	struct Vetor vetores;
	printf("Me informe o valor do %d vetor: ", 1); scanf("%f", &vetores.x); getchar();
	printf("Me informe o valor do %d vetor: ", 2); scanf("%f", &vetores.y); getchar();
	vetores.z=vetores.x+vetores.y;
	printf("O valor da soma dos vetores é: %.2f", vetores.z);
}
