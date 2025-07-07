#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// Função para arredondar valor das casas decimais
double arredondando(double v, int c) {
    double f = pow(10, c);
    return round(v * f) / f;
}

int main() {
    double num;
    int CASAS;
    char op;

    printf("Digite um número decimal: ");
    scanf("%lf", &num);

    printf("Deseja informar o número de casas decimais? (s/n): ");
    scanf(" %c", &op);

    if (op == 's' || op == 'S') {
        printf("Digite o número de casas decimais: ");
        scanf("%d", &CASAS);
    } else {
        CASAS = 0;  // padrão
    }

    double r = arredondando(num, CASAS);
    printf("Resultado: %.10f\n", r);

    return 0;
}

