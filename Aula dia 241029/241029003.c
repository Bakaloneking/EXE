#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fp;
	fp = fopen("dados.txt", "wb");
	if(fp==NULL){
		printf("Erro na abertura do arquivo\n");
		system("pause");
		exit(1);
	}
	char str[20];
	float x=5;
	int v[5]={1,2,3,4,5};
	//Lembrese: vetores não precisam de &
	fwrite(str,sizeof(char),20,fp);
	fwrite(&x,sizeof(float),1,fp);
	fwrite(v,sizeof(int),5,fp);
	fclose(fp);
	return 0;
}
