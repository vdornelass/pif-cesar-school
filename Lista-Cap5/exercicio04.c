#include <stdio.h>

/*
 * Questao 04: Recursao: Caso Base, Passo Recursivo e Pilha de Execucao
 * Rastreamento e calculo de fatorial recursivo.
 */

// Prototipo
long fatorial(int n);

int main(void) {
    int valor = 4;

    printf("=== QUESTAO 04: FATORIAL RECURSIVO ===\n");
    printf("Calculando fatorial(%d)...\n\n", valor);

    long resultado = fatorial(valor);

    printf("Resultado final: %d! = %ld\n", valor, resultado);

    return 0;
}

long fatorial(int n) {
    // Caso Base: n == 0 retorna 1 (condicao de parada da recursao)
    // Passo Recursivo: n * fatorial(n - 1)
    if (n == 0) {
        printf("-> Atingiu o Caso Base: fatorial(0) = 1 (inicio do desempilhamento)\n");
        return 1L;
    }

    printf("-> Empilhando chamada: fatorial(%d), aguardando fatorial(%d)...\n", n, n - 1);
    long res_parcial = (long)n * fatorial(n - 1);
    printf("<- Desempilhando chamada: fatorial(%d) = %ld\n", n, res_parcial);

    return res_parcial;
}
