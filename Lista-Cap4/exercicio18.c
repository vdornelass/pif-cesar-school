#include <stdio.h>

/*
 * Questao 18: Conversor Multidirecional de Escalas Termometricas
 * Menu:
 * 1. Celsius para Fahrenheit: F = C * 1.8 + 32
 * 2. Celsius para Kelvin: K = C + 273.15
 * 3. Fahrenheit para Celsius: C = (F - 32) / 1.8
 * 4. Kelvin para Celsius: C = K - 273.15
 */

int main(void) {
    int opcao;
    double temp_in, temp_out;

    printf("=== CONVERSOR DE ESCALAS TERMOMETRICAS ===\n");
    printf("1. Celsius -> Fahrenheit\n");
    printf("2. Celsius -> Kelvin\n");
    printf("3. Fahrenheit -> Celsius\n");
    printf("4. Kelvin -> Celsius\n");
    printf("Selecione a opcao (1 a 4): ");
    if (scanf("%d", &opcao) != 1) return 1;

    switch (opcao) {
        case 1:
            printf("Digite a temperatura em Celsius: ");
            scanf("%lf", &temp_in);
            temp_out = temp_in * 1.8 + 32.0;
            printf("%.2f C = %.2f F\n", temp_in, temp_out);
            break;
        case 2:
            printf("Digite a temperatura em Celsius: ");
            scanf("%lf", &temp_in);
            temp_out = temp_in + 273.15;
            printf("%.2f C = %.2f K\n", temp_in, temp_out);
            break;
        case 3:
            printf("Digite a temperatura em Fahrenheit: ");
            scanf("%lf", &temp_in);
            temp_out = (temp_in - 32.0) / 1.8;
            printf("%.2f F = %.2f C\n", temp_in, temp_out);
            break;
        case 4:
            printf("Digite a temperatura em Kelvin: ");
            scanf("%lf", &temp_in);
            temp_out = temp_in - 273.15;
            printf("%.2f K = %.2f C\n", temp_in, temp_out);
            break;
        default:
            printf("Erro: Opcao invalida!\n");
            break;
    }

    return 0;
}
