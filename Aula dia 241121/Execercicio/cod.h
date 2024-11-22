#ifdef COD_H
#define COD_H

#include <stdbool.h>

// Estrutura do n� da fila
typedef struct Node {
    void *data;              // Dado gen�rico armazenado no n�
    struct Node *next;       // Ponteiro para o pr�ximo n�
} NODE;

// Estrutura da fila
typedef struct {
    NODE *head;             // Ponteiro para o in�cio da fila
    NODE *tail;              // Ponteiro para o final da fila
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



#endif


