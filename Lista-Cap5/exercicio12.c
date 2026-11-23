#include <stdio.h>

/*
 * Questao 12: Procedimento de Menu
 * Procedimento void exibeMenu(void) e tratamento de opcao com switch-case.
 */

// Prototipo
void exibeMenu(void);

int main(void) {
    int opcao;

    exibeMenu();
    printf("Digite sua opcao: ");
    if (scanf("%d", &opcao) != 1) return 1;

    printf("\n[RESPOSTA DO SISTEMA]:\n");
    switch (opcao) {
        case 1:
            printf("Opcao selecionada: 1 - Cadastrar novo registro.\n");
            break;
        case 2:
            printf("Opcao selecionada: 2 - Listar registros existentes.\n");
            break;
        case 3:
            printf("Opcao selecionada: 3 - Remover registro do sistema.\n");
            break;
        case 0:
            printf("Opcao selecionada: 0 - Encerrando o programa. Ate logo!\n");
            break;
        default:
            printf("Erro: Opcao %d invalida!\n", opcao);
            break;
    }

    return 0;
}

void exibeMenu(void) {
    printf("===============================\n");
    printf("        MENU DO SISTEMA        \n");
    printf("===============================\n");
    printf("1 - Cadastrar\n");
    printf("2 - Listar\n");
    printf("3 - Remover\n");
    printf("0 - Sair\n");
    printf("-------------------------------\n");
}
