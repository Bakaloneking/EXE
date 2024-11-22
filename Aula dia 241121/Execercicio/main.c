//Exemplo de implementacao de TAD de fila genérica
// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cod.h"

// Função para liberar dados do tipo string
void liberarString(void *data) {
    free(data);
}

// Função de exemplo com fila genérica
int main() {
    FILA *fila = criarFila();
	int cx;
	//Caixas
	printf("Quantos caixas serão abertos"); scanf("%d", &cx);
//	printf("Quantos clientes temos para serem")
    // Libera a memória da fila e os dados
    liberarFila(fila, liberarString);

    return 0;
}

