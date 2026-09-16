#include <stdio.h>

/*
 * Questao 07: Leitura e Inversao Formatada de Datas
 * Le uma data no formato dd/mm/aaaa e exibe no formato aaaa/mm/dd.
 */

int main(void) {
    int dia, mes, ano;
    printf("Digite uma data no formato dd/mm/aaaa: ");
    if (scanf("%d/%d/%d", &dia, &mes, &ano) == 3) {
        printf("Data invertida: %04d/%02d/%02d\n", ano, mes, dia);
    } else {
        printf("Formato de data invalido!\n");
    }
    return 0;
}
