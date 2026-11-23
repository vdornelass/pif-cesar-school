#include <stdio.h>

/*
 * Questao 20: Numero Primo
 * Funcao int ehPrimo(int n) que retorna 1 se primo e 0 caso contrario.
 * Na main(), testa o valor e imprime todos os primos de 1 a 50.
 */

// Prototipo
int ehPrimo(int n);

int main(void) {
    int num;

    printf("=== VERIFICADOR E GERADOR DE NUMEROS PRIMOS ===\n");
    printf("Digite um numero inteiro para teste: ");
    if (scanf("%d", &num) != 1) return 1;

    if (ehPrimo(num)) {
        printf("O numero %d EH PRIMO.\n\n", num);
    } else {
        printf("O numero %d NAO EH PRIMO.\n\n", num);
    }

    printf("Listando todos os numeros primos de 1 ate 50:\n");
    for (int i = 1; i <= 50; i++) {
        if (ehPrimo(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}

int ehPrimo(int n) {
    if (n <= 1) return 0; // 0 e 1 nao sao primos
    if (n <= 3) return 1; // 2 e 3 sao primos
    if (n % 2 == 0 || n % 3 == 0) return 0;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return 0;
        }
    }
    return 1;
}
