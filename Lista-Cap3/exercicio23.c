#include <stdio.h>

/*
 * Questao 23: Desenho de Moldura e Quadrado Vazado com Caracteres
 * Solicita a dimensao do lado L de um quadrado (com L entre 3 e 20).
 * Utiliza lacos aninhados para desenhar um quadrado vazado composto pelo caractere 'X'.
 */

int main(void) {
    int l;

    printf("Digite o tamanho do lado do quadrado L (entre 3 e 20): ");
    if (scanf("%d", &l) != 1 || l < 3 || l > 20) {
        printf("Valor invalido! O lado deve ser um inteiro entre 3 e 20.\n");
        return 1;
    }

    printf("\nQuadrado vazado de dimensao %d x %d:\n", l, l);
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            // Bordas superior, inferior, esquerda e direita
            if (i == 0 || i == l - 1 || j == 0 || j == l - 1) {
                putchar('X');
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }

    return 0;
}
