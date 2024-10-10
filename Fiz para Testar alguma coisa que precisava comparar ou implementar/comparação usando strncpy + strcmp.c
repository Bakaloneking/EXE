#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

void main(){
	setlocale(LC_ALL,"portugese");
	long unsigned r=0;
	char nome[50], nomen[50];
	strcpy(nome,"Carlos Henrique");
	printf("Me informe o nome que precisa Buscar:"); gets(nomen);
	printf("comparação usando strncpy + strcmp\n");
	r=strlen(nomen);
	char aux[r];
	fflush(stdin);
	strncpy(aux,nome,r);
	fflush(stdin);
	printf("%d, %s, %s, %s, %lu\n",strcmp(aux,nomen), nome, aux, nomen, r);
	printf("comparação usando apenas strcmp\n");
	printf("%d, %s, %s, %lu",strcmp(nome,nomen), nome, nomen, r);
}
