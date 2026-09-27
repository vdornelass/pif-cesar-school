#include <stdio.h>

/*
 * Questao 24: Padrao Visual em X (Diagonais Cruzadas)
 * Solicita uma dimensao impar N (entre 3 e 19).
 * Utiliza lacos aninhados e condicionais logicas para desenhar um 'X' com '*'.
 * Condicao para '*': diagonal principal (i == j) ou diagonal secundaria (i + j == N - 1).
 */

int main(void) {
    int n;

    printf("Digite uma dimensao impar N (entre 3 e 19): ");
    if (scanf("%d", &n) != 1 || n < 3 || n > 19 || n % 2 == 0) {
        printf("Valor invalido! N deve ser um inteiro IMPAR entre 3 e 19.\n");
        return 1;
    }

    printf("\nPadrao visual em 'X' para N = %d:\n", n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || i + j == n - 1) {
                putchar('*');
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }

    return 0;
}
