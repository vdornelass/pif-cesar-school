#include <stdio.h>

/*
 * Questao 28: Caixa Simples de Mercadinho
 * Modularizacao do checkout de loja com tres funcoes dedicadas.
 */

// Prototipos
float calculaSubtotal(float preco, int quantidade);
float aplicaDesconto(float valor, int opcaoPagamento);
float calculaTroco(float total, float pago);

int main(void) {
    float preco, valor_pago;
    int qtd, forma_pagto;

    printf("=== CAIXA DE MERCADINHO MODULAR ===\n");
    printf("Digite o preco unitario do produto (R$): ");
    if (scanf("%f", &preco) != 1 || preco <= 0.0f) return 1;

    printf("Digite a quantidade comprada: ");
    if (scanf("%d", &qtd) != 1 || qtd <= 0) return 1;

    printf("\nFormas de Pagamento:\n");
    printf("1 - A Vista (com 10%% de desconto)\n");
    printf("2 - A Prazo / Cartao (sem desconto)\n");
    printf("Escolha a forma (1 ou 2): ");
    if (scanf("%d", &forma_pagto) != 1) return 1;

    float subtotal = calculaSubtotal(preco, qtd);
    float total_pagar = aplicaDesconto(subtotal, forma_pagto);

    printf("\nSubtotal: R$ %.2f\n", subtotal);
    printf("Total a Pagar: R$ %.2f\n", total_pagar);

    printf("Digite o valor entregue pelo cliente (R$): ");
    if (scanf("%f", &valor_pago) != 1) return 1;

    if (valor_pago < total_pagar) {
        printf("Erro: Valor entregue (R$ %.2f) insuficiente para quitar R$ %.2f!\n", valor_pago, total_pagar);
        return 1;
    }

    float troco = calculaTroco(total_pagar, valor_pago);
    printf("Troco a devolver: R$ %.2f\n", troco);

    return 0;
}

float calculaSubtotal(float preco, int quantidade) {
    return preco * (float)quantidade;
}

float aplicaDesconto(float valor, int opcaoPagamento) {
    if (opcaoPagamento == 1) {
        return valor * 0.90f; // 10% de desconto a vista
    }
    return valor; // Sem desconto
}

float calculaTroco(float total, float pago) {
    return pago - total;
}
