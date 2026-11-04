#include <stdio.h>

/*
 * Questao 26: Quantidade de Dias de um Mes e Validacao de Fevereiro Bissexto
 * Le mes (1 a 12) e ano. Informa nome e total de dias.
 */

int main(void) {
    int mes, ano, dias;
    const char *nome_mes = "";
    int bissexto;

    printf("=== DIAS DO MES E BISSEXTO ===\n");
    printf("Digite o numero do mes (1 a 12): ");
    if (scanf("%d", &mes) != 1 || mes < 1 || mes > 12) {
        printf("Erro: Mes invalido.\n");
        return 1;
    }

    printf("Digite o ano: ");
    if (scanf("%d", &ano) != 1 || ano <= 0) {
        printf("Erro: Ano invalido.\n");
        return 1;
    }

    bissexto = (ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0);

    switch (mes) {
        case 1:  nome_mes = "Janeiro";   dias = 31; break;
        case 2:
            nome_mes = "Fevereiro";
            dias = bissexto ? 29 : 28;
            break;
        case 3:  nome_mes = "Marco";     dias = 31; break;
        case 4:  nome_mes = "Abril";     dias = 30; break;
        case 5:  nome_mes = "Maio";      dias = 31; break;
        case 6:  nome_mes = "Junho";     dias = 30; break;
        case 7:  nome_mes = "Julho";     dias = 31; break;
        case 8:  nome_mes = "Agosto";    dias = 31; break;
        case 9:  nome_mes = "Setembro";  dias = 30; break;
        case 10: nome_mes = "Outubro";   dias = 31; break;
        case 11: nome_mes = "Novembro";  dias = 30; break;
        case 12: nome_mes = "Dezembro";  dias = 31; break;
    }

    printf("\nMes: %s de %d\n", nome_mes, ano);
    printf("Total de dias: %d dias%s\n", dias, (mes == 2 && bissexto) ? " (Ano Bissexto)" : "");

    return 0;
}
