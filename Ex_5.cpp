#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 100
#define MAX_NOME 50

int main() {
    FILE *fmenu = fopen("menu.txt", "r");
    if (!fmenu) {
        perror("Erro ao abrir menu.txt");
        return 1;
    }

    int m;
    fscanf(fmenu, "%d", &m);  // número de itens no menu

    char nom s[MAX_ITENS][MAX_NOME];
    float p[MAX_ITENS];

    // Lê os itens do menu
    for (int i = 0; i < m; i++) {
        fscanf(fmenu, "%s %f", nomes[i], &p[i]);
    }

    // Mostra o menu
    printf("==== MENU ====\n");
    for (int i = 0; i < n; i++) {
        printf("%d - %s : R$ %.2f\n", i + 1, nomes[i], precos[i]);
    }

    int qtd[MAX_ITENS] = {0};
    int e, quantidade;

    // Lê pedidos do usuário
    while (1) {
        printf("Digite o número do item que deseja comprar (0 para finalizar): ");
        scanf("%d", &e);
        if (e == 0) break;
        if (e < 1 || e > m) {
            printf("Opção inválida!\n");
            continue;
        }

        printf("Digite a quantidade de %s: ", nomes[escolha - 1]);
        scanf("%d", & quantidade);
        qtd[e - 1] += quantidade;
    }

    // Gera boleto.txt
    FILE *fbol = fopen("boleto.txt", "w");
    if (!fbol) {
        perror("Erro ao criar boleto.txt");
        return 1;
    }

    fprintf(fbol, "====== BOLETO ======\n");
    float t = 0.0;
    for (int i = 0; i < m; i++) {
        if (qtd[i] > 0) {
            float s = qtd[i] * p[i];
            fprintf(fbol, "%s x %d = R$ %.2f\n", nomes[i], quantidades[i], subt);
            t += s;
        }
    }
    fprintf(fbol, "TOTAL A PAGAR: R$ %.2f\n", t);
    fclose(fbol);

    printf("\nPedido registrado no arquivo boleto.txt\n");
    
    getchar();
    fclose(fmenu);
    return 0;
}
