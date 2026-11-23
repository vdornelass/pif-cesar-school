#include <stdio.h>

/*
 * Questao 05: Diretiva #define, Constantes e Macros com Argumentos
 * Demonstracao de expansao textual de macros e a necessidade critica
 * de parenteses de protecao.
 */

#define PI 3.14
#define SQR(x) ((x)*(x))       // Macro correta com parenteses de protecao
#define DOBRO(x) x*2           // Macro incorreta sem parenteses (gera efeito colateral)
#define DOBRO_CORRETO(x) ((x)*2)

// Macro de impressao corrigida (sem espaco entre identificador e argumentos)
#define PRN(n) printf("Valor impresso via macro: %d\n", n)

int main(void) {
    printf("=== QUESTAO 05: MACROS E PRE-PROCESSAMENTO ===\n\n");

    // SQR(2+3) expande textualmente para ((2+3)*(2+3)) = 5 * 5 = 25
    printf("SQR(2+3) = %d (esperado 25)\n", SQR(2+3));

    // DOBRO(2+3) expande textualmente para 2+3*2 = 2 + 6 = 8 (errado!)
    printf("DOBRO(2+3) sem protecao = %d (esperava-se 10, deu 8 devido a precedencia)\n", DOBRO(2+3));

    // DOBRO_CORRETO(2+3) expande para ((2+3)*2) = 5 * 2 = 10
    printf("DOBRO_CORRETO(2+3) = %d (corrigido)\n\n", DOBRO_CORRETO(2+3));

    PRN(42);

    return 0;
}
