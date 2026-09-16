#include <stdio.h>

/*
 * Questao 15: Calculo de Media Aritmetica Simples e Ponderada
 * a) Media aritmetica simples das 4 notas
 * b) Media ponderada: pesos 1 para provas 1 e 2; pesos 2 para provas 3 e 4.
 */

int main(void) {
    double n1, n2, n3, n4;
    printf("Digite as 4 notas do aluno (n1 n2 n3 n4): ");
    if (scanf("%lf %lf %lf %lf", &n1, &n2, &n3, &n4) == 4) {
        double media_simples = (n1 + n2 + n3 + n4) / 4.0;
        double media_ponderada = (n1 * 1.0 + n2 * 1.0 + n3 * 2.0 + n4 * 2.0) / (1.0 + 1.0 + 2.0 + 2.0);

        printf("a) Media Simples:   %.2f\n", media_simples);
        printf("b) Media Ponderada: %.2f\n", media_ponderada);
    } else {
        printf("Entrada invalida!\n");
    }
    return 0;
}
