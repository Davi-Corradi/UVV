### Resumo Completo da Unidade 3: Funções e Fundamentos da Biblioteca Padrão

#### 1. Arquitetura Modular e Abstração Procedural

A construção de softwares escaláveis no C++ fundamenta-se na estratégia de "dividir para conquistar" (divide and conquer), que particiona problemas complexos em subproblemas autônomos e testáveis chamados funções. A **abstração procedural** é o princípio que separa a interface de uma função (o que ela exige e o que retorna) da sua implementação concreta (como os cálculos são feitos). Isso garante o reaproveitamento de código (princípio DRY - Don't Repeat Yourself) e o ocultamento de detalhes lógicos.

#### 2. Anatomia de uma Função: Parâmetros vs. Argumentos

Uma função é estruturada em um **cabeçalho** (tipo de retorno, nome e lista de parâmetros) e um **corpo** (o bloco delimitado por chaves `{}`). A distinção terminológica é rigorosa no C++:

* **Parâmetro (Formal):** É a variável local declarada na assinatura da função (ex: `int numero` em `int calcular(int numero)`).


* **Argumento (Real):** É o valor numérico, variável ou expressão concreta fornecida no exato momento da chamada da função (ex: `calcular(5)`).



#### 3. Gerenciamento de Memória e Pilha de Execução (Call Stack)

Toda chamada de função desencadeia operações físicas na memória RAM através da **pilha de execução** (call stack). Quando uma função é invocada, o sistema empilha um **quadro de pilha** (stack frame), que armazena temporalmente os parâmetros fornecidos, as variáveis locais e o endereço de retorno para a função chamadora.
Quando a função atinge o comando `return` ou o fechamento das chaves, o quadro de pilha é desempilhado (popped) e toda a memória associada àquelas variáveis locais é permanentemente desalocada e destruída.

#### 4. A Biblioteca `<cmath>` e Processamento Numérico

A Biblioteca Padrão fornece algoritmos matemáticos otimizados no cabeçalho `<cmath>`, com todas as suas entidades alocadas no `namespace std`.

* **Arredondamento:** `std::ceil(x)` força o arredondamento para o teto (maior inteiro), enquanto `std::floor(x)` puxa para o chão (menor inteiro).


* **Trigonometria e Proteção:** Funções como `std::sin` e `std::tan` operam **estritamente em radianos**. Para cálculos de distância, a função `std::hypot(x, y)` deve ser preferida no lugar de `std::sqrt(x*x + y*y)`, pois o algoritmo interno do `hypot` impede erros de intervalo (overflow ou underflow) que poderiam explodir os limites da memória durante multiplicações gigantescas.



#### 5. Protótipos, Definições e Fases de Compilação

Como o compilador C++ lê os arquivos sequencialmente de cima para baixo, as funções precisam ser anunciadas antes de serem chamadas.

* **Protótipo (Declaração):** Apresenta a interface da função ao compilador para permitir o *type checking* (verificação rigorosa de tipos). Termina em ponto e vírgula e dispensa a nomeação de parâmetros (apenas os tipos são obrigatórios).


* **Definição (Implementação):** Contém o bloco de código funcional. Se o protótipo existir, mas a definição for omitida, a compilação ocorre com sucesso, mas o processo esbarra em um **erro de vinculação** (linker error) apontando falha na referência.



#### 6. Assinaturas de Funções e o Mecanismo de Sobrecarga

A **assinatura da função** é composta unicamente pelo **nome da função** somado à **sequência exata dos tipos dos seus parâmetros**. O tipo de retorno e os nomes das variáveis **não** fazem parte da assinatura. Essa regra define a **sobrecarga de funções**, permitindo que funções tenham o mesmo nome, desde que suas listas de parâmetros sejam exclusivas.

**O seu código de exemplo e a Ambiguidade:**

```cpp
#include <iostream>

// Protótipos com assinaturas distintas:
// Assinatura 1: soma(int, int)
int soma(int a, int b); 
// Assinatura 2: soma(double, double)
double soma(double c, double d); 

int main() {
    std::cout << "A soma eh: " << soma(5, 8);         // Chama soma(int, int) perfeitamente.
    std::cout << "\nA soma eh: " << soma(5.5, 8.5);   // Chama soma(double, double) perfeitamente.
    
    // Chamada ambígua: soma(int, double)
    // std::cout << "\nA soma eh: " << soma(5, 8.5); 
    
    return 0;
}

int soma(int a, int b) { return a + b; }
double soma(double c, double d) { return c + d; }

```

A terceira chamada (`soma(5, 8.5)`) injeta um `int` e um `double`. O compilador entra em colapso lógico porque encontra duas rotas viáveis, cada uma custando exatamente uma conversão:

* Rota A: Usar `soma(int, int)` exigiria manter o `5` e **truncar** o `8.5` para `8`.
* Rota B: Usar `soma(double, double)` exigiria **promover** o `5` para `5.0` e manter o `8.5`.
Como o compilador C++ não toma decisões de conversões simultâneas conflitantes (ele não advinha a sua intenção), ele interrompe a execução com um erro de ambiguidade.

#### 7. Coerção de Argumentos: Promoção vs. Truncamento

A coerção é a adaptação forçada que a linguagem faz quando o tipo do argumento não bate com o tipo do parâmetro formal.

* **Promoção (Promotion):** Ocorre sem perda de dados. Transforma tipos menores em maiores (ex: `int` para `double`, ou `char` promovido para seu correspondente inteiro ASCII).


* **Estreitamento (Demotion/Truncation):** Ocorre com potencial perda de dados. Passar um `double 9.9` para um parâmetro `int` descarta silenciosamente as casas decimais, gravando apenas `9` na memória.



#### 8. Bibliotecas Padrão, Namespaces e Portabilidade

No C++ moderno, as bibliotecas antigas do C (como `math.h` e `stdlib.h`) sofreram uma atualização padronizada: o sufixo `.h` foi removido e o prefixo `c` foi acoplado (tornando-se `<cmath>` e `<cstdlib>`). Essa mudança arquitetural garante que as funções sejam alocadas no `namespace std`, evitando poluição do escopo global. Adicionalmente, confiar em **inclusões implícitas** (quando o compilador carrega uma biblioteca embutida em outra secretamente) destrói a portabilidade do software entre sistemas operacionais diferentes.

---

### Principais Pontos de Atenção para Provas (Armadilhas Comuns)

* **A Ilusão do Retorno na Sobrecarga:** As bancas adoram afirmar que "duas funções podem ter os mesmos parâmetros se retornarem tipos diferentes". **Falso.** O retorno é ignorado pelo compilador na verificação da assinatura. O código não compilará.
* **O Ângulo das Funções Trigonométricas:** Na pressa, é comum passar graus literais para `std::sin(90.0)`. A linguagem sempre interpretará isso como 90 radianos. A conversão ($Graus \times \pi / 180$) deve ocorrer antes da injeção do argumento.
* **Compilador vs. Linker:**
* Erro no Protótipo: O código não compila (Identifier not declared).
* Erro na Definição (Corpo faltando): O código compila, mas trava no Linker (Undefined reference).


* **A Mentira do Arredondamento Implícito:** A coerção de `double` para `int` **nunca arredonda matematicamente** para o número mais próximo. Ela opera exclusivamente via truncamento agressivo (corta toda a casa decimal). Um `3.99` armazenado em um `int` vira apenas `3`.
* **Retorno de Variáveis Locais:** Afirmações sugerindo que "retornar a referência de uma variável calculada dentro da função economiza memória" estão tecnicamente erradas e engatilham Comportamentos Indefinidos, pois o stack frame morre assim que o return finaliza.
