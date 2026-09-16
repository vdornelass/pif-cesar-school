#include <stdio.h>

/*
 * Questao 12: Operadores Unarios de Antecessor e Sucessor
 * Le um inteiro e exibe seu antecessor e sucessor utilizando exclusivamente
 * os operadores unarios de incremento (++) e decremento (--).
 * 
 * Justificativa logica:
 * Criamos copias da variavel informada e aplicamos os operadores unarios diretamente:
 * --antecessor subtrai 1 da variavel auxiliar, enquanto ++sucessor adiciona 1.
 */

int main(void) {
    int numero;
    printf("Digite um numero inteiro: ");
    if (scanf("%d", &numero) == 1) {
        int antecessor = numero;
        --antecessor; // Decremento unario prefixado

        int sucessor = numero;
        ++sucessor;   // Incremento unario prefixado

        printf("Numero informado: %d\n", numero);
        printf("Antecessor (--n): %d\n", antecessor);
        printf("Sucessor (++n):   %d\n", sucessor);
    } else {
        printf("Entrada invalida!\n");
    }
    return 0;
}
