#include <stdio.h>
#include <math.h>

#define PI 3.14159265

/*
 * Questao 8: Calculos Geometricos e Constantes com <math.h>
 * Solicita o raio R de uma esfera e calcula a area da superficie e o volume
 * utilizando a constante PI e a funcao pow() de <math.h>.
 * Formata os resultados com 3 casas decimais.
 */

int main(void) {
    double r;

    printf("Digite o raio R da esfera: ");
    if (scanf("%lf", &r) != 1 || r < 0.0) {
        printf("Valor invalido! O raio deve ser um numero nao-negativo.\n");
        return 1;
    }

    double area = 4.0 * PI * pow(r, 2.0);
    double volume = (4.0 / 3.0) * PI * pow(r, 3.0); // Divisao real 4.0 / 3.0

    printf("\n=== Resultados para Esfera de Raio R = %.3f ===\n", r);
    printf("a) Area da superficie: %.3f\n", area);
    printf("b) Volume da esfera:    %.3f\n", volume);

    return 0;
}
