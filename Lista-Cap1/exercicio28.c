#include <stdio.h>

int main(void) {
    int v1, v2, v3;

    printf("Digite tres valores inteiros separados por espaco: ");
    if (scanf("%d %d %d", &v1, &v2, &v3) == 3) {
        double media = (double)(v1 + v2 + v3) / 3.0;
        printf("A media aritmetica simples dos valores eh: %.2f\n", media);
    } else {
        printf("Entrada invalida. Por favor, digite tres numeros inteiros.\n");
    }

    return 0;
}
