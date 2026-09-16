#include <stdio.h>

/*
 * Questao 28: Calculo de Salario Anual com Imposto Progressivo
 * Hora normal: R$ 10,00
 * Hora extra: R$ 15,00
 * Isento ate R$ 12.000,00 anuais; 10% sobre o excedente.
 * Utiliza o operador ternario (? :) para calculo direto do imposto.
 */

#define HORA_NORMAL 10.00
#define HORA_EXTRA  15.00
#define ISENCAO     12000.00
#define ALIQUOTA    0.10

int main(void) {
    double horas_normais, horas_extras;

    printf("Digite o total de horas normais trabalhadas no ano: ");
    if (scanf("%lf", &horas_normais) != 1) return 1;

    printf("Digite o total de horas extras trabalhadas no ano: ");
    if (scanf("%lf", &horas_extras) != 1) return 1;

    double salario_bruto = (horas_normais * HORA_NORMAL) + (horas_extras * HORA_EXTRA);

    // Operador ternario: aplica 10% apenas se salario_bruto > 12000.00
    double imposto = (salario_bruto > ISENCAO) ? (salario_bruto - ISENCAO) * ALIQUOTA : 0.0;
    double salario_liquido = salario_bruto - imposto;

    printf("\n--- Demonstrativo Anual ---\n");
    printf("a) Salario Anual Bruto: R$ %.2f\n", salario_bruto);
    printf("b) Imposto Progressivo Devido: R$ %.2f\n", imposto);
    printf("   Salario Anual Liquido: R$ %.2f\n", salario_liquido);

    return 0;
}
