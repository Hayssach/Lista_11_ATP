#include <stdio.h>
#include <stdlib.h>

void escreverArquivo(const char *nomeArquivo, int **A, int **B, int n) {
    FILE *f = fopen(nomeArquivo, "w");
    if (!f) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    fprintf(f, "%d\n", n);

    // Escreve matriz A
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fprintf(f, "%d%c", A[i][j], (j == n - 1) ? '\n' : ' ');

    // Escreve matriz B
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fprintf(f, "%d%c", B[i][j], (j == n - 1) ? '\n' : ' ');

    fclose(f);
}

void lerArquivo(const char *nomeArquivo, int ***A, int ***B, int *n) {
    FILE *f = fopen(nomeArquivo, "r");
    if (!f) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    fscanf(f, "%d", n);

    // Aloca memória
    *A = malloc((*n) * sizeof(int *));
    *B = malloc((*n) * sizeof(int *));
    for (int i = 0; i < *n; i++) {
        (*A)[i] = malloc((*n) * sizeof(int));
        (*B)[i] = malloc((*n) * sizeof(int));
    }

    // Lê matriz A
    for (int i = 0; i < *n; i++)
        for (int j = 0; j < *n; j++)
            fscanf(f, "%d", &(*A)[i][j]);

    // Lê matriz B
    for (int i = 0; i < *n; i++)
        for (int j = 0; j < *n; j++)
            fscanf(f, "%d", &(*B)[i][j]);

    fclose(f);
}

void somarMatrizes(int **A, int **B, int n, int **S) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            S[i][j] = A[i][j] + B[i][j];
}

void imprimirMatriz(int **M, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", M[i][j]);
        printf("\n");
    }
}

int main() {
    int n;
    printf("Informe a dimensão da matriz quadrada: ");
    scanf("%d", &n);

    // Aloca memória para as matrizes A e B
    int **A = malloc(n * sizeof(int *));
    int **B = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        A[i] = malloc(n * sizeof(int));
        B[i] = malloc(n * sizeof(int));
    }

    printf("Digite os elementos da matriz A:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Digite os elementos da matriz B:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    escreverArquivo("matriz.txt", A, B, n);

    // Lê as matrizes do arquivo
    int **matA, **matB;
    lerArquivo("matriz.txt", &matA, &matB, &n);

    // Soma as matrizes
    int **S = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        S[i] = malloc(n * sizeof(int));
    somarMatrizes(matA, matB, n, S);

    // Exibe a matriz soma
    printf("Matriz Soma:\n");
    imprimirMatriz(S, n);

    // Libera memória
    for (int i = 0; i < n; i++) {
        free(A[i]); free(B[i]);
        free(matA[i]); free(matB[i]); free(S[i]);
    }
    free(A); free(B);
    free(matA); free(matB); free(S);
    getchar();
    return 0;
}
