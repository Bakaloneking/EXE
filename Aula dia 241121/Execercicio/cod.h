#ifdef COD_H
#define COD_H

#include <stdbool.h>

// Estrutura do nó da fila
typedef struct Node {
    void *data;              // Dado genérico armazenado no nó
    struct Node *next;       // Ponteiro para o próximo nó
} NODE;

// Estrutura da fila
typedef struct {
    NODE *head;             // Ponteiro para o início da fila
    NODE *tail;              // Ponteiro para o final da fila
    int size;                // Tamanho atual da fila
} FILA;

// Funções para manipulação da fila genérica
FILA *criarFila();                             // Cria uma fila vazia
void enqueue(FILA *fila, void *data, size_t dataSize);  // Insere um elemento na fila
void *dequeue(FILA *fila);                     // Remove e retorna o elemento no início da fila
void *peek(FILA *fila);                        // Retorna o elemento no início da fila sem removê-lo
bool isEmpty(FILA *fila);                      // Verifica se a fila está vazia
int tamanhoFila(FILA *fila);                   // Retorna o tamanho da fila
void liberarFila(FILA *fila, void (*freeData)(void *)); // Libera a memória da fila



#endif


