#include <stdio.h>
#include <string.h>

struct Aluno{
	char nome[50], curso[50];
	int matr;
}alunos[5];
void registro(int n);
void impressao(int n);
int main(){
	int i;
	printf("Quantos alunos serão registrados: "); scanf("%d", &i); getchar();
	registro(i);
	impressao(i);
	return 0;
}

void registro(int n){
	int i;
	system("cls");
	for(i=0;i<n;i++){
	printf("Me informe o nome do %d aluno: ", i+1); fgets(alunos[i].nome, 50, stdin); fflush(stdin);
	alunos[i].nome[strcspn(alunos[i].nome,"\n")]=0;
	printf("Me informe o numero de matricula de %s: ", alunos[i].nome); scanf("%d", &alunos[i].matr); getchar();
	printf("Me informe o Curso do aluno: "); fgets(alunos[i].curso, 50, stdin); fflush(stdin);
	}
	system("pause");
}

void impressao(int n){
	int i;
	system("cls");
	for(i=0;i<n;i++){
		printf("Os dados do %d aluno sao:\n", i+1);
		printf("Nome: %s\nMatricula: %d\nCurso: %s", alunos[i].nome, alunos[i].matr, alunos[i].curso);
	}
	system("pause");
}
