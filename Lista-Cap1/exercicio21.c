#include <stdio.h>

void versao1(void) {
    printf("--- Versao 1: Unica chamada a printf() ---\n");
    printf("Treinamento em programacao.\nLinguagem C.\n\n");
}

void versao2(void) {
    printf("--- Versao 2: Duas chamadas independentes a printf() ---\n");
    printf("Treinamento em programacao.\n");
    printf("Linguagem C.\n\n");
}

void versao3(void) {
    printf("--- Versao 3: Frases emolduradas com caracteres graficos ---\n");
    printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    printf("\xBA Treinamento em programacao. \xBA\n");
    printf("\xBA Linguagem C.                 \xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
}

int main(void) {
    versao1();
    versao2();
    versao3();
    return 0;
}
