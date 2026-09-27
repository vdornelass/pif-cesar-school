#include <stdio.h>

/*
 * Questao 09: Acumulador de Valores Reais com Sentinela de Parada Negativa
 * Le valores reais positivos ate que um numero negativo seja fornecido como sentinela.
 * Ao final, exibe a quantidade de valores validos, soma e media aritmetica.
 */

int main(void) {
    double valor;
    double soma = 0.0;
    int quantidade = 0;

    printf("Digite valores reais positivos (ou um numero negativo para encerrar):\n");

    while (1) {
        printf("Valor %d: ", quantidade + 1);
        if (scanf("%lf", &valor) != 1) {
            while (getchar() != '\n');
            printf("Entrada invalida! Digite um numero valido.\n");
            continue;
        }

        if (valor < 0.0) {
            // Valor sentinela: nao entra na contagem nem na soma
            break;
        }

        soma += valor;
        quantidade++;
    }

    printf("\n--- Relatorio Final ---\n");
    printf("Quantidade de valores validos: %d\n", quantidade);
    printf("Soma total: %.2f\n", soma);

    if (quantidade > 0) {
        double media = soma / quantidade;
        printf("Media aritmetica: %.2f\n", media);
    } else {
        printf("Media aritmetica: Indefinida (nenhum valor positivo foi digitado).\n");
    }

    return 0;
}
