#include <stdio.h>
#include <stdlib.h>

struct cadastro{
	char nome[20], rua[20];
	int idade;
};

int main(){
	FILE *fp = fopen("arquivo.txt","rb");
	if(fp==NULL){
		printf("Erro na abertura do arquivo\n");
		system("pause");
		exit(1);
	}
	struct cadastro c;
	fseek(fp,2*sizeof(struct cadastro), SEEK_SET);
	fread(&c,sizeof(struct cadastro),1,fp);
	printf("%s\n%s\n%d\n", c.nome,c.rua,c.idade);
	fclose(fp);
	return 0;
}
