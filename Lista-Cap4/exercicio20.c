#include <stdio.h>
#include <math.h>

/*
 * Questao 20: Resolucao da Equacao do Segundo Grau (Formula de Bhaskara)
 * ax^2 + bx + c = 0, com a != 0.
 * Delta = b^2 - 4ac.
 * Delta < 0: 'A equacao nao possui raizes reais.'
 * Delta == 0: raiz unica x = -b / (2a)
 * Delta > 0: duas raizes reais x1, x2.
 */

int main(void) {
    double a, b, c;
    double delta, x1, x2;

    printf("=== EQUACAO DO SEGUNDO GRAU (BHASKARA) ===\n");
    printf("Digite os coeficientes a, b e c: ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) return 1;

    if (a == 0.0) {
        printf("Erro: 'a' nao pode ser zero (nao eh equacao do 2o grau).\n");
        return 1;
    }

    delta = (b * b) - (4.0 * a * c);
    printf("Delta calculado = %.4f\n", delta);

    if (delta < 0.0) {
        printf("A equacao nao possui raizes reais.\n");
    } else if (delta == 0.0) {
        x1 = -b / (2.0 * a);
        printf("Raiz unica: x = %.4f\n", x1);
    } else {
        x1 = (-b + sqrt(delta)) / (2.0 * a);
        x2 = (-b - sqrt(delta)) / (2.0 * a);
        printf("Duas raizes reais distintas:\n");
        printf("x1 = %.4f\n", x1);
        printf("x2 = %.4f\n", x2);
    }

    return 0;
}
