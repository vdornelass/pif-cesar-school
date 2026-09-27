#include <stdio.h>

#define SENHA_SECRETA 2026
#define MAX_TENTATIVAS 3

/*
 * Questao 14: Autenticacao de Senha com Limite Finito de Tentativas
 * Sistema de autenticacao que permite ate 3 tentativas para acertar a senha (2026)
 * utilizando um laco while. Exibe 'Acesso Concedido!' ou 'Conta Bloqueada por Seguranca!'.
 */

int main(void) {
    int senha_digitada;
    int tentativas = 0;
    int autenticado = 0;

    printf("=== Sistema de Autenticacao ===\n");

    while (tentativas < MAX_TENTATIVAS) {
        tentativas++;
        printf("Tentativa %d de %d - Digite a senha numerica: ", tentativas, MAX_TENTATIVAS);

        if (scanf("%d", &senha_digitada) != 1) {
            while (getchar() != '\n');
            printf("Entrada invalida! Contabilizada como erro.\n");
            continue;
        }

        if (senha_digitada == SENHA_SECRETA) {
            autenticado = 1;
            break;
        } else {
            printf("Senha incorreta!\n\n");
        }
    }

    if (autenticado) {
        printf("\nAcesso Concedido!\n");
    } else {
        printf("\nConta Bloqueada por Seguranca!\n");
    }

    return 0;
}
