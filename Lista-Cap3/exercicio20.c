#include <stdio.h>

/*
 * Questao 20: Tabela de Caracteres ASCII e Codigos Hexadecimais
 * Imprime a tabela de caracteres ASCII para os codigos decimais de 32 a 126 (imprimiveis),
 * exibindo o valor em decimal, em hexadecimal (%X) e o respectivo caractere.
 */

int main(void) {
    printf("+---------+-------------+-----------+\n");
    printf("| Decimal | Hexadecimal | Caractere |\n");
    printf("+---------+-------------+-----------+\n");

    for (int i = 32; i <= 126; i++) {
        printf("|   %3d   |    0x%02X     |     %c     |\n", i, i, (char)i);
    }

    printf("+---------+-------------+-----------+\n");
    return 0;
}
