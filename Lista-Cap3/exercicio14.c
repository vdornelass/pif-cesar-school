#include <stdio.h>

/*
 * Questao 14: Sequencia de Quadrados e Acumulador Global
 * Imprime os inteiros de 1 a 100 com seus respectivos quadrados (i -> i^2)
 * e, ao final, calcula e exibe a soma total dos quadrados de todos os 100 numeros.
 */

int main(void) {
    long long int soma_quadrados = 0;

    printf("Listagem de numeros e seus respectivos quadrados:\n");
    for (int i = 1; i <= 100; i++) {
        long long int quadrado = (long long int)i * i;
        printf("%d -> %lld\n", i, quadrado);
        soma_quadrados += quadrado;
    }

    printf("\nSoma total dos quadrados de 1 a 100: %lld\n", soma_quadrados);
    return 0;
}
