#include <stdio.h>

/*
 * Questao 09: Operacoes Aritmeticas Basicas e Cast de Tipos
 * Le dois inteiros e calcula soma, subtracao, multiplicacao e divisao real.
 * 
 * Tratamento de divisao por zero no escopo do Capitulo 2:
 * Como ainda nao utilizamos estruturas de selecao compostas (if/else complexos),
 * podemos utilizar o operador condicional ternario (? :) para verificar matematicamente
 * se o divisor eh diferente de zero antes da divisao, evitando erro em tempo de execucao.
 */

int main(void) {
    int a, b;
    printf("Digite o primeiro numero inteiro: ");
    if (scanf("%d", &a) != 1) return 1;
    printf("Digite o segundo numero inteiro: ");
    if (scanf("%d", &b) != 1) return 1;

    printf("Soma: %d\n", a + b);
    printf("Subtracao: %d\n", a - b);
    printf("Multiplicacao: %d\n", a * b);

    // Divisao real com cast explicito e verificacao ternaria de seguranca
    b != 0 
        ? printf("Divisao real: %.2f\n", (double)a / (double)b)
        : printf("Divisao real: Indefinida (divisao por zero)\n");

    return 0;
}
