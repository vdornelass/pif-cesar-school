#include <stdio.h>

/*
 * Questao 02: Escopo e Tempo de Vida de Variaveis de Bloco
 * Codigo corrigido para calcular a soma dos quadrados dos numeros inteiros de 1 a 9.
 * Declara e inicializa a variavel 'soma' fora do escopo do laco for para garantir
 * que o acumulador persista ao longo de todas as iteracoes.
 */

int main(void) {
    int i;
    int soma = 0; // Declarada fora do laco for com escopo na funcao main

    for (i = 1; i < 10; i++) {
        soma += i * i;
    }

    printf("Soma final dos quadrados de 1 a 9 = %d\n", soma);
    return 0;
}
