#include <stdio.h>

/*
 * Questao 02: Associacao do Comando else e Aninhamento de Decisões
 * Analisa o problema do 'dangling else' (else orfao/pendente) na linguagem C
 * e demonstra a forma correta de amarracao utilizando blocos delimitados por chaves.
 */

int main(void) {
    int x = 15, y = 5;

    printf("=== QUESTAO 02: DANGLING ELSE ===\n\n");

    printf("--- Codigo Original (Sem chaves) ---\n");
    // O compilador associa o 'else' ao 'if' mais proximo: if (y > 10)
    if (x > 10)
        if (y > 10)
            printf("Opcao A\n");
        else
            printf("Opcao B (impresso porque else pertence a 'y > 10'!)\n");

    printf("\n--- Codigo Corrigido com Chaves (Garantindo que Opcao B ocorra quando x <= 10) ---\n");
    if (x > 10) {
        if (y > 10) {
            printf("Opcao A\n");
        }
    } else {
        printf("Opcao B (agora associado corretamente a x <= 10)\n");
    }

    // Testando com x = 8 para comprovar a execucao do else
    printf("\n--- Teste com x = 8 e y = 5 no codigo corrigido ---\n");
    x = 8;
    if (x > 10) {
        if (y > 10) {
            printf("Opcao A\n");
        }
    } else {
        printf("Opcao B executada com sucesso (x = %d <= 10)!\n", x);
    }

    return 0;
}
