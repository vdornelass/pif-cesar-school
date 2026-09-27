#include <stdio.h>

/*
 * Questao 13: Calculo do Fatorial com Tratamento do Zero e Tipo long long int
 * Le um inteiro N e calcula N! utilizando a variavel acumuladora como 'long long int'
 * formatada com '%lld'. Trata entradas invalidas (numeros negativos) e os casos 0! = 1 e 1! = 1.
 */

int main(void) {
    int n;

    printf("Digite um numero inteiro nao-negativo (N >= 0): ");
    if (scanf("%d", &n) != 1) {
        printf("Erro: Entrada invalida!\n");
        return 1;
    }

    if (n < 0) {
        printf("Erro: Fatorial nao eh definido para numeros negativos (%d < 0)!\n", n);
        return 1;
    }

    long long int fatorial = 1;

    for (int i = 2; i <= n; i++) {
        fatorial *= i;
    }

    printf("\nResultado: %d! = %lld\n", n, fatorial);
    return 0;
}
