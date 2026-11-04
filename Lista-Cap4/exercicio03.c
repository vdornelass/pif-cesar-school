#include <stdio.h>

/*
 * Questao 03: Operador Condicional Ternario vs. Estrutura if-else
 * Demonstra a utilizacao do operador ternario (? :) para atribuicao condicional
 * e sua equivalencia semantica com a estrutura if-else.
 */

int main(void) {
    double nota1 = 6.5, nota2 = 7.1;
    double media;
    char situacao_ternario;
    char situacao_ifelse;

    media = (nota1 + nota2) / 2.0;

    printf("=== QUESTAO 03: OPERADOR TERNARIO VS IF-ELSE ===\n\n");
    printf("Notas: %.1f e %.1f | Media calculada = %.2f\n\n", nota1, nota2, media);

    // Abordagem 1: Operador Ternario
    situacao_ternario = (media >= 7.0) ? 'A' : 'R';
    printf("[Operador Ternario]: Situacao = '%c' (%s)\n",
           situacao_ternario, (situacao_ternario == 'A') ? "Aprovado" : "Reprovado");

    // Abordagem 2: Estrutura if-else tradicional
    if (media >= 7.0) {
        situacao_ifelse = 'A';
    } else {
        situacao_ifelse = 'R';
    }
    printf("[Estrutura if-else]: Situacao = '%c' (%s)\n\n",
           situacao_ifelse, (situacao_ifelse == 'A') ? "Aprovado" : "Reprovado");

    // Teste com media = 6.8 solicitada na questao
    media = 6.8;
    situacao_ternario = (media >= 7.0) ? 'A' : 'R';
    printf("Para media = 6.8: situacao = '%c' (pois 6.8 >= 7.0 eh FALSO, selecionando 'R').\n", situacao_ternario);

    return 0;
}
