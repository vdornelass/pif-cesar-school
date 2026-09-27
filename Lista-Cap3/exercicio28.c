#include <stdio.h>

/*
 * Questao 28: Sistema de Folha de Pagamento com Menu Continuo (do-while & switch)
 * Gerenciamento de folha de pagamento com menu de opcoes interativo:
 * 1. Reajuste Salarial (15% ate R$ 2.000,00 e 10% acima).
 * 2. Retencao de Imposto de Renda (8% ate R$ 3.000,00 e 15% acima).
 * 3. Encerrar Programa.
 * Valida opcoes e encerra apenas quando a opcao 3 for selecionada.
 */

int main(void) {
    int opcao;
    double salario, novo_salario, desconto, imposto;

    do {
        printf("\n=========================================\n");
        printf("       SISTEMA DE FOLHA DE PAGAMENTO     \n");
        printf("=========================================\n");
        printf("1. Reajuste Salarial\n");
        printf("2. Retencao de Imposto de Renda\n");
        printf("3. Encerrar Programa\n");
        printf("-----------------------------------------\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n');
            printf("\nOpcao invalida! Digite um numero de 1 a 3.\n");
            continue;
        }

        switch (opcao) {
            case 1:
                printf("\n--- Calculo de Reajuste Salarial ---\n");
                printf("Informe o salario atual: R$ ");
                if (scanf("%lf", &salario) != 1 || salario <= 0.0) {
                    while (getchar() != '\n');
                    printf("Salario invalido!\n");
                    break;
                }

                if (salario <= 2000.00) {
                    novo_salario = salario * 1.15;
                    printf("Aumento concedido: 15%% (R$ %.2f)\n", salario * 0.15);
                } else {
                    novo_salario = salario * 1.10;
                    printf("Aumento concedido: 10%% (R$ %.2f)\n", salario * 0.10);
                }
                printf("Novo salario reajustado: R$ %.2f\n", novo_salario);
                break;

            case 2:
                printf("\n--- Calculo de Retencao de Imposto de Renda ---\n");
                printf("Informe o salario para calculo de IR: R$ ");
                if (scanf("%lf", &salario) != 1 || salario <= 0.0) {
                    while (getchar() != '\n');
                    printf("Salario invalido!\n");
                    break;
                }

                if (salario <= 3000.00) {
                    imposto = salario * 0.08;
                    printf("Aliquota aplicada: 8%%\n");
                } else {
                    imposto = salario * 0.15;
                    printf("Aliquota aplicada: 15%%\n");
                }
                desconto = salario - imposto;
                printf("Valor retido na fonte: R$ %.2f\n", imposto);
                printf("Salario liquido apos retencao: R$ %.2f\n", desconto);
                break;

            case 3:
                printf("\nEncerrando o programa de Folha de Pagamento. Ate logo!\n");
                break;

            default:
                printf("\nOpcao invalida! Escolha uma opcao valida entre 1 e 3.\n");
                break;
        }

    } while (opcao != 3);

    return 0;
}
