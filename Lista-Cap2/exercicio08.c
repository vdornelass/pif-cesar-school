#include <stdio.h>

/*
 * Questao 08: Potencias e Divisao com Ponto Flutuante
 * Le um inteiro e calcula:
 * a) Seu quadrado (inteiro);
 * b) Sua decima parte (ponto flutuante com 2 casas decimais).
 */

int main(void) {
    int num;
    printf("Digite um numero inteiro: ");
    if (scanf("%d", &num) == 1) {
        int quadrado = num * num;
        double decima_parte = num / 10.0; // Divisao real por 10.0 evita truncamento

        printf("a) Quadrado: %d\n", quadrado);
        printf("b) Decima parte: %.2f\n", decima_parte);
    } else {
        printf("Entrada invalida!\n");
    }
    return 0;
}
