#include <stdio.h>

/*
 * Questao 06: Laco Sem Corpo e Incremento Pos-fixado
 * Analisa a execucao de um laco while com corpo vazio (instrucao nula ';')
 * e expressao de teste com pos-incremento 'while (x++ < 5);', apresentando
 * tambem a versao equivalente sem corpo vazio.
 */

int main(void) {
    int x1 = 0;
    // Trecho original com corpo vazio
    while (x1++ < 5);
    printf("Versao Original (corpo vazio): Valor final de x = %d\n", x1);

    int x2 = 0;
    // Versao equivalente explicita e clara
    while (x2 < 5) {
        x2++;
    }
    x2++; // Incremento correspondente a avaliacao da condicao quando x era 5 (5 < 5 falso)
    printf("Versao Explicita e Clara:      Valor final de x = %d\n", x2);

    return 0;
}
