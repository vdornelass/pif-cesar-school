#include <stdio.h>

/*
 * Questao 06: Comportamento e Precedencia dos Incrementos
 * Demonstra a diferenca entre pre-incremento (++n) e pos-incremento (m++).
 */

int main(void) {
    // Trecho A: Pre-incremento (incrementa antes e retorna o novo valor)
    int n = 5;
    int x = ++n;
    printf("Trecho A: n = %d, x = %d\n", n, x);

    // Trecho B: Pos-incremento (retorna o valor atual e depois incrementa)
    int m = 5;
    int y = m++;
    printf("Trecho B: m = %d, y = %d\n", m, y);

    return 0;
}
