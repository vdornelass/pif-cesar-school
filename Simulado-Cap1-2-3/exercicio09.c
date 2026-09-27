#include <stdio.h>
#include <math.h>

/*
 * Questao 9: Geometria do Triangulo e Formula de Heron
 * Le os comprimentos dos tres lados (a, b, c) de um triangulo,
 * valida a condicao de existencia e calcula a area pela Formula de Heron.
 */

int main(void) {
    double a, b, c;

    printf("Digite os comprimentos dos tres lados do triangulo:\n");
    printf("Lado a: ");
    if (scanf("%lf", &a) != 1) return 1;
    printf("Lado b: ");
    if (scanf("%lf", &b) != 1) return 1;
    printf("Lado c: ");
    if (scanf("%lf", &c) != 1) return 1;

    // Condicao de existencia do triangulo
    if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a) {
        printf("Erro: Os lados informados nao formam um triangulo valido!\n");
        return 1;
    }

    double p = (a + b + c) / 2.0; // Semiperimetro
    double area = sqrt(p * (p - a) * (p - b) * (p - c)); // Formula de Heron

    printf("\n=== Geometria do Triangulo ===\n");
    printf("Semiperimetro (p): %.4f\n", p);
    printf("Area do triangulo: %.4f\n", area);

    return 0;
}
