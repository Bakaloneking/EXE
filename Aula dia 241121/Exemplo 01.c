//Exemplo de implementacao de TAD de fila gen�rica

// fila.h
#ifndef FILA_H
#define FILA_H

#include <stdbool.h>

// Estrutura do n� da fila
typedef struct Node {
    void *data;              // Dado gen�rico armazenado no n�
    struct Node *next;       // Ponteiro para o pr�ximo n�
} NODE;

// Estrutura da fila
typedef struct {
    NODE *front;             // Ponteiro para o in�cio da fila
    NODE *rear;              // Ponteiro para o final da fila
    int size;                // Tamanho atual da fila
} FILA;

// Fun��es para manipula��o da fila gen�rica
FILA *criarFila();                             // Cria uma fila vazia
void enqueue(FILA *fila, void *data, size_t dataSize);  // Insere um elemento na fila
void *dequeue(FILA *fila);                     // Remove e retorna o elemento no in�cio da fila
void *peek(FILA *fila);                        // Retorna o elemento no in�cio da fila sem remov�-lo
bool isEmpty(FILA *fila);                      // Verifica se a fila est� vazia
int tamanhoFila(FILA *fila);                   // Retorna o tamanho da fila
void liberarFila(FILA *fila, void (*freeData)(void *)); // Libera a mem�ria da fila

#endif // FILA_H

// fila.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

// Cria uma nova fila vazia
FILA *criarFila() {
    FILA *fila = malloc(sizeof(FILA));
    if (fila != NULL) {
        fila->front = NULL;
        fila->rear = NULL;
        fila->size = 0;
    }
    return fila;
}

// Insere um elemento no final da fila
void enqueue(FILA *fila, void *data, size_t dataSize) {
    NODE *novoNode = malloc(sizeof(NODE));
    if (novoNode == NULL) {
        printf("Erro: Mem�ria insuficiente para inserir elemento.\n");
        exit(EXIT_FAILURE);
    }

    novoNode->data = malloc(dataSize);
    if (novoNode->data == NULL) {
        printf("Erro: Mem�ria insuficiente para alocar dados.\n");
        free(novoNode);
        exit(EXIT_FAILURE);
    }
    memcpy(novoNode->data, data, dataSize);
    novoNode->next = NULL;

    if (fila->rear == NULL) {  // Fila est� vazia
        fila->front = novoNode;
        fila->rear = novoNode;
    } else {
        fila->rear->next = novoNode;
        fila->rear = novoNode;
    }
    fila->size++;
}

// Remove e retorna o elemento no in�cio da fila
void *dequeue(FILA *fila) {
    if (isEmpty(fila)) {
        printf("Erro: Tentativa de remo��o em uma fila vazia.\n");
        return NULL;
    }

    NODE *tempNode = fila->front;
    void *data = tempNode->data;

    fila->front = tempNode->next;
    if (fila->front == NULL) {  // Se a fila ficou vazia
        fila->rear = NULL;
    }
    free(tempNode);
    fila->size--;
    return data;
}

// Retorna o elemento no in�cio da fila sem remov�-lo
void *peek(FILA *fila) {
    if (isEmpty(fila)) {
        printf("Erro: Tentativa de acessar o in�cio de uma fila vazia.\n");
        return NULL;
    }
    return fila->front->data;
}

// Verifica se a fila est� vazia
bool isEmpty(FILA *fila) {
    return fila->front == NULL;
}

// Retorna o tamanho atual da fila
int tamanhoFila(FILA *fila) {
    return fila->size;
}

// Libera a mem�ria alocada pela fila
void liberarFila(FILA *fila, void (*freeData)(void *)) {
    while (!isEmpty(fila)) {
        void *data = dequeue(fila);
        if (freeData != NULL) {
            freeData(data);
        }
    }
    free(fila);
}

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
