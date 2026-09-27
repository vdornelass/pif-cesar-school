#include <stdio.h>

/*
 * Questao 10: Resto da Divisao (%) e Decomposicao do Tempo
 * Le uma quantidade inteira de segundos e decompoe em Horas, Minutos e Segundos
 * utilizando operadores de divisao inteira (/) e resto da divisao (%).
 */

int main(void) {
    long long int total_segundos;

    printf("Digite a quantidade inteira de segundos: ");
    if (scanf("%lld", &total_segundos) != 1 || total_segundos < 0) {
        printf("Valor invalido! Por favor forneca um valor positivo ou zero.\n");
        return 1;
    }

    long long int horas = total_segundos / 3600;
    long long int resto = total_segundos % 3600;
    long long int minutos = resto / 60;
    long long int segundos = resto % 60;

    printf("\n%lld segundos correspondem a:\n", total_segundos);
    printf("%lld hora(s), %lld minuto(s) e %lld segundo(s)\n", horas, minutos, segundos);
    printf("Formato HH:MM:SS -> %02lld:%02lld:%02lld\n", horas, minutos, segundos);

    return 0;
}
