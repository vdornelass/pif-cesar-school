#include <stdio.h>

/*
 * Questao 14: Matriz de Classificacao de Conceito por Nota e Faltas
 * Combina nota (float) e faltas (int) conforme tabela institucional.
 */

int main(void) {
    float nota;
    int faltas;
    char conceito;

    printf("=== CLASSIFICACAO DE CONCEITO ACADEMICO ===\n");
    printf("Digite a nota final (0.0 a 10.0): ");
    if (scanf("%f", &nota) != 1 || nota < 0.0f || nota > 10.0f) {
        printf("Erro: Nota invalida.\n");
        return 1;
    }

    printf("Digite a quantidade de faltas: ");
    if (scanf("%d", &faltas) != 1 || faltas < 0) {
        printf("Erro: Faltas invalidas.\n");
        return 1;
    }

    if (nota >= 9.0f) {
        conceito = (faltas <= 20) ? 'A' : 'B';
    } else if (nota >= 7.5f) {
        conceito = (faltas <= 20) ? 'B' : 'C';
    } else if (nota >= 5.0f) {
        conceito = (faltas <= 20) ? 'C' : 'D';
    } else if (nota >= 4.0f) {
        conceito = (faltas <= 20) ? 'D' : 'E';
    } else {
        conceito = 'E';
    }

    printf("\nNota: %.1f | Faltas: %d | Conceito Obtido: CONCEITO %c\n", nota, faltas, conceito);

    return 0;
}
