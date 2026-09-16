#include <stdio.h>
#include <math.h>

/*
 * Questao 16: Quantidade de Degraus em uma Escada de Obra
 * Converte a altura total de metros para centimetros e calcula
 * o numero minimo de degraus necessarios arredondando para cima com ceil().
 */

int main(void) {
    double altura_degrau_cm, altura_total_m;
    printf("Digite a altura de cada degrau (em centimetros): ");
    if (scanf("%lf", &altura_degrau_cm) != 1) return 1;

    printf("Digite a altura total que deseja alcancar (em metros): ");
    if (scanf("%lf", &altura_total_m) != 1) return 1;

    double altura_total_cm = altura_total_m * 100.0;
    int degraus = (int)ceil(altura_total_cm / altura_degrau_cm);

    printf("Numero minimo de degraus necessarios: %d\n", degraus);
    return 0;
}
