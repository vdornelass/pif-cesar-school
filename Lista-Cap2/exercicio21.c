#include <stdio.h>

/*
 * Questao 21: Leitura de Caractere e Exibicao de seu Codigo ASCII
 * 
 * Explicacao:
 * Na memoria do computador, caracteres sao armazenados como valores numericos inteiros
 * de 1 byte conforme a Tabela ASCII (ex: 'A' eh 65, 'a' eh 97). Ao formatar com %d,
 * visualizamos diretamente essa representacao numerica interna.
 */

int main(void) {
    char caractere;
    printf("Digite um caractere: ");
    if (scanf(" %c", &caractere) == 1) {
        printf("Caractere: '%c'\n", caractere);
        printf("Codigo numerico na Tabela ASCII: %d\n", (int)caractere);
    } else {
        printf("Entrada invalida!\n");
    }
    return 0;
}
