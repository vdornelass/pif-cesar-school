#include <stdio.h>

/*
 * Questao 04: Operadores de Atribuicao Composta e Precedencia
 * Executa sequencialmente as atribuicoes compostas e exibe os valores finais.
 */

int main(void) {
    int a = 1, b = 2, c = 3, d = 4;

    a += b + c;       // a = 1 + (2 + 3) = 6
    b *= c = d + 2;   // c = 4 + 2 = 6; b = 2 * 6 = 12
    d %= a + a + a;   // d = 4 % (6 + 6 + 6) = 4 % 18 = 4
    d -= c -= b -= a; // b = 12 - 6 = 6; c = 6 - 6 = 0; d = 4 - 0 = 4
    a += b += c += 7; // c = 0 + 7 = 7; b = 6 + 7 = 13; a = 6 + 13 = 19

    printf("Valores finais:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);
    printf("d = %d\n", d);

    return 0;
}
