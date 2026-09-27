#include <stdio.h>
#include <stdlib.h> // Correcao 1: sem ponto-e-virgula ao final da diretiva de include

/*
 * Questao 02: Especificadores de Formato, Sequencias de Escape e Erros de Compilacao
 * Versao corrigida do codigo do estudante:
 * 1. Removido o ponto-e-virgula apos '#include <stdlib.h>'
 * 2. Corrigido 'Main()' para 'main()' com letra minuscula
 * 3. Delimitada a string de formato do printf com aspas duplas e adicionado '\n'
 * 4. Substituido 'cout << endl;' (C++) por funcao padrao de C (printf/putchar)
 */

int main(void) { // Correcao 2: main() em minusculas
    int idade = 20;

    // Correcao 3: string entre aspas duplas formatada com especificador %d
    printf("A idade do aluno eh: %d anos..\n", idade);

    // Correcao 4: em C utiliza-se quebra de linha nativa em vez do comando C++ 'cout << endl;'
    putchar('\n');

    return 0;
}
