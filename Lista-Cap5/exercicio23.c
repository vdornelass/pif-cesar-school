#include <stdio.h>

/*
 * Questao 23: Macro versus Funcao
 * Demonstracao de substituicao textual sem parenteses vs avaliacao de funcao.
 */

#define DOBRO_MACRO_INCORRETA(x) x*2
#define DOBRO_MACRO_CORRIGIDA(x) ((x)*2)

// Prototipo
int dobro_funcao(int x);

int main(void) {
    int arg1 = 2, arg2 = 3;

    printf("=== MACRO VERSUS FUNCAO (AVALIACAO DE 2+3) ===\n\n");

    // 1. Chamada da macro incorreta: DOBRO_MACRO_INCORRETA(2+3) -> 2 + 3 * 2 = 2 + 6 = 8
    printf("1. DOBRO_MACRO_INCORRETA(2+3) = %d (Resultado inesperado: 8)\n", DOBRO_MACRO_INCORRETA(2+3));
    printf("   Explicacao: A macro realiza substituicao puramente textual. Sem parenteses,\n"
           "   a multiplicacao tem maior precedencia que a soma (2 + 3*2 = 8).\n\n");

    // 2. Chamada da funcao: dobro_funcao(2+3) -> argumento avaliado antes: dobro_funcao(5) = 10
    printf("2. dobro_funcao(2+3) = %d (Resultado correto: 10)\n", dobro_funcao(2+3));
    printf("   Explicacao: A funcao avalia a expressao do argumento (2+3 = 5) ANTES de invocar\n"
           "   o corpo da funcao, garantindo integridade aritmetica.\n\n");

    // 3. Chamada da macro corrigida com parenteses
    printf("3. DOBRO_MACRO_CORRIGIDA(2+3) = %d (Resultado correto via macro)\n", DOBRO_MACRO_CORRIGIDA(2+3));
    printf("   Explicacao: Com parenteses de protecao ((2+3)*2), a soma eh avaliada primeiro.\n");

    return 0;
}

int dobro_funcao(int x) {
    return x * 2;
}
