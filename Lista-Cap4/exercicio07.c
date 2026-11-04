#include <stdio.h>
#include <math.h>

/*
 * Questao 07: Raiz Quadrada ou Quadrado de um Numero Real
 * Le um numero real. Se positivo ou nulo, calcula e imprime sqrt(x).
 * Se negativo, calcula e imprime x^2.
 */

int main(void) {
    double numero, resultado;

    printf("=== CALCULO: RAIZ QUADRADA OU QUADRADO ===\n");
    printf("Digite um numero real: ");
    if (scanf("%lf", &numero) != 1) {
        printf("Erro: Entrada invalida.\n");
        return 1;
    }

    if (numero >= 0.0) {
        resultado = sqrt(numero);
        printf("Numero nao-negativo (%.4f):\n", numero);
        printf("Raiz quadrada = %.4f\n", resultado);
    } else {
        resultado = numero * numero;
        printf("Numero negativo (%.4f):\n", numero);
        printf("Quadrado = %.4f\n", resultado);
    }

    return 0;
}
