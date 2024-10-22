#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fp = fopen("arquivo.txt","w");
	if(fp==NULL){
		printf("Erro na abertura do arquivo\n");
		system("pause");
		exit(1);
	}
	return 0;
}
