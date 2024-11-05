#include <stdio.h>	//Para entrada e saida.
#include <stdlib.h>	//Para manipulção de 
#include <locale.h>	//Para o sistema imprimir caracteres especiais.
#include <string.h>	//Para manupulação de 

typedef struct {
	int dia, mes, ano;
}Data;
typedef struct {
	int id;
	char nome[100], marca[100], lote[100], loc[100];
	float peso, litro;
	Data vencimento;
}ReagentesCad;
//Funções CRUD Reagentes
Data* nova_data();
ReagentesCad* criar_cadastro(int *n);
void exibir_reagentes(ReagentesCad *cadastros, int n);
void atualizar_reagente(ReagentesCad *cadastros, int n);
ReagentesCad* deletar_reagente(ReagentesCad *cadastros, int *n);



int main(){
	setlocale(LC_ALL,"portuguese");
	ReagentesCad *cadastros = NULL;
    int n = 0;
    int opcao;

    do {
    	system("cls");
        printf("Menu:\n");
        printf("1. Adicionar/Cadastrar reagente\n");
        printf("2. Exibir Reagentes\n");
        printf("3. Atualizar Reagente\n");
        printf("4. Deletar Reagente\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastros = criar_cadastro(&n);
                break;
            case 2:
                exibir_reagentes(cadastros, n);
                break;
            case 3:
                atualizar_reagente(cadastros, n);
                break;
            case 4:
                cadastros = deletar_reagente(cadastros, &n);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 5);

    // Liberação da memória antes de sair
    free(cadastros);
}

Data* nova_data(){
	Data* datas = (Data*)malloc( sizeof(Data));
    if (datas == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }
    printf("Digite o dia: ");
    scanf("%d", &datas->dia);
    printf("Digite o mes: ");
    scanf("%d", &datas->mes);
    printf("Digite o ano:");
    scanf("%d", &datas->ano);

    return datas;
}

// Função que aloca um vetor de N elementos da estrutura Cadastro e preenche os dados
ReagentesCad* criar_cadastro(int *n) {
	int i;
	printf("Quantos reagentes deseja cadastrar? ");
    scanf("%d", n);
    getchar();
    // Alocação dinâmica do vetor de estruturas Cadastro
    ReagentesCad* cadastros = (ReagentesCad*)malloc((*n)* sizeof(ReagentesCad));
    if (cadastros == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }

    // Preenchimento dos dados para cada pessoa
    for (i = 0; i < *n; i++) {
    	cadastros[i].id = i+1;
        printf("Id: %d\n", cadastros[i].id);
        printf("Digite o nome: ");
        fgets(cadastros[i].nome, 100, stdin);
        cadastros[i].nome[strcspn(cadastros[i].nome, "\n")] = 0;
		getchar();

		printf("Digite a marca: ");
        fgets(cadastros[i].marca, 100, stdin);
        cadastros[i].marca[strcspn(cadastros[i].marca, "\n")] = 0;
        getchar();
        
        printf("Digite o lote: ");
        fgets(cadastros[i].lote, 100, stdin);
        cadastros[i].lote[strcspn(cadastros[i].lote, "\n")] = 0;
        getchar();
        
        printf("Digite a localização: ");
        fgets(cadastros[i].loc, 100, stdin);
        cadastros[i].loc[strcspn(cadastros[i].loc, "\n")] = 0;
		getchar();
		
        printf("Digite o peso: ");
        scanf("%f", &cadastros[i].peso);
        getchar(); // Limpar o buffer após ler o inteiro

		printf("Digite o litro: ");
        scanf("%f", &cadastros[i].litro);
        getchar();

        printf("Digite o vencimento: ");
        scanf("%d %d %d", &cadastros[i].vencimento.dia, &cadastros[i].vencimento.mes, &cadastros[i].vencimento.ano);
        getchar();

        printf("\n");
    }

    return cadastros;
}
//exibição de cadastro
void exibir_reagentes(ReagentesCad *cadastros, int n) {
	printf("Digite o Id do regenete que deseja exibir: ");
	scanf("%d", &n);
    if (n == 0 ) {
        printf("Nenhum reagente cadastrado.\n");
        return;
    }
        printf("Id: %d\n", cadastros->id);
        printf("Nome: %s\n", cadastros->nome);
        printf("Marca: %s\n", cadastros->marca);
        printf("Lote: %s\n", cadastros->lote);
        printf("Localização: %s\n", cadastros->loc);
        printf("Peso: %.2f\n", cadastros->peso);
        printf("Litro: %.2f\n", cadastros->litro);
        printf("Vencimento: %02d/%02d/%04d\n", cadastros->vencimento.dia, cadastros->vencimento.mes, cadastros->vencimento.ano);
        printf("\n");
    system("pause");
}

//atualização de cadastro
void atualizar_reagente(ReagentesCad *cadastros, int n) {
	FILE *fp = fopen("reagentesPF.txt", "ab+")
	int i;
    if (n == 0) {
        printf("Nenhum reagente cadastrado.\n");
        return;
    }

    int id;
    printf("Digite o ID do reagente que deseja atualizar: ");
    scanf("%d", &id);
    getchar();
 
    for (i = 0; i < n; i++) {
        if (cadastros[i].id == id) {
        printf("Digite o nome: ");
        fgets(cadastros[i].nome, 100, stdin);
        cadastros[i].nome[strcspn(cadastros[i].nome, "\n")] = 0;

		printf("Digite a marca: ");
        fgets(cadastros[i].marca, 100, stdin);
        cadastros[i].marca[strcspn(cadastros[i].marca, "\n")] = 0;
        
        printf("Digite o lote: ");
        fgets(cadastros[i].lote, 100, stdin);
        cadastros[i].lote[strcspn(cadastros[i].lote, "\n")] = 0;
        
        printf("Digite a localização: ");
        fgets(cadastros[i].loc, 100, stdin);
        cadastros[i].loc[strcspn(cadastros[i].loc, "\n")] = 0;
        fflush(stdin);

        printf("Digite o peso: ");
        scanf("%f", &cadastros[i].peso);
        getchar(); // Limpar o buffer após ler o inteiro

		printf("Digite o litro: ");
        scanf("%f", &cadastros[i].litro);
        getchar();

        printf("Digite o vencimento: ");
        scanf("%d %d %d", &cadastros[i].vencimento.dia, &cadastros[i].vencimento.mes, &cadastros[i].vencimento.ano);
        getchar();
        printf("Dados atualizados com sucesso!\n\n");
        return;
        }
    }
    printf("Reagente com ID %d não encontrado.\n", id);
}

// Função para deletar um reagente
ReagentesCad* deletar_reagente(ReagentesCad *cadastros, int *n) {
	int i,j;
    if (*n == 0) {
        printf("Nenhum reagente cadastrado.\n");
        return cadastros;
    }

    int id;
    printf("Digite o ID do reagente que deseja deletar: ");
    scanf("%d", &id);
    getchar();

    for (i = 0; i < *n; i++) {
        if (cadastros[i].id == id) {
            printf("Deletando reagente com ID %d...\n", id);
            // Deslocar os elementos para remover o reagente
            for ( j = i; j < *n - 1; j++) {
                cadastros[j] = cadastros[j + 1];
            }
            (*n)--;

            // Realocar memória para o novo tamanho
            cadastros = (ReagentesCad*)realloc(cadastros, (*n) * sizeof(ReagentesCad));
            printf("Reagente deletado com sucesso!\n\n");
            return cadastros;
        }
    }
    printf("Reagente com ID %d não encontrado.\n", id);
    return cadastros;
}
