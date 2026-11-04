#include <stdio.h>

/*
 * Questao 15: Verificacao de Elegibilidade para Aposentadoria
 * Condicoes:
 * - Pelo menos 65 anos de idade; OU
 * - Pelo menos 30 anos de servico; OU
 * - Pelo menos 60 anos de idade E 25 anos de servico.
 */

int main(void) {
    int idade, tempo_servico;

    printf("=== VERIFICADOR DE APOSENTADORIA ===\n");
    printf("Digite a idade do trabalhador: ");
    if (scanf("%d", &idade) != 1 || idade <= 0) return 1;

    printf("Digite o tempo de servico (em anos): ");
    if (scanf("%d", &tempo_servico) != 1 || tempo_servico < 0) return 1;

    if (idade >= 65 || tempo_servico >= 30 || (idade >= 60 && tempo_servico >= 25)) {
        printf("\nResultado: O trabalhador ESTA ELEGIVEL para aposentadoria.\n");
    } else {
        printf("\nResultado: O trabalhador NAO ESTA ELEGIVEL para aposentadoria.\n");
    }

    return 0;
}
