#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// Função para arredondar valor para "casas" casas decimais
double arredondar(double valor, int casas) {
    double fator = pow(10, casas);
    return round(valor * fator) / fator;
}

int main() {
    double numero;
    int casas;
    char opcao;

    printf("Digite um número decimal: ");
    scanf("%lf", &numero);

    printf("Deseja informar o número de casas decimais? (s/n): ");
    scanf(" %c", &opcao);

    if (opcao == 's' || opcao == 'S') {
        printf("Digite o número de casas decimais: ");
        scanf("%d", &casas);
    } else {
        casas = 0;  // padrão
    }

    double resultado = arredondar(numero, casas);
    printf("Resultado: %.10f\n", resultado);

    return 0;
}

