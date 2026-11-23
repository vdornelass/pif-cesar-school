#include <stdio.h>

/*
 * Questao 27: Conversor de Temperaturas Modular
 * Funcoes float para conversao entre Celsius, Fahrenheit e Kelvin.
 */

// Prototipos
float celsiusParaFahrenheit(float c);
float celsiusParaKelvin(float c);
float fahrenheitParaCelsius(float f);
float kelvinParaCelsius(float k);

int main(void) {
    int opcao;
    float temp, resultado;

    printf("=== CONVERSOR DE TEMPERATURAS MODULAR ===\n");
    printf("1 - Celsius para Fahrenheit\n");
    printf("2 - Celsius para Kelvin\n");
    printf("3 - Fahrenheit para Celsius\n");
    printf("4 - Kelvin para Celsius\n");
    printf("Escolha a opcao (1-4): ");
    if (scanf("%d", &opcao) != 1 || opcao < 1 || opcao > 4) {
        printf("Erro: Opcao invalida.\n");
        return 1;
    }

    printf("Digite o valor da temperatura: ");
    if (scanf("%f", &temp) != 1) return 1;

    switch (opcao) {
        case 1:
            resultado = celsiusParaFahrenheit(temp);
            printf("%.2f C = %.2f F\n", temp, resultado);
            break;
        case 2:
            resultado = celsiusParaKelvin(temp);
            printf("%.2f C = %.2f K\n", temp, resultado);
            break;
        case 3:
            resultado = fahrenheitParaCelsius(temp);
            printf("%.2f F = %.2f C\n", temp, resultado);
            break;
        case 4:
            resultado = kelvinParaCelsius(temp);
            printf("%.2f K = %.2f C\n", temp, resultado);
            break;
    }

    return 0;
}

float celsiusParaFahrenheit(float c) {
    return (c * 1.8f) + 32.0f;
}

float celsiusParaKelvin(float c) {
    return c + 273.15f;
}

float fahrenheitParaCelsius(float f) {
    return (f - 32.0f) / 1.8f;
}

float kelvinParaCelsius(float k) {
    return k - 273.15f;
}
