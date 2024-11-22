//Exemplo de implementacao de TAD de fila gen�rica
// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cod.h"

// Fun��o para liberar dados do tipo string
void liberarString(void *data) {
    free(data);
}

// Fun��o de exemplo com fila gen�rica
int main() {
    FILA *fila = criarFila();
	int cx;
	//Caixas
	printf("Quantos caixas ser�o abertos"); scanf("%d", &cx);
//	printf("Quantos clientes temos para serem")
    // Libera a mem�ria da fila e os dados
    liberarFila(fila, liberarString);

    return 0;
}

