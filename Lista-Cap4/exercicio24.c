#include <stdio.h>

/*
 * Questao 24: Classificacao de Triangulos quanto aos Angulos Internos
 * Le tres angulos inteiros. Valida se a soma eh igual a 180 graus.
 * Classifica:
 * Retangulo: possui angulo de 90 graus
 * Obtusangulo: possui angulo maior que 90 graus
 * Acutangulo: possui todos os tres menores que 90 graus
 */

int main(void) {
    int a1, a2, a3;

    printf("=== CLASSIFICADOR DE TRIANGULOS POR ANGULOS ===\n");
    printf("Digite os tres angulos internos (graus): ");
    if (scanf("%d %d %d", &a1, &a2, &a3) != 3) return 1;

    if (a1 <= 0 || a2 <= 0 || a3 <= 0 || (a1 + a2 + a3 != 180)) {
        printf("Erro: A soma dos angulos deve ser exatamente 180 graus e todos devem ser positivos!\n");
        return 1;
    }

    printf("Triangulo Valido! Classificacao: ");
    if (a1 == 90 || a2 == 90 || a3 == 90) {
        printf("RETANGULO (possui um angulo reto de 90 graus)\n");
    } else if (a1 > 90 || a2 > 90 || a3 > 90) {
        printf("OBTUSANGULO (possui um angulo obtuso > 90 graus)\n");
    } else {
        printf("ACUTANGULO (todos os tres angulos sao agudos < 90 graus)\n");
    }

    return 0;
}
