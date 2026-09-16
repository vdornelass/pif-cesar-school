#include <stdio.h>

/*
 * Questao 10: Conversao de Temperatura de Celsius para Fahrenheit e Kelvin
 * Formulas:
 * F = (C * 9.0 / 5.0) + 32.0
 * K = C + 273.15
 */

int main(void) {
    double celsius;
    printf("Digite a temperatura em graus Celsius: ");
    if (scanf("%lf", &celsius) == 1) {
        double fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
        double kelvin = celsius + 273.15;

        printf("Temperatura em Fahrenheit: %.2f F\n", fahrenheit);
        printf("Temperatura em Kelvin: %.2f K\n", kelvin);
    } else {
        printf("Entrada invalida!\n");
    }
    return 0;
}
