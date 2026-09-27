#include <stdio.h>

/*
 * Questao 26: Mapeamento e Soma de Primos em um Intervalo Fechado [A, B]
 * Solicita dois inteiros positivos A e B garantindo A < B.
 * Lista todos os primos no intervalo fechado [A, B] e exibe a soma total deles.
 */

int main(void) {
    int a, b;

    do {
        printf("Digite dois numeros inteiros positivos A e B (com A < B):\n");
        printf("A: ");
        if (scanf("%d", &a) != 1) {
            while (getchar() != '\n');
            continue;
        }
        printf("B: ");
        if (scanf("%d", &b) != 1) {
            while (getchar() != '\n');
            continue;
        }

        if (a <= 0 || b <= 0) {
            printf("Erro: Ambos os numeros devem ser estritamente positivos!\n\n");
        } else if (a >= b) {
            printf("Erro: A deve ser estritamente menor que B (%d >= %d)!\n\n", a, b);
        }
    } while (a <= 0 || b <= 0 || a >= b);

    long long int soma_primos = 0;
    int qtd_primos = 0;

    printf("\nNumeros primos no intervalo [%d, %d]:\n", a, b);

    for (int num = a; num <= b; num++) {
        if (num <= 1) {
            continue;
        }

        int primo = 1;
        for (int d = 2; d * d <= num; d++) {
            if (num % d == 0) {
                primo = 0;
                break;
            }
        }

        if (primo) {
            printf("%d ", num);
            soma_primos += num;
            qtd_primos++;
        }
    }

    if (qtd_primos == 0) {
        printf("Nenhum numero primo encontrado no intervalo.\n");
    } else {
        printf("\n\nTotal de primos encontrados: %d\n", qtd_primos);
        printf("Soma total dos numeros primos: %lld\n", soma_primos);
    }

    return 0;
}
