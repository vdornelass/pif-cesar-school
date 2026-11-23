#include <stdio.h>

/*
 * Questao 09: Maior de Dois Numeros
 * Funcao int maior(int a, int b) que retorna o maior entre dois inteiros.
 */

// Prototipo
int maior(int a, int b);

int main(void) {
    int x, y, m;

    printf("=== MAIOR DE DOIS NUMEROS ===\n");
    printf("Digite dois numeros inteiros separados por espaco: ");
    if (scanf("%d %d", &x, &y) != 2) return 1;

    m = maior(x, y);

    printf("Entre %d e %d, o maior eh: %d\n", x, y, m);

    return 0;
}

int maior(int a, int b) {
    return (a > b) ? a : b;
}
