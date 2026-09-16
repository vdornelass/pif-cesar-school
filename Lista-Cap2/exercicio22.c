#include <stdio.h>

/*
 * Questao 22: Conversao de Caixa Alta para Baixa via Tabela ASCII
 * Na tabela ASCII, 'A' = 65 e 'a' = 97 (diferenca constante de 32 posicoes).
 * Somando 32 (ou 'a' - 'A'), convertemos uma letra maiuscula para minuscula.
 */

int main(void) {
    char maiuscula;
    printf("Digite uma letra maiuscula: ");
    if (scanf(" %c", &maiuscula) == 1) {
        char minuscula = maiuscula + ('a' - 'A'); // offset de 32
        printf("Letra em minuscula: %c\n", minuscula);
    } else {
        printf("Entrada invalida!\n");
    }
    return 0;
}
