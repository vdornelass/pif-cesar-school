#include <stdio.h>

/*
 * Questao 01: Anatomia de uma Funcao e o Papel do Prototipo
 * Demonstracao de prototipo, chamada e definicao da funcao celsius().
 */

// 1. Prototipo da funcao (declaracao pre-main)
float celsius(float);

int main(void) {
    float c, f = 100.0f;

    printf("=== QUESTAO 01: PROTOTIPO, CHAMADA E DEFINICAO ===\n");
    printf("Temperatura em Fahrenheit de entrada: %.2f F\n", f);

    // 2. Chamada da funcao
    c = celsius(f);

    printf("Resultado convertido para Celsius: %.2f C\n", c);

    return 0;
}

// 3. Definicao da funcao (cabecalho + corpo)
float celsius(float fahr) {
    return (fahr - 32.0f) * 5.0f / 9.0f;
}
