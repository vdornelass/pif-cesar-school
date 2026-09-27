# Lista de Exercícios – Simulado – Capítulos 1, 2 e 3
**Disciplina:** Programação Imperativa e Funcional (PIF - 2026.2)  
**Curso:** Graduação Tecnológica em Análise e Desenvolvimento de Sistemas (ADS)  
**Instituição:** CESAR School  
**Docente:** Prof. Danilo Farias Soares da Silva  
**Estudante:** Gabriel Dornelas  

---

## PARTE I: QUESTÕES TEÓRICAS E ANALÍTICAS (CONCEITOS E PRECEDÊNCIA)

### Questão 01. Sensibilidade a Caixa (Case Sensitivity) e Identificadores em C (Cap. 1)
Código demonstrativo em [`exercicio01.c`](exercicio01.c).

A linguagem C diferencia rigorosamente letras maiúsculas e minúsculas na formação de nomes de identificadores e palavras-chave. Com base nessa premissa, analise os pares de identificadores abaixo e assinale a alternativa correta:

- **a)** Os nomes de variáveis 'numero' e 'Numero' referenciam o mesmo endereço de memória.
- **b)** A palavra-chave 'Main' com 'M' maiúsculo é reconhecida pelo compilador como ponto de entrada válido.
- **c)** Todos os pares de nomes ('valor'/'VALOR', 'peso'/'Peso', 'taxa'/'TAXA') representam identificadores totalmente distintos para o compilador.
- **d)** A sensibilidade a caixa baixa/alta depende exclusivamente do sistema operacional utilizado na compilação.

> **Alternativa Correta:** **c) Todos os pares de nomes ('valor'/'VALOR', 'peso'/'Peso', 'taxa'/'TAXA') representam identificadores totalmente distintos para o compilador.**  
> 
> **Justificativa Detalhada:**
> - A linguagem C é estritamente **sensível à caixa** (*case-sensitive*). Na análise léxica, cada caractere é mapeado para o seu respectivo valor na tabela ASCII (por exemplo, `'v'` tem código decimal 118, enquanto `'V'` tem código decimal 86). Dessa forma, `valor` e `VALOR` geram símbolos internos completamente diferentes na tabela de símbolos do compilador e residem em endereços de memória distintos.
> - O item **a** é incorreto porque se tratam de posições de memória separadas.
> - O item **b** é incorreto porque o padrão ISO C define explicitamente que o ponto de entrada da execução de um programa C hospedado (*hosted environment*) deve ser a função `main` (com letras minúsculas); `Main` resultará em erro na etapa de linkedição (*undefined reference to `main`*).
> - O item **d** é incorreto porque a sensibilidade à caixa é uma especificação da sintaxe da linguagem C, e não do sistema operacional.

---

### Questão 02. Especificadores de Formato, Sequências de Escape e Erros de Compilação (Cap. 1)
Código corrigido em [`exercicio02.c`](exercicio02.c).

Código original analisado:
```c
#include <stdio.h>
#include <stdlib.h>;
int Main()
{
 int idade = 20;
 printf( A idade do aluno eh: %d anos.. , idade);
 cout << endl;
 system("PAUSE");
 return 0;
}
```

> **Identificação dos Três Erros Sintáticos / Estruturais Principais:**
> 
> 1. **Ponto-e-vírgula em diretiva de pré-processador (`#include <stdlib.h>;`):**  
>    As diretivas iniciadas por `#` pertencem ao pré-processador e não à gramática de instruções C. Elas terminam no final da linha e **não devem conter ponto-e-vírgula (`;`)**. A presença do `;` causa erro de sintaxe ou gera tokens indesejados.  
>    *Correção:* `#include <stdlib.h>`
> 
> 2. **Ponto de entrada grafado com maiúscula (`int Main()`):**  
>    Devido à característica *case-sensitive* de C, a função principal do programa deve ser obrigatoriamente grafada em minúsculas: `int main(void)` ou `int main()`. O compilador compila `Main()` como uma função comum e o *linker* emitirá o erro de símbolo indefinido `undefined reference to main`.  
>    *Correção:* `int main(void)`
> 
> 3. **Ausência de aspas duplas na string de controle do `printf`:**  
>    No trecho `printf( A idade do aluno eh: %d anos.. , idade);`, o texto a ser exibido não foi delimitado por aspas duplas `""`. O compilador interpreta cada palavra como um identificador ou operador C inexistente, gerando uma cascata de erros de compilação (*undeclared identifier*).  
>    *Correção:* `printf("A idade do aluno eh: %d anos..\n", idade);`
> 
> *(Erro adicional notável: a linha `cout << endl;` pertence à linguagem C++ `<iostream>` e não é válida em C padrão; em C utiliza-se `\n` ou `putchar('\n')` de `<stdio.h>`)*.

---

### Questão 03. Operadores de Atribuição Composta e Avaliação Sequencial (Cap. 2)
Código de validação em [`exercicio03.c`](exercicio03.c).

Valores iniciais: `int a = 2, b = 4, c = 5, d = 10;`

#### Avaliação Sequencial Passo a Passo:

1. **`a += b + c;`**
   - O operador de soma `+` tem maior precedência que o operador de atribuição composta `+=`.
   - Subexpressão: `b + c = 4 + 5 = 9`.
   - Atribuição: `a = a + 9 = 2 + 9 = 11`.
   - **Estado após a instrução:** `a = 11, b = 4, c = 5, d = 10`.

2. **`b *= c = d - 2;`**
   - Operadores de atribuição (`=` e `*=`) possuem associatividade da **direita para a esquerda** (*right-to-left*).
   - Avaliação da expressão aritmética: `d - 2 = 10 - 2 = 8`.
   - Primeira atribuição: `c = 8` (a variável `c` passa a valer 8, e o valor resultante da expressão é 8).
   - Segunda atribuição: `b *= 8` $\implies b = b \times 8 = 4 \times 8 = 32$.
   - **Estado após a instrução:** `a = 11, b = 32, c = 8, d = 10`.

3. **`d %= a + 3;`**
   - Expressão aritmética: `a + 3 = 11 + 3 = 14`.
   - Atribuição composta módulo: `d %= 14` $\implies d = 10 \pmod{14} = 10$.
   - **Estado após a instrução:** `a = 11, b = 32, c = 8, d = 10`.

4. **`a += b += c += 5;`**
   - Associatividade da direita para a esquerda:
     1. `c += 5` $\implies c = c + 5 = 8 + 5 = \mathbf{13}$ (o valor retornado da expressão é 13).
     2. `b += 13` $\implies b = b + 13 = 32 + 13 = \mathbf{45}$ (o valor retornado da expressão é 45).
     3. `a += 45` $\implies a = a + 45 = 11 + 45 = \mathbf{56}$.
   - **Estado final:** `a = 56, b = 45, c = 13, d = 10`.

| Variável | Valor Final |
| :---: | :---: |
| **`a`** | **56** |
| **`b`** | **45** |
| **`c`** | **13** |
| **`d`** | **10** |

---

### Questão 04. Avaliação de Expressões Lógicas, Relacionais e Precedência (Cap. 2)
Código de verificação em [`exercicio04.c`](exercicio04.c).

Valores fornecidos: `int i = 2, j = 3, k = 0; float x = 2.5, y = 5.0;`

| Item | Expressão | Avaliação Passo a Passo | Resultado em C |
| :---: | :--- | :--- | :---: |
| **a)** | `i < j + 2` | `j + 2 = 5` $\implies 2 < 5$ (Verdadeiro) | **1** |
| **b)** | `2 * i - 5 <= j - 4` | `2*2 - 5 = -1` e `3 - 4 = -1` $\implies -1 \le -1$ (Verdadeiro) | **1** |
| **c)** | `!k && (x + y >= 7.5)` | `k = 0 \implies !0 = 1`; `x + y = 7.5 \implies 7.5 \ge 7.5 = 1`; $1 \land 1 = 1$ | **1** |
| **d)** | `!(i == j) \|\| (y / x == 2.0)` | `i == j` é Falso ($0$); `!(0) = 1` (Verdadeiro); Por curto-circuito (*short-circuit*), $1 \lor (\dots) = 1$ | **1** |
| **e)** | `i == 2 && j == 4 \|\| k == 0` | O operador `&&` tem maior precedência: `(i == 2 && j == 4)` resulta em $1 \land 0 = 0$. Em seguida, $0 \lor (k == 0) \implies 0 \lor 1 = 1$ | **1** |

---

### Questão 05. Estruturas de Repetição: Comparação entre for, while e do-while (Cap. 3)
Código em [`exercicio05.c`](exercicio05.c).

**a) Qual é a diferença essencial entre while e do-while em relação ao número mínimo de execuções do bloco de código e ao momento do teste condicional?**  
> **Resposta:**  
> - **`while`:** Trata-se de uma estrutura pré-testada (*entry-condition*). A expressão de teste é avaliada **antes** de qualquer iteração. Se a condição for falsa de início, o bloco de comandos não é executado nenhuma vez (mínimo de **0 execuções**).  
> - **`do-while`:** Trata-se de uma estrutura pós-testada (*exit-condition*). O bloco de comandos é executado primeiro e a condição é testada apenas no final. Por isso, o bloco de código é executado **obrigatoriamente pelo menos uma vez** (mínimo de **1 execução**), mesmo que a condição seja falsa desde o início.

**b) Em que cenários o laço for se apresenta como a escolha mais elegante e legível frente ao laço while?**  
> **Resposta:** O laço `for` é a escolha mais elegante e legível em **iterações determinísticas ou contadas**, isto é, situações onde os limites de início, condição de parada e o passo de atualização da variável de controle são previamente definidos (ex: contagens de 1 a N, travessia de índices em arrays/vetores e matrizes bidimensionais). Sua vantagem reside em encapsular a inicialização, a guarda de parada e o incremento centralizados em uma única linha no cabeçalho.

**c) O trecho de código 'while (condicao);' (com ponto-e-vírgula ao final do cabeçalho) constitui um erro de compilação ou de lógica? O que acontece se condicao for verdadeira?**  
> **Resposta:** Constitui um **erro de lógica** (*semantic bug*). Em C, o ponto-e-vírgula `;` isolado representa a instrução nula (*null statement*). Se a condição avaliada for verdadeira e não houver alteração de estado na própria expressão condicional, o programa entrará em um **laço infinito em espera ativa (*busy-wait*)**, consumindo CPU indefinidamente e travando a execução do programa naquele ponto.

---

### Questão 06. Escopo de Bloco e Comandos de Desvio (break e continue) (Cap. 3)
Código corrigido em [`exercicio06.c`](exercicio06.c).

Código sob análise:
```c
#include <stdio.h>
#include <stdlib.h>
int main() {
    int i;
    for (i = 1; i <= 10; i++) {
        if (i == 5) continue;
        if (i == 8) break;
        int soma = 0;
        soma += i * i;
    }
    printf("Soma final = %d\n", soma);
    system("PAUSE");
    return 0;
}
```

**a) Por que o compilador emitirá um erro de compilação na instrução printf final?**  
> **Resposta:** Porque a variável `soma` foi declarada **dentro do bloco do laço `for`**. Em C, variáveis declaradas no corpo de um bloco de chaves `{}` possuem **escopo de bloco** (*block scope*). Fora do laço `for`, no `printf("Soma final = %d\n", soma);`, o identificador `soma` não é visível e não existe na memória, gerando erro de compilação (`'soma' undeclared`).

**b) Quais iterações do laço serão efetivamente executadas e qual o impacto dos comandos continue e break no fluxo?**  
> **Resposta:**  
> - **`i = 1, 2, 3, 4`:** Executam normalmente o corpo do laço, calculando os quadrados.  
> - **`i = 5`:** A condição `if (i == 5)` é verdadeira e o comando `continue` é acionado. O `continue` aborta imediatamente o restante da iteração 5 e salta direto para o incremento `i++`. Logo, o quadrado de 5 **não é somado**.  
> - **`i = 6, 7`:** Executam normalmente o corpo do laço, calculando os quadrados.  
> - **`i = 8`:** A condição `if (i == 8)` é verdadeira e o comando `break` é acionado. O `break` encerra imediatamente e de forma definitiva o laço `for`. As iterações `8`, `9` e `10` **não chegam a ser executadas**.  
> - **Iterações com cálculo efetivo:** `i = 1, 2, 3, 4, 6, 7`.

**c) Reescreva o código corrigindo o escopo de 'soma' e apresente o resultado que será impresso no console.**  
> **Código Corrigido:**
> ```c
> #include <stdio.h>
> 
> int main(void) {
>     int i;
>     int soma = 0; // Declarada fora do laço para preservar o acumulador
> 
>     for (i = 1; i <= 10; i++) {
>         if (i == 5) continue;
>         if (i == 8) break;
>         soma += i * i;
>     }
> 
>     printf("Soma final = %d\n", soma);
>     return 0;
> }
> ```
> **Resultado no Console:**  
> Cálculo da soma acumulada:  
> $$1^2 + 2^2 + 3^2 + 4^2 + 6^2 + 7^2 = 1 + 4 + 9 + 16 + 36 + 49 = \mathbf{115}$$  
> **Saída:**  
> `Soma final = 115`

---

## PARTE II: QUESTÕES PRÁTICAS DE IMPLEMENTAÇÃO (CÓDIGO FONTE EM C)

| Questão | Descrição do Problema | Arquivo Fonte |
| :---: | :--- | :---: |
| **Questão 8** | Cálculos geométricos da esfera: área da superfície ($4\pi R^2$) e volume ($(4.0/3.0)\pi R^3$) com `pow()` e $\pi = 3.14159265$ formatados em 3 casas decimais. | [`exercicio08.c`](exercicio08.c) |
| **Questão 9** | Geometria do triângulo: validação de existência, cálculo do semiperímetro $p$ e determinação da área pela Fórmula de Heron com `sqrt()`. | [`exercicio09.c`](exercicio09.c) |
| **Questão 10** | Decomposição temporal de segundos inteiros em Horas, Minutos e Segundos utilizando divisões inteiras (`/`) e resto da divisão (`%`). | [`exercicio10.c`](exercicio10.c) |
| **Questão 11** | Cálculo de folha de técnico com valor por diária (R$ 45,00/dia), gratificação de 5%, retenção de IR de 8% e emissão de holerite detalhado. | [`exercicio11.c`](exercicio11.c) |
| **Questão 12** | Validação garantida de nota no intervalo fechado $[0.0, 10.0]$ repetindo a solicitação com a estrutura `do-while`. | [`exercicio12.c`](exercicio12.c) |
| **Questão 13** | Cálculo de fatorial ($N!$) com suporte a `long long int` (`%lld`), validação de negativos e tratamento de casos especiais ($0! = 1, 1! = 1$). | [`exercicio13.c`](exercicio13.c) |
| **Questão 14** | Sistema de controle de acesso com autenticação de senha numérica (2026) e limite máximo de 3 tentativas com bloqueio de segurança. | [`exercicio14.c`](exercicio14.c) |
| **Questão 15** | Geração do padrão visual do Triângulo de Floyd de $N$ linhas utilizando laços aninhados e contagem progressiva. | [`exercicio15.c`](exercicio15.c) |
