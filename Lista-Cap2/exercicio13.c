#include <stdio.h>

/*
 * Questao 13: Calculo de Areas de Figuras Planas Basicas
 * a) Area do quadrado (L * L)
 * b) Area do retangulo (B * H)
 * c) Area do triangulo retangulo ((B * H) / 2.0)
 */

int main(void) {
    double lado, base_ret, altura_ret, base_tri, altura_tri;

    printf("--- Geometria Plana Basica ---\n");
    printf("Digite o lado do quadrado (L): ");
    if (scanf("%lf", &lado) != 1) return 1;

    printf("Digite a base (B) e a altura (H) do retangulo: ");
    if (scanf("%lf %lf", &base_ret, &altura_ret) != 2) return 1;

    printf("Digite a base (B) e a altura (H) do triangulo retangulo: ");
    if (scanf("%lf %lf", &base_tri, &altura_tri) != 2) return 1;

    double area_quadrado = lado * lado;
    double area_retangulo = base_ret * altura_ret;
    double area_triangulo = (base_tri * altura_tri) / 2.0;

    printf("\n--- Resultados ---\n");
    printf("a) Area do quadrado: %.2f\n", area_quadrado);
    printf("b) Area do retangulo: %.2f\n", area_retangulo);
    printf("c) Area do triangulo retangulo: %.2f\n", area_triangulo);

    return 0;
}
