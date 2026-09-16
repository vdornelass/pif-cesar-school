#include <stdio.h>

/*
 * Questao 26: Orcamento para Cercamento Perimetral de Terrenos
 * Perimetro = 2 * (comprimento + largura)
 * Arame necessario = 3 * Perimetro (3 fios esticados)
 * Custo total = Arame * preco_unitario
 */

int main(void) {
    double comprimento, largura, preco_metro;

    printf("Digite o comprimento do terreno (em metros): ");
    if (scanf("%lf", &comprimento) != 1) return 1;

    printf("Digite a largura do terreno (em metros): ");
    if (scanf("%lf", &largura) != 1) return 1;

    printf("Digite o preco do metro de arame farpado (em R$): ");
    if (scanf("%lf", &preco_metro) != 1) return 1;

    double perimetro = 2.0 * (comprimento + largura);
    double total_arame = perimetro * 3.0;
    double custo_total = total_arame * preco_metro;

    printf("\n--- Orcamento de Cercamento ---\n");
    printf("Perimetro do terreno: %.2f m\n", perimetro);
    printf("Metros de arame farpado necessarios: %.2f m\n", total_arame);
    printf("Custo total do cercamento: R$ %.2f\n", custo_total);

    return 0;
}
