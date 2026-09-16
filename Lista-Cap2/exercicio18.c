#include <stdio.h>

/*
 * Questao 18: Geometria da Esfera e Fracoes de Ponto Flutuante
 * Area = 4 * Pi * R^2
 * Volume = (4.0 / 3.0) * Pi * R^3
 * Constante Pi = 3.141593
 * 
 * Atencao: O uso de (4.0 / 3.0) assegura divisao em ponto flutuante,
 * impedindo o truncamento inteiro para 1 que ocorreria com 4 / 3.
 */

#define PI 3.141593

int main(void) {
    double raio;
    printf("Digite o raio da esfera: ");
    if (scanf("%lf", &raio) == 1) {
        double area = 4.0 * PI * raio * raio;
        double volume = (4.0 / 3.0) * PI * raio * raio * raio;

        printf("Area da superficie da esfera: %.4f\n", area);
        printf("Volume da esfera: %.4f\n", volume);
    } else {
        printf("Entrada invalida!\n");
    }
    return 0;
}
