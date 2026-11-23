#include <stdio.h>

/*
 * Questao 08: Conversor de Fahrenheit para Celsius
 * Funcao com prototipo que converte temperatura em F para C.
 */

// Prototipo
float celsius(float fahr);

int main(void) {
    float f, c;

    printf("=== CONVERSOR FAHRENHEIT PARA CELSIUS ===\n");
    printf("Digite a temperatura em graus Fahrenheit: ");
    if (scanf("%f", &f) != 1) return 1;

    c = celsius(f);

    printf("Temperatura equivalente: %.2f F = %.2f C\n", f, c);

    return 0;
}

float celsius(float fahr) {
    return (fahr - 32.0f) * 5.0f / 9.0f;
}
