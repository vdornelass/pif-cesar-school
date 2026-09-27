#include <stdio.h>

#define VALOR_DIARIA 45.00
#define TAXA_GRATIFICACAO 0.05
#define TAXA_IMPOSTO 0.08

/*
 * Questao 11: Calculo Salarial com Gratificacao e Impostos
 * Solicita o numero de dias trabalhados de um tecnico (R$ 45,00/dia),
 * calcula o salario bruto, gratificacao (+5%) e imposto retido (-8%)
 * e exibe o holerite detalhado com o salario liquido final.
 */

int main(void) {
    int dias;

    printf("Informe a quantidade de dias trabalhados: ");
    if (scanf("%d", &dias) != 1 || dias < 0) {
        printf("Valor invalido para dias trabalhados!\n");
        return 1;
    }

    double salario_bruto = dias * VALOR_DIARIA;
    double gratificacao = salario_bruto * TAXA_GRATIFICACAO;
    double imposto_renda = salario_bruto * TAXA_IMPOSTO;
    double salario_liquido = salario_bruto + gratificacao - imposto_renda;

    printf("\n=========================================\n");
    printf("           HOLERITE DE PAGAMENTO         \n");
    printf("=========================================\n");
    printf("Dias trabalhados:        %d\n", dias);
    printf("Valor da diaria:         R$ %8.2f\n", VALOR_DIARIA);
    printf("-----------------------------------------\n");
    printf("Salario Bruto:           R$ %8.2f\n", salario_bruto);
    printf("(+) Gratificacao (5%%):    R$ %8.2f\n", gratificacao);
    printf("(-) Imposto Renda (8%%):   R$ %8.2f\n", imposto_renda);
    printf("-----------------------------------------\n");
    printf("Salario Liquido a Receber: R$ %8.2f\n", salario_liquido);
    printf("=========================================\n");

    return 0;
}
