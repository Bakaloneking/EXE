//Exemplo de implementacao de TAD de fila gen�rica
// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

// Fun��o para liberar dados do tipo string
void liberarString(void *data) {
    free(data);
}

// Fun��o de exemplo com fila gen�rica
int main() {
    FILA *fila = criarFila();

    // Exemplo 1: Inteiros
    printf("Inserindo inteiros na fila...\n");
    int a = 10, b = 20, c = 30;
    enqueue(fila, &a, sizeof(int));
    enqueue(fila, &b, sizeof(int));
    enqueue(fila, &c, sizeof(int));

    printf("Elemento no in�cio da fila (peek): %d\n", *(int *)peek(fila));
    printf("Removendo elemento: %d\n", *(int *)dequeue(fila));
    printf("Tamanho da fila: %d\n", tamanhoFila(fila));

    // Exemplo 2: Strings
    printf("\nInserindo strings na fila...\n");
    char *str1 = strdup("Hello");
    char *str2 = strdup("World");
    char *str3 = strdup("C Programming");
    enqueue(fila, str1, strlen(str1) + 1);
    enqueue(fila, str2, strlen(str2) + 1);
    enqueue(fila, str3, strlen(str3) + 1);

    printf("Elemento no in�cio da fila (peek): %s\n", (char *)peek(fila));
    printf("Removendo elemento: %s\n", (char *)dequeue(fila));
    printf("Tamanho da fila: %d\n", tamanhoFila(fila));

    // Libera a mem�ria da fila e os dados
    liberarFila(fila, liberarString);

    return 0;
}
