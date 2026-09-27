#include <stdio.h>

/*
 * Questao 01: Diferencas Fundamentais e Tempo de Avaliacao de Lacos
 * Demonstra a diferenca essencial entre as estruturas while (pre-testada)
 * e do-while (pos-testada) quando a condicao inicial eh falsa, alem do
 * comportamento de um laco com instrucao nula (ponto-e-virgula ao final).
 */

int main(void) {
    int condicao = 0; // Falso (0)

    printf("--- Teste com a estrutura while (pre-testada) ---\n");
    while (condicao) {
        printf("Este comando nunca sera executado!\n");
    }
    printf("Resultado: O bloco do while foi executado 0 vezes.\n\n");

    printf("--- Teste com a estrutura do-while (pos-testada) ---\n");
    do {
        printf("Este comando eh executado ao menos uma vez antes do teste!\n");
    } while (condicao);
    printf("Resultado: O bloco do do-while foi executado 1 vez.\n\n");

    printf("--- Demonstracao de laco com instrucao nula (ponto-e-virgula) controlado ---\n");
    int contador = 0;
    while (contador++ < 5); // Laco com corpo vazio
    printf("Valor final de contador apos laco com instrucao nula = %d\n", contador);

    return 0;
}
