#include <stdio.h>

/*
 * Questao 10: Analise de Paridade e Sinal de Inteiros
 * Recebe um numero inteiro e determina simultaneamente:
 * a) Par ou Impar (atraves do operador %)
 * b) Positivo, Negativo ou Zero
 */

int main(void) {
    int numero;

    printf("=== ANALISE DE PARIDADE E SINAL ===\n");
    printf("Digite um numero inteiro: ");
    if (scanf("%d", &numero) != 1) {
        printf("Erro: Entrada invalida.\n");
        return 1;
    }

    printf("\nResultado para o numero %d:\n", numero);

    // a) Paridade
    if (numero % 2 == 0) {
        printf("- Paridade: PAR\n");
    } else {
        printf("- Paridade: IMPAR\n");
    }

    // b) Sinal
    if (numero > 0) {
        printf("- Sinal: POSITIVO\n");
    } else if (numero < 0) {
        printf("- Sinal: NEGATIVO\n");
    } else {
        printf("- Sinal: ZERO (NULO / NEUTRO)\n");
    }

    return 0;
}
