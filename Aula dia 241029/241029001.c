#include <stdio.h>
#include <stdlib.h>

int main(){
	char str[20];
	FILE *fp;
	fp = fopen("arquivo.txt","r");
	if(fp==NULL){
		printf("Erro na abertura do arquivo\n");
		system("pause");
		exit(1);
	}
	char *result=fgets(str,12,fp); //lê 11 chars
	if(result==NULL){
		prinnt("Erro na Leitura\n");
	} else {
		printf("%s", str);
	}
	printf("\n");
	fclose(fp);
	return 0;
}
