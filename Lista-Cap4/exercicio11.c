#include <stdio.h>

/*
 * Questao 11: Ordenacao Crescente de Tres Valores Numericos
 * Le tres inteiros e exibe em ordem estritamente crescente
 * utilizando comparacoes condicionais sem vetores.
 */

int main(void) {
    int a, b, c;
    int temp;

    printf("=== ORDENACAO CRESCENTE DE TRES NUMEROS ===\n");
    printf("Digite tres numeros inteiros separados por espaco: ");
    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        printf("Erro: Forneca tres inteiros validos.\n");
        return 1;
    }

    // Ordenacao por trocas condicionais (bubble/insertion simples de 3 variaveis)
    if (a > b) {
        temp = a; a = b; b = temp;
    }
    if (a > c) {
        temp = a; a = c; c = temp;
    }
    if (b > c) {
        temp = b; b = c; c = temp;
    }

    printf("Valores em ordem crescente: %d <= %d <= %d\n", a, b, c);

    return 0;
}
