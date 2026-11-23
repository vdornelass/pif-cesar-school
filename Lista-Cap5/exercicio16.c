#include <stdio.h>

/*
 * Questao 16: Ano Bissexto
 * Funcao int ehBissexto(int ano) retornando 1 se for bissexto e 0 caso contrario.
 */

// Prototipo
int ehBissexto(int ano);

int main(void) {
    int ano;

    printf("=== VERIFICADOR DE ANO BISSEXTO MODULAR ===\n");
    printf("Digite o ano a ser verificado: ");
    if (scanf("%d", &ano) != 1 || ano <= 0) return 1;

    if (ehBissexto(ano)) {
        printf("O ano %d EH BISSEXTO (possui 366 dias).\n", ano);
    } else {
        printf("O ano %d NAO EH BISSEXTO (possui 365 dias).\n", ano);
    }

    return 0;
}

int ehBissexto(int ano) {
    return ((ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0)) ? 1 : 0;
}
