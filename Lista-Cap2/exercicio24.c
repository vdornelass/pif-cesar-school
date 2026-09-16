#include <stdio.h>

/*
 * Questao 24: Conversor de Velocidade de km/h para m/s
 * Formula fisica: m/s = km/h / 3.6
 */

#define FATOR_CONVERSAO 3.6

int main(void) {
    double kmh;
    printf("Digite a velocidade em km/h: ");
    if (scanf("%lf", &kmh) == 1) {
        double ms = kmh / FATOR_CONVERSAO;
        printf("Velocidade convertida: %.2f m/s\n", ms);
    } else {
        printf("Entrada invalida!\n");
    }
    return 0;
}
