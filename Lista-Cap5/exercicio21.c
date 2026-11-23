#include <stdio.h>

/*
 * Questao 21: Macros Utilitarias
 * Definicao de SQR(x), MAX(a,b) e MIN(a,b) com parenteses de protecao.
 */

#define SQR(x) (((x)) * ((x)))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int main(void) {
    int x, y;

    printf("=== MACROS UTILITARIAS COM PROTECAO ===\n");
    printf("Digite dois numeros inteiros: ");
    if (scanf("%d %d", &x, &y) != 2) return 1;

    printf("\nResultados calculados via macro:\n");
    printf("Quadrado de %d: %d\n", x, SQR(x));
    printf("Quadrado de %d: %d\n", y, SQR(y));
    printf("Maior valor entre %d e %d: %d\n", x, y, MAX(x, y));
    printf("Menor valor entre %d e %d: %d\n", x, y, MIN(x, y));

    return 0;
}
