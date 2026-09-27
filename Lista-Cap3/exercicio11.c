#include <stdio.h>

/*
 * Questao 11: Intervalo Numerico Dinamico (Crescente e Decrescente)
 * Le dois inteiros A e B fornecidos pelo usuario e imprime todos os numeros
 * inteiros no intervalo fechado [A, B]. Se A <= B, imprime em ordem crescente;
 * se A > B, imprime em ordem decrescente.
 */

int main(void) {
    int a, b;

    printf("Digite o primeiro numero inteiro (A): ");
    if (scanf("%d", &a) != 1) {
        printf("Entrada invalida para A!\n");
        return 1;
    }

    printf("Digite o segundo numero inteiro (B): ");
    if (scanf("%d", &b) != 1) {
        printf("Entrada invalida para B!\n");
        return 1;
    }

    printf("\nIntervalo entre %d e %d: ", a, b);

    if (a <= b) {
        for (int i = a; i <= b; i++) {
            printf("%d ", i);
        }
    } else {
        for (int i = a; i >= b; i--) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
