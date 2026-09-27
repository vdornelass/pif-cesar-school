#include <stdio.h>

/*
 * Questao 18: Inversao de Digitos de um Numero Inteiro (Algoritmo Numerico)
 * Le um inteiro positivo e constroi um novo numero inteiro com seus digitos invertidos,
 * utilizando operacoes aritmeticas de resto (%) e divisao inteira (/).
 */

int main(void) {
    long long int num, original;
    long long int invertido = 0;

    printf("Digite um numero inteiro positivo: ");
    if (scanf("%lld", &num) != 1 || num <= 0) {
        printf("Valor invalido! Por favor forneca um inteiro positivo.\n");
        return 1;
    }

    original = num;

    while (num > 0) {
        int digito = num % 10;
        invertido = (invertido * 10) + digito;
        num /= 10;
    }

    printf("Numero original: %lld\n", original);
    printf("Numero invertido: %lld\n", invertido);

    return 0;
}
