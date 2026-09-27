#include <stdio.h>

/*
 * Questao 03: Flexibilidade do Laco for e Omissao de Expressoes
 * Demonstra a execucao do Trecho A (incremento por divisao sucessiva) e
 * a interrupcao programatica do laco infinito do Trecho C atraves do comando break.
 */

int main(void) {
    int a;

    printf("--- Trecho A: Incremento por divisao sucessiva (a /= 2) ---\n");
    for (a = 36; a > 0; a /= 2) {
        printf("%d\t", a);
    }
    printf("\n\n");

    printf("--- Trecho C: Interrupcao programatica de laco infinito com break ---\n");
    int contador = 1;
    for (;;) {
        printf("Iteracao %d do laco infinito\n", contador);
        if (contador == 3) {
            printf("Condicao atingida! Encerrando laco infinito com o comando 'break'.\n");
            break;
        }
        contador++;
    }

    return 0;
}
