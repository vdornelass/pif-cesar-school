#include <stdio.h>

/*
 * Questao 22: Calculo de Impostos Estaduais sobre Produtos
 * Estados e taxas:
 * 1 = MG: 7%
 * 2 = SP: 12%
 * 3 = RJ: 15%
 * 4 = MS: 8%
 */

int main(void) {
    float valor_produto, aliquota, imposto, valor_final;
    int estado;

    printf("=== IMPOSTO ESTADUAL SOBRE PRODUTOS ===\n");
    printf("Digite o valor do produto: R$ ");
    if (scanf("%f", &valor_produto) != 1 || valor_produto <= 0.0f) return 1;

    printf("Estados de destino: 1 = MG | 2 = SP | 3 = RJ | 4 = MS\n");
    printf("Digite o codigo do estado: ");
    if (scanf("%d", &estado) != 1) return 1;

    switch (estado) {
        case 1:
            aliquota = 0.07f;
            break;
        case 2:
            aliquota = 0.12f;
            break;
        case 3:
            aliquota = 0.15f;
            break;
        case 4:
            aliquota = 0.08f;
            break;
        default:
            printf("Erro: Codigo de estado invalido!\n");
            return 1;
    }

    imposto = valor_produto * aliquota;
    valor_final = valor_produto + imposto;

    printf("\nValor base: R$ %.2f\n", valor_produto);
    printf("Aliquota: %.0f%% | Imposto: R$ %.2f\n", aliquota * 100.0f, imposto);
    printf("Preco final com imposto: R$ %.2f\n", valor_final);

    return 0;
}
