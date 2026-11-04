#include <stdio.h>

/*
 * Questao 12: Dia da Semana com Comando switch-case
 * Le um inteiro de 1 a 7 e imprime o dia correspondente.
 * Trata valores fora da faixa com a clausula default.
 */

int main(void) {
    int opcao;

    printf("=== DIA DA SEMANA ===\n");
    printf("Digite um numero de 1 a 7: ");
    if (scanf("%d", &opcao) != 1) {
        printf("Erro: Entrada invalida.\n");
        return 1;
    }

    switch (opcao) {
        case 1:
            printf("1 = Domingo\n");
            break;
        case 2:
            printf("2 = Segunda-feira\n");
            break;
        case 3:
            printf("3 = Terca-feira\n");
            break;
        case 4:
            printf("4 = Quarta-feira\n");
            break;
        case 5:
            printf("5 = Quinta-feira\n");
            break;
        case 6:
            printf("6 = Sexta-feira\n");
            break;
        case 7:
            printf("7 = Sabado\n");
            break;
        default:
            printf("Erro: Opcao Invalida!\n");
            break;
    }

    return 0;
}
