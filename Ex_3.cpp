#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define CARTELAS 5     // número de cartelas a serem geradas
#define COLUNAS 5      // B, I, N, G, O
#define LINHAS 5       // 5 linhas por cartela

// Gera um número aleatório único dentro de um intervalo
int numeroUnico(int usados[], int tamanho, int min, int max) {
    int num, i;
    do {
        num = rand() % (max - min + 1) + min;
        for (i = 0; i < tamanho; i++) {
            if (usados[i] == num)
                break;
        }
    } while (i != tamanho);
    return num;
}

void gerarCartela(int cartela[LINHAS][COLUNAS]) {
    int usados[LINHAS];
    int i, j;

    for (j = 0; j < COLUNAS; j++) {
        int min = j * 15 + 1;
        int max = min + 14;
        int qtd = LINHAS;

        if (j == 2) qtd = 4; // Coluna N terá 4 números (posição do meio é "FREE")

        for (i = 0; i < qtd; i++) {
            usados[i] = numeroUnico(usados, i, min, max);
        }

        for (i = 0; i < LINHAS; i++) {
            if (j == 2 && i == 2) {
                cartela[i][j] = -1; // posição "FREE"
            } else {
                int idx = (j == 2 && i > 1) ? i - 1 : i;
                cartela[i][j] = usados[idx];
            }
        }
    }
}

void salvarCartelasCSV(const char *nomeArquivo, int qtdCartelas) {
    FILE *fp = fopen(nomeArquivo, "w");
    if (fp == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return;
    }

    fprintf(fp, "B,I,N,G,O\n");

    for (int c = 0; c < qtdCartelas; c++) {
        int cartela[LINHAS][COLUNAS];
        gerarCartela(cartela);

        for (int i = 0; i < LINHAS; i++) {
            for (int j = 0; j < COLUNAS; j++) {
                if (j > 0) fprintf(fp, ",");
                if (cartela[i][j] == -1)
                    fprintf(fp, "FREE");
                else
                    fprintf(fp, "%d", cartela[i][j]);
            }
            fprintf(fp, "\n");
        }

        if (c < qtdCartelas - 1) fprintf(fp, "\n"); // espaço entre cartelas
    }

    fclose(fp);
    printf("Cartelas geradas e salvas em '%s'\n", nomeArquivo);
}

int main() {
    srand(time(NULL)); // inicializa semente do rand

    int qtd;
    printf("Quantas cartelas deseja gerar? ");
    scanf("%d", &qtd);

    salvarCartelasCSV("cartelas_bingo.csv", qtd);

    return 0;
}

