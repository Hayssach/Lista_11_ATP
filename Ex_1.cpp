#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Função para verificar se é primo
bool ehPrimo(int m) {
    if (m < 2) return false;
    for (int j = 2; j * j <= m; j++) {
        if (m % j == 0) return false;
    }
    return true;
}

int main(int arg, char *argv[]) {
    int comeco, f;

    if (arg == 3) {
        // Argumentos fornecidos via linha de comando
        comeco = atoi(argv[1]);
        f = atoi(argv[2]);
    } else {
        // Argumentos não fornecidos — pedir via teclado
        printf("Digite o número inicial do intervalo: ");
        scanf("%d", &comeco);
        printf("Digite o número final do intervalo: ");
        scanf("%d", &f);
    }

    if (comeco > f) {
        printf("Erro: o número inicial deve ser menor ou igual ao final.\n");
        return 1;
    }

    printf("Números primos entre %d e %d:\n", comeco, f);
    for (int j = comeco; j <= f; j++) {
        if (ehPrimo(j)) {
            printf("%d ", j);
        }
    }
    printf("\n");

    return 0;
}

