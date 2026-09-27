#include <stdio.h>

/*
 * Questao 03: Operadores de Atribuicao Composta e Avaliacao Sequencial
 * Executa a sequencia de expressoes e exibe os valores finais das variaveis a, b, c e d.
 */

int main(void) {
    int a = 2, b = 4, c = 5, d = 10;

    printf("Valores iniciais: a = %d, b = %d, c = %d, d = %d\n\n", a, b, c, d);

    // Passo 1: a += b + c; (b + c = 9; a = 2 + 9 = 11)
    a += b + c;
    printf("Apos 'a += b + c;':\n");
    printf("  a = %d, b = %d, c = %d, d = %d\n\n", a, b, c, d);

    // Passo 2: b *= c = d - 2; (d - 2 = 8; c = 8; b = 4 * 8 = 32)
    b *= c = d - 2;
    printf("Apos 'b *= c = d - 2;':\n");
    printf("  a = %d, b = %d, c = %d, d = %d\n\n", a, b, c, d);

    // Passo 3: d %= a + 3; (a + 3 = 14; d = 10 % 14 = 10)
    d %= a + 3;
    printf("Apos 'd %%= a + 3;':\n");
    printf("  a = %d, b = %d, c = %d, d = %d\n\n", a, b, c, d);

    // Passo 4: a += b += c += 5; (c = 8 + 5 = 13; b = 32 + 13 = 45; a = 11 + 45 = 56)
    a += b += c += 5;
    printf("Apos 'a += b += c += 5;':\n");
    printf("  a = %d, b = %d, c = %d, d = %d\n\n", a, b, c, d);

    printf("=== Valores Finais ===\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);
    printf("d = %d\n", d);

    return 0;
}
