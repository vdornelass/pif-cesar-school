#include <stdio.h>
#include "areas.h"

/*
 * Questao 22: Biblioteca de Areas com Arquivo de Cabecalho (areas.h)
 * Utiliza as macros A_CIRC, A_RET e A_TRI definidas em areas.h.
 */

int main(void) {
    double r, base_r, alt_r, base_t, alt_t;

    printf("=== CALCULADORA DE AREAS VIA HEADER 'areas.h' ===\n\n");

    printf("1. Circulo - Digite o raio: ");
    if (scanf("%lf", &r) != 1) return 1;
    printf("Area do Circulo = %.4f\n\n", A_CIRC(r));

    printf("2. Retangulo - Digite base e altura: ");
    if (scanf("%lf %lf", &base_r, &alt_r) != 2) return 1;
    printf("Area do Retangulo = %.4f\n\n", A_RET(base_r, alt_r));

    printf("3. Triangulo - Digite base e altura: ");
    if (scanf("%lf %lf", &base_t, &alt_t) != 2) return 1;
    printf("Area do Triangulo = %.4f\n", A_TRI(base_t, alt_t));

    return 0;
}
