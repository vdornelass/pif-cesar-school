#include <stdio.h>

/*
 * Questao 15: Geracao de Padroes Visuais com Lacos Aninhados: Triangulo de Floyd
 * Le um numero inteiro positivo N e imprime N linhas do Triangulo de Floyd.
 * Exemplo para N = 5:
 * 1
 * 2 3
 * 4 5 6
 * 7 8 9 10
 * 11 12 13 14 15
 */

int main(void) {
    int n;

    printf("Digite o numero de linhas do Triangulo de Floyd (N > 0): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Valor invalido! N deve ser um inteiro estritamente positivo.\n");
        return 1;
    }

    int contador = 1;

    printf("\nTriangulo de Floyd com %d linhas:\n", n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d", contador++);
            if (j < i) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
