#include <stdio.h>

/*
 * Questao 07: Soma de Dois Inteiros
 * Funcao com prototipo que retorna a soma de dois numeros inteiros.
 */

// Prototipo
int soma(int a, int b);

int main(void) {
    int n1, n2, resultado;

    printf("=== SOMA DE DOIS INTEIROS ===\n");
    printf("Digite o primeiro numero inteiro: ");
    if (scanf("%d", &n1) != 1) return 1;

    printf("Digite o segundo numero inteiro: ");
    if (scanf("%d", &n2) != 1) return 1;

    resultado = soma(n1, n2);

    printf("Resultado: %d + %d = %d\n", n1, n2, resultado);

    return 0;
}

int soma(int a, int b) {
    return a + b;
}
