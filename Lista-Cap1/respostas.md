# Lista de Exercícios - Capítulo 1
**Disciplina:** Programação Imperativa e Funcional (PIF)  
**Curso:** Análise e Desenvolvimento de Sistemas - CESAR School (2026.2)  
**Docente:** Prof. Danilo Farias Soares da Silva  

---

### Questão 01
Código em [`exercicio01.c`](exercicio01.c). Declara uma variável inteira `anoAtual` e imprime o valor com o especificador `%d`.

### Questão 02
Código em [`exercicio02.c`](exercicio02.c). Declara uma variável `float` com o número de Euler (2.71828) e exibe com 3 casas decimais (`%.3f`).

### Questão 03
Código em [`exercicio03.c`](exercicio03.c). Demonstra o uso de comentários de múltiplas linhas e linha única conforme o modelo fornecido.

### Questão 04
Código corrigido em [`exercicio04.c`](exercicio04.c).

**Erros identificados no código original:**
1. `#include <stdlib.h>;` - Presença indevida de ponto e vírgula ao final da diretiva.
2. `int Main{}` - A linguagem C é case-sensitive (`main` em minúsculo) e parênteses `()` devem ser usados para a lista de parâmetros.
3. `(` e `)` - O bloco da função deve usar chaves `{}`.
4. `printf( Existem %d semanas no ano.,52);` - Falta de aspas duplas na string de formato.
5. `cout << endl;` - Comando de C++ (`iostream`), inexistente na linguagem C.

### Questão 05
Código corrigido em [`exercicio05.c`](exercicio05.c).

**Análise (ANSI C):** O código original não está correto para compilação direta.
**Elementos faltantes:**
1. Inclusão dos cabeçalhos `#include <stdio.h>` e `#include <stdlib.h>`.
2. Especificação do tipo de retorno `int` para `main()`.
3. Instrução `return 0;` ao final da função.

### Questão 06
Código corrigido em [`exercicio06.c`](exercicio06.c).

**Erros identificados:**
1. `int a=1; b=2; c=3:` - Variáveis separadas por `;` sem tipo declarado e terminando em `:` em vez de `;`.
2. `printf("0s números são: %d%d%d\n, a, b, c, d);` - Falta aspa de fechamento, passa 4 argumentos para 3 especificadores `%d` e usa a variável `d` não declarada.
3. Ausência dos cabeçalhos `<stdio.h>` e `<stdlib.h>`, do tipo `int` em `main()` e do `return 0;`.

### Questão 07
Saída exata de cada instrução:

- **a)** `printf("\n\tBom dia! Shirley.");`  
  Quebra de linha, tabulação e `Bom dia! Shirley.`
- **b)** `printf("Você já tomou café? \n");`  
  `Você já tomou café? ` seguido de quebra de linha.
- **c)** `printf("\n\nA solução não existe!\nNão insista.");`  
  Duas quebras de linha, `A solução não existe!`, quebra de linha e `Não insista.`
- **d)** `printf("Duas\tlinhas\tde\tsaída\ou\tuma?");`  
  `Duas	linhas	de	saídaou	uma?` (a sequência `\o` é lida como a letra 'o').
- **e)** `printf("%s\n%s\n%s\n", "um", "dois", "três");`  
  `um`, `dois` e `três` impressos cada um em sua própria linha.

### Questão 08
Código em [`exercicio08.c`](exercicio08.c).  
As sequências de escape `\n` pula linha, `\t` insere tabulação e `\"` imprime aspas duplas.

**Saída exata:**
```text

	"Primeiro programa"
```

### Questão 09
Código em [`exercicio09.c`](exercicio09.c).  
O modificador `%c` interpreta os valores inteiros ASCII para os caracteres `'\n'`, `'\t'` e `'\"'`.

**Saída exata:**
```text

	"Primeiro programa"
```

### Questão 10
**Resposta:** **b) Verdadeiro** (a linguagem C diferencia rigorosamente letras maiúsculas de minúsculas).

**Justificativa:** Em C, letras maiúsculas e minúsculas possuem códigos ASCII diferentes. Portanto, `peso`, `Peso` e `PESO` são três variáveis totalmente distintas na memória.

### Questão 11
| Constante | Classificação | Tipo Base em C |
| :--- | :--- | :--- |
| `\r` | Sequência de escape | `char` |
| `2130` | Constante inteira decimal | `int` |
| `-123` | Constante inteira decimal | `int` |
| `33.28` | Constante de ponto flutuante | `double` |
| `0XFA` | Constante inteira hexadecimal | `int` |
| `0101` | Constante inteira octal | `int` |
| `2.0e30` | Constante de ponto flutuante (notação científica) | `double` |
| `\xDC` | Sequência de escape hexadecimal | `char` |
| `'\"'` | Constante de caractere | `char` |
| `'\\'` | Constante de caractere | `char` |
| `'F'` | Constante de caractere | `char` |
| `0` | Constante inteira decimal | `int` |
| `'\0'` | Constante de caractere (nulo) | `char` |
| `"F"` | Constante string | `char[]` / `char *` |
| `-4567.89` | Constante de ponto flutuante | `double` |

### Questão 12
| Instrução | Status (C/I) | Justificativa Teórica |
| :--- | :--- | :--- |
| a) `int a;` | Correto | Declaração válida de inteiro. |
| b) `float b;` | Correto | Declaração válida de ponto flutuante. |
| c) `double float c;` | Incorreto | `double` e `float` não podem ser combinados. |
| d) `unsigned char d;` | Correto | Declaração válida de caractere sem sinal. |
| e) `unsigned e;` | Correto | Válido em C (equivale a `unsigned int`). |
| f) `long float f;` | Incorreto | Sintaxe inválida no C moderno (usar `double`). |
| g) `long g;` | Correto | Válido em C (equivale a `long int`). |
| h) `long double h;` | Correto | Declaração válida de precisão estendida. |

### Questão 13
**Resposta:** **c)** São arquivos de texto ASCII padrão contendo protótipos de funções, definições de constantes, macros e tipos.

### Questão 14
**Resposta:** **a)** Instruir o compilador a carregar as definições das funções da biblioteca padrão antes de compilar o código-fonte.

### Questão 15
**Resposta:** **c)** Uma diretiva especial para o pré-processador C, executada antes da compilação.

### Questão 16
**Resposta:** **c)** Pré-processador (fase do compilador que altera o programa-fonte antes da compilação propriamente dita).

### Questão 17
As opções **a**, **b** e **c** estão corretas. A opção **d** está incorreta pois chamadas de função em C exigem parênteses. Isso demonstra que o compilador C ignora espaços em branco entre os elementos sintáticos.

### Questão 18
Código em [`exercicio18.c`](exercicio18.c). Tabela de preços alinhada à direita usando `%12.2f`.

### Questão 19
Código em [`exercicio19.c`](exercicio19.c). Tabulação em cascata em um único `printf()`.

### Questão 20
Código em [`exercicio20.c`](exercicio20.c). Moldura 4x4 em ASCII estendido usando constantes hexadecimais.

### Questão 21
Código em [`exercicio21.c`](exercicio21.c). Três versões independentes (1 printf, 2 printfs e moldura).

### Questão 22
Código em [`exercicio22.c`](exercicio22.c). Arte gráfica de carro e caminhonete com blocos `\xDC` e `\xDF`.

### Questão 23
Código em [`exercicio23.c`](exercicio23.c). Caixa retangular 5x5 vazia com 'X'.

### Questão 24
Código em [`exercicio24.c`](exercicio24.c). Tabela de notas escolares alinhada com larguras de campo.

### Questão 25
Código em [`exercicio25.c`](exercicio25.c). Letra 'C' ampliada impressa com um único `printf()`.

### Questão 26
Código em [`exercicio26.c`](exercicio26.c). Pinheiro de Natal estilizado com enfeites.

### Questão 27
Código em [`exercicio27.c`](exercicio27.c). Conversão de segundos em Horas, Minutos e Segundos usando `scanf()`.

### Questão 28
Código em [`exercicio28.c`](exercicio28.c). Média de 3 inteiros como `double` formatada a 2 casas decimais.
