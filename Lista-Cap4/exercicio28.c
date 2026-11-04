#include <stdio.h>

/*
 * Questao 28: Sistema de Atendimento Automatico Bancario (SAC / URA)
 * Menu:
 * 1 - Consultar Saldo
 * 2 - Efetuar Extrato
 * 3 - Fazer Transferencia
 * 4 - Falar com Atendente
 * Trata opcoes invalidas com default.
 */

int main(void) {
    int opcao;

    printf("=========================================\n");
    printf("    BANCO DIGITAL CESAR - ATENDIMENTO SAC\n");
    printf("=========================================\n");
    printf("1 - Consultar Saldo\n");
    printf("2 - Efetuar Extrato\n");
    printf("3 - Fazer Transferencia\n");
    printf("4 - Falar com Atendente\n");
    printf("-----------------------------------------\n");
    printf("Digite o numero da opcao desejada: ");
    if (scanf("%d", &opcao) != 1) {
        printf("Erro: Entrada invalida.\n");
        return 1;
    }

    printf("\n[DIRECIONAMENTO URA]:\n");
    switch (opcao) {
        case 1:
            printf("Voce escolheu 'Consultar Saldo'.\n"
                   "-> Por favor, confirme os 4 digitos da sua senha de transacao no teclado.\n");
            break;
        case 2:
            printf("Voce escolheu 'Efetuar Extrato'.\n"
                   "-> Seu demonstrativo dos ultimos 30 dias foi gerado e enviado ao seu e-mail cadastrado.\n");
            break;
        case 3:
            printf("Voce escolheu 'Fazer Transferencia'.\n"
                   "-> Digite a chave Pix ou os dados bancarios da conta de destino.\n");
            break;
        case 4:
            printf("Voce escolheu 'Falar com Atendente'.\n"
                   "-> Aguarde na linha. Voce eh o proximo na fila de atendimento especializado.\n");
            break;
        default:
            printf("Erro: Opcao %d invalida!\n"
                   "-> Por favor, selecione uma das opcoes disponiveis entre 1 e 4.\n", opcao);
            break;
    }

    return 0;
}
