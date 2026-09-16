#include <stdio.h>

/*
 * Questao 19: Calculo de Salario Liquido com Desconto na Fonte
 * Taxa diaria fixa: R$ 30,00 por dia util.
 * Desconto de IR na fonte: 8% sobre o total bruto.
 */

#define DIARIA 30.00
#define IMPOSTO_ALIQUOTA 0.08

int main(void) {
    int dias;
    printf("Digite o numero de dias uteis trabalhados: ");
    if (scanf("%d", &dias) == 1) {
        double bruto = dias * DIARIA;
        double desconto = bruto * IMPOSTO_ALIQUOTA;
        double liquido = bruto - desconto;

        printf("Quantia bruta devida: R$ %.2f\n", bruto);
        printf("Desconto de IR (8%%):   R$ %.2f\n", desconto);
        printf("Valor liquido final:   R$ %.2f\n", liquido);
    } else {
        printf("Entrada invalida!\n");
    }
    return 0;
}
