#include <stdio.h>

/*
 * Questao 04: Selecao Multipla com switch-case e Efeito Fall-Through
 * Demonstra a execucao de um switch-case com omissao de break,
 * evidenciando o efeito de passagem direta (fall-through).
 */

int main(void) {
    int codigo = 2;

    printf("=== QUESTAO 04: SWITCH-CASE E FALL-THROUGH ===\n\n");
    printf("Codigo fornecido: %d\n\n", codigo);

    printf("--- Execucao do Codigo Original (com Fall-Through) ---\n");
    switch (codigo) {
        case 1:
            printf("Bronze\n");
        case 2:
            printf("Prata\n");
        case 3:
            printf("Ouro\n");
            break;
        default:
            printf("Sem Medalha\n");
    }

    printf("\n--- Execucao com Break em Todos os Casos ---\n");
    switch (codigo) {
        case 1:
            printf("Bronze\n");
            break;
        case 2:
            printf("Prata\n");
            break;
        case 3:
            printf("Ouro\n");
            break;
        default:
            printf("Sem Medalha\n");
            break;
    }

    return 0;
}
