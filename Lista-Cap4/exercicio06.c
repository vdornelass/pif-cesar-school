#include <stdio.h>

/*
 * Questao 06: Construcoes else-if e Analise Logica de Intervalos
 * Demonstra a diferenca entre sequencias de comandos if independentes
 * e uma cadeia estruturada else-if com faixas etarias mutuamente exclusivas.
 */

int main(void) {
    int idade = 65;

    printf("=== QUESTAO 06: CONSTRUCOES ELSE-IF ===\n\n");
    printf("Idade de teste: %d anos\n\n", idade);

    printf("--- Codigo Original com ifs Independentes (Comportamento Incorreto) ---\n");
    if (idade >= 60)
        printf("Idoso\n");
    if (idade >= 18)
        printf("Adulto\n");
    if (idade >= 12)
        printf("Jovem\n");
    else
        printf("Crianca\n");

    printf("\n--- Codigo Corrigido com Estrutura else-if Elegante ---\n");
    if (idade >= 60) {
        printf("Idoso\n");
    } else if (idade >= 18) {
        printf("Adulto\n");
    } else if (idade >= 12) {
        printf("Jovem\n");
    } else {
        printf("Crianca\n");
    }

    return 0;
}
