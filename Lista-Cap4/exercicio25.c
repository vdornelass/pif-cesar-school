#include <stdio.h>

/*
 * Questao 25: Decomposicao de Troco na Menor Quantidade de Cedulas
 * Cedulas disponiveis: R$ 100, 50, 20, 10, 5 e 2.
 */

int main(void) {
    int total_pagar, valor_entregue, troco, restante;
    int c100 = 0, c50 = 0, c20 = 0, c10 = 0, c5 = 0, c2 = 0, m1 = 0;

    printf("=== DECOMPOSICAO DE TROCO EM CEDULAS ===\n");
    printf("Digite o valor total a pagar (R$): ");
    if (scanf("%d", &total_pagar) != 1 || total_pagar <= 0) return 1;

    printf("Digite o valor entregue pelo cliente (R$): ");
    if (scanf("%d", &valor_entregue) != 1) return 1;

    if (valor_entregue < total_pagar) {
        printf("Erro: Valor entregue (R$ %d) eh insuficiente para pagar R$ %d!\n", valor_entregue, total_pagar);
        return 1;
    }

    troco = valor_entregue - total_pagar;
    printf("\nTroco total devido = R$ %d\n", troco);

    if (troco == 0) {
        printf("Pagamento exato, nao ha troco.\n");
        return 0;
    }

    restante = troco;

    c100 = restante / 100; restante %= 100;
    c50  = restante / 50;  restante %= 50;
    c20  = restante / 20;  restante %= 20;
    c10  = restante / 10;  restante %= 10;
    c5   = restante / 5;   restante %= 5;
    c2   = restante / 2;   restante %= 2;
    m1   = restante;

    printf("Menor quantidade de cedulas/moedas:\n");
    if (c100 > 0) printf("- %d cedula(s) de R$ 100\n", c100);
    if (c50 > 0)  printf("- %d cedula(s) de R$ 50\n", c50);
    if (c20 > 0)  printf("- %d cedula(s) de R$ 20\n", c20);
    if (c10 > 0)  printf("- %d cedula(s) de R$ 10\n", c10);
    if (c5 > 0)   printf("- %d cedula(s) de R$ 5\n", c5);
    if (c2 > 0)   printf("- %d cedula(s) de R$ 2\n", c2);
    if (m1 > 0)   printf("- %d moeda(s) de R$ 1\n", m1);

    return 0;
}
