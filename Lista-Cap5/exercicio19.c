#include <stdio.h>

/*
 * Questao 19: Contagem Regressiva e Crescente Recursiva
 * Demonstra como a ordem da chamada recursiva em relacao ao printf
 * altera o sentido da impressao (empilhamento vs desempilhamento).
 */

// Prototipos
void contagem(int n);
void contagemCrescente(int n);

int main(void) {
    int n;

    printf("=== CONTAGEM RECURSIVA ===\n");
    printf("Digite um valor inicial positivo: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Erro: Digite um valor maior que zero.\n");
        return 1;
    }

    printf("\n--- Contagem Regressiva (Impressao no Empilhamento) ---\n");
    contagem(n);

    printf("\n--- Contagem Crescente (Impressao no Desempilhamento) ---\n");
    contagemCrescente(n);
    printf("\n");

    return 0;
}

void contagem(int n) {
    // Caso Base
    if (n < 1) {
        printf("Fogo!\n");
        return;
    }
    // Imprime ANTES da chamada recursiva: executa durante a descida (empilhamento)
    printf("%d... ", n);
    contagem(n - 1);
}

void contagemCrescente(int n) {
    // Caso Base
    if (n < 1) {
        return;
    }
    // Chama recursivamente ANTES de imprimir: executa na volta (desempilhamento)
    contagemCrescente(n - 1);
    printf("%d... ", n);
}
