#include <stdio.h>

/*
 * Questao 27: Tarifador de Estacionamento com Faixas Progressivas
 * Regra:
 * 1a e 2a hora: R$ 2,00 por hora
 * 3a e 4a hora: R$ 2,50 por hora
 * 5a hora em diante: R$ 3,00 por hora adicional
 */

int main(void) {
    int horas;
    double valor_total = 0.0;

    printf("=== TARIFADOR DE ESTACIONAMENTO PROGRESSIVO ===\n");
    printf("Digite o numero de horas inteiras de permanencia: ");
    if (scanf("%d", &horas) != 1 || horas <= 0) {
        printf("Erro: Horas de permanencia invalidas.\n");
        return 1;
    }

    if (horas <= 2) {
        valor_total = horas * 2.00;
    } else if (horas <= 4) {
        valor_total = (2 * 2.00) + ((horas - 2) * 2.50);
    } else {
        valor_total = (2 * 2.00) + (2 * 2.50) + ((horas - 4) * 3.00);
    }

    printf("\nTempo de permanencia: %d hora(s)\n", horas);
    printf("Discriminacao tarifaria:\n");
    if (horas >= 1) printf("- Horas 1 e 2 (R$ 2.00/h): R$ %.2f\n", (horas >= 2 ? 2 : horas) * 2.00);
    if (horas >= 3) printf("- Horas 3 e 4 (R$ 2.50/h): R$ %.2f\n", (horas >= 4 ? 2 : (horas - 2)) * 2.50);
    if (horas >= 5) printf("- A partir da 5a hora (R$ 3.00/h): R$ %.2f\n", (horas - 4) * 3.00);
    printf("----------------------------------------\n");
    printf("VALOR TOTAL DO TICKET: R$ %.2f\n", valor_total);

    return 0;
}
