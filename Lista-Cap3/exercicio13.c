#include <stdio.h>

/*
 * Questao 13: Calculo de Fatorial com Tratamento de Casos Especiais
 * Le um inteiro N e calcula N! utilizando o tipo 'long long int'.
 * Trata os casos especiais 0! = 1, 1! = 1 e emite erro para numeros negativos.
 */

int main(void) {
    int n;

    printf("Digite um numero inteiro nao-negativo para calcular o fatorial: ");
    if (scanf("%d", &n) != 1) {
        printf("Entrada invalida!\n");
        return 1;
    }

    if (n < 0) {
        printf("Erro: Fatorial nao eh definido para numeros negativos!\n");
        return 1;
    }

    long long int fatorial = 1;
    for (int i = 2; i <= n; i++) {
        fatorial *= i;
    }

    printf("%d! = %lld\n", n, fatorial);
    return 0;
}
