#include <stdio.h>
#include <string.h>

struct Aluno{
	int mat;
	char nome[50];
	float nota[3];
}alunos[5];

void inserir(int n);
void calcular(int n);

int main(){
	int i;
	printf("Me informe quantos alunos ira registrar: "); scanf("%d", &i);
	inserir(i);
	calcular(i);
	return 0;
}

void inserir(int n){
	int i,j;
	for(i=0;i<n;i++){
		printf("Me informe a matricula do %d aluno: ", i+1); scanf("%d", &alunos[i].mat); getchar();
		printf("Me informe o nome do aluno de matricula %d: ", alunos[i].mat); fgets(alunos[i].nome,50,stdin); fflush(stdin);
		alunos[i].nome[strcspn(alunos[i].nome,"\n")]=0;
		for(j=0;j<3;j++){
			printf("Me informe a %d nota do aluno: \n", j+1); scanf("%f", &alunos[i].nota[j]); getchar();
		}
	}
}

void calcular(int n){
	system("cls");
	int i,j=0,k;
	for(i=0;i<n;i++){
		j=alunos[i].nota[0];
		if(j<alunos[i+1].nota[0]){
			j=alunos[i+1].nota[0];
			k=i+1;
		}
	}
	printf("O aluno com a maior nota na Primeira prova foi: %s", alunos[k].nome);
	int maior=0, menor=100;
	char *ma, *me;
	k=0;
	for(i=0;i<n;i++){
		for(j=0;j<3;j++){
			k=k+alunos[i].nota[j];
		}
		k=k/3;
		if(maior<k){
			maior=k;
			strcpy(ma,alunos[i].nome);
		} else {
			if(menor>k){
				menor=k;
				strcpy(me,alunos[i].nome);
			}
		}
	}
	printf("O aluno com a maior media foi %s", ma);
	printf("O aluno com a menor media foi %s", me);
}
