#include <stdio.h>
#include <stdlib.h>

struct cadastro{
	char nome[20], rua[20];
	int idade;
};

int main(){
	FILE *fp = fopen("arquivo.txt","wb");
	if(fp==NULL){
		printf("Erro na abertura do arquivo\n");
		system("pause");
		exit(1);
	}
	struct cadastro cad[4]={
		"Carlos", "Rua G",27,
		"Pit","Rua 27", 26,
		"Alessandro", "Rua 8", 32,
		"Mirian", "Rua 29", 52};
	fwrite(cad,sizeof(struct cadastro),4,fp);
	fclose(fp);
	return 0;
}
