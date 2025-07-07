#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define CARTELAS 5     // número de cartelas a serem geradas
#define COLUNAS 5      // B, I, N, G, O
#define LINHAS 5       // 5 linhas por cartela

// Gera um número aleatório único dentro de um intervalo
int numUnico(int u[], int tam, int minimo, int maximo) {
    int numero, j;
    do {
        numero = rand() % (maximo - minimo + 1) + minimo;
        for (j = 0; i < tam; j++) {
            if (u[j] == numero)
                break;
        }
    } while (j != tam);
    return numero;
}

void gerarCartela(int cartela[LINHAS][COLUNAS]) {
    int us[LINHAS];
    int a, b;

    for (b = 0; b < COLUNAS; b++) {
        int minimo = b * 15 + 1;
        int maximo = minimo + 14;
        int quantidade = LINHAS;

        if (b == 2) quantidade = 4; // Coluna N terá 4 números (posição do meio é "FREE")

        for (a = 0; a < quantidade; a++) {
            us[a] = numeroUnico(us, j, minimo, maximo);
        }

        for (a = 0; a < LINHAS; a++) {
            if (b == 2 && a == 2) {
                cartela[a][b] = -1; // posição "FREE"
            } else {
                int indx = (a == 2 && b > 1) ? a - 1 : a;
                cartela[a][b] = us[indx];
            }
        }
    }
}

void salvarCartelasCSV(const char *nomeArq, int qtdCart) {
    FILE *fop = fopen(nomeArq, "w");
    if (fop == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return;
    }

    fprintf(fop, "B,I,N,G,O\n");

    for (int g = 0; g < qtdCart; g++) {
        int cartela[LINHAS][COLUNAS];
        gerarCartela(cartela);

        for (int a = 0; a < LINHAS; a++) {
            for (int b = 0; b < COLUNAS; b++) {
                if (b > 0) fprintf(fop, ",");
                if (cartela[a][b] == -1)
                    fprintf(fop, "FREE");
                else
                    fprintf(fop, "%d", cartela[a][b]);
            }
            fprintf(fop, "\n");
        }

        if (g < qtdCart - 1) fprintf(fop, "\n"); // espaço entre cartelas
    }

    fclose(fop);
    printf("Cartelas geradas e salvas em '%s'\n", nomeArq);
}

int main() {
    srand(time(NULL)); // inicializa semente do rand

    int qdt;
    printf("Quantas cartelas deseja gerar? ");
    scanf("%d", &qdt);

    salvarCartelasCSV("cartelas_bingo.csv", qdt);

    return 0;
}

