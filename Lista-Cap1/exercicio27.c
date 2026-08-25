#include <stdio.h>

int main(void) {
    int totalSegundos;
    int horas, minutos, segundos;

    printf("Digite o intervalo de tempo em segundos: ");
    if (scanf("%d", &totalSegundos) == 1) {
        horas = totalSegundos / 3600;
        minutos = (totalSegundos % 3600) / 60;
        segundos = totalSegundos % 60;

        printf("%d segundos correspondem a %d hora(s), %d minuto(s) e %d segundo(s).\n",
               totalSegundos, horas, minutos, segundos);
    } else {
        printf("Entrada invalida. Por favor, insira um numero inteiro.\n");
    }

    return 0;
}
