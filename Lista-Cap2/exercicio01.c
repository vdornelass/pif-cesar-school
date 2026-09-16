#include <stdio.h>
#include <stdlib.h>

/*
 * Questao 01: Truncamento de Tipos e Coercao Implicita
 * Demonstra a atribuicao de um valor de ponto flutuante (double)
 * para uma variavel inteira (int), resultando em truncamento da parte decimal.
 */

int main(void) {
    int valor_inteiro;
    valor_inteiro = 2.97; // Coercao implicita: a parte fracionaria (.97) eh descartada (truncamento)
    
    printf("O valor armazenado eh: %d\n", valor_inteiro);
    return 0;
}
