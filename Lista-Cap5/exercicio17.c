#include <stdio.h>

/*
 * Questao 17: Fatorial Iterativo e Recursivo
 * Implementacao comparativa de fatorial com laco iterativo e recursao.
 */

// Prototipos
long fatorialIterativo(int n);
long fatorialRecursivo(int n);

int main(void) {
    int n;

    printf("=== FATORIAL: ITERATIVO VS RECURSIVO ===\n");
    printf("Digite um numero inteiro nao negativo: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Erro: Entrada invalida.\n");
        return 1;
    }

    long fat_it = fatorialIterativo(n);
    long fat_rec = fatorialRecursivo(n);

    printf("Fatorial Iterativo: %d! = %ld\n", n, fat_it);
    printf("Fatorial Recursivo: %d! = %ld\n", n, fat_rec);

    if (fat_it == fat_rec) {
        printf("Confirmacao: Ambos os metodos produziram exatamente o mesmo resultado!\n");
    }

    return 0;
}

long fatorialIterativo(int n) {
    long fat = 1L;
    for (int i = 2; i <= n; i++) {
        fat *= i;
    }
    return fat;
}

long fatorialRecursivo(int n) {
    // Caso Base
    if (n <= 1) {
        return 1L;
    }
    // Passo Recursivo
    return (long)n * fatorialRecursivo(n - 1);
}
