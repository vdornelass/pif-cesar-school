#include <stdio.h>

/*
 * Questao 06: Escopo de Bloco e Comandos de Desvio (break e continue)
 * Codigo corrigido que declara 'soma' fora do laco for, permitindo
 * acumular a soma dos quadrados das iteracoes executadas (1, 2, 3, 4, 6, 7).
 * O continue pula i = 5 e o break interrompe o laco em i = 8.
 */

int main(void) {
    int i;
    int soma = 0; // Declarada fora do laco for para manter o valor acumulado

    for (i = 1; i <= 10; i++) {
        if (i == 5) continue; // Pula o calculo da iteracao 5
        if (i == 8) break;    // Encerra imediatamente o laco no inicio da iteracao 8
        
        soma += i * i;
    }

    printf("Soma final = %d\n", soma);
    return 0;
}
