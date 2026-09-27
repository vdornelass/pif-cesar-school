#include <stdio.h>

/*
 * Questao 05: Operador Virgula e Multiplas Variaveis de Controle
 * Executa o laco original com o operador virgula no cabecalho do for
 * e apresenta a reescrita equivalente obrigatoria utilizando a estrutura while.
 */

int main(void) {
    int i, j;

    printf("--- Execucao do laco for original (com operador virgula) ---\n");
    for (i = 0, j = 10; i < j; i++, j--) {
        printf("i = %d, j = %d | soma = %d\n", i, j, i + j);
    }

    printf("\n--- Execucao da versao reescrita utilizando while ---\n");
    i = 0;
    j = 10;
    while (i < j) {
        printf("i = %d, j = %d | soma = %d\n", i, j, i + j);
        i++;
        j--;
    }

    return 0;
}
