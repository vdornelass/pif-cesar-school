#include <stdio.h>

/*
 * Questao 04: Avaliacao de Expressoes Logicas, Relacionais e Precedencia
 * Avalia as cinco expressoes propostas e imprime o resultado logico (1 ou 0).
 */

int main(void) {
    int i = 2, j = 3, k = 0;
    float x = 2.5f, y = 5.0f;

    int res_a = (i < j + 2);
    int res_b = (2 * i - 5 <= j - 4);
    int res_c = (!k && (x + y >= 7.5));
    int res_d = (!(i == j) || (y / x == 2.0));
    // Expressao e): (i == 2 && j == 4) || (k == 0) - parenteses explicitam a precedencia de && sobre ||
    int res_e = ((i == 2 && j == 4) || k == 0);

    printf("Resultados das avaliacoes logicas:\n");
    printf("a) i < j + 2                   => %d (%s)\n", res_a, res_a ? "Verdadeiro" : "Falso");
    printf("b) 2 * i - 5 <= j - 4          => %d (%s)\n", res_b, res_b ? "Verdadeiro" : "Falso");
    printf("c) !k && (x + y >= 7.5)        => %d (%s)\n", res_c, res_c ? "Verdadeiro" : "Falso");
    printf("d) !(i == j) || (y / x == 2.0) => %d (%s)\n", res_d, res_d ? "Verdadeiro" : "Falso");
    printf("e) i == 2 && j == 4 || k == 0  => %d (%s)\n", res_e, res_e ? "Verdadeiro" : "Falso");

    return 0;
}
