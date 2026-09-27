#include <stdio.h>

/*
 * Questao 07: Contagem Progressiva em Tres Versoes (for, while, do-while)
 * Imprime os numeros inteiros de 0 a 100 em ordem crescente utilizando
 * tres funcoes independentes para cada estrutura de repeticao.
 */

void contagem_for(void) {
    printf("--- Contagem com 'for' (0 a 100) ---\n");
    for (int i = 0; i <= 100; i++) {
        printf("%d ", i);
    }
    printf("\n\n");
}

void contagem_while(void) {
    printf("--- Contagem com 'while' (0 a 100) ---\n");
    int i = 0;
    while (i <= 100) {
        printf("%d ", i);
        i++;
    }
    printf("\n\n");
}

void contagem_dowhile(void) {
    printf("--- Contagem com 'do-while' (0 a 100) ---\n");
    int i = 0;
    do {
        printf("%d ", i);
        i++;
    } while (i <= 100);
    printf("\n\n");
}

int main(void) {
    contagem_for();
    contagem_while();
    contagem_dowhile();
    return 0;
}

/*
 * RESPOSTA A PERGUNTA:
 * Qual das tres estruturas eh a mais adequada para este caso e por que?
 * 
 * A estrutura mais adequada eh o laco 'for'.
 * Justificativa: Trata-se de uma iteracao contada e deterministica, onde os limites
 * inferior (0), superior (100) e o passo de incremento (+1) sao conhecidos previamente.
 * O laco 'for' permite agrupar a inicializacao, a expressao de teste e o incremento
 * de forma compacta e centralizada em uma unica linha no cabecalho, proporcionando maior
 * legibilidade, menor risco de esquecimento do incremento (o que causaria laco infinito)
 * e delimitacao estrita do escopo da variavel de controle.
 */
