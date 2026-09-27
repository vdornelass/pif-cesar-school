#include <stdio.h>

/*
 * Questao 15: Filtragem Numerica Simultanea com Operadores Logicos
 * Solicita um numero limite inteiro positivo NUM e imprime todos os numeros
 * no intervalo fechado [1, NUM] que sejam multiplos de 3 e de 5 simultaneamente.
 * Caso nenhum numero atenda a condicao, informa o usuario.
 */

int main(void) {
    int num;

    printf("Digite um numero limite inteiro positivo (NUM): ");
    if (scanf("%d", &num) != 1 || num <= 0) {
        printf("Valor invalido! Por favor forneca um inteiro positivo maior que zero.\n");
        return 1;
    }

    int encontrados = 0;
    printf("\nMultiplos simultaneos de 3 e 5 no intervalo [1, %d]:\n", num);

    for (int i = 1; i <= num; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            printf("%d ", i);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhum numero no intervalo satisfaz a condicao.\n");
    } else {
        printf("\nTotal de multiplos encontrados: %d\n", encontrados);
    }

    return 0;
}
