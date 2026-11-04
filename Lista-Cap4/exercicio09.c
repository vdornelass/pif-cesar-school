#include <stdio.h>

/*
 * Questao 09: Calculo de Media Ponderada e Situacao Academica
 * Pesos: Trabalho de Laboratorio (2), Avaliacao Semestral (3), Exame Final (5).
 * Situacao:
 * 0.0 a 2.9: Reprovado
 * 3.0 a 4.9: Em Recuperacao
 * >= 5.0: Aprovado
 */

int main(void) {
    double trab_lab, aval_sem, exame_final;
    double media_ponderada;

    printf("=== CALCULADORA DE MEDIA PONDERADA ===\n");
    printf("Digite a nota do Trabalho de Laboratorio (peso 2): ");
    if (scanf("%lf", &trab_lab) != 1) return 1;

    printf("Digite a nota da Avaliacao Semestral (peso 3): ");
    if (scanf("%lf", &aval_sem) != 1) return 1;

    printf("Digite a nota do Exame Final (peso 5): ");
    if (scanf("%lf", &exame_final) != 1) return 1;

    media_ponderada = (trab_lab * 2.0 + aval_sem * 3.0 + exame_final * 5.0) / 10.0;

    printf("\nMedia Ponderada Final = %.2f\n", media_ponderada);
    printf("Situacao Academica: ");

    if (media_ponderada >= 5.0) {
        printf("APROVADO\n");
    } else if (media_ponderada >= 3.0) {
        printf("EM RECUPERACAO\n");
    } else {
        printf("REPROVADO\n");
    }

    return 0;
}
