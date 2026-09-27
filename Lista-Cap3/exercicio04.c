#include <stdio.h>

/*
 * Questao 04: Comandos de Desvio de Fluxo: break vs. continue
 * Demonstra a acao do comando continue (salta para o incremento do for)
 * e do comando break (interrompe imediatamente o laco mais interno).
 */

int main(void) {
    int i, j;

    printf("--- Demonstracao do comando 'continue' (ignora numeros pares) ---\n");
    for (i = 1; i <= 6; i++) {
        if (i % 2 == 0) {
            continue; // Pula diretamente para a expressao de incremento (i++)
        }
        printf("Numero impar processado: %d\n", i);
    }

    printf("\n--- Demonstracao do comando 'break' em lacos aninhados ---\n");
    for (i = 1; i <= 3; i++) {
        printf("Inicio da iteracao do laco externo (i = %d):\n", i);
        for (j = 1; j <= 5; j++) {
            if (j == 3) {
                printf("  [break acionado em j = %d] Interrompe APENAS o laco interno!\n", j);
                break; // Encerra somente o laco interno
            }
            printf("  Laco interno: j = %d\n", j);
        }
        printf("Fim da iteracao do laco externo (i = %d)\n\n", i);
    }

    return 0;
}
