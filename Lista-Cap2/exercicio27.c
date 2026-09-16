#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Questao 27: Geracao de Valores Aleatorios via Resto de Divisao
 * Simula o lancamento de 3 dados independentes (intervalo 1 a 6)
 * utilizando rand() % 6 + 1 e srand(time(NULL)).
 */

int main(void) {
    srand((unsigned int)time(NULL));

    int dado1 = (rand() % 6) + 1;
    int dado2 = (rand() % 6) + 1;
    int dado3 = (rand() % 6) + 1;

    printf("--- Lancamento de Tres Dados ---\n");
    printf("Dado 1: %d\n", dado1);
    printf("Dado 2: %d\n", dado2);
    printf("Dado 3: %d\n", dado3);

    return 0;
}
