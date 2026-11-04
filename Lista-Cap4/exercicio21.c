#include <stdio.h>

/*
 * Questao 21: Calculo de Reajuste Salarial com Base em Categorias
 * Cargos:
 * 1 = Tecnico: 15% se salario <= 3000; 10% se salario > 3000.
 * 2 = Gerente: 10% se salario <= 5000; 5% se salario > 5000.
 * 3 = Demais: 8% fixo.
 */

int main(void) {
    double salario_atual, percentual, aumento, novo_salario;
    int cargo;

    printf("=== REAJUSTE SALARIAL ===\n");
    printf("Digite o salario atual: R$ ");
    if (scanf("%lf", &salario_atual) != 1 || salario_atual <= 0.0) return 1;

    printf("Cargos: 1 = Tecnico | 2 = Gerente | 3 = Demais Cargos\n");
    printf("Digite o codigo do cargo: ");
    if (scanf("%d", &cargo) != 1) return 1;

    switch (cargo) {
        case 1: // Tecnico
            percentual = (salario_atual <= 3000.0) ? 0.15 : 0.10;
            break;
        case 2: // Gerente
            percentual = (salario_atual <= 5000.0) ? 0.10 : 0.05;
            break;
        case 3: // Demais
            percentual = 0.08;
            break;
        default:
            printf("Erro: Codigo de cargo invalido!\n");
            return 1;
    }

    aumento = salario_atual * percentual;
    novo_salario = salario_atual + aumento;

    printf("\nPercentual aplicado: %.1f%%\n", percentual * 100.0);
    printf("Valor do aumento: R$ %.2f\n", aumento);
    printf("Novo salario reajustado: R$ %.2f\n", novo_salario);

    return 0;
}
