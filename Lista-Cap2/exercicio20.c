#include <stdio.h>
#include <math.h>

/*
 * Questao 20: Teorema de Pitagoras e a Hipotenusa
 * Hipotenusa = sqrt(lado_a^2 + lado_b^2)
 * Compilar vinculando a biblioteca matematica: gcc exercicio20.c -o exercicio20 -lm
 */

int main(void) {
    double lado_a, lado_b;
    printf("Digite o valor do primeiro cateto (lado_a): ");
    if (scanf("%lf", &lado_a) != 1) return 1;

    printf("Digite o valor do segundo cateto (lado_b): ");
    if (scanf("%lf", &lado_b) != 1) return 1;

    double hipotenusa = sqrt(pow(lado_a, 2) + pow(lado_b, 2));

    printf("Comprimento da hipotenusa: %.4f\n", hipotenusa);
    return 0;
}
