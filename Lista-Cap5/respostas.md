# Lista de Exercícios – Capítulo 5: Funções
**Disciplina:** Programação Imperativa e Funcional (PIF - 2026.2)  
**Curso:** Graduação Tecnológica em Análise e Desenvolvimento de Sistemas (ADS)  
**Instituição:** CESAR School  
**Docente:** Prof. Danilo Farias Soares da Silva  
**Estudante:** Gabriel Dornelas (vdornelass)  

---

## PARTE I: QUESTÕES TEÓRICAS E ANALÍTICAS (CONCEITOS, RETORNO, RECURSÃO E PRÉ-PROCESSAMENTO)

### Questão 01. Anatomia de uma Função e o Papel do Protótipo
Código demonstrativo em [`exercicio01.c`](exercicio01.c).

Trecho em análise:
```c
#include <stdio.h>
float celsius(float);
int main() {
    float c, f = 100.0;
    c = celsius(f);
    printf("Celsius = %.2f\n", c);
    return 0;
}
float celsius(float fahr) {
    return (fahr - 32.0) * 5.0 / 9.0;
}
```

**a) Identifique no código o protótipo, a chamada e a definição da função celsius(). Explique o papel de cada uma dessas três etapas.**  
> **Resposta:**  
> - **Protótipo (Declaração prévia - linha 2):** `float celsius(float);`  
>   *Papel:* Informa antecipadamente ao compilador a assinatura da função (seu identificador, o tipo de dado que ela retorna e os tipos dos parâmetros que ela espera receber), antes que qualquer invocação ocorra na função `main()`.  
> - **Chamada (Invocação - linha 5):** `c = celsius(f);`  
>   *Papel:* Transfere o fluxo de controle da CPU do ponto corrente para o endereço de memória onde reside o código da função, passando o valor do argumento `f` e aguardando o retorno do resultado para atribuí-lo à variável `c`.  
> - **Definição (Implementação concreta - linhas 9 a 11):** `float celsius(float fahr) { ... }`  
>   *Papel:* Contém o bloco real de instruções em linguagem de máquina que realiza a computação da fórmula de conversão e devolve o valor calculado através do comando `return`.

**b) Qual é a função do protótipo para o compilador? O que aconteceria, em termos de verificação de parâmetros, se ele fosse omitido e a função fosse definida depois da main()?**  
> **Resposta:**  
> - O protótipo atua como um **contrato formal de interface**. Ele permite que o compilador realize a checagem estática de tipos (*type checking*), verificando se o número e os tipos dos argumentos passados na chamada são compatíveis com a assinatura, além de realizar conversões implícitas seguras (coerção de tipos) quando necessário.  
> - Se o protótipo fosse omitido e a definição estivesse abaixo da `main()`, o compilador aplicaria no padrão C clássico a regra da **declaração implícita de função** (*implicit function declaration*). O compilador assumiria arbitrariamente que a função retorna um valor do tipo `int` e que aceita parâmetros indeterminados. Isso provocaria erros graves em tempo de execução: o valor `float` retornado pela função seria interpretado como um padrão de bits inteiro, corrompendo o resultado e emitindo avisos/erros graves de compilação em compiladores modernos padrão C99/C11.

**c) Qual é o tipo da função celsius()? Explique por que o tipo de uma função é determinado pelo valor retornado e não pelos parâmetros recebidos.**  
> **Resposta:**  
> - O tipo da função `celsius()` é **`float`**.  
> - Na linguagem C, uma função é sintaticamente tratada como uma expressão que produz um valor. O tipo da função define **o tipo do valor escalar resultante que a função devolve ao chamador** através do comando `return`. Os parâmetros de entrada determinam apenas a assinatura de recebimento de argumentos (a lista de tipos esperados na pilha), enquanto o tipo de retorno especifica o espaço e a representação de dados necessários no ponto de chamada para armazenar ou manipular o resultado produzido.

---

### Questão 02. O Comando return e suas Limitações
Código demonstrativo em [`exercicio02.c`](exercicio02.c).

Trechos em análise:
```c
int calcular(int a, int b, int c) {
    int soma = a + b + c;
    int media = soma / 3;
    return soma, media;
}
void imprime_mensagem(int erro) {
    if (erro < 0) {
        printf("Erro invalido\n");
        return;
    }
    printf("Codigo processado: %d\n", erro);
}
```

**a) Quantos valores uma função em C pode devolver por meio do comando return? O que o programador pretendia fazer na função calcular() e por que a abordagem não cumpre esse objetivo?**  
> **Resposta:**  
> - Uma função em C pode devolver **apenas um único valor escalar** por meio do comando `return`.  
> - O programador pretendia retornar simultaneamente dois valores distintos: a soma e a média dos três números inteiros.  
> - A instrução `return soma, media;` não cumpre esse objetivo porque a vírgula `,` é interpretada pelo compilador como o **operador vírgula** (*comma operator*). Na linguagem C, o operador vírgula avalia o operando da esquerda (`soma`), descarta o seu resultado e, em seguida, avalia e devolve o operando da direita (`media`). Portanto, a função devolve exclusivamente o valor de `media`, enquanto o valor de `soma` é sumariamente descartado.

**b) Qual é o efeito do comando return; dentro da função void imprime_mensagem()? Ele é obrigatório no final de uma função void? Justifique.**  
> **Resposta:**  
> - O comando `return;` (sem expressão associada) atua como um **desvio de saída antecipada** (*early return*), interrompendo imediatamente a execução do procedimento e devolvendo o controle da CPU para a função chamadora. No trecho, caso `erro < 0`, ele impede que a mensagem `"Codigo processado..."` seja executada.  
> - O `return;` **não é obrigatório no final de uma função void**. Ao atingir a chave de fechamento `}` do corpo da função, o compilador insere automaticamente um retorno implícito de controle. Ele só é necessário no meio da função quando se deseja interromper o fluxo sob uma determinada condição lógica.

**c) Reescreva a função calcular() para que ela retorne apenas a média dos três valores. Em seguida, crie uma segunda função, separada, que retorne apenas a soma. Explique por que, em C, precisamos de duas funções para devolver dois resultados diferentes quando usamos apenas o comando return.**  
> **Resposta:**
```c
int soma_tres(int a, int b, int c) {
    return a + b + c;
}

float media_tres(int a, int b, int c) {
    return (float)soma_tres(a, b, c) / 3.0f;
}
```
> - **Explicação:** Como o comando `return` em C é univalorado e não suporta tuplas nativas, cada invocação de função só pode transportar um único elemento na convenção de chamada (normalmente alocado em um único registrador da CPU, como o registrador `EAX`/`RAX`). Se não utilizarmos ponteiros (passagem por referência) ou agregação em estruturas (`struct`), o paradigma imperativo exige a decomposição do problema em funções modulares e coesas, onde cada função possui a responsabilidade única de calcular e retornar uma grandeza específica.

---

### Questão 03. Funções void, Parâmetros e Assinaturas
Código demonstrativo em [`exercicio03.c`](exercicio03.c).

Protótipos em análise:
1. `void exibe_mensagem(char* msg);`
2. `int obter_codigo(void);`
3. `void limpar_tela(void);`

**a) Classifique cada protótipo quanto à existência de parâmetros de entrada e de valor de retorno.**  
> **Resposta:**  
> 1. `void exibe_mensagem(char* msg);`: **Possui parâmetro de entrada** (um ponteiro para caractere / string `msg`) e **não possui valor de retorno** (`void`). Trata-se de um procedimento parametrizado.  
> 2. `int obter_codigo(void);`: **Não possui parâmetros de entrada** (`void` na lista de parâmetros) e **possui valor de retorno** do tipo inteiro (`int`). Trata-se de uma função produtora de valor sem argumentos.  
> 3. `void limpar_tela(void);`: **Não possui parâmetros de entrada** (`void`) e **não possui valor de retorno** (`void`). Trata-se de um procedimento sem argumentos.

**b) Qual é a diferença prática entre uma função com retorno e um procedimento (função void)? Dê um exemplo de situação em que cada um é a escolha mais adequada.**  
> **Resposta:**  
> - **Função com retorno:** Tem como objetivo primordial o processamento de dados e a geração de um valor de saída que pode ser utilizado em expressões matemáticas, atribuições a variáveis ou testes condicionais. *Exemplo de uso:* Uma função `float calcula_raiz(float x)` ou `int busca_indice(int chave)`.  
> - **Procedimento (`void`):** Tem como propósito executar uma sequência de comandos com **efeitos colaterais** (*side effects*) no ambiente, como escrita em arquivos, comunicação com hardware ou impressão de interfaces visuais no terminal, sem necessidade de devolver um dado computado. *Exemplo de uso:* Um procedimento `void exibe_cabecalho(void)` ou `void resetar_sensores(void)`.

**c) Uma chamada como x = limpar_tela(); é válida? Justifique com base no tipo da função.**  
> **Resposta:**  
> - **Não é válida.** A instrução resulta em um **erro fatal de compilação** (ex: *`error: void value not ignored as it ought to be`*).  
> - **Justificativa:** O tipo `void` denota um tipo incompleto que representa explicitamente a **ausência total de valor**. Como `limpar_tela()` não produz nenhum resultado computacional, não existe dado algum a ser copiado para a variável `x`.

---

### Questão 04. Recursão: Caso Base, Passo Recursivo e Pilha de Execução
Código demonstrativo em [`exercicio04.c`](exercicio04.c).

Função em análise:
```c
long fatorial(int n) {
    return ((n == 0) ? (long)1 : (long)n * fatorial(n - 1));
}
```

**a) Identifique o caso base e o passo recursivo. O que aconteceria se o caso base fosse removido?**  
> **Resposta:**  
> - **Caso Base:** A condição de parada `(n == 0) ? (long)1`, que retorna o valor trivial `1L` sem disparar novas invocações.  
> - **Passo Recursivo:** A expressão `(long)n * fatorial(n - 1)`, que reduz o tamanho da entrada aproximando o problema da condição de parada.  
> - **Se o caso base fosse removido:** A função chamaria a si mesma indefinidamente com valores negativos decrescentes (`fatorial(-1)`, `fatorial(-2)`, ...), resultando em um laço infinito de chamadas na pilha até esgotar toda a memória reservada, disparando o erro de **Estouro de Pilha** (*Stack Overflow / Segmentation Fault*).

**b) Faça o rastreamento completo da chamada fatorial(4), mostrando a fase de empilhamento e a fase de desempilhamento, com o valor devolvido por cada chamada.**  
> **Resposta:**  
> 
> **Fase 1: Empilhamento (Descida / Chamadas pendentes na Call Stack):**
> 1. `fatorial(4)` é invocada e aguarda: `4 * fatorial(3)`
> 2. `fatorial(3)` é invocada e aguarda: `3 * fatorial(2)`
> 3. `fatorial(2)` é invocada e aguarda: `2 * fatorial(1)`
> 4. `fatorial(1)` é invocada e aguarda: `1 * fatorial(0)`
> 5. `fatorial(0)` atinge o **Caso Base** e retorna `1L`.
> 
> **Fase 2: Desempilhamento (Subida / Resolução das multiplicações acumuladas):**
> 1. `fatorial(0)` devolve `1L` para a chamada anterior.
> 2. `fatorial(1)` resolve `1 * 1 = 1L` e devolve `1L`.
> 3. `fatorial(2)` resolve `2 * 1 = 2L` e devolve `2L`.
> 4. `fatorial(3)` resolve `3 * 2 = 6L` e devolve `6L`.
> 5. `fatorial(4)` resolve `4 * 6 = 24L` e entrega o resultado final `24L` para a função chamadora.

**c) Explique, em termos de pilha de execução, o que acontece na memória a cada chamada recursiva e por que uma recursão sem caso base pode causar falha no programa.**  
> **Resposta:**  
> - A cada chamada de função, o sistema operacional aloca na região de memória denominada **Pilha de Execução** (*Call Stack*) uma nova estrutura de dados chamada **Quadro de Pilha** ou **Registro de Ativação** (*Stack Frame*). Esse registro armazena o endereço de retorno da instrução chamadora, os parâmetros passados por valor (`n`), as variáveis locais e os registradores de contexto da CPU.  
> - Na recursão, cada nova chamada cria um novo quadro empilhado sobre o anterior, sem liberar a memória do chamador até que o caso base seja alcançado. Como a memória da pilha é finita (tipicamente entre 1 MB e 8 MB), uma recursão que não possui caso base consome progressivamente todo o espaço de endereçamento disponível até violar a fronteira da pilha, causando o colapso e o encerramento forçado do programa pelo sistema operacional (*Stack Overflow*).

---

### Questão 05. Diretiva #define, Constantes e Macros com Argumentos
Código demonstrativo em [`exercicio05.c`](exercicio05.c).

Código em análise:
```c
#define PI 3.14
#define SQR(x) ((x)*(x))
#define DOBRO(x) x*2
int main() {
    printf("%d\n", SQR(2+3));
    printf("%d\n", DOBRO(2+3));
    return 0;
}
```

**a) Qual será a saída de cada printf? Explique por que SQR e DOBRO se comportam de maneira diferente, relacionando o resultado ao uso de parênteses de proteção.**  
> **Resposta:**  
> - **Saída do 1º printf (`SQR(2+3)`):** `25`  
>   *Explicação:* A macro `SQR(x)` possui parênteses de proteção em torno do parâmetro e da expressão inteira. O pré-processador substitui textualmente `SQR(2+3)` por `((2+3)*(2+3))`. Como a adição entre parênteses tem prioridade, é avaliada como `(5)*(5) = 25`.  
> - **Saída do 2º printf (`DOBRO(2+3)`):** `8` (e **não** 10!)  
>   *Explicação:* A macro `DOBRO(x)` não possui parênteses de proteção. A substituição textual direta de `x*2` com o argumento `2+3` resulta em: `2+3*2`. Pela regra de precedência aritmética de operadores da linguagem C, a multiplicação (`3*2 = 6`) é avaliada antes da adição, resultando em `2 + 6 = 8`.

**b) Por que a diretiva #define não termina com ponto e vírgula? Por que, por convenção, usamos identificadores em maiúsculas?**  
> **Resposta:**  
> - **Ausência de ponto e vírgula:** A diretiva `#define` é uma instrução para o **pré-processador**, e não um comando executável C. Ela opera exclusivamente através de substituição textual bruta. Se colocássemos um ponto e vírgula ao final (ex: `#define PI 3.14;`), o compilador substituiria cada ocorrência de `PI` por `3.14;`, o que geraria instruções sintaticamente inválidas como `float area = 3.14; * r * r;`.  
> - **Uso de maiúsculas:** Trata-se de uma convenção universal de Engenharia de Software para alertar imediatamente o programador de que aquele identificador é uma macro ou constante literal textual e que, diferentemente de variáveis ou funções comuns, não possui tipo estrito e pode provocar efeitos colaterais de reavaliação de argumentos.

**c) Explique por que #define PRN (n) printf("%d", n) está incorreto e qual é a forma correta. Aponte também uma diferença entre uma macro com argumentos e uma função comum.**  
> **Resposta:**  
> - **Erro:** Há um espaço em branco entre o identificador `PRN` e a lista de argumentos `(n)`. Para o pré-processador de C, a presença de espaço faz com que a macro seja interpretada como uma constante de substituição textual simples, onde o nome é `PRN` e o texto de substituição passa a ser `(n) printf("%d", n)`. Ao invocar `PRN(42)`, o pré-processador não substituirá o argumento `n`.  
> - **Forma correta (sem espaço):** `#define PRN(n) printf("%d\n", n)`  
> - **Diferenças fundamentais entre Macro e Função:**
>   1. *Tempo de Resolução:* Macros são expandidas textualmente pelo **pré-processador** em tempo de compilação, sem gerar código de chamada de sub-rotina; funções são invocadas em **tempo de execução**.
>   2. *Sobrecarga de Execução:* Funções consomem ciclos de CPU empilhando e desempilhando registradores de ativação; macros possuem custo zero de chamada, mas aumentam o tamanho final do código binário (*code bloat*).
>   3. *Segurança de Tipos:* Funções realizam validação rigorosa dos tipos de dados de entrada; macros não possuem checagem de tipos e podem causar comportamentos imprevisíveis com argumentos que possuem efeitos colaterais (como `SQR(i++)`).

---

### Questão 06. Diretivas #include, #undef e Compilação Condicional
Código demonstrativo em [`exercicio06.c`](exercicio06.c).

Trecho em análise:
```c
#include <stdio.h>
#include "areas.h"
#define SOMA(x,y) ((x)+(y))
#undef SOMA
#ifdef DEBUG
    printf("Modo de depuracao\n");
#else
    printf("Modo normal\n");
#endif
```

**a) Qual é a diferença entre #include <stdio.h> e #include "areas.h"? Em que situação usamos cada sintaxe?**  
> **Resposta:**  
> - **`#include <stdio.h>` (Chaves angulares `< >`):** Instrui o pré-processador a procurar o arquivo de cabeçalho diretamente nos **diretórios padrão do sistema operacional e da biblioteca padrão C** configurados no compilador (ex: `/usr/include` ou diretórios do toolchain). Usado para bibliotecas padrão ou bibliotecas globais instaladas no sistema.  
> - **`#include "areas.h"` (Aspas duplas `" "`):** Instrui o pré-processador a procurar o arquivo **primeiramente no mesmo diretório local onde reside o código-fonte corrente**. Caso o arquivo não seja encontrado localmente, o pré-processador então recorre aos diretórios padrão do sistema. Usado para cabeçalhos personalizados e módulos criados pelo próprio desenvolvedor.

**b) Qual é o efeito de #undef SOMA? Por que a forma #undef SOMA(x,y) está incorreta?**  
> **Resposta:**  
> - **Efeito:** A diretiva `#undef SOMA` **cancela e remove a definição da macro** `SOMA` da tabela de símbolos do pré-processador. A partir dessa linha, qualquer tentativa subsequente de invocar `SOMA(x, y)` será tratada pelo compilador como uma chamada a uma função inexistente ou identificador indefinido.  
> - **Por que a forma com parâmetros está incorreta:** A sintaxe gramatical da linguagem C estipula que `#undef` aceita estritamente o **identificador puro** da macro, sem parênteses nem lista de parâmetros formais, pois o identificador é a chave única na tabela do pré-processador.

**c) Se DEBUG não foi definido, qual mensagem será impressa? Explique em que momento (pré-processamento ou execução) essa decisão é tomada e por que as diretivas não aparecem no executável final.**  
> **Resposta:**  
> - **Mensagem impressa:** `"Modo normal\n"`.  
> - **Momento da decisão:** A decisão é tomada integralmente na fase de **pré-processamento** (antes da compilação propriamente dita).  
> - **Ausência no executável:** As diretivas iniciadas por `#` (`#ifdef`, `#else`, `#endif`, `#define`) são instruções exclusivas para o pré-processador textual. Como `DEBUG` não está definido, o pré-processador apaga fisicamente o bloco do `#ifdef` e mantém apenas o código da cláusula `#else`. Para o compilador e para o arquivo binário final, o trecho não selecionado simplesmente não existe, não consumindo um único byte de memória no executável.

---

## PARTE II: QUESTÕES PRÁTICAS DE IMPLEMENTAÇÃO (CÓDIGO FONTE EM C)

Todas as implementações práticas foram elaboradas obedecendo rigorosamente à obrigatoriedade do uso de **funções com protótipos declarados antes da função `main()`**, com tratamento de entradas e código modular coeso.

| Exercício | Arquivo de Código | Descrição da Solução e Conceito Aplicado |
| :--- | :--- | :--- |
| **Questão 07** | [`exercicio07.c`](exercicio07.c) | Função univalorada `int soma(int a, int b)` com protótipo e exibição do resultado na `main()`. |
| **Questão 08** | [`exercicio08.c`](exercicio08.c) | Função modular `float celsius(float fahr)` aplicando fórmula de conversão termométrica com 2 casas decimais. |
| **Questão 09** | [`exercicio09.c`](exercicio09.c) | Função `int maior(int a, int b)` que calcula e retorna o maior entre dois números inteiros. |
| **Questão 10** | [`exercicio10.c`](exercicio10.c) | Constante literal `#define PI` e função `float area(float r)` calculando a superfície da esfera ($4 \pi r^2$). |
| **Questão 11** | [`exercicio11.c`](exercicio11.c) | Função predicativa booleana `int ehPar(int n)` retornando `1` para números pares e `0` para ímpares. |
| **Questão 12** | [`exercicio12.c`](exercicio12.c) | Procedimento de interface `void exibeMenu(void)` sem retorno integrado ao controle de fluxo via `switch-case`. |
| **Questão 13** | [`exercicio13.c`](exercicio13.c) | Calculadora modular completa com funções aritméticas separadas e validação preventiva contra divisão por zero. |
| **Questão 14** | [`exercicio14.c`](exercicio14.c) | Função recursiva `int somaDigitos(int n)` com caso base `n < 10` e decomposição posicional por operadores `%` e `/`. |
| **Questão 15** | [`exercicio15.c`](exercicio15.c) | Funções combinadas: `float mediaPonderada(...)` com pesos 2, 3 e 5 e procedimento `void exibeSituacao(float media)`. |
| **Questão 16** | [`exercicio16.c`](exercicio16.c) | Função `int ehBissexto(int ano)` encapsulando a regra astronômica gregoriana de 400, 4 e 100 anos. |
| **Questão 17** | [`exercicio17.c`](exercicio17.c) | Comparação de implementação: `fatorialIterativo()` com laço `for` versus `fatorialRecursivo()` com caso base `n <= 1`. |
| **Questão 18** | [`exercicio18.c`](exercicio18.c) | Função recursiva `long potencia(int base, int expoente)` sem dependência de `<math.h>` com validação de expoente. |
| **Questão 19** | [`exercicio19.c`](exercicio19.c) | Procedimentos recursivos `contagem()` e `contagemCrescente()` demonstrando a ordem do `printf` na pilha. |
| **Questão 20** | [`exercicio20.c`](exercicio20.c) | Função predicativa `int ehPrimo(int n)` e sua reutilização para filtragem e exibição de primos no intervalo [1, 50]. |
| **Questão 21** | [`exercicio21.c`](exercicio21.c) | Implementação das macros `SQR(x)`, `MAX(a,b)` e `MIN(a,b)` com parênteses defensivos contra efeitos de precedência. |
| **Questão 22** | [`exercicio22.c`](exercicio22.c) | Criação da biblioteca modular [`areas.h`](areas.h) com macros geométricas `A_CIRC`, `A_RET` e `A_TRI` com `#include "areas.h"`. |
| **Questão 23** | [`exercicio23.c`](exercicio23.c) | Demonstração empírica da substituição textual da macro `#define DOBRO(x) x*2` frente à função `int dobro(int x)`. |
| **Questão 24** | [`exercicio24.c`](exercicio24.c) | Compilação condicional com diretiva `#ifdef DEBUG` para rastreamento transparente de iterações em tempo de depuração. |
| **Questão 25** | [`exercicio25.c`](exercicio25.c) | Algoritmo recursivo clássico de Euclides `int mdc(int a, int b)` e procedimento de redução de fração `simplifica()`. |
| **Questão 26** | [`exercicio26.c`](exercicio26.c) | Função recursiva `long fibonacci(int n)` com análise de complexidade temporal exponencial $O(2^n)$. |
| **Questão 27** | [`exercicio27.c`](exercicio27.c) | Conversor de escalas termométricas modular com 4 funções dedicadas para Celsius, Fahrenheit e Kelvin. |
| **Questão 28** | [`exercicio28.c`](exercicio28.c) | Ponto de Venda de Mercadinho estruturado com funções puras para subtotal, cálculo de desconto de 10% e troco. |
