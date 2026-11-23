#include <stdio.h>

/*
 * Questao 13: Calculadora com Quatro Operacoes
 * Funcoes soma, subtrai, multiplica e divide (float -> float).
 * Validacao previa de divisao por zero.
 */

// Prototipos
float soma(float a, float b);
float subtrai(float a, float b);
float multiplica(float a, float b);
float divide(float a, float b);

int main(void) {
    int op;
    float n1, n2, res;

    printf("=== CALCULADORA MODULAR ===\n");
    printf("1 - Soma (+)\n");
    printf("2 - Subtracao (-)\n");
    printf("3 - Multiplicacao (*)\n");
    printf("4 - Divisao (/)\n");
    printf("Escolha a operacao (1-4): ");
    if (scanf("%d", &op) != 1 || op < 1 || op > 4) {
        printf("Erro: Operacao invalida.\n");
        return 1;
    }

    printf("Digite o primeiro operando: ");
    if (scanf("%f", &n1) != 1) return 1;

    printf("Digite o segundo operando: ");
    if (scanf("%f", &n2) != 1) return 1;

    switch (op) {
        case 1:
            res = soma(n1, n2);
            printf("Resultado: %.2f + %.2f = %.2f\n", n1, n2, res);
            break;
        case 2:
            res = subtrai(n1, n2);
            printf("Resultado: %.2f - %.2f = %.2f\n", n1, n2, res);
            break;
        case 3:
            res = multiplica(n1, n2);
            printf("Resultado: %.2f * %.2f = %.2f\n", n1, n2, res);
            break;
        case 4:
            if (n2 == 0.0f) {
                printf("Erro: Impossivel realizar divisao por zero!\n");
            } else {
                res = divide(n1, n2);
                printf("Resultado: %.2f / %.2f = %.2f\n", n1, n2, res);
            }
            break;
    }

    return 0;
}

float soma(float a, float b) {
    return a + b;
}

float subtrai(float a, float b) {
    return a - b;
}

float multiplica(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    return a / b;
}
