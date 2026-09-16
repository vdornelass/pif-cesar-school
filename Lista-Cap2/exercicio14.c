#include <stdio.h>
#include <math.h>

/*
 * Questao 14: Formula de Heron para Triangulos Quaisquer
 * Area = sqrt(p * (p - a) * (p - b) * (p - c))
 * onde p = (a + b + c) / 2.0
 * Compilar vinculando a biblioteca matematica: gcc exercicio14.c -o exercicio14 -lm
 */

int main(void) {
    double a, b, c;
    printf("Digite os tres lados do triangulo (a b c): ");
    if (scanf("%lf %lf %lf", &a, &b, &c) == 3) {
        double p = (a + b + c) / 2.0;
        double area = sqrt(p * (p - a) * (p - b) * (p - c));

        printf("Semiperimetro (p): %.2f\n", p);
        printf("Area do triangulo: %.2f\n", area);
    } else {
        printf("Entrada invalida!\n");
    }
    return 0;
}
