#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fp;
	fp = fopen("vetor.txt", "rb");
	if(fp==NULL){
		printf("Erro na abertura do arquivo\n");
		system("pause");
		exit(1);
	}
	int totalLido, v[5]={1,2,3,4,5};
	totalLido = fread(v,sizeof(int),5,fp);
	if(totalLido != 5){
		printf("erro na leitura\n");
		system("pause");
		exit(1);
	}
	fclose(fp);
	printf("%d, %d, %d, %d, %d", v[0],v[1],v[2],v[3],v[4]);
	return 0;
}
