#include <stdio.h>
#include <stdlib.h>

void escreveArquivo(const char *nomeArq, int **B, int **C, int m) {
    FILE *fop = fopen(nomeArq, "w");
    if (!fop) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    fprintf(fop, "%d\n", m);

    // Escreve matriz B
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            fprintf(fop, "%d%c", B[i][j], (j == m - 1) ? '\n' : ' ');

    // Escreve matriz C
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            fprintf(f, "%d%c", C[i][j], (j == m - 1) ? '\n' : ' ');

    fclose(fop);
}

void leArquivo(const char *nomeArq, int ***B, int ***C, int *m) {
    FILE *fop = fopen(nomeArq, "r");
    if (!fop) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    fscanf(fop, "%d", m);

    // Aloca memória
    *B = malloc((*m) * sizeof(int *));
    *C = malloc((*m) * sizeof(int *));
    for (int i = 0; i < *m; i++) {
        (*B)[i] = malloc((*m) * sizeof(int));
        (*C)[i] = malloc((*m) * sizeof(int));
    }

    // Lê matriz B
    for (int i = 0; i < *m; i++)
        for (int j = 0; j < *m; j++)
            fscanf(fop, "%d", &(*B)[i][j]);

    // Lê matriz C
    for (int i = 0; i < *m; i++)
        for (int j = 0; j < *m; j++)
            fscanf(fop, "%d", &(*C)[i][j]);

    fclose(fop);
}

void somaMatrizes(int **B, int **C, int m, int **K) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            K[i][j] = B[i][j] + C[i][j];
}

void imprimeMatriz(int **A, int m) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }
}

int main() {
    int m;
    printf("Informe a dimensão da matriz quadrada: ");
    scanf("%d", &m);

    // Aloca memória para as matrizes A e B
    int **B = malloc(m * sizeof(int *));
    int **C = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        B[i] = malloc(m * sizeof(int));
        C[i] = malloc(m * sizeof(int));
    }

    printf("Digite os elementos da matriz B:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &B[i][j]);

    printf("Digite os elementos da matriz C:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &C[i][j]);

    escreveArquivo("matriz.txt", B, C, m);

    // Lê as matrizes do arquivo
    int **matrizB, **matrizC;
    leArquivo("matriz.txt", &matrizB, &matrizC, &m);

    // Soma as matrizes
    int **K = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
        K[i] = malloc(m * sizeof(int));
    somaMatrizes(matrizB, mattizC, m, K);

    // Exibe a matriz soma
    printf("Matriz Soma:\n");
    imprimeMatriz(K, m);

    // Libera memória
    for (int i = 0; i < m; i++) {
        free(B[i]); free(C[i]);
        free(matrizB[i]); free(matrizC[i]); free(K[i]);
    }
    free(B); free(C);
    free(matrizB); free(matrizC); free(K);
    getchar();
    return 0;
}
