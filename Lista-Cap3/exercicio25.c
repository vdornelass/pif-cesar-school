#include <stdio.h>

/*
 * Questao 25: Analise e Teste de Primalidade de um Numero Inteiro
 * Le um inteiro positivo N e verifica se eh primo contando os divisores
 * no intervalo de 1 a N. Exibe a quantidade de divisores e a conclusao.
 */

int main(void) {
    int n;

    printf("Digite um numero inteiro positivo: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Valor invalido! Por favor informe um inteiro positivo maior que zero.\n");
        return 1;
    }

    int divisores = 0;

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            divisores++;
        }
    }

    printf("\nO numero %d possui %d divisor(es).\n", n, divisores);

    if (n > 1 && divisores == 2) {
        printf("Conclusao: %d EH um numero primo!\n", n);
    } else {
        printf("Conclusao: %d NAO eh um numero primo.\n", n);
    }

    return 0;
}
