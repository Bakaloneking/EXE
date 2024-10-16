#include <stdio.h>

#define TAM 10

void bubbleSort(int * const array, const int tamanho);

int main(void){
	int a[TAM]={2,6,4,8,10,12,89,68,45,37};
	int i;
	
	printf("itens de dados na ordem original\n");
	for(i=0;i<TAM;i++){
		printf("%4d",a[i]);
	}
	
	bubbleSort(a, TAM);
	
	printf("\nItens de dados em ordem crescente\n");
	for(i=0;i<TAM;i++){
		printf("%4d", a[i]);
	}
	printf("\n");
	
	return 0;
	
}

void bubbleSort(int * const array, const int tamanho){
	void troca(int *elem1Ptr, int *elem2Ptr);
	
	int passadas;
	int j;
	
	for(passadas=0;passadas<tamanho-1;passadas++){
		for(j=0;j<tamanho-1;j++){
			if(array[j]>array[j+1]){
				troca(&array[j], &array[j+1]);
			}
		}
	}
}

void troca(int *elem1Ptr, int *elem2Ptr){
	int aux=*elem1Ptr;
	*elem1Ptr=*elem2Ptr;
	*elem2Ptr=aux;
}
