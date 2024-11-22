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
