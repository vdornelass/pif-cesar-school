#include <stdio.h>

/*
 * Questao 26: Sequencia de Fibonacci Recursiva
 * Funcao recursiva long fibonacci(int n) e explicacao de desempenho.
 */

// Prototipo
long fibonacci(int n);

int main(void) {
    int termos;

    printf("=== SEQUENCIA DE FIBONACCI RECURSIVA ===\n");
    printf("Digite a quantidade de termos a exibir: ");
    if (scanf("%d", &termos) != 1 || termos <= 0) {
        printf("Erro: Forneca um numero inteiro positivo.\n");
        return 1;
    }

    printf("\nTermos da Sequencia de Fibonacci:\n");
    for (int i = 0; i < termos; i++) {
        printf("F(%d) = %ld\n", i, fibonacci(i));
    }

    // Nota de desempenho: A versao recursiva possui complexidade O(2^n).
    // Para valores de n > 40, o tempo de processamento torna-se excessivamente
    // elevado devido a chamadas duplicadas repetidas (arvore de recursao binaria).

    return 0;
}

long fibonacci(int n) {
    // Casos Base
    if (n == 0) return 0L;
    if (n == 1) return 1L;

    // Passo Recursivo
    return fibonacci(n - 1) + fibonacci(n - 2);
}
