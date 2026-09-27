#include <stdio.h>

/*
 * Questao 27: Simulador de Caixa Eletronico (Decomposicao de Cedulas)
 * Simula o saque de um caixa eletronico informando a menor quantidade de cedulas
 * de R$ 100, R$ 50, R$ 20, R$ 10, R$ 5 e R$ 2 para compor o valor.
 * Utiliza lacos de repeticao (while) para efetuar as subtracoes sucessivas.
 */

int main(void) {
    int valor, valor_original;
    int c100 = 0, c50 = 0, c20 = 0, c10 = 0, c5 = 0, c2 = 0;

    printf("Digite o valor do saque em reais (R$): ");
    if (scanf("%d", &valor) != 1 || valor <= 0) {
        printf("Valor invalido! O saque deve ser um numero inteiro positivo.\n");
        return 1;
    }

    if (valor == 1 || valor == 3) {
        printf("Nao eh possivel sacar o valor de R$ %d com as cedulas disponiveis (R$ 100, 50, 20, 10, 5, 2).\n", valor);
        return 1;
    }

    valor_original = valor;

    // Se o valor for impar, necessitamos de pelo menos uma cedula de R$ 5
    // para que a quantia restante se torne par e possa ser sacada com cedulas de R$ 2
    if (valor % 2 != 0) {
        c5++;
        valor -= 5;
    }

    // Subtracoes sucessivas com laco while conforme solicitado pelo enunciado
    while (valor >= 100) {
        valor -= 100;
        c100++;
    }

    while (valor >= 50) {
        valor -= 50;
        c50++;
    }

    while (valor >= 20) {
        valor -= 20;
        c20++;
    }

    while (valor >= 10) {
        valor -= 10;
        c10++;
    }

    while (valor >= 2) {
        valor -= 2;
        c2++;
    }

    printf("\n=== Decomposicao do Saque de R$ %d ===\n", valor_original);
    if (c100 > 0) printf("Cedulas de R$ 100: %d\n", c100);
    if (c50 > 0)  printf("Cedulas de R$ 50:  %d\n", c50);
    if (c20 > 0)  printf("Cedulas de R$ 20:  %d\n", c20);
    if (c10 > 0)  printf("Cedulas de R$ 10:  %d\n", c10);
    if (c5 > 0)   printf("Cedulas de R$ 5:   %d\n", c5);
    if (c2 > 0)   printf("Cedulas de R$ 2:   %d\n", c2);

    return 0;
}
