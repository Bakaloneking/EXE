#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

#define N d5;

void busca();
void geren();
void print();

int i=0;

struct Pessoa{
	char nome[50], emai[50], rua[50], bair[50], cida[50], comp[50], est[50], pais[50], obs[100];
	int tel, num, cep, ddd, dia, mes, ano;
};struct Pessoa agen[101];

int main(){
	setlocale(LC_ALL,"portuguese");
	int n;
	printf("Me informe o que deseja fazer:\n1 - Buscar\n2 - Gerenciar\n3 - Imprimir\n4 - Fechar\n"); scanf("%d", &n);
	//do{	
		switch(n){
			case 1: busca();
				break;
			case 2: geren();
				break;
			case 3: print();
				break;
			default: system("exit");
		/*	default: printf("Função invalida!\n Me infome novamente!\n"); scanf("%d", &i);*/
		}
	/*	if(i<0&&i>5){
			printf("Função invalida!\n Me infome novamente!"); scanf("%d", &i);
		}*/
	//}while(i<0&&i>5);
}

void busca(){
	printf("Null");
	/*
	int r;
	char nome[50];
	system ("cls");
	printf("Qual modo de Busca você tem interesse?\n1 - 1º Nome\n2 - Mês de Aniversario"); scanf("%d", &i);
	switch(i){
		case 1:	fflush(stdin);
				printf("Me informe o nome que precisa Buscar: "); fgets(nome, 50, stdin);
				r=strlen(nome);
				char aux[r];
				for(i=0;i<100;i++){
				strncpy(aux,agen[i].nome,r);
				aux[r] = "\0";
				if(strcmp(aux,nome)==0){
				
	*/
}

void geren(){
	printf("Null");
}

void print(){
	printf("Null");
}
