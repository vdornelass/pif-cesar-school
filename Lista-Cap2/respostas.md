# Lista de Exercícios – Capítulo 2: Operadores e Entrada/Saída Formatada
**Disciplina:** Programação Imperativa e Funcional (PIF - 2026.2)  
**Curso:** Graduação Tecnológica em Análise e Desenvolvimento de Sistemas (ADS)  
**Instituição:** CESAR School  
**Docente:** Prof. Danilo Farias Soares da Silva  
**Estudante:** Gabriel Dornelas  

---

## PARTE I: QUESTÕES TEÓRICAS E ANALÍTICAS (CONCEITOS E PRECEDÊNCIA)

### Questão 01. Truncamento de Tipos e Coerção Implícita
Código em [`exercicio01.c`](exercicio01.c).

**a) Qual é o valor numérico que será efetivamente exibido no console ao executar esse programa?**  
> **Resposta:** O valor exibido será **`2`**.

**b) Explique por que isso ocorre. Qual é o nome do fenômeno que acontece nessa atribuição?**  
> **Resposta:** Isso ocorre porque a variável `valor_inteiro` foi declarada como inteira (`int`), enquanto o literal atribuído `2.97` é um número em ponto flutuante de precisão dupla (`double`). Quando um tipo de dado de maior domínio/precisão é atribuído a uma variável de menor domínio sem conversão explícita, a linguagem C realiza automaticamente uma **coerção implícita de tipo** (*implicit type conversion*). Nesse processo, a parte fracionária (`.97`) é descartada sumariamente. Esse descarte da fração sem qualquer arredondamento é denominado **truncamento** (*truncation*).

**c) Como este tipo de comportamento pode ser evitado ou controlado explicitamente em C pelo programador caso ele necessite arredondar o valor ou manter a precisão?**  
> **Resposta:**  
> 1. **Para manter a precisão real:** Declarar a variável com um tipo de ponto flutuante apropriado, como `float` ou `double` (ex: `double valor = 2.97; printf("%.2f\n", valor);`).  
> 2. **Para arredondamento explícito:** Utilizar as funções matemáticas da biblioteca `<math.h>`:  
>    - `round(2.97)`: arredonda para o inteiro mais próximo (resultando em `3.0`).  
>    - `ceil(2.97)`: arredonda sempre para cima (teto, resultando em `3.0`).  
>    - `floor(2.97)`: arredonda sempre para baixo (piso, resultando em `2.0`).  
> 3. **Para conversão explícita (Type Casting):** Fazer o casting explícito de tipos para documentar a intenção do código, como `(int)(valor + 0.5)` para arredondamento positivo simples ou `(int)round(valor)`.

---

### Questão 02. Entrada Standard de Caracteres vs. Bibliotecas Legadas
Código demonstrativo em [`exercicio02.c`](exercicio02.c).

**a) Por que o uso de funções contidas em `<conio.h>` deve ser evitado em sistemas modernos (Linux, macOS, servidores)?**  
> **Resposta:** O cabeçalho `<conio.h>` (*Console Input/Output*) e suas funções associadas (como `getch()`, `getche()`, `clrscr()`) são extensões proprietárias antigas criadas para compiladores DOS/Windows da década de 1980 (como MS-DOS Turbo C). Elas **não fazem parte do padrão ANSI/ISO C** (C89, C99, C11, etc.). Em consequência, sistemas POSIX modernos (Linux, macOS, BSD e servidores de produção) não possuem esse cabeçalho por padrão, tornando o código não portável e incompatível.

**b) Quais são as funções equivalentes e portáveis fornecidas pela biblioteca padrão `<stdio.h>` para entrada e saída de caracteres?**  
> **Resposta:**  
> - **Entrada de caracteres:** `getchar()`, `fgetc(stdin)`, `getc(stdin)` e `scanf(" %c", &var)`.  
> - **Saída de caracteres:** `putchar()`, `fputc(c, stdout)`, `putc(c, stdout)` e `printf("%c", c)`.

**c) Escreva um pequeno trecho de código padrão C que leia um caractere do console de maneira robusta, ignorando eventuais quebras de linha (`'\n'`) residuais no buffer do teclado.**  
```c
char c;
// O espaco em branco antes de %c instrui o scanf a ignorar automaticamente 
// quaisquer espacos em branco, tabs e quebras de linha ('\n') pendentes no buffer.
scanf(" %c", &c);
```

---

### Questão 03. Formatação de Saída em Bases Numéricas e ASCII
Código em [`exercicio03.c`](exercicio03.c).

Lê um número inteiro e exibe simultaneamente em base decimal (`%d`), hexadecimal em caixa baixa (`%x`), octal (`%o`) e o caractere ASCII correspondente (`%c`).

```c
#include <stdio.h>

int main(void) {
    int valor;
    printf("Digite um numero inteiro: ");
    if (scanf("%d", &valor) == 1) {
        printf("Decimal: %d | Hexadecimal: %x | Octal: %o | ASCII: %c\n",
               valor, valor, valor, (char)valor);
    }
    return 0;
}
```

---

### Questão 04. Operadores de Atribuição Composta e Precedência
Código de verificação em [`exercicio04.c`](exercicio04.c).

Valores iniciais: `int a = 1, b = 2, c = 3, d = 4;`

#### Avaliação Passo a Passo:

1. **`a += b + c;`**
   - O operador aritmético `+` possui precedência superior ao operador de atribuição composta `+=`.
   - Avaliação da subexpressão: `b + c` $ightarrow 2 + 3 = 5$.
   - Execução da atribuição composta: `a = a + 5` $ightarrow a = 1 + 5 = \mathbf{6}$.
   - **Estado após o comando:** `a = 6, b = 2, c = 3, d = 4`.

2. **`b *= c = d + 2;`**
   - Avaliação aritmética: `d + 2` $ightarrow 4 + 2 = 6$.
   - Operadores de atribuição (`=` e `*=`) possuem associatividade da **direita para a esquerda** (*right-to-left*).
   - Primeira atribuição: `c = 6` $ightarrow \mathbf{c = 6}$ (o resultado da expressão de atribuição é 6).
   - Segunda atribuição: `b *= 6` $ightarrow b = b 	imes 6 = 2 	imes 6 = \mathbf{12}$.
   - **Estado após o comando:** `a = 6, b = 12, c = 6, d = 4`.

3. **`d %= a + a + a;`**
   - Avaliação aritmética: `a + a + a` $ightarrow 6 + 6 + 6 = 18$.
   - Execução da atribuição composta: `d %= 18` $ightarrow d = d \pmod{18} = 4 \pmod{18} = \mathbf{4}$.
   - **Estado após o comando:** `a = 6, b = 12, c = 6, d = 4`.

4. **`d -= c -= b -= a;`**
   - Associatividade da direita para a esquerda:
     1. `b -= a` $ightarrow b = b - a = 12 - 6 = \mathbf{6}$ (o valor retornado é 6).
     2. `c -= 6` $ightarrow c = c - 6 = 6 - 6 = \mathbf{0}$ (o valor retornado é 0).
     3. `d -= 0` $ightarrow d = d - 0 = 4 - 0 = \mathbf{4}$.
   - **Estado após o comando:** `a = 6, b = 6, c = 0, d = 4`.

5. **`a += b += c += 7;`**
   - Associatividade da direita para a esquerda:
     1. `c += 7` $ightarrow c = c + 7 = 0 + 7 = \mathbf{7}$ (o valor retornado é 7).
     2. `b += 7` $ightarrow b = b + 7 = 6 + 7 = \mathbf{13}$ (o valor retornado é 13).
     3. `a += 13` $ightarrow a = a + 13 = 6 + 13 = \mathbf{19}$.
   - **Estado final:** `a = 19, b = 13, c = 7, d = 4`.

| Variável | Valor Final |
| :--- | :--- |
| **`a`** | **19** |
| **`b`** | **13** |
| **`c`** | **7** |
| **`d`** | **4** |

---

### Questão 05. Avaliação de Expressões Lógicas e Relacionais
Código de verificação em [`exercicio05.c`](exercicio05.c).

Valores iniciais: `int i = 1, j = 2, k = 3, n = 2; float x = 3.3, y = 4.4;`

| Item | Expressão | Avaliação Passo a Passo | Resultado Lógico |
| :--- | :--- | :--- | :---: |
| **a)** | `i < j + 3` | `j + 3 = 5` $ightarrow 1 < 5$ (Verdadeiro) | **1** |
| **b)** | `2 * i - 7 <= j - 8` | `2*1 - 7 = -5` e `2 - 8 = -6` $ightarrow -5 \le -6$ (Falso) | **0** |
| **c)** | `-x + y >= 2.0 * y` | `-3.3 + 4.4 = 1.1` e `2.0 * 4.4 = 8.8` $ightarrow 1.1 \ge 8.8$ (Falso) | **0** |
| **d)** | `x == y` | `3.3 == 4.4` (Falso) | **0** |
| **e)** | `!(n - j)` | `n - j = 2 - 2 = 0` $ightarrow !(0) = 1$ (Verdadeiro) | **1** |
| **f)** | `!n - j` | `!n = !(2) = 0` (não-zero é V, negado vira 0) $ightarrow 0 - 2 = \mathbf{-2}$ (Valor numérico $-2$) | **-2** *(não-zero: Verdadeiro)* |
| **g)** | `i && j && k` | `1 && 2 && 3` $ightarrow 1 \land 1 \land 1 = 1$ (Todos não-zero) | **1** |
| **h)** | `i || j - 3 && k` | `i = 1` (Verdadeiro) $ightarrow$ por curto-circuito (*short-circuit*), $1 \lor (\dots) = 1$ | **1** |
| **i)** | `i < j && 2 >= k` | `(1 < 2)` $ightarrow 1$; `(2 >= 3)` $ightarrow 0$; $1 \land 0 = 0$ | **0** |
| **j)** | `i == 2 || j == 4 || k == 5` | `(1==2)` $ightarrow 0$; `(2==4)` $ightarrow 0$; `(3==5)` $ightarrow 0$; $0 \lor 0 \lor 0 = 0$ | **0** |

---

### Questão 06. Comportamento e Precedência dos Incrementos
Código em [`exercicio06.c`](exercicio06.c).

**a) Explique a diferença de fluxo e atribuição que ocorre entre o operador prefixado (`++n`) e o pós-fixado (`m++`). Quais serão os valores impressos na tela por cada trecho?**  
> **Resposta:**  
> - **Pré-incremento (`++n`):** A variável `n` é incrementada em 1 **antes** de seu valor ser retornado e utilizado na expressão/atribuição. Logo, `n` passa de 5 para 6, e o valor 6 é atribuído a `x`.  
>   - **Saída do Trecho A:** `Trecho A: n = 6, x = 6`  
> - **Pós-incremento (`m++`):** O valor corrente de `m` (5) é retornado e utilizado na expressão/atribuição para `y`, e **somente após** essa avaliação a variável `m` é incrementada para 6.  
>   - **Saída do Trecho B:** `Trecho B: m = 6, y = 5`

**b) Um programador júnior tentou imprimir uma variável em `printf()` modificando-a múltiplas vezes de forma sequencial na mesma chamada: `printf("%d\t%d\t%d\n", n, n+1, n++);`. Explique por que essa instrução pode gerar resultados inconsistentes e imprevisíveis dependendo do compilador adotado (comportamento indefinido).**  
> **Resposta:** Segundo os padrões ANSI/ISO C, a **ordem de avaliação dos argumentos passados para uma função não é especificada** (*unspecified evaluation order*). Além disso, modificar o valor de um objeto escalar (`n++`) e simultaneamente ler esse mesmo objeto (`n` e `n+1`) sem a presença de um ponto de sequência intermediário (*sequence point*) configura formalmente um **Comportamento Indefinido** (*Undefined Behavior - UB*). Compiladores diferentes (ou diferentes níveis de otimização `-O2`, `-O3`) podem avaliar os parâmetros da direita para a esquerda ou da esquerda para a direita, gerando resultados divergentes e imprevisíveis.

---

## PARTE II: QUESTÕES PRÁTICAS DE IMPLEMENTAÇÃO (CÓDIGO FONTE EM C)

| Questão | Descrição do Problema | Arquivo Fonte |
| :--- | :--- | :---: |
| **Questão 07** | Leitura formatada de datas no formato `dd/mm/aaaa` e exibição invertida `aaaa/mm/dd` usando strings de controle de `scanf()`. | [`exercicio07.c`](exercicio07.c) |
| **Questão 08** | Leitura de número inteiro, cálculo do quadrado e da décima parte real com precisão de duas casas decimais evitando truncamento. | [`exercicio08.c`](exercicio08.c) |
| **Questão 09** | Operações aritméticas fundamentais (soma, subtração, multiplicação e divisão real com cast explícito e verificação de divisão por zero). | [`exercicio09.c`](exercicio09.c) |
| **Questão 10** | Conversão de temperatura em Celsius para as escalas Fahrenheit e Kelvin ($F = (C \cdot 9/5) + 32$ e $K = C + 273.15$). | [`exercicio10.c`](exercicio10.c) |
| **Questão 11** | Conversão de ângulo de graus para radianos com a constante $\pi = 3.141593$. | [`exercicio11.c`](exercicio11.c) |
| **Questão 12** | Obtenção do antecessor e sucessor de um número utilizando exclusivamente operadores unários de incremento (`++`) e decremento (`--`). | [`exercicio12.c`](exercicio12.c) |
| **Questão 13** | Programa unificado para cálculo de áreas de quadrado ($L^2$), retângulo ($B \cdot H$) e triângulo retângulo ($(B \cdot H)/2$). | [`exercicio13.c`](exercicio13.c) |
| **Questão 14** | Cálculo da área de triângulos pela Fórmula de Heron ($Area = \sqrt{p(p-a)(p-b)(p-c)}$) vinculando `<math.h>` (`-lm`). | [`exercicio14.c`](exercicio14.c) |
| **Questão 15** | Cálculo da média aritmética simples e média ponderada (pesos 1, 1, 2, 2) de 4 notas escolares. | [`exercicio15.c`](exercicio15.c) |
| **Questão 16** | Cálculo do número mínimo de degraus de uma escada com compatibilização de unidades (cm e m) e arredondamento superior com `ceil()`. | [`exercicio16.c`](exercicio16.c) |
| **Questão 17** | Geometria do círculo com constantes: cálculo da área ($A = \pi R^2$) e circunferência ($C = 2\pi R$). | [`exercicio17.c`](exercicio17.c) |
| **Questão 18** | Geometria da esfera: área de superfície ($4\pi R^2$) e volume ($(4.0/3.0)\pi R^3$) com frações em ponto flutuante. | [`exercicio18.c`](exercicio18.c) |
| **Questão 19** | Cálculo de salário bruto, desconto de imposto de renda retido na fonte (8%) e salário líquido para diárias de encanador (R$ 30,00/dia). | [`exercicio19.c`](exercicio19.c) |
| **Questão 20** | Aplicação do Teorema de Pitágoras para determinação do comprimento da hipotenusa a partir de dois catetos. | [`exercicio20.c`](exercicio20.c) |
| **Questão 21** | Leitura de caractere e exibição do seu código numérico de 1 byte correspondente na Tabela ASCII. | [`exercicio21.c`](exercicio21.c) |
| **Questão 22** | Conversão de letra maiúscula para minúscula utilizando manipulação aritmética de deslocamento na tabela ASCII (`+32`). | [`exercicio22.c`](exercicio22.c) |
| **Questão 23** | Cálculo do horário de término de experimento a partir do horário inicial e duração em segundos, utilizando `/` e `%`. | [`exercicio23.c`](exercicio23.c) |
| **Questão 24** | Conversão física de velocidade de km/h para m/s utilizando o fator de conversão $3.6$. | [`exercicio24.c`](exercicio24.c) |
| **Questão 25** | Cálculo de salário líquido com gratificação (+5%) e imposto retido (-7%) sobre o salário-base ($Base 	imes 0.98$). | [`exercicio25.c`](exercicio25.c) |
| **Questão 26** | Orçamento perimetral para cercamento de terrenos agrícolas com 3 fios de arame farpado. | [`exercicio26.c`](exercicio26.c) |
| **Questão 27** | Simulação do lançamento de 3 dados com números aleatórios entre 1 e 6 usando `rand()`, `srand(time(NULL))` e `%`. | [`exercicio27.c`](exercicio27.c) |
| **Questão 28** | Cálculo de remuneração anual com horas normais e extras, aplicando alíquota progressiva de IR (10% sobre excedente a R$ 12.000,00) com operador ternário `(? :)`. | [`exercicio28.c`](exercicio28.c) |
