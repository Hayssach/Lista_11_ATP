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

    int n;
    fscanf(fmenu, "%d", &n);  // número de itens no menu

    char nomes[MAX_ITENS][MAX_NOME];
    float precos[MAX_ITENS];

    // Lê os itens do menu
    for (int i = 0; i < n; i++) {
        fscanf(fmenu, "%s %f", nomes[i], &precos[i]);
    }

    // Mostra o menu
    printf("==== MENU ====\n");
    for (int i = 0; i < n; i++) {
        printf("%d - %s : R$ %.2f\n", i + 1, nomes[i], precos[i]);
    }

    int quantidades[MAX_ITENS] = {0};
    int escolha, qtd;

    // Lê pedidos do usuário
    while (1) {
        printf("Digite o número do item que deseja comprar (0 para finalizar): ");
        scanf("%d", &escolha);
        if (escolha == 0) break;
        if (escolha < 1 || escolha > n) {
            printf("Opção inválida!\n");
            continue;
        }

        printf("Digite a quantidade de %s: ", nomes[escolha - 1]);
        scanf("%d", &qtd);
        quantidades[escolha - 1] += qtd;
    }

    // Gera boleto.txt
    FILE *fbol = fopen("boleto.txt", "w");
    if (!fbol) {
        perror("Erro ao criar boleto.txt");
        return 1;
    }

    fprintf(fbol, "====== BOLETO ======\n");
    float total = 0.0;
    for (int i = 0; i < n; i++) {
        if (quantidades[i] > 0) {
            float subt = quantidades[i] * precos[i];
            fprintf(fbol, "%s x %d = R$ %.2f\n", nomes[i], quantidades[i], subt);
            total += subt;
        }
    }
    fprintf(fbol, "TOTAL A PAGAR: R$ %.2f\n", total);
    fclose(fbol);

    printf("\nPedido registrado no arquivo boleto.txt\n");
    
    getchar();
    fclose(fmenu);
    return 0;
}
