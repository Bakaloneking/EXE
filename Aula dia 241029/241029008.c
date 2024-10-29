#include <stdio.h>
#include <stdlib.h>

int main(){
	char nome[50]="Carlos";
	int i=27;
	float a=1.72;
	FILE *fp = fopen("cad.txt", "w");
	if(fp==NULL){
		printf("Erro na abertura do arquivo\n");
		system("pause");
		exit(1);
	}
	printf("Nome: %s\nIdade: %d\nAltura: %f\n", nome,i,a);
	fprintf(fp,"Nome: %s\nIdade: %d\nAltura: %f\n", nome,i,a);
	fclose(fp); 
	return 0;
}
