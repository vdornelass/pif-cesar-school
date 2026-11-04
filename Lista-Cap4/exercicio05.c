#include <stdio.h>

/*
 * Questao 05: Avaliacao de Curto-Circuito em Operadores Logicos
 * Demonstra o comportamento de curto-circuito (short-circuit evaluation)
 * nos operadores logicos E (&&) e OU (||) da linguagem C.
 */

int main(void) {
    int a, b, c;

    printf("=== QUESTAO 05: AVALIACAO DE CURTO-CIRCUITO ===\n\n");

    // Caso 1: if (a != 0 && ++b > 5)
    a = 0; b = 5; c = 10;
    printf("Valores iniciais: a = %d, b = %d, c = %d\n", a, b, c);

    if (a != 0 && ++b > 5) {
        c += 10;
    } else {
        c -= 2;
    }
    printf("Apos 'if (a != 0 && ++b > 5)': a = %d, b = %d, c = %d\n", a, b, c);
    printf("Explicacao: Como 'a != 0' eh FALSO (0), o operador && sofreu curto-circuito.\n"
           "A subexpressao '++b > 5' NUNCA foi avaliada, logo 'b' permaneceu 5 e c = 10 - 2 = 8.\n\n");

    // Caso 2: if (a == 0 || ++b > 5)
    a = 0; b = 5; c = 10;
    printf("Valores reiniciados: a = %d, b = %d, c = %d\n", a, b, c);

    if (a == 0 || ++b > 5) {
        c += 10;
    } else {
        c -= 2;
    }
    printf("Apos 'if (a == 0 || ++b > 5)': a = %d, b = %d, c = %d\n", a, b, c);
    printf("Explicacao: Como 'a == 0' eh VERDADEIRO (1), o operador || sofreu curto-circuito.\n"
           "A subexpressao '++b > 5' tambem nao foi avaliada, logo 'b' permaneceu 5 e c = 10 + 10 = 20.\n");

    return 0;
}
