#include <stdio.h>

/*
 * Questao 02: Entrada Standard de Caracteres vs. Bibliotecas Legadas
 * Demonstra a leitura robusta de um caractere usando funcoes padrao ANSI C (<stdio.h>),
 * ignorando quebras de linha ('\n') residuais no buffer de entrada.
 */

int main(void) {
    char c;
    printf("Digite um caractere: ");
    // O espaco antes de %c consome espacos em branco e quebras de linha pendentes
    if (scanf(" %c", &c) == 1) {
        printf("Caractere lido com sucesso: '%c'\n", c);
    }
    return 0;
}
