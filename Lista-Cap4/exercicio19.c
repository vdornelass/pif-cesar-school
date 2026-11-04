#include <stdio.h>

/*
 * Questao 19: Validacao de Condicao de Existencia e Tipo de Triangulo
 * Verifica se lados A, B, C formam um triangulo:
 * A < B + C && B < A + C && C < A + B.
 * Se valido, classifica em: Equilatero, Isosceles ou Escaleno.
 */

int main(void) {
    double a, b, c;

    printf("=== CLASSIFICADOR DE TRIANGULOS POR LADOS ===\n");
    printf("Digite os tres lados (A, B, C): ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) return 1;

    // Condicao de existencia: lados positivos e desigualdade triangular
    if (a <= 0.0 || b <= 0.0 || c <= 0.0 ||
        a >= b + c || b >= a + c || c >= a + b) {
        printf("Erro: Os lados fornecidos nao formam um triangulo!\n");
        return 0;
    }

    printf("Triangulo Valido! Classificacao: ");
    if (a == b && b == c) {
        printf("EQUILATERO (tres lados iguais)\n");
    } else if (a == b || a == c || b == c) {
        printf("ISOSCELES (dois lados iguais)\n");
    } else {
        printf("ESCALENO (tres lados distintos)\n");
    }

    return 0;
}
