#include <stdio.h>

/*
 * Questao 01: Avaliacao de Expressoes Condicionais e Atribuicao vs. Igualdade
 * Demonstra a diferenca conceitual e pratica entre os operadores de atribuicao (=)
 * e de comparacao de igualdade (==) dentro da condicao de um comando if.
 */

int main(void) {
    int x;

    printf("=== DEMONSTRACAO DA QUESTAO 01 ===\n\n");

    // Teste A: if (x = 0)
    printf("1. Testando atribuicao dentro da condicao: if (x = 0)\n");
    x = 10; // Valor inicial
    printf("Valor antes do if: x = %d\n", x);
    if (x = 0) {
        printf("Bloco do if executado!\n");
    } else {
        printf("Bloco do else executado!\n");
    }
    printf("Valor apos o if: x = %d (a atribuicao sobrescreveu a variavel)\n\n", x);

    // Teste B: if (x == 0)
    printf("2. Testando comparacao correta: if (x == 0)\n");
    x = 0;
    if (x == 0) {
        printf("Condicao verdadeira: x eh estritamente igual a 0!\n");
    } else {
        printf("Condicao falsa!\n");
    }
    printf("Valor de x permanece: %d\n\n", x);

    // Teste C: if (x = -5)
    printf("3. Testando atribuicao com valor nao-nulo: if (x = -5)\n");
    if (x = -5) {
        printf("Bloco executado! Em ANSI C, qualquer valor diferente de zero eh VERDADEIRO (x = %d).\n", x);
    } else {
        printf("Bloco ignorado!\n");
    }

    return 0;
}
