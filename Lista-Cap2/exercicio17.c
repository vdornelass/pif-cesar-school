#include <stdio.h>

/*
 * Questao 17: Geometria do Circulo com Constantes
 * Area = Pi * R^2
 * Circunferencia = 2 * Pi * R
 * Constante Pi = 3.141593
 */

#define PI 3.141593

int main(void) {
    double raio;
    printf("Digite o valor do raio do circulo: ");
    if (scanf("%lf", &raio) == 1) {
        double area = PI * raio * raio;
        double circunferencia = 2.0 * PI * raio;

        printf("Area do circulo: %.4f\n", area);
        printf("Circunferencia do circulo: %.4f\n", circunferencia);
    } else {
        printf("Entrada invalida!\n");
    }
    return 0;
}
