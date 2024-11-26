//Lista circular simplesmente encadeada

#include <stdio.h>
#include <stdlib.h>

// Estrutura do n�
typedef struct Node {
    int playerId;           // ID do jogador
    struct Node *next;      // Ponteiro para o pr�ximo n�
} NODE;

// Fun��es para manipular a lista circular
NODE *criarNo(int playerId);
NODE *adicionarJogador(NODE *head, int playerId);
NODE *removerJogador(NODE *head, int playerId);
void exibirJogadores(NODE *head);
void simularJogo(NODE *head, int rodadas);

int main() {
    NODE *head = NULL;

    // Adicionando jogadores
    head = adicionarJogador(head, 1);
    head = adicionarJogador(head, 2);
    head = adicionarJogador(head, 3);
    head = adicionarJogador(head, 4);

    printf("Jogadores na lista:\n");
    exibirJogadores(head);

    printf("\nSimulando jogo por 6 rodadas...\n");
    simularJogo(head, 6);

    printf("\nRemovendo jogador 3...\n");
    head = removerJogador(head, 3);
    exibirJogadores(head);

    printf("\nSimulando jogo por 4 rodadas...\n");
    simularJogo(head, 4);

    return 0;
}

// Cria um novo n�
NODE *criarNo(int playerId) {
    NODE *novoNo = (NODE *)malloc(sizeof(NODE));
    if (novoNo == NULL) {
        printf("Erro: Mem�ria insuficiente.\n");
        exit(EXIT_FAILURE);
    }
    novoNo->playerId = playerId;
    novoNo->next = novoNo; // Aponta para si mesmo (�nico n�)
    return novoNo;
}

// Adiciona um jogador � lista circular
NODE *adicionarJogador(NODE *head, int playerId) {
    NODE *novoNo = criarNo(playerId);

    if (head == NULL) {
        return novoNo; // Primeiro jogador na lista
    }

    // Encontrar o �ltimo n�
    NODE *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    // Inserir o novo n� no final e fazer a conex�o circular
    temp->next = novoNo;
    novoNo->next = head;
    return head;
}

// Remove um jogador da lista circular
NODE *removerJogador(NODE *head, int playerId) {
    if (head == NULL) {
        printf("Erro: Lista vazia.\n");
        return NULL;
    }

    NODE *temp = head;
    NODE *prev = NULL;

    // Caso especial: �nico jogador na lista
    if (temp->playerId == playerId && temp->next == head) {
        free(temp);
        return NULL;
    }

    // Encontrar o n� a ser removido
    do {
        if (temp->playerId == playerId) {
            if (prev == NULL) { // Remo��o do primeiro n�
                NODE *last = head;
                while (last->next != head) {
                    last = last->next;
                }
                head = head->next;
                last->next = head;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            return head;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != head);

    printf("Jogador %d n�o encontrado.\n", playerId);
    return head;
}

// Exibe os jogadores na lista
void exibirJogadores(NODE *head) {
    if (head == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    NODE *temp = head;
    do {
        printf("Jogador %d -> ", temp->playerId);
        temp = temp->next;
    } while (temp != head);
    printf("(volta ao in�cio)\n");
}

// Simula o jogo, mostrando os jogadores em sequ�ncia
void simularJogo(NODE *head, int rodadas) {
	int i;
    if (head == NULL) {
        printf("Erro: Lista vazia, n�o � poss�vel simular.\n");
        return;
    }

    NODE *current = head;
    for (i = 1; i <= rodadas; i++) {
        printf("Rodada %d: Jogador %d\n", i, current->playerId);
        current = current->next;
    }
}
