#include <stdio.h>

/*
 * Questao 03: Funcoes void, Parametros e Assinaturas
 * Demonstracao dos prototipos:
 * - void exibe_mensagem(char* msg);
 * - int obter_codigo(void);
 * - void limpar_tela(void);
 */

// Prototipos exigidos
void exibe_mensagem(char* msg);
int obter_codigo(void);
void limpar_tela(void);

int main(void) {
    printf("=== QUESTAO 03: ASSINATURAS E PROCEDIMENTOS ===\n\n");

    exibe_mensagem("Iniciando o sistema...");

    int cod = obter_codigo();
    printf("Codigo capturado da funcao com retorno: %d\n\n", cod);

    printf("Chamando procedimento sem retorno (void):\n");
    limpar_tela();

    // Nota conceitual: Uma instrucao como 'int x = limpar_tela();'
    // geraria erro em tempo de compilacao ("void value not ignored").

    return 0;
}

void exibe_mensagem(char* msg) {
    printf("[MENSAGEM DO SISTEMA]: %s\n", msg);
}

int obter_codigo(void) {
    // Funcao produtiva que gera um valor de retorno
    return 404;
}

void limpar_tela(void) {
    // Procedimento com efeito colateral
    printf("----------------------------------------\n");
    printf("[TELA SIMULADA LIMPA COM SUCESSO]\n");
    printf("----------------------------------------\n");
}
