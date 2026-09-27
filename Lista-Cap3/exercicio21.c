#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Questao 21: Jogo de Adivinhacao com Letras Aleatorias e Dicas (rand())
 * Sorteia uma letra minuscula entre 'a' e 'z'. O jogador deve adivinhar a letra,
 * recebendo dicas se a letra secreta vem antes ou depois no alfabeto,
 * exibindo ao final a mensagem de parabens e o total de tentativas.
 */

int main(void) {
    srand((unsigned int)time(NULL));

    char letra_secreta = (char)(rand() % 26 + 'a');
    char palpite;
    int tentativas = 0;

    printf("=== Jogo de Adivinhacao de Letras ===\n");
    printf("Uma letra entre 'a' e 'z' foi sorteada. Tente adivinhar!\n\n");

    do {
        printf("Digite o seu palpite (letra minuscula): ");
        if (scanf(" %c", &palpite) != 1) {
            while (getchar() != '\n');
            printf("Entrada invalida! Tente novamente.\n");
            continue;
        }

        tentativas++;

        if (palpite == letra_secreta) {
            printf("\nParabens! Voce acertou a letra secreta '%c'!\n", letra_secreta);
            printf("Total de tentativas utilizadas: %d\n", tentativas);
        } else if (palpite < letra_secreta) {
            printf("Dica: A letra secreta vem DEPOIS de '%c' no alfabeto.\n\n", palpite);
        } else {
            printf("Dica: A letra secreta vem ANTES de '%c' no alfabeto.\n\n", palpite);
        }

    } while (palpite != letra_secreta);

    return 0;
}
