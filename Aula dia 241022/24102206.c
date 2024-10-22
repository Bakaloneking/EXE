#include <stdio.h>
#include <stdlib.h>

// Função para alocar uma matriz MxN dinamicamente
double** alocar_matriz(int m, int n) {
	int i;
    double **matriz = (double**)malloc(m * sizeof(double*));
    if (matriz == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }

    for (i = 0; i < m; i++) {
        matriz[i] = (double*)malloc(n * sizeof(double));
        if (matriz[i] == NULL) {
            printf("Erro ao alocar memória\n");
            exit(1);
        }
    }

    return matriz;
}

// Função para liberar a memória alocada para uma matriz
void liberar_matriz(double **matriz, int m) {
	int i;
    for (i = 0; i < m; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

// Função para preencher uma matriz com valores fornecidos pelo usuário
void preencher_matriz(double **matriz, int m, int n) {
	int i,j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("Digite o elemento [%d][%d]: ", i, j);
            scanf("%lf", &matriz[i][j]);  // %lf para double
        }
    }
}

// Função para somar duas matrizes e armazenar o resultado em uma terceira matriz
void somar_matrizes(double **matriz1, double **matriz2, double **resultado, int m, int n) {
	int i,j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
}

// Função para imprimir uma matriz
void imprimir_matriz(double **matriz, int m, int n) {
    int i,j;
	for ( i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%.2lf ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m, n;

    // Solicita as dimensões da matriz
    printf("Digite o número de linhas (m): ");
    scanf("%d", &m);
    printf("Digite o número de colunas (n): ");
    scanf("%d", &n);

    // Alocando as três matrizes: matriz1, matriz2 e resultado
    double **matriz1 = alocar_matriz(m, n);
    double **matriz2 = alocar_matriz(m, n);
    double **resultado = alocar_matriz(m, n);

    // Preenchendo a primeira matriz
    printf("Preencha a primeira matriz:\n");
    preencher_matriz(matriz1, m, n);

    // Preenchendo a segunda matriz
    printf("Preencha a segunda matriz:\n");
    preencher_matriz(matriz2, m, n);

    // Somando as duas matrizes
    somar_matrizes(matriz1, matriz2, resultado, m, n);

    // Imprimindo o resultado
    printf("Resultado da soma das duas matrizes:\n");
    imprimir_matriz(resultado, m, n);

    // Liberando a memória alocada
    liberar_matriz(matriz1, m);
    liberar_matriz(matriz2, m);
    liberar_matriz(resultado, m);

    return 0;
}
