#include <stdio.h>

/*
 * Questao 16: Classificacao de Eficiencia de Consumo de Combustivel
 * Le distancia em km e litros de gasolina consumidos.
 * Calcula km/l:
 * < 8.0: 'Venda o carro!'
 * 8.0 a 14.0: 'Economico!'
 * > 14.0: 'Super economico!'
 */

int main(void) {
    float distancia, litros, consumo;

    printf("=== EFICIENCIA DE CONSUMO DE COMBUSTIVEL ===\n");
    printf("Digite a distancia percorrida (km): ");
    if (scanf("%f", &distancia) != 1 || distancia <= 0.0f) return 1;

    printf("Digite os litros de combustivel consumidos: ");
    if (scanf("%f", &litros) != 1 || litros <= 0.0f) return 1;

    consumo = distancia / litros;

    printf("\nConsumo medido = %.2f km/l\n", consumo);
    printf("Classificacao: ");

    if (consumo < 8.0f) {
        printf("Venda o carro!\n");
    } else if (consumo <= 14.0f) {
        printf("Economico!\n");
    } else {
        printf("Super economico!\n");
    }

    return 0;
}
