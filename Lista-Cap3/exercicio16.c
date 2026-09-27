#include <stdio.h>

#define SENHA_SECRETA 2026
#define MAX_TENTATIVAS 3

/*
 * Questao 16: Autenticacao de Senha com Limite Finito de Tentativas
 * Sistema de autenticacao com limite de 3 tentativas para acertar a senha secreta (2026).
 * Exibe 'Acesso Concedido!' com o total de tentativas usadas ou 'Conta Bloqueada por Seguranca!'.
 */

int main(void) {
    int senha_digitada;
    int tentativas = 0;
    int acertou = 0;

    printf("=== Sistema de Autenticacao de Seguranca ===\n");

    while (tentativas < MAX_TENTATIVAS) {
        tentativas++;
        printf("Tentativa %d de %d - Digite a senha numerica: ", tentativas, MAX_TENTATIVAS);
        
        if (scanf("%d", &senha_digitada) != 1) {
            while (getchar() != '\n');
            printf("Entrada invalida! Conta como tentativa incorreta.\n");
            continue;
        }

        if (senha_digitada == SENHA_SECRETA) {
            acertou = 1;
            break;
        } else {
            printf("Senha incorreta!\n");
        }
    }

    if (acertou) {
        printf("\nAcesso Concedido!\n");
        printf("Tentativas utilizadas: %d\n", tentativas);
    } else {
        printf("\nConta Bloqueada por Seguranca!\n");
    }

    return 0;
}
