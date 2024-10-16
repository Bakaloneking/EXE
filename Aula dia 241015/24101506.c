#include <stdio.h>

void imprime(int m[][2], int tam){
	int i,j;
	for(i=0;i<tam;i++){
		for(j=0;j<2;j++){
		printf("%d\n", m[i][j]);
		}
	}
}
	int main(){
		int mat[3][2]={{1,2},{3,4},{5,6}};
		imprime(mat,3);
		return 0;
	}

