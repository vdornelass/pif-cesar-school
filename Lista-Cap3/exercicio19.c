#include <stdio.h>

/*
 * Questao 19: Calculo do N-esimo Termo da Sequencia de Fibonacci
 * Solicita a posicao N desejada, lista todos os termos da sequencia
 * de Fibonacci ate N e exibe o valor do N-esimo termo.
 * Sequencia: 1, 1, 2, 3, 5, 8, 13, 21, ...
 */

int main(void) {
    int n;

    printf("Digite o numero do termo desejado (N >= 1): ");
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Valor invalido! N deve ser um inteiro maior ou igual a 1.\n");
        return 1;
    }

    long long int t1 = 1, t2 = 1, proximo;

    printf("\nSequencia de Fibonacci ate o termo %d:\n", n);

    if (n == 1) {
        printf("Termo 1: %lld\n", t1);
        printf("\nO 1-esimo termo da sequencia de Fibonacci eh: %lld\n", t1);
    } else if (n == 2) {
        printf("Termo 1: %lld\n", t1);
        printf("Termo 2: %lld\n", t2);
        printf("\nO 2-esimo termo da sequencia de Fibonacci eh: %lld\n", t2);
    } else {
        printf("Termo 1: %lld\n", t1);
        printf("Termo 2: %lld\n", t2);

        for (int i = 3; i <= n; i++) {
            proximo = t1 + t2;
            printf("Termo %d: %lld\n", i, proximo);
            t1 = t2;
            t2 = proximo;
        }

        printf("\nO %d-esimo termo da sequencia de Fibonacci eh: %lld\n", n, t2);
    }

    return 0;
}
