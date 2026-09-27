#include <stdio.h>

/*
 * Questao 08: Validacao de Entrada de Dados com Laco Garantido (do-while)
 * Solicita uma nota no intervalo fechado de 0.0 a 10.0.
 * Utiliza do-while para repetir a solicitacao com mensagem de erro caso o valor seja invalido,
 * encerrando com 'Nota registrada com sucesso!'.
 */

int main(void) {
    double nota;
    int valida;

    do {
        printf("Digite uma nota entre 0.0 e 10.0: ");
        if (scanf("%lf", &nota) != 1) {
            // Limpa buffer em caso de caractere invalido
            while (getchar() != '\n');
            printf("Erro: Entrada invalida! Por favor, digite um valor numerico.\n\n");
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

    printf("Nota registrada com sucesso!\n");
    return 0;
}
