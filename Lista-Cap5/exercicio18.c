#include <stdio.h>

/*
 * Questao 18: Potencia com Recursao
 * Funcao recursiva long potencia(int base, int expoente) sem usar pow().
 */

// Prototipo
long potencia(int base, int expoente);

int main(void) {
    int base, exp;

    printf("=== EXPONENCIACAO RECURSIVA ===\n");
    printf("Digite a base (inteira): ");
    if (scanf("%d", &base) != 1) return 1;

    printf("Digite o expoente (inteiro nao negativo): ");
    if (scanf("%d", &exp) != 1) return 1;

    if (exp < 0) {
        printf("Erro: O expoente nao pode ser negativo nesta implementacao inteira.\n");
        return 1;
    }

    long resultado = potencia(base, exp);

    printf("Resultado: %d ^ %d = %ld\n", base, exp, resultado);

    return 0;
}

long potencia(int base, int expoente) {
    // Caso Base: qualquer numero elevado a zero eh 1
    if (expoente == 0) {
        return 1L;
    }
    // Passo Recursivo: base * potencia(base, expoente - 1)
    return (long)base * potencia(base, expoente - 1);
}
