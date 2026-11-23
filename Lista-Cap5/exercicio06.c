#include <stdio.h>

/*
 * Questao 06: Diretivas #include, #undef e Compilacao Condicional
 * Demonstracao de controle de pre-processamento.
 */

#define DEBUG // Comente esta linha para testar o modo normal

#define SOMA(x,y) ((x)+(y))

// #undef cancela a definicao anterior da macro
#undef SOMA

int main(void) {
    printf("=== QUESTAO 06: COMPILACAO CONDICIONAL ===\n");

#ifdef DEBUG
    printf("[MODO DEPURAÇÃO ATIVO]: Variaveis de rastreamento habilitadas.\n");
#else
    printf("[MODO NORMAL]: Execucao de producao.\n");
#endif

    // Observacao: a macro SOMA foi desfeita com #undef SOMA.
    // Tentar utiliza-la agora causaria erro de compilacao.

    return 0;
}
