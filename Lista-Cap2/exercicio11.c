#include <stdio.h>

/*
 * Questao 11: Conversor de Angulos de Graus para Radianos
 * Formula: radianos = graus * (Pi / 180.0)
 * Constante Pi = 3.141593
 */

#define PI 3.141593

int main(void) {
    double graus;
    printf("Digite o angulo em graus: ");
    if (scanf("%lf", &graus) == 1) {
        double radianos = graus * (PI / 180.0);
        printf("Angulo em radianos: %.6f rad\n", radianos);
    } else {
        printf("Entrada invalida!\n");
    }
    return 0;
}
