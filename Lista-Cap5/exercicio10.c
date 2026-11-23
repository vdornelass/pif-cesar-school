#include <stdio.h>

/*
 * Questao 10: Area da Esfera com #define
 * Constante PI via #define e funcao float area(float r) usando 4 * PI * r^2.
 */

#define PI 3.14159265f

// Prototipo
float area(float r);

int main(void) {
    float raio, resultado;

    printf("=== CALCULO DA AREA DA ESFERA ===\n");
    printf("Digite o raio da esfera: ");
    if (scanf("%f", &raio) != 1 || raio < 0.0f) {
        printf("Erro: Raio invalido.\n");
        return 1;
    }

    resultado = area(raio);

    printf("Area da superficie esferica = %.4f\n", resultado);

    return 0;
}

float area(float r) {
    return 4.0f * PI * r * r;
}
