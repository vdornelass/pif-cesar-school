#include <stdio.h>

/*
 * Questao 02: O Comando return e suas Limitacoes
 * Demonstracao de return unico em C e uso de funcoes separadas para
 * soma e media de tres valores.
 */

// Prototipos
int soma_tres(int a, int b, int c);
float media_tres(int a, int b, int c);
void imprime_mensagem(int erro);

int main(void) {
    int v1 = 10, v2 = 20, v3 = 30;

    printf("=== QUESTAO 02: RETORNO DE FUNCOES EM C ===\n");
    printf("Valores de entrada: %d, %d, %d\n", v1, v2, v3);

    // Como o comando return em C eh estritamente univalorado,
    // utilizamos duas funcoes distintas e coesas para obter soma e media.
    int s = soma_tres(v1, v2, v3);
    float m = media_tres(v1, v2, v3);

    printf("Soma calculada: %d\n", s);
    printf("Media calculada: %.2f\n\n", m);

    printf("--- Teste de saida antecipada em funcao void ---\n");
    imprime_mensagem(-1); // Ativa o return antecipado
    imprime_mensagem(200); // Executa o fluxo completo

    return 0;
}

int soma_tres(int a, int b, int c) {
    return a + b + c;
}

float media_tres(int a, int b, int c) {
    return (float)soma_tres(a, b, c) / 3.0f;
}

void imprime_mensagem(int erro) {
    if (erro < 0) {
        printf("[Status]: Erro invalido detectado (saida antecipada via return;)\n");
        return; // Interrompe o procedimento imediatamente
    }
    printf("[Status]: Codigo processado com sucesso: %d\n", erro);
}
