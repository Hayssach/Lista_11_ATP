#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Fun��o para verificar se um n�mero � primo
bool ehPrimo(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main(int argc, char *argv[]) {
    int inicio, fim;

    if (argc == 3) {
        // Argumentos fornecidos via linha de comando
        inicio = atoi(argv[1]);
        fim = atoi(argv[2]);
    } else {
        // Argumentos n�o fornecidos � pedir via teclado
        printf("Digite o n�mero inicial do intervalo: ");
        scanf("%d", &inicio);
        printf("Digite o n�mero final do intervalo: ");
        scanf("%d", &fim);
    }

    if (inicio > fim) {
        printf("Erro: o n�mero inicial deve ser menor ou igual ao final.\n");
        return 1;
    }

    printf("N�meros primos entre %d e %d:\n", inicio, fim);
    for (int i = inicio; i <= fim; i++) {
        if (ehPrimo(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}

