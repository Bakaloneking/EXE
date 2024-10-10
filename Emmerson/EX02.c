#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

const int N=5;

void ord();

struct Pessoa{
	char nome[50], rua[50], bair[50], cida[50], comp[50], uf[3];
	int tel[3], num, cep;
};struct Pessoa pess[6];

int main(){
	setlocale(LC_ALL,"portuguese");
	int i;
	for(i=0;i<N;i++){
		fflush(stdin);
		printf("Me informe o %d nome:", i+1); fgets(pess[i].nome, 50, stdin);
		printf("Me informe o Endereço rua:"); fgets(pess[i].rua, 50, stdin);
		printf("Me informe o Número da casa:"); scanf("%d", &pess[i].num);
		fflush(stdin);
		printf("Me informe o Bairro:" ); fgets(pess[i].bair, 50, stdin);
		printf("Me informe o Complemento:"); fgets(pess[i].comp, 50, stdin);
		printf("Me informe o CEP:"); scanf("%d", &pess[i].cep);
		fflush(stdin);
		printf("Me informe a Cidade:"); fgets(pess[i].cida, 50, stdin);
		printf("Me informe o UF:"); fgets(pess[i].uf, 3, stdin);
		fflush(stdin);
		printf("Me informe o 1º Telefone:"); scanf("%d", &pess[i].tel[1]);
		printf("Me informe o 2º Telefone:"); scanf("%d", &pess[i].tel[2]);
		printf("Me informe o 3º Telefone:"); scanf("%d", &pess[i].tel[3]);
	}
	system("cls");
	ord();
		
}
 void ord(){
 	int i=0, j=0;
 	for(i;i<N;i++){
 		for(j=i+1;j<N;j++){
 			if(strcmp(pess[i].nome,pess[j].nome)>0){
 				pess[6]=pess[i];
 				pess[i]=pess[j];
 				pess[j]=pess[6];
			 }	
		 }
	 }
	for(i=0;i<N;i++){
		printf("***PESSOA %d***\n%s\n%s\n%d\n%s\n%s\n%d\n%s\n%s\n%d\n%d\n%d\n",i+1,pess[i].nome,pess[i].rua,pess[i].num,pess[i].bair,pess[i].comp,pess[i].cep,pess[i].cida,pess[i].uf,pess[i].tel[1],pess[i].tel[2],pess[i].tel[3]);
	} 
 }
