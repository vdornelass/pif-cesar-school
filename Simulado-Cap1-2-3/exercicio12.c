#include <stdio.h>

/*
 * Questao 12: Validacao de Entrada de Dados com Laco Garantido (do-while)
 * Solicita uma nota no intervalo fechado [0.0, 10.0].
 * Repete a solicitacao exibindo mensagem de erro enquanto o valor digitado
 * estiver fora do intervalo permitido, utilizando a estrutura do-while.
 */

int main(void) {
    double nota;
    int valida;

    do {
        printf("Digite uma nota valida entre 0.0 e 10.0: ");
        if (scanf("%lf", &nota) != 1) {
            while (getchar() != '\n');
            printf("Erro: Entrada invalida! Digite um valor numerico.\n\n");
            valida = 0;
            continue;
        }

        if (nota < 0.0 || nota > 10.0) {
            printf("Erro: Nota %.2f fora do intervalo permitido [0.0, 10.0]!\n\n", nota);
            valida = 0;
        } else {
            valida = 1;
        }
    } while (!valida);

    printf("\nNota %.2f aceita e registrada com sucesso!\n", nota);
    return 0;
}
