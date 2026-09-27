#include <stdio.h>

/*
 * Questao 05: Estruturas de Repeticao: Comparacao entre for, while e do-while
 * Demonstra a diferenca entre o laco while (teste previo, 0 iteracoes possiveis)
 * e o laco do-while (teste posterior, minimo 1 iteracao garantida), alem
 * do efeito de um laco com instrucao nula.
 */

int main(void) {
    int condicao = 0; // Falso

    printf("--- Teste do lao while com condicao falsa ---\n");
    while (condicao) {
        printf("Mensagem no while (nunca deve aparecer!)\n");
    }
    printf("Bloco while executou 0 vezes.\n\n");

    printf("--- Teste do lao do-while com condicao falsa ---\n");
    do {
        printf("Mensagem no do-while executada ao menos uma vez!\n");
    } while (condicao);
    printf("Bloco do-while executou 1 vez.\n\n");

    printf("--- Demonstracao de laco de instrucao nula controlado ---\n");
    int c = 0;
    while (c++ < 5); // Corpo vazio (instrucao nula ';')
    printf("Valor final de c apos laco nulo = %d\n", c);

    return 0;
}
