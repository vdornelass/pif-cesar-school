#include <stdio.h>

/*
 * Questao 24: Compilacao Condicional para Depuracao
 * Funcao int somaAteN(int n) com rastreamento via #ifdef DEBUG.
 *
 * Como compilar em modo de depuracao:
 * gcc -DDEBUG exercicio24.c -o exercicio24
 *
 * Como compilar em modo normal (producao):
 * gcc exercicio24.c -o exercicio24
 */

#define DEBUG // Habilitado por padrao para demonstracao

// Prototipo
int somaAteN(int n);

int main(void) {
    int n = 5;

    printf("=== SOMA ATE N COM COMPILACAO CONDICIONAL ===\n");
    printf("Calculando somatorio de 1 ate %d...\n\n", n);

    int total = somaAteN(n);

    printf("\nSomatorio final de 1 ate %d = %d\n", n, total);

    return 0;
}

int somaAteN(int n) {
    int soma = 0;
    for (int i = 1; i <= n; i++) {
        soma += i;
#ifdef DEBUG
        printf("[DEBUG]: Iteracao %d | Termo somado: %d | Soma parcial: %d\n", i, i, soma);
#endif
    }
    return soma;
}
