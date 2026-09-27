#include <stdio.h>

/*
 * Questao 10: Geracao de Multiplos com Formatacao em Colunas
 * Determina e exibe no console os 100 primeiros multiplos inteiros e positivos de 3.
 * A saida eh formatada em colunas de 10 numeros por linha separados por tabulacao (\t).
 */

int main(void) {
    int i;
    int multiplo;

    printf("Os 100 primeiros multiplos inteiros e positivos de 3:\n\n");

    for (i = 1; i <= 100; i++) {
        multiplo = i * 3;
        printf("%d\t", multiplo);

        // A cada 10 numeros exibidos, salta uma linha
        if (i % 10 == 0) {
            printf("\n");
        }
    }

    return 0;
}
