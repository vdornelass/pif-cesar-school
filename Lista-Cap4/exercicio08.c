#include <stdio.h>

/*
 * Questao 08: Verificacao de Ano Bissexto
 * Solicita um ano inteiro positivo e determina se eh bissexto.
 * Regra do Calendario Gregoriano:
 * Divisivel por 400 OU (Divisivel por 4 E NAO divisivel por 100).
 */

int main(void) {
    int ano;

    printf("=== VERIFICADOR DE ANO BISSEXTO ===\n");
    printf("Digite um ano (inteiro positivo): ");
    if (scanf("%d", &ano) != 1 || ano <= 0) {
        printf("Erro: Forneca um ano positivo valido.\n");
        return 1;
    }

    if ((ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0)) {
        printf("O ano %d EH BISSEXTO (possui 366 dias, com 29 de fevereiro).\n", ano);
    } else {
        printf("O ano %d NAO EH BISSEXTO (possui 365 dias, com 28 de fevereiro).\n", ano);
    }

    return 0;
}
