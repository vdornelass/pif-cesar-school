#include <stdio.h>

/*
 * Questao 12: Tabela de Conversao de Temperaturas (Celsius, Fahrenheit e Kelvin)
 * Imprime uma tabela de conversao de 0°C a 100°C, de 5 em 5 graus Celsius,
 * exibindo os valores equivalentes em Fahrenheit (F = (9*C)/5 + 32)
 * e Kelvin (K = C + 273.15) alinhados com duas casas decimais.
 */

int main(void) {
    printf("+------------+--------------+------------+\n");
    printf("| Celsius    | Fahrenheit   | Kelvin     |\n");
    printf("+------------+--------------+------------+\n");

    for (int c = 0; c <= 100; c += 5) {
        double f = (9.0 * c) / 5.0 + 32.0;
        double k = c + 273.15;
        printf("| %8.2f C | %10.2f F | %8.2f K |\n", (double)c, f, k);
    }

    printf("+------------+--------------+------------+\n");
    return 0;
}
