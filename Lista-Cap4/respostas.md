# Lista de Exercícios – Capítulo 4: Comandos de Decisão
**Disciplina:** Programação Imperativa e Funcional (PIF - 2026.2)  
**Curso:** Graduação Tecnológica em Análise e Desenvolvimento de Sistemas (ADS)  
**Instituição:** CESAR School  
**Docente:** Prof. Danilo Farias Soares da Silva  
**Estudante:** Gabriel Dornelas  

---

## PARTE I: QUESTÕES TEÓRICAS E ANALÍTICAS (CONCEITOS E PRECEDÊNCIA)

### Questão 01. Avaliação de Expressões Condicionais e Atribuição vs. Igualdade
Código demonstrativo em [`exercicio01.c`](exercicio01.c).

Em relação à sintaxe e semântica do comando `if` na Linguagem C:

**a) Qual é o efeito prático de escrever if (x = 0) em vez de if (x == 0)? Explique o que acontece com a variável x e qual bloco de código será executado.**  
> **Resposta:**  
> - **Efeito em `if (x = 0)`:** O símbolo `=` é o operador de **atribuição**, não de comparação. A expressão `x = 0` armazena o valor `0` na variável `x` e retorna como resultado da própria expressão o valor atribuído (`0`). Na linguagem C, o valor numérico `0` representa **falso**. Portanto, a condição do `if` é avaliada invariavelmente como falsa e o seu bloco associado **nunca será executado** (o fluxo é desviado para o `else`, caso exista). Como efeito colateral destrutivo, o valor anterior da variável `x` é permanentemente sobrescrito por `0`.
> - **Efeito em `if (x == 0)`:** O símbolo `==` é o operador relacional de **igualdade**. A expressão apenas compara o conteúdo atual da variável `x` com `0`, sem modificar o valor armazenado em memória. Se `x` for igual a `0`, a expressão avalia para `1` (verdadeiro) e o bloco do `if` é executado; caso contrário, avalia para `0` (falso).

**b) Como a Linguagem C interpreta valores numéricos inteiros ou reais dentro da condição do comando if? O que significa um resultado ser avaliado como 'falso' ou 'verdadeiro'?**  
> **Resposta:**  
> - No padrão ANSI C clássico (C89/C90), a linguagem não possuía um tipo booleano nativo primitivo (`bool`), tratando condições como expressões numéricas escalares (inteiras, reais ou ponteiros):
>   - **Falso:** Representado estritamente pelo valor escalar **zero** (`0`, `0.0` ou ponteiro nulo `NULL`).
>   - **Verdadeiro:** Representado por **qualquer valor numérico diferente de zero**, sejam positivos ou negativos (ex: `1`, `-5`, `42`, `0.001`, `-0.5`).
> - Quando uma expressão condicional relacional ou lógica é calculada pelo processador (como `5 > 2`), o compilador gera como resultado inteiro o valor `1` para indicar verdade e `0` para falsidade.

**c) Analise a instrução if (x = -5) e determine se o bloco de código associado será executado ou ignorado. Justifique sua resposta com base no padrão ANSI C.**  
> **Resposta:**  
> - O bloco de código associado **será executado obrigatoriamente**.  
> - **Justificativa:** A expressão `x = -5` atribui o valor inteiro `-5` à variável `x` e produz o resultado `-5` como valor de retorno da expressão condicional. De acordo com a especificação ANSI C, qualquer valor diferente de zero é semanticamente verdadeiro. Como `-5 != 0`, a condição é avaliada como verdadeira, direcionando o fluxo do programa para o bloco interno do `if`.

---

### Questão 02. Associação do Comando else e Aninhamento de Decisões
Código demonstrativo em [`exercicio02.c`](exercicio02.c).

Trecho em análise:
```c
int x = 15, y = 5;
if (x > 10)
    if (y > 10)
        printf("Opção A\n");
else
    printf("Opção B\n");
```

**a) Qual mensagem será impressa no console ao executar o código acima? Justifique por que a Opção B é ou não exibida.**  
> **Resposta:**  
> - **Nenhuma mensagem será impressa no console** (ou, dependendo de como a indentação foi redigida mentalmente, a Opção B **não** é executada para `x <= 10`).  
> - **Justificativa detalhada:** Na linguagem C, a indentação tem propósito puramente visual e é ignorada pelo compilador. Pela regra gramatical de resolução de ambiguidade (*dangling else*), a cláusula `else` associa-se automaticamente ao `if` mais próximo que ainda não possua um `else`. Portanto, o `else` pertence a `if (y > 10)` e não a `if (x > 10)`.  
> - Como `x = 15 > 10` é verdadeiro, o programa entra no primeiro `if`. Em seguida, avalia `y > 10`: como `y = 5 > 10` é falso, o fluxo desvia para o `else` de `y`, imprimindo **`Opção B`**! A Opção B é exibida justamente porque `y <= 10`, e não porque `x <= 10` como a indentação sugeria enganosamente.

**b) Qual é a regra oficial da Linguagem C para associar uma cláusula else a um comando if em códigos sem chaves de bloco?**  
> **Resposta:**  
> - A regra gramatical canônica da especificação ANSI C determina que **uma cláusula `else` sempre se vincula ao comando `if` precedente mais próximo e lexicalmente aberto** (ou seja, o `if` aninhado mais interno que ainda não foi fechado por um delimitador de bloco ou completado por outro `else`).

**c) Reescreva o código acima utilizando chaves { } para garantir explicitamente que a Opção B seja impressa apenas quando x <= 10.**  
> **Resposta:**
```c
int x = 15, y = 5;
if (x > 10) {
    if (y > 10) {
        printf("Opção A\n");
    }
} else {
    printf("Opção B\n");
}
```

---

### Questão 03. Operador Condicional Ternário vs. Estrutura if-else
Código demonstrativo em [`exercicio03.c`](exercicio03.c).

Instruções em análise:
```c
media = (nota1 + nota2) / 2.0;
situacao = (media >= 7.0) ? 'A' : 'R';
```

**a) Explique detalhadamente o funcionamento da segunda linha de código e qual valor será armazenado na variável situacao se media = 6.8.**  
> **Resposta:**  
> - A segunda linha utiliza o **operador condicional ternário (`? :`)**, que avalia uma expressão de teste (`media >= 7.0`). Se essa condição for verdadeira (diferente de zero), a expressão inteira retorna o valor da primeira ramificação (`'A'`); se for falsa (igual a zero), retorna o valor da segunda ramificação (`'R'`). O resultado retornado é então atribuído à variável `situacao`.  
> - Para `media = 6.8`: como `6.8 >= 7.0` resulta em falso (`0`), a expressão retorna o caractere `'R'`. Portanto, o valor armazenado na variável `situacao` será `'R'` (Reprovado).

**b) Reescreva o trecho de código acima utilizando obrigatoriamente a estrutura tradicional if-else.**  
> **Resposta:**
```c
media = (nota1 + nota2) / 2.0;
if (media >= 7.0) {
    situacao = 'A';
} else {
    situacao = 'R';
}
```

**c) O operador ternário pode substituir qualquer estrutura if-else na Linguagem C? Explique as limitações do operador ternário em relação a blocos com múltiplos comandos.**  
> **Resposta:**  
> - **Não.** O operador ternário é uma **expressão** (*expression*), enquanto a estrutura `if-else` é um **comando de controle de fluxo** (*statement*).  
> - **Limitações:**
>   1. O operador ternário exige que cada uma de suas ramificações produza um valor ou expressão compatível de retorno. Ele não foi concebido para executar blocos extensos de múltiplos comandos, declarações de variáveis ou estruturas de controle aninhadas.
>   2. Embora seja tecnicamente possível usar o operador vírgula `,` para encadear instruções dentro de uma ramificação ternária, isso gera código ilegível, não idiomático e propenso a erros.
>   3. Quando o objetivo é puramente executar procedimentos ou chamadas com efeitos colaterais distintos (sem produzir um valor atribuível), o comando `if-else` é a única escolha correta e elegante.

---

### Questão 04. Seleção Múltipla com switch-case e Efeito Fall-Through
Código demonstrativo em [`exercicio04.c`](exercicio04.c).

Programa em análise:
```c
#include <stdio.h>
int main() {
    int codigo = 2;
    switch (codigo) {
        case 1:
            printf("Bronze\n");
        case 2:
            printf("Prata\n");
        case 3:
            printf("Ouro\n");
            break;
        default:
            printf("Sem Medalha\n");
    }
    return 0;
}
```

**a) Escreva a saída exata gerada no terminal ao executar este programa. Explique por que ocorreu mais de uma impressão.**  
> **Resposta:**  
> - **Saída impressa:**
>   ```text
>   Prata
>   Ouro
>   ```
> - **Explicação:** Como `codigo == 2`, o fluxo do `switch` salta diretamente para o rótulo `case 2:`, executando `printf("Prata\n");`. Como **não há um comando `break`** ao término do `case 2`, o fluxo não sai do `switch`, caindo sequencialmente para a instrução imediatamente seguinte (`case 3:`). O comando `printf("Ouro\n");` é executado e, ao atingir o `break` do `case 3`, o bloco `switch` é finalmente encerrado.

**b) Qual é o papel da instrução break dentro de um bloco switch-case e qual é o nome do fenômeno que ocorre quando ela é omitida?**  
> **Resposta:**  
> - **Papel do `break`:** Interromper imediatamente a execução do bloco `switch-case`, desviando o fluxo do programa para a primeira linha após o fechamento da chave `}` do `switch`.  
> - **Fenômeno da omissão:** Denomina-se **Fall-Through** (ou passagem direta / cascata). Na linguagem C, os rótulos `case:` atuam meramente como marcadores de salto (*jump labels*); sem o `break`, as instruções subsequentes continuam sendo executadas sequencialmente, ignorando os rótulos posteriores.

**c) Quais tipos de dados de variáveis ou expressões podem ser utilizados como argumento no comando switch (expressão)? É permitido usar float ou double? Justifique.**  
> **Resposta:**  
> - **Tipos permitidos:** Apenas expressões que avaliem para **tipos integrais** (*integer types*): `int`, `char`, `short`, `long`, `unsigned` e tipos enumerados (`enum`).  
> - **Permissão de float/double:** **Não é permitido.** Tentar compilar `switch (flutuante)` resulta em erro de compilação (ex: *`statement requires expression of integer type`*).  
> - **Justificativa técnica:** Tipos de ponto flutuante sofrem com imprecisões intrínsecas de representação binária (padrão IEEE 754), tornando comparações exatas de igualdade inerentemente instáveis e não determinísticas. Além disso, a instrução `switch` é projetada para ser otimizada pelos compiladores através de tabelas de salto em memória (*jump tables / dispatch tables*), que requerem chaves discretas inteiras e indexáveis.

---

### Questão 05. Avaliação de Curto-Circuito em Operadores Lógicos
Código demonstrativo em [`exercicio05.c`](exercicio05.c).

Trecho em análise:
```c
int a = 0, b = 5, c = 10;
if (a != 0 && ++b > 5)
    c += 10;
else
    c -= 2;
printf("a = %d, b = %d, c = %d\n", a, b, c);
```

**a) Qual será a saída exata impressa pelo comando printf? Observe se o incremento ++b foi executado ou ignorado.**  
> **Resposta:**  
> - **Saída impressa:**
>   ```text
>   a = 0, b = 5, c = 8
>   ```
> - **Análise do incremento:** O incremento `++b` **foi completamente ignorado**.  
> - **Justificativa:** Como `a = 0`, a primeira subexpressão `(a != 0)` avalia para falso (`0`). Como o operador lógico é o `&&` (conjunção), a falsidade do primeiro termo já garante que a conjunção inteira será falsa. Por avaliação de curto-circuito, o compilador suspende imediatamente a avaliação, e a segunda expressão `++b > 5` sequer é tocada pela CPU. Assim, `b` permanece inalterado com valor `5`, o bloco `else` é executado e `c` passa a valer `10 - 2 = 8`.

**b) Explique o conceito de avaliação de curto-circuito para o operador lógico E (&&) e para o operador lógico OU (||).**  
> **Resposta:**  
> - **Operador E (`&&`):** A avaliação ocorre da esquerda para a direita. Se o operando da esquerda for avaliado como **falso (`0`)**, o resultado global da expressão já é garantidamente falso. O operando da direita **não é avaliado**.  
> - **Operador OU (`||`):** A avaliação ocorre da esquerda para a direita. Se o operando da esquerda for avaliado como **verdadeiro (`!= 0`)**, o resultado global da expressão já é garantidamente verdadeiro. O operando da direita **não é avaliado**.

**c) Qual seria o valor final de b e c se a condição fosse alterada para if (a == 0 || ++b > 5)?**  
> **Resposta:**  
> - **Valores finais:** `b = 5` e `c = 20`.  
> - **Justificativa:** Para `a = 0`, a primeira subexpressão `(a == 0)` é verdadeira (`1`). Como o operador é o `||`, a verdade do primeiro operando basta para determinar a verdade de toda a disjunção. Ocorre o curto-circuito do `||`: o segundo termo `++b > 5` não é executado, mantendo `b = 5`. O bloco do `if` é executado, atualizando `c = 10 + 10 = 20`.

---

### Questão 06. Construções else-if e Análise Lógica de Intervalos
Código demonstrativo em [`exercicio06.c`](exercicio06.c).

Trecho em análise:
```c
int idade = 25;
if (idade >= 60)
    printf("Idoso\n");
if (idade >= 18)
    printf("Adulto\n");
if (idade >= 12)
    printf("Jovem\n");
else
    printf("Criança\n");
```

**a) Qual será a saída do programa para idade = 65? Explique por que múltiplas mensagens são exibidas.**  
> **Resposta:**  
> - **Saída impressa:**
>   ```text
>   Idoso
>   Adulto
>   Jovem
>   ```
> - **Explicação:** O código foi estruturado como uma sequência de comandos `if` independentes, e não como uma cadeia mutuamente exclusiva. Para `idade = 65`:
>   - `65 >= 60` é verdadeiro -> imprime `"Idoso\n"`.
>   - `65 >= 18` é verdadeiro -> imprime `"Adulto\n"`.
>   - `65 >= 12` é verdadeiro -> imprime `"Jovem\n"`.
>   - A cláusula `else` vincula-se unicamente ao último `if (idade >= 12)`, portanto não é executada.

**b) Qual é a diferença fundamental de execução entre uma sequência de comandos if independentes e uma cadeia else-if?**  
> **Resposta:**  
> - **Comandos `if` independentes:** Cada condição é avaliada incondicionalmente pelo processador, uma após a outra. Vários blocos de código podem ser executados caso o dado de entrada satisfaça múltiplos critérios simultâneos.  
> - **Cadeia `else-if`:** Modela condições **mutuamente exclusivas**. O processador testa as expressões ordenadamente e, assim que a primeira condição verdadeira é encontrada, o seu bloco correspondente é executado e **todas as demais ramificações subsequentes são imediatamente saltadas**, garantindo a execução de exatamente uma alternativa.

**c) Reescreva o programa utilizando a estrutura elegante e correta else-if para garantir que apenas uma categoria seja impressa.**  
> **Resposta:**
```c
int idade = 25;
if (idade >= 60) {
    printf("Idoso\n");
} else if (idade >= 18) {
    printf("Adulto\n");
} else if (idade >= 12) {
    printf("Jovem\n");
} else {
    printf("Criança\n");
}
```

---

## PARTE II: QUESTÕES PRÁTICAS DE IMPLEMENTAÇÃO (CÓDIGO FONTE EM C)

Abaixo estão listadas as implementações desenvolvidas para os exercícios práticos, contendo a lógica aplicada e os arquivos fontes correspondentes:

| Exercício | Arquivo | Descrição Resumida da Solução |
| :--- | :--- | :--- |
| **Questão 07** | [`exercicio07.c`](exercicio07.c) | Cálculo condicional: se `x >= 0` imprime `sqrt(x)` via `<math.h>`; se `x < 0` imprime `x * x`. |
| **Questão 08** | [`exercicio08.c`](exercicio08.c) | Verificação de bissexto gregoriano: `(ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0)`. |
| **Questão 09** | [`exercicio09.c`](exercicio09.c) | Média ponderada com pesos 2, 3 e 5 e faixas de Reprovado (<3.0), Recuperação (3.0 a 4.9) e Aprovado (>=5.0). |
| **Questão 10** | [`exercicio10.c`](exercicio10.c) | Análise simultânea de paridade com operador módulo `% 2` e classificação de sinal (positivo, negativo ou zero). |
| **Questão 11** | [`exercicio11.c`](exercicio11.c) | Ordenação de três valores inteiros por trocas consecutivas em variáveis auxiliares sem uso de vetores. |
| **Questão 12** | [`exercicio12.c`](exercicio12.c) | Mapeamento de dia da semana de 1 a 7 com `switch-case` e tratamento de entrada inválida no `default`. |
| **Questão 13** | [`exercicio13.c`](exercicio13.c) | Calculadora aritmética (`+`, `-`, `*`, `/`) e científica (`^` com `pow()`) tratando divisão por zero. |
| **Questão 14** | [`exercicio14.c`](exercicio14.c) | Matriz de conceitos (A, B, C, D, E) cruzando faixas de notas reais com limite de 20 faltas. |
| **Questão 15** | [`exercicio15.c`](exercicio15.c) | Elegibilidade previdenciária combinando idade (>=65), tempo de serviço (>=30) ou regra mista (idade >=60 e tempo >=25). |
| **Questão 16** | [`exercicio16.c`](exercicio16.c) | Cálculo de consumo automotivo em km/l e classificação ('Venda o carro!', 'Econômico!', 'Super econômico!'). |
| **Questão 17** | [`exercicio17.c`](exercicio17.c) | Venda com desconto de 10% à vista ou 3x sem juros, calculando a respectiva comissão de 5% do vendedor. |
| **Questão 18** | [`exercicio18.c`](exercicio18.c) | Conversor bidirecional de escalas termométricas (Celsius, Fahrenheit e Kelvin) formatado com 2 casas decimais. |
| **Questão 19** | [`exercicio19.c`](exercicio19.c) | Validação da desigualdade triangular geométrica e classificação em Equilátero, Isósceles ou Escaleno. |
| **Questão 20** | [`exercicio20.c`](exercicio20.c) | Resolução de equação do 2º grau por Bhaskara, discriminando raízes complexas ($\Delta < 0$), raiz dupla e reais distintas. |
| **Questão 21** | [`exercicio21.c`](exercicio21.c) | Reajuste salarial escalonado por cargo (Técnico, Gerente, Demais) e faixa salarial, exibindo acréscimo e novo total. |
| **Questão 22** | [`exercicio22.c`](exercicio22.c) | Cálculo de impostos sobre produtos por estado destinatário (MG 7%, SP 12%, RJ 15%, MS 8%) via `switch`. |
| **Questão 23** | [`exercicio23.c`](exercicio23.c) | Conversão de data numérica para data formatada por extenso (`DD de Mês de AAAA`) utilizando `switch-case`. |
| **Questão 24** | [`exercicio24.c`](exercicio24.c) | Validação angular euclidiana ($\sum = 180^\circ$) e classificação em Retângulo, Obtusângulo ou Acutângulo. |
| **Questão 25** | [`exercicio25.c`](exercicio25.c) | Decomposição ótima de troco em dinheiro na menor quantidade de cédulas de R$ 100, 50, 20, 10, 5 e 2. |
| **Questão 26** | [`exercicio26.c`](exercicio26.c) | Calendário perpétuo mensal que valida dinamicamente o total de dias de fevereiro em anos bissextos (28 ou 29 dias). |
| **Questão 27** | [`exercicio27.c`](exercicio27.c) | Tarifador progressivo de estacionamento com faixas de 1h-2h (R$ 2/h), 3h-4h (R$ 2,50/h) e excedente (R$ 3/h). |
| **Questão 28** | [`exercicio28.c`](exercicio28.c) | Simulação de URA/SAC bancário interativo com opções de menu de autoatendimento e direcionamento via `switch`. |
