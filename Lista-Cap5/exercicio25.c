#include <stdio.h>

/*
 * Questao 25: Maximo Divisor Comum com Recursao (Algoritmo de Euclides)
 * Funcao recursiva int mdc(int a, int b) e procedimento void simplifica(int num, int den).
 */

// Prototipos
int mdc(int a, int b);
void simplifica(int num, int den);

int main(void) {
    int a, b;

    printf("=== MDC E SIMPLIFICACAO DE FRACOES (EUCLIDES) ===\n");
    printf("Digite o numerador e o denominador (inteiros positivos): ");
    if (scanf("%d %d", &a, &b) != 2 || a <= 0 || b <= 0) {
        printf("Erro: Forneca dois inteiros estritamente positivos.\n");
        return 1;
    }

    int resultado_mdc = mdc(a, b);
    printf("MDC(%d, %d) = %d\n", a, b, resultado_mdc);

    simplifica(a, b);

    return 0;
}

int mdc(int a, int b) {
    // Caso Base: quando o resto eh zero, o divisor corrente eh o MDC
    if (b == 0) {
        return a;
    }
    // Passo Recursivo: mdc(b, a % b)
    return mdc(b, a % b);
}

void simplifica(int num, int den) {
    int divisor_comum = mdc(num, den);
    int num_simp = num / divisor_comum;
    int den_simp = den / divisor_comum;

    printf("Fracao original: %d/%d\n", num, den);
    if (den_simp == 1) {
        printf("Fracao simplificada: %d (inteiro puro)\n", num_simp);
    } else {
        printf("Fracao simplificada: %d/%d\n", num_simp, den_simp);
    }
}
