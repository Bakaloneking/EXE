#include <stdio.h>
#include <stdlib.h>

int main(){
	char texto[20], nome[20];
	int i;
	float a;
	FILE *fp=fopen("cad.txt", "r");
	if(fp==NULL){
		printf("Erro na abertura do arquivo\n");
		system("pause");
		exit(1);
	}
	fscanf(fp,"%s %s", texto, nome);
	printf("%s %s\n", texto, nome);
	fscanf(fp,"%s %d", texto, &i);
	printf("%s %d\n", texto, i);
	fscanf(fp,"%s %f", texto, &a);
	printf("%s %f\n", texto, a);
	fclose(fp); 
	return 0;
}
