# Lista de Exercícios – Capítulo 3: Laços de Repetição
**Disciplina:** Programação Imperativa e Funcional (PIF - 2026.2)  
**Curso:** Graduação Tecnológica em Análise e Desenvolvimento de Sistemas (ADS)  
**Instituição:** CESAR School  
**Docente:** Prof. Danilo Farias Soares da Silva  
**Estudante:** Gabriel Dornelas  

---

## PARTE I: QUESTÕES TEÓRICAS E ANALÍTICAS (CONCEITOS E PRECEDÊNCIA)

### Questão 01. Diferenças Fundamentais e Tempo de Avaliação de Laços
Código demonstrativo em [`exercicio01.c`](exercicio01.c).

A linguagem C disponibiliza três estruturas de controle para execução iterativa de código: `for`, `while` e `do-while`.

**a) Qual é a diferença essencial entre as estruturas while e do-while em relação ao número mínimo de execuções do bloco de código e ao momento em que a condição de teste é avaliada?**  
> **Resposta:**  
> - **`while` (Laço Pré-testado / *Entry-condition loop*):** A expressão de teste condicional é avaliada **antes** de qualquer instrução do corpo ser executada. Caso a condição seja falsa inicialmente, o bloco de código **não é executado nenhuma vez** (o número mínimo de execuções é **0**).  
> - **`do-while` (Laço Pós-testado / *Exit-condition loop*):** O bloco de instruções é executado primeiro e a expressão de teste condicional é avaliada **apenas no final** da iteração. Dessa forma, o bloco de código é executado **obrigatoriamente pelo menos uma vez** (o número mínimo de execuções é **1**), independentemente de a condição ser verdadeira ou falsa de início.

**b) Em que situações de programação cada uma das três estruturas (for, while e do-while) se apresenta como a escolha mais elegante, legível e adequada?**  
> **Resposta:**  
> - **`for`:** Apresenta-se como a escolha ideal em iterações **determinísticas ou contadas**, isto é, situações onde o número de repetições, os limites do intervalo e o passo de atualização são conhecidos a priori (por exemplo: percorrer índices de um vetor de tamanho fixo, contadores de 1 a N, tabulações). Sua elegância decorre de centralizar inicialização, condição e incremento no cabeçalho em uma única linha.  
> - **`while`:** É a estrutura mais indicada para iterações **indeterminadas e condicionais**, em que o laço depende de um estado ou evento externo que pode não se cumprir logo na primeira avaliação (por exemplo: leitura de fluxos de dados ou arquivos até o marcador de fim de arquivo `EOF`, processamento com sentinelas ou convergência de cálculos numéricos).  
> - **`do-while`:** É a escolha mais adequada para situações em que a ação precisa ser executada ao menos uma vez antes de qualquer teste de validação fazer sentido. Os casos de uso canônicos são **menus interativos de navegação** (onde a interface de opções deve ser exibida ao menos uma vez) e **rotinas de validação de entrada de dados** (onde o dado precisa ser digitado pelo usuário antes de ser testado se está dentro do intervalo permitido).

**c) Análise de código: O trecho 'while (condicao);' (com ponto-e-vírgula ao final) é um erro de compilação ou um erro de lógica? Explique detalhadamente o que ocorre durante a execução se condicao for verdadeira.**  
> **Resposta:**  
> - O trecho **não é um erro de compilação**, mas sim um **erro de lógica** (*semantic bug*).  
> - Na gramática da linguagem C, o ponto-e-vírgula isolado `;` representa a **instrução nula** (*null statement*). Portanto, o compilador interpreta que o corpo do laço `while` é composto exclusivamente por essa instrução vazia.  
> - Caso a `condicao` seja verdadeira e não haja efeitos colaterais na própria expressão condicional que a tornem falsa, o programa entrará em um **laço infinito de espera ativa** (*busy-wait infinite loop*). O fluxo de execução fica retido indefinidamente nesse ponto, consumindo 100% de uso do núcleo da CPU e impedindo que qualquer linha subsequente do programa seja executada.

---

### Questão 02. Escopo e Tempo de Vida de Variáveis de Bloco
Código corrigido em [`exercicio02.c`](exercicio02.c).

Programa em análise:
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    for (i = 1; i < 10; i++) {
        int soma = 0;
        soma += i * i;
    }
    printf("Soma final = %d\n", soma);
    system("PAUSE");
    return 0;
}
```

**a) Por que o compilador emitirá um erro de sintaxe/declaração na instrução printf final?**  
> **Resposta:** O compilador emitirá um erro de compilação (ex: *`'soma' undeclared (first use in this function)`*) porque a variável `soma` foi declarada **dentro do bloco do laço `for`** (`{ int soma = 0; ... }`). Em C, variáveis declaradas dentro de um bloco delimitado por chaves possuem **escopo de bloco** (*block scope*). Ao término de cada iteração e, definitivamente, após o fechamento da chave do `for`, a variável `soma` deixa de existir e não é visível no escopo da função `main()`, tornando inválida a tentativa de acessá-la no `printf` externo.

**b) Mesmo que a instrução printf fosse movida para dentro do bloco do laço for, por que o valor impresso para soma estaria conceitualmente incorreto a cada iteração?**  
> **Resposta:** Porque a declaração `int soma = 0;` está localizada no interior do corpo do laço. Dessa forma, a cada nova iteração, a variável `soma` é alocada e **reinicializada com zero**. Em seguida, ela recebe apenas `0 + i * i` (o quadrado do elemento daquela iteração específica), perdendo integralmente o valor acumulado das iterações anteriores. Ela funcionaria apenas como o quadrado do número corrente e não como um somatório acumulado.

**c) Apresente o código corrigido e explique o conceito de visibilidade, escopo de bloco e tempo de vida de variáveis na linguagem C.**  
> **Código Corrigido:**
> ```c
> #include <stdio.h>
> 
> int main(void) {
>     int i;
>     int soma = 0; // Declarada e inicializada no escopo da funcao main
> 
>     for (i = 1; i < 10; i++) {
>         soma += i * i;
>     }
> 
>     printf("Soma final = %d\n", soma);
>     return 0;
> }
> ```
> **Conceitos Fundamentais:**  
> - **Escopo de Bloco (*Block Scope*):** Região do código delimitada por `{}` onde um identificador é reconhecido. O identificador nasce no ponto de sua declaração e seu escopo termina na chave de fechamento `}` correspondente.
> - **Visibilidade (*Visibility*):** Propriedade que determina se uma variável pode ser referenciada diretamente por seu nome naquele ponto de execução sem ser ocultada por outro identificador de mesmo nome em escopo mais interno (*shadowing*).  
> - **Tempo de Vida (*Storage Duration / Lifetime*):** Período de execução do programa durante o qual a memória reservada para a variável existe e preserva seu valor. Variáveis locais comuns possuem tempo de vida automático (*automatic storage duration*): são alocadas na pilha (*stack*) na entrada do bloco e destruídas na saída dele. Para acumular valores entre iterações, a variável deve possuir tempo de vida que englobe todo o ciclo de repetições.

---

### Questão 03. Flexibilidade do Laço for e Omissão de Expressões
Código demonstrativo em [`exercicio03.c`](exercicio03.c).

Analise dos trechos:
```c
// Trecho A: Incremento por divisão
for (a = 36; a > 0; a /= 2)
    printf("%d\t", a);

// Trecho B: Omissão de inicialização e incremento
for (; (ch = getch()) != 'X' ;)
    printf("%c", ch + 1);

// Trecho C: Omissão completa de expressões
for (;;)
    printf("Laço Infinito\n");
```

**a) Qual é a sequência exata de valores impressos no console ao executar o Trecho A?**  
> **Resposta:**  
> - Iteração 1: $a = 36 \implies 36 > 0$ (V), imprime `36\t`, atualiza $a = 36 / 2 = 18$  
> - Iteração 2: $a = 18 \implies 18 > 0$ (V), imprime `18\t`, atualiza $a = 18 / 2 = 9$  
> - Iteração 3: $a = 9 \implies 9 > 0$ (V), imprime `9\t`, atualiza $a = 9 / 2 = 4$ (divisão inteira truncada)  
> - Iteração 4: $a = 4 \implies 4 > 0$ (V), imprime `4\t`, atualiza $a = 4 / 2 = 2$  
> - Iteração 5: $a = 2 \implies 2 > 0$ (V), imprime `2\t`, atualiza $a = 2 / 2 = 1$  
> - Iteração 6: $a = 1 \implies 1 > 0$ (V), imprime `1\t`, atualiza $a = 1 / 2 = 0$  
> - Teste: $a = 0 \implies 0 > 0$ (Falso, o laço é encerrado).  
> 
> **Sequência exata impressa:**  
> `36	18	9	4	2	1	`

**b) Explique o comportamento do Trecho B. O que faz a operação 'ch + 1' e por que os parênteses em '(ch = getch())' são estritamente necessários antes da comparação com 'X'?**  
> **Resposta:**  
> - **Comportamento:** O laço lê interativamente caracteres do teclado. Enquanto o caractere digitado não for `'X'`, ele executa o corpo imprimindo `ch + 1`.  
> - **Operação `'ch + 1'`:** Em C, caracteres são valores inteiros representados pela codificação ASCII. Somar 1 a um caractere (`ch + 1`) produz o código ASCII do caractere imediatamente posterior no alfabeto ou tabela (ex: se o usuário digitar `'A'`, a tela exibirá `'B'`; se digitar `'a'`, exibirá `'b'`).  
> - **Necessidade dos Parênteses:** O operador relacional de desigualdade `!=` possui **maior precedência** que o operador de atribuição `=`. Se omitíssemos os parênteses, isto é, `ch = getch() != 'X'`, o compilador avaliaria primeiro a comparação `getch() != 'X'`, cujo resultado é booleano (`1` para verdadeiro ou `0` para falso). Esse valor binário (`1` ou `0`) seria então atribuído a `ch`, corrompendo a leitura do caractere. Os parênteses garantem que a atribuição `ch = getch()` seja executada primeiro, e o caractere retornado seja devidamente comparado a `'X'`.

**c) Como o programa pode interromper a execução do laço infinito do Trecho C de forma programática sem forçar o encerramento do processo pelo sistema operacional?**  
> **Resposta:**  
> 1. Utilizando a instrução de salto condicional **`break;`** associada a uma condição de parada (ex: `if (condicao) break;`).  
> 2. Utilizando a instrução **`return;`** (caso se deseje retornar imediatamente da função que abriga o laço).  
> 3. Utilizando a instrução **`goto rotulo;`** apontando para um identificador de rótulo fora do laço.

---

### Questão 04. Comandos de Desvio de Fluxo: break vs. continue
Código demonstrativo em [`exercicio04.c`](exercicio04.c).

**a) Descreva a ação exata executada pelo programa quando o comando break é acionado dentro de um laço for ou while.**  
> **Resposta:** O comando `break` causa a **interrupção imediata e definitiva** do laço de repetição mais interno em que se encontra. A execução do corpo do laço é abortada no ponto exato da instrução, nenhuma iteração subsequente é executada, e o controle do fluxo é transferido diretamente para a primeira linha de código imediatamente posterior ao fechamento do bloco do laço.

**b) Descreva a ação exata executada pelo programa quando o comando continue é acionado dentro de um laço for. Qual das três expressões do cabeçalho do for é executada imediatamente após o continue?**  
> **Resposta:** O comando `continue` encerra prematuramente **apenas a iteração corrente** do laço, ignorando todas as linhas de código restantes abaixo dele dentro do corpo do laço. Em um laço `for (expr1; expr2; expr3)`, o controle do programa salta imediatamente para a **terceira expressão do cabeçalho (`expr3`)**, que é a **expressão de incremento/atualização**. Somente após a atualização da variável de controle a expressão condicional de teste (`expr2`) é avaliada para decidir se haverá a próxima iteração.

**c) Em uma estrutura de laços aninhados (um laço for interno dentro de outro laço for externo), qual laço é interrompido quando a instrução break é executada dentro do laço interno?**  
> **Resposta:** O comando `break` interrompe **apenas o laço mais interno** no qual ele está fisicamente contido. O laço externo continua sua contagem e iterações normais a partir do ponto imediatamente seguinte ao fechamento do laço interno.

---

### Questão 05. Operador Vírgula e Múltiplas Variáveis de Controle
Código em [`exercicio05.c`](exercicio05.c).

Trecho em análise:
```c
int i, j;
for (i = 0, j = 10; i < j; i++, j--) {
    printf("i = %d, j = %d | soma = %d\n", i, j, i + j);
}
```

**a) Exatamente quantas iterações o laço acima executará antes de ser encerrado?**  
> **Resposta:** O laço executará exatamente **5 iterações**.  
> - Início: `i = 0`, `j = 10`  
> - Iteração 1: `0 < 10` (V) $\to$ executa corpo $\to$ passo: `i = 1, j = 9`  
> - Iteração 2: `1 < 9` (V) $\to$ executa corpo $\to$ passo: `i = 2, j = 8`  
> - Iteração 3: `2 < 8` (V) $\to$ executa corpo $\to$ passo: `i = 3, j = 7`  
> - Iteração 4: `3 < 7` (V) $\to$ executa corpo $\to$ passo: `i = 4, j = 6`  
> - Iteração 5: `4 < 6` (V) $\to$ executa corpo $\to$ passo: `i = 5, j = 5`  
> - Teste seguinte: `5 < 5` (Falso) $\to$ laço é finalizado.

**b) Escreva a saída exata produzida pelo comando printf em cada uma das iterações executadas.**  
> **Resposta:**
> ```text
> i = 0, j = 10 | soma = 10
> i = 1, j = 9 | soma = 10
> i = 2, j = 8 | soma = 10
> i = 3, j = 7 | soma = 10
> i = 4, j = 6 | soma = 10
> ```

**c) Reescreva a lógica deste mesmo laço utilizando obrigatoriamente a estrutura while.**  
> **Resposta:**
> ```c
> int i = 0;
> int j = 10;
> 
> while (i < j) {
>     printf("i = %d, j = %d | soma = %d\n", i, j, i + j);
>     i++;
>     j--;
> }
> ```

---

### Questão 06. Laço Sem Corpo e Incremento Pós-fixado
Código em [`exercicio06.c`](exercicio06.c).

Trecho em análise:
```c
int x = 0;
while (x++ < 5);
printf("Valor final de x = %d\n", x);
```

**a) Qual é o valor final da variável x que será impresso pela instrução printf?**  
> **Resposta:** O valor final impresso será **`6`**.

**b) Explique passo a passo a sequência de incrementos e comparações lógicas que ocorrem durante a execução do teste 'x++ < 5'.**  
> **Resposta:** O operador `++` pós-fixado (*post-increment*) avalia o valor corrente de `x` na expressão comparativa e programa o incremento de `x` para ocorrer imediatamente após a avaliação da subexpressão:  
> 1. `x` é `0`: avalia `0 < 5` (Verdadeiro). `x` é incrementado para `1`. Corpo nulo `;` executado.  
> 2. `x` é `1`: avalia `1 < 5` (Verdadeiro). `x` é incrementado para `2`. Corpo nulo `;` executado.  
> 3. `x` é `2`: avalia `2 < 5` (Verdadeiro). `x` é incrementado para `3`. Corpo nulo `;` executado.  
> 4. `x` é `3`: avalia `3 < 5` (Verdadeiro). `x` é incrementado para `4`. Corpo nulo `;` executado.  
> 5. `x` é `4`: avalia `4 < 5` (Verdadeiro). `x` é incrementado para `5`. Corpo nulo `;` executado.  
> 6. `x` é `5`: avalia `5 < 5` (**Falso** $\implies$ laço encerrado). **Contudo**, como a expressão de pós-incremento foi lida e avaliada, o efeito colateral de incremento ocorre obrigatoriamente, elevando `x` para **`6`**.  
> Por isso, ao atingir o `printf`, o valor final de `x` é **`6`**.

**c) Reescreva esse código de forma explícita e clara (sem corpo vazio), mantendo exatamente o mesmo resultado final de x.**  
> **Resposta:**
> ```c
> int x = 0;
> while (x < 5) {
>     x++;
> }
> x++; // Efeito colateral do teste que falhou no pós-incremento (quando x atingiu 5)
> printf("Valor final de x = %d\n", x);
> ```

---

## PARTE II: QUESTÕES PRÁTICAS DE IMPLEMENTAÇÃO (CÓDIGO FONTE EM C)

| Questão | Descrição do Problema | Arquivo Fonte |
| :--- | :--- | :---: |
| **Questão 07** | Contagem progressiva de 0 a 100 em três versões independentes (`for`, `while`, `do-while`) com análise comparativa de adequação. | [`exercicio07.c`](exercicio07.c) |
| **Questão 08** | Validação de entrada de notas no intervalo [0.0, 10.0] utilizando repetição garantida com `do-while`. | [`exercicio08.c`](exercicio08.c) |
| **Questão 09** | Acumulador de valores reais com sentinela negativo, exibindo quantidade válida, soma e média aritmética. | [`exercicio09.c`](exercicio09.c) |
| **Questão 10** | Exibição dos 100 primeiros múltiplos inteiros e positivos de 3 formatados em 10 colunas tabuladas por linha. | [`exercicio10.c`](exercicio10.c) |
| **Questão 11** | Impressão de intervalo numérico fechado entre A e B de forma dinâmica (crescente se $A \le B$ e decrescente se $A > B$). | [`exercicio11.c`](exercicio11.c) |
| **Questão 12** | Tabela de conversão de temperaturas (Celsius de 0 a 100 de 5 em 5 para Fahrenheit e Kelvin) formatada com 2 casas decimais. | [`exercicio12.c`](exercicio12.c) |
| **Questão 13** | Cálculo de fatorial ($N!$) com suporte a `long long int`, validação de inteiros negativos e casos especiais ($0! = 1, 1! = 1$). | [`exercicio13.c`](exercicio13.c) |
| **Questão 14** | Listagem de inteiros de 1 a 100 acompanhados de seus quadrados e somatório global acumulado ao final. | [`exercicio14.c`](exercicio14.c) |
| **Questão 15** | Filtragem numérica de múltiplos simultâneos de 3 e de 5 (múltiplos de 15) no intervalo $[1, NUM]$ com tratamento de conjunto vazio. | [`exercicio15.c`](exercicio15.c) |
| **Questão 16** | Autenticação de senha com limite de 3 tentativas exibindo 'Acesso Concedido!' ou bloqueio de segurança. | [`exercicio16.c`](exercicio16.c) |
| **Questão 17** | Coleta de notas da turma com parada sentinela `-1.0`, calculando contagem de alunos, maior nota, menor nota e média geral. | [`exercicio17.c`](exercicio17.c) |
| **Questão 18** | Inversão aritmética dos dígitos de um número inteiro positivo através de operadores de resto (`%`) e divisão inteira (`/`). | [`exercicio18.c`](exercicio18.c) |
| **Questão 19** | Geração e listagem de termos da Sequência de Fibonacci até o N-ésimo elemento e exibição do valor final. | [`exercicio19.c`](exercicio19.c) |
| **Questão 20** | Tabela de caracteres imprimíveis da tabela ASCII (códigos 32 a 126) em decimal, hexadecimal (`%X`) e caractere. | [`exercicio20.c`](exercicio20.c) |
| **Questão 21** | Jogo de adivinhação de letra secreta com geração aleatória (`rand()`), dicas de ordem alfabética e contagem de tentativas. | [`exercicio21.c`](exercicio21.c) |
| **Questão 22** | Geração e impressão do Triângulo de Floyd de N linhas utilizando laços aninhados. | [`exercicio22.c`](exercicio22.c) |
| **Questão 23** | Desenho de moldura de quadrado vazado com o caractere `'X'` de lado L entre 3 e 20 com laços aninhados. | [`exercicio23.c`](exercicio23.c) |
| **Questão 24** | Desenho de padrão visual em 'X' (diagonais principal e secundária cruzadas) com dimensões ímpares entre 3 e 19. | [`exercicio24.c`](exercicio24.c) |
| **Questão 25** | Teste de primalidade de um número inteiro positivo N com contagem total de divisores e mensagem conclusiva. | [`exercicio25.c`](exercicio25.c) |
| **Questão 26** | Mapeamento e somatório de todos os números primos situados no intervalo fechado $[A, B]$ com validação $A < B$. | [`exercicio26.c`](exercicio26.c) |
| **Questão 27** | Decomposição de cédulas de saque de caixa eletrônico (R$ 100, 50, 20, 10, 5, 2) utilizando laços de subtrações sucessivas. | [`exercicio27.c`](exercicio27.c) |
| **Questão 28** | Sistema contínuo de folha de pagamento com menu interativo (`do-while` e `switch`), reajuste salarial e retenção de IR. | [`exercicio28.c`](exercicio28.c) |
