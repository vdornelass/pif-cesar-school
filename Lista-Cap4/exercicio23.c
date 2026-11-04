#include <stdio.h>

/*
 * Questao 23: Impressao de Data Por Extenso com switch-case
 * Le Dia, Mes e Ano. Valida mes em [1, 12] e converte nome por extenso.
 */

int main(void) {
    int dia, mes, ano;
    const char *nome_mes = NULL;

    printf("=== DATA POR EXTENSO ===\n");
    printf("Digite o Dia, Mes e Ano separados por espaco (ex: 25 12 2026): ");
    if (scanf("%d %d %d", &dia, &mes, &ano) != 3) return 1;

    switch (mes) {
        case 1:  nome_mes = "janeiro"; break;
        case 2:  nome_mes = "fevereiro"; break;
        case 3:  nome_mes = "marco"; break;
        case 4:  nome_mes = "abril"; break;
        case 5:  nome_mes = "maio"; break;
        case 6:  nome_mes = "junho"; break;
        case 7:  nome_mes = "julho"; break;
        case 8:  nome_mes = "agosto"; break;
        case 9:  nome_mes = "setembro"; break;
        case 10: nome_mes = "outubro"; break;
        case 11: nome_mes = "novembro"; break;
        case 12: nome_mes = "dezembro"; break;
        default:
            printf("Erro: Mes %d invalido (deve estar entre 1 e 12).\n", mes);
            return 1;
    }

    // Validacao basica de dia
    if (dia < 1 || dia > 31) {
        printf("Erro: Dia %d invalido.\n", dia);
        return 1;
    }

    printf("\nData formatada: %02d de %s de %04d\n", dia, nome_mes, ano);

    return 0;
}
