#include <stdio.h>

/*
 * Questao 15: Media Ponderada e Situacao
 * Funcao float mediaPonderada(float n1, float n2, float n3) com pesos 2, 3 e 5.
 * Procedimento void exibeSituacao(float media).
 */

// Prototipos
float mediaPonderada(float n1, float n2, float n3);
void exibeSituacao(float media);

int main(void) {
    float n1, n2, n3, media;

    printf("=== AVALIACAO ACADEMICA MODULAR ===\n");
    printf("Digite as tres notas (Trabalho, Avaliacao, Exame): ");
    if (scanf("%f %f %f", &n1, &n2, &n3) != 3) return 1;

    media = mediaPonderada(n1, n2, n3);

    printf("\nMedia Ponderada: %.2f\n", media);
    exibeSituacao(media);

    return 0;
}

float mediaPonderada(float n1, float n2, float n3) {
    return (n1 * 2.0f + n2 * 3.0f + n3 * 5.0f) / 10.0f;
}

void exibeSituacao(float media) {
    printf("Situacao Final: ");
    if (media >= 5.0f) {
        printf("Aprovado\n");
    } else if (media >= 3.0f) {
        printf("Em Recuperacao\n");
    } else {
        printf("Reprovado\n");
    }
}
