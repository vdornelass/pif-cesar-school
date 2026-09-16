#include <stdio.h>

/*
 * Questao 03: Formatacao de Saida em Bases Numericas e ASCII
 * Le um numero inteiro e exibe simultaneamente em decimal (%d),
 * hexadecimal em caixa baixa (%x), octal (%o) e o caractere ASCII (%c).
 */

int main(void) {
    int valor;
    printf("Digite um numero inteiro: ");
    if (scanf("%d", &valor) == 1) {
        printf("Decimal: %d | Hexadecimal: %x | Octal: %o | ASCII: %c\n",
               valor, valor, valor, (char)valor);
    } else {
        printf("Entrada invalida!\n");
    }
    return 0;
}
