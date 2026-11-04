#include <stdio.h>

/*
 * Questao 17: Calculo de Pagamento e Comissao de Vendas
 * Opcoes:
 * 1 = A Vista com 10% de desconto
 * 2 = Parcelado em 3x sem juros
 * Comissao:
 * 5% sobre valor com desconto (a vista) ou 5% sobre o valor total (parcelado).
 */

int main(void) {
    double valor_total;
    int opcao;
    double valor_final, parcela, comissao;

    printf("=== PAGAMENTO E COMISSAO DE VENDAS ===\n");
    printf("Digite o valor total da compra: R$ ");
    if (scanf("%lf", &valor_total) != 1 || valor_total <= 0.0) return 1;

    printf("\nOpcoes de Pagamento:\n");
    printf("1 - A Vista (10%% de desconto)\n");
    printf("2 - Parcelado em 3x sem juros\n");
    printf("Escolha a opcao: ");
    if (scanf("%d", &opcao) != 1) return 1;

    if (opcao == 1) {
        valor_final = valor_total * 0.90;
        comissao = valor_final * 0.05;
        printf("\n[PAGAMENTO A VISTA]\n");
        printf("Valor original: R$ %.2f\n", valor_total);
        printf("Desconto (10%%): R$ %.2f\n", valor_total * 0.10);
        printf("Total a pagar: R$ %.2f\n", valor_final);
        printf("Comissao do vendedor (5%% sobre valor a vista): R$ %.2f\n", comissao);
    } else if (opcao == 2) {
        parcela = valor_total / 3.0;
        comissao = valor_total * 0.05;
        printf("\n[PAGAMENTO PARCELADO EM 3X]\n");
        printf("Total a pagar: R$ %.2f\n", valor_total);
        printf("Valor de cada parcela (3x): R$ %.2f\n", parcela);
        printf("Comissao do vendedor (5%% sobre total): R$ %.2f\n", comissao);
    } else {
        printf("Erro: Opcao de pagamento invalida.\n");
    }

    return 0;
}
