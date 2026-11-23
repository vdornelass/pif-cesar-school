#include <stdio.h>

/*
 * Questao 11: Verificacao de Numero Par
 * Funcao int ehPar(int n) que retorna 1 se for par e 0 caso contrario.
 */

// Prototipo
int ehPar(int n);

int main(void) {
    int num;

    printf("=== VERIFICADOR DE PARIDADE ===\n");
    printf("Digite um numero inteiro: ");
    if (scanf("%d", &num) != 1) return 1;

    if (ehPar(num)) {
        printf("O numero %d eh PAR.\n", num);
    } else {
        printf("O numero %d eh IMPAR.\n", num);
    }

    return 0;
}

int ehPar(int n) {
    return (n % 2 == 0) ? 1 : 0;
}
