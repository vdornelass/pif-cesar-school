#include <stdio.h>
#include <math.h>

/*
 * Questao 13: Calculadora Aritmetica e Cientifica com Menu switch
 * Operacoes: + (Soma), - (Subtracao), * (Multiplicacao), / (Divisao), ^ (Potencia).
 * Valida divisao por zero.
 */

int main(void) {
    char operacao;
    double n1, n2, resultado;

    printf("=== CALCULADORA ARITMETICA E CIENTIFICA ===\n");
    printf("Escolha a operacao [+ , - , * , / , ^]: ");
    if (scanf(" %c", &operacao) != 1) return 1;

    printf("Digite o primeiro operando: ");
    if (scanf("%lf", &n1) != 1) return 1;

    printf("Digite o segundo operando: ");
    if (scanf("%lf", &n2) != 1) return 1;

    switch (operacao) {
        case '+':
            resultado = n1 + n2;
            printf("Resultado: %.4f + %.4f = %.4f\n", n1, n2, resultado);
            break;
        case '-':
            resultado = n1 - n2;
            printf("Resultado: %.4f - %.4f = %.4f\n", n1, n2, resultado);
            break;
        case '*':
            resultado = n1 * n2;
            printf("Resultado: %.4f * %.4f = %.4f\n", n1, n2, resultado);
            break;
        case '/':
            if (n2 == 0.0) {
                printf("Erro: Divisao por zero nao eh permitida!\n");
            } else {
                resultado = n1 / n2;
                printf("Resultado: %.4f / %.4f = %.4f\n", n1, n2, resultado);
            }
            break;
        case '^':
            resultado = pow(n1, n2);
            printf("Resultado: %.4f ^ %.4f = %.4f\n", n1, n2, resultado);
            break;
        default:
            printf("Erro: Operacao '%c' invalida!\n", operacao);
            break;
    }

    return 0;
}
