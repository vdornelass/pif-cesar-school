#include <stdio.h>

/*
 * Questao 25: Salario Liquido com Gratificacao e Tributacao
 * Gratificacao: +5% sobre o salario-base
 * Imposto retido: 7% sobre o salario-base
 * 
 * Justificativa da formula:
 * Salario_Liquido = Base + (Base * 0.05) - (Base * 0.07)
 *                 = Base * (1.0 + 0.05 - 0.07)
 *                 = Base * 0.98
 */

int main(void) {
    double salario_base;
    printf("Digite o salario-base do funcionario: R$ ");
    if (scanf("%lf", &salario_base) == 1) {
        double gratificacao = salario_base * 0.05;
        double imposto = salario_base * 0.07;
        double salario_liquido = salario_base + gratificacao - imposto;

        printf("\n--- Resumo Salarial ---\n");
        printf("Salario-Base:    R$ %.2f\n", salario_base);
        printf("Gratificacao (+5%%): R$ %.2f\n", gratificacao);
        printf("Imposto Retido (-7%%): R$ %.2f\n", imposto);
        printf("Salario Liquido a Receber: R$ %.2f\n", salario_liquido);
    } else {
        printf("Entrada invalida!\n");
    }
    return 0;
}
