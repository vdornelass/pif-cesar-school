#include <stdio.h>

/*
 * Questao 14: Soma dos Digitos com Recursao
 * Funcao recursiva int somaDigitos(int n) para inteiros positivos.
 */

// Prototipo
int somaDigitos(int n);

int main(void) {
    int numero;

    printf("=== SOMA DOS DIGITOS (RECURSIVA) ===\n");
    printf("Digite um numero inteiro positivo: ");
    if (scanf("%d", &numero) != 1 || numero < 0) {
        printf("Erro: Digite um inteiro nao negativo.\n");
        return 1;
    }

    int soma = somaDigitos(numero);

    printf("A soma dos digitos de %d eh: %d\n", numero, soma);

    return 0;
}

int somaDigitos(int n) {
    // Caso Base: quando resta apenas um digito (0 a 9)
    if (n < 10) {
        return n;
    }

    // Passo Recursivo: separa o ultimo digito (n % 10) e soma com a chamada recursiva do restante (n / 10)
    return (n % 10) + somaDigitos(n / 10);
}
