#include <stdio.h>

/*
 * Questao 01: Sensibilidade a Caixa (Case Sensitivity) e Identificadores em C
 * Demonstra na pratica que identificadores com caixas diferentes representam
 * variaveis distintas com posicoes de memoria unicas.
 */

int main(void) {
    int valor = 10;
    int VALOR = 20;

    int peso = 70;
    int Peso = 85;

    int taxa = 5;
    int TAXA = 15;

    printf("Identificadores 'valor' e 'VALOR':\n");
    printf("  valor = %d (endereco: %p)\n", valor, (void*)&valor);
    printf("  VALOR = %d (endereco: %p)\n\n", VALOR, (void*)&VALOR);

    printf("Identificadores 'peso' e 'Peso':\n");
    printf("  peso  = %d (endereco: %p)\n", peso, (void*)&peso);
    printf("  Peso  = %d (endereco: %p)\n\n", Peso, (void*)&Peso);

    printf("Identificadores 'taxa' e 'TAXA':\n");
    printf("  taxa  = %d (endereco: %p)\n", taxa, (void*)&taxa);
    printf("  TAXA  = %d (endereco: %p)\n\n", TAXA, (void*)&TAXA);

    printf("Conclusao: A linguagem C diferencia rigorosamente maiusculas de minusculas (case-sensitive).\n");
    return 0;
}
