## Resumo Detalhado: Unidade 2 - Introdução a Classes, Objetos e POO

O foco desta unidade é a transição da programação estruturada para o paradigma Orientado a Objetos (POO), modelando entidades do mundo real com forte ênfase em arquitetura de software modular, segurança de memória e responsabilidades bem definidas.

### 1. Classes, Objetos e a Abstração do Domínio

A POO agrupa dados e operações relacionadas em uma mesma entidade, abandonando o modelo de funções soltas operando sobre variáveis globais ou independentes.

* **Classe:** É a especificação (o molde ou planta arquitetônica) que descreve as características e os comportamentos de uma categoria.


* **Objeto:** É a instância concreta criada na memória durante a execução do programa a partir da classe.


* **Estado e Comportamento:** O estado é mantido pelos membros de dados (atributos), enquanto o comportamento é definido pelas funções-membro (métodos).



### 2. Encapsulamento e Proteção de Estado

A linguagem utiliza especificadores de acesso para estabelecer uma fronteira rígida entre o que é de uso interno e o que compõe a interface pública, impedindo que o código cliente injete estados inválidos no objeto.

* **Membros `private`:** Ocultam os dados de implementação. Tentativas de acesso direto a atributos privados pelo código externo geram erro de compilação.


* **Getters e Setters (Interface Pública):** Funções-membro `public` atuam como intermediárias para consultar ou modificar o estado. O *setter* é o local exato para implementar regras de validação (ex: rejeitar preços negativos antes de tocar na memória).


* **Ocultamento vs. Funcionalidade:** Encapsular não é apenas criar getters e setters cegamente para todos os atributos; é expor apenas as operações que façam sentido para a regra de negócio daquela entidade.



### 3. Construtores e Inicialização Segura

Construtores são funções-membro especiais invocadas automaticamente no instante em que o objeto é instanciado, garantindo que ele nasça em um estado válido.

* **Características:** Possuem o exato mesmo nome da classe e não possuem tipo de retorno (nem mesmo `void`).


* **Sobrecarga de Construtores:** Uma classe pode ter múltiplos construtores (ex: um padrão sem parâmetros e um parametrizado), desde que suas assinaturas sejam diferentes.


* **Lista de Inicialização de Membros:** É a forma idiomática e mais eficiente de iniciar variáveis em C++. Ela inicializa os atributos estruturalmente antes mesmo do corpo do construtor ser executado (ex: `Produto(std::string n) : nome{n} {}`).


* **Ordem de Inicialização:** O compilador sempre inicializa os membros na exata ordem em que foram declarados dentro da classe, independentemente da ordem escrita na lista do construtor.



### 4. Modularização Arquitetural (Separação `.h` e `.cpp`)

Para manter o projeto escalável, limpo e otimizado para o controle de versão, a interface é separada da implementação.

* **Arquivos de Cabeçalho (`.h` ou `.hpp`):** Contêm o "contrato" da classe — as declarações dos atributos e as assinaturas das funções-membro.


* **Arquivos de Implementação (`.cpp`):** Contêm a lógica real das funções, utilizando o operador de resolução de escopo (`::`) para ligar o método à sua respectiva classe (ex: `void Produto::setPreco(double p)`).


* **Guardas de Inclusão:** Diretivas de pré-processador como `#pragma once` ou o bloco `#ifndef`, `#define` e `#endif` impedem que o compilador leia a mesma classe duas vezes na mesma unidade de tradução, evitando o erro de redefinição de classe.



### 5. Tipagem e a Classe `std::string`

O C++ distingue tipos fundamentais nativos da linguagem (como `int`, `double`, `char`, `bool`) de tipos compostos oferecidos pela Biblioteca Padrão.

* A `std::string` é uma classe da biblioteca `<string>`, não um tipo fundamental, o que significa que ela possui funções-membro próprias (como `.size()`) e sobrecarga de operadores (como `+` para concatenação).


* A indexação começa em zero, e tentar acessar uma posição fora do limite ($n-1$) resulta em falha de memória.



### 6. Matriz de Paradigmas em C++

A linguagem permite resolver o mesmo problema sob diferentes óticas, impactando diretamente a engenharia do software.

* **Imperativo:** Foca em laços manuais e mutabilidade contínua (ex: variáveis contadoras locais), o que dificulta o paralelismo devido a efeitos colaterais e condições de corrida.


* **Orientado a Objetos:** Foca no encapsulamento. Protege o estado interno, garantindo manutenibilidade e baixo acoplamento.


* **Funcional (C++20 Ranges):** Prioriza a imutabilidade e diz "o que fazer" em vez de "como fazer" (ex: usando `std::views::filter`). Ao eliminar variáveis que mudam de estado, torna-se naturalmente seguro para múltiplas threads (thread-safe).



---

### Pontos de Atenção Prática e Provas

* **O Ponto e Vírgula Final:** A declaração de uma classe exige obrigatoriamente um `;` após a chave de fechamento (`};`). Esquecer isso trava a compilação no arquivo de cabeçalho.


* **Instanciação Falsa:** Escrever `class Produto { };` não cria um objeto, apenas especifica o tipo. O objeto só existe na memória ao ser declarado explicitamente (`Produto p;`).


* **Inclusões Implícitas:** Nunca dependa de um cabeçalho carregando outro em segundo plano. Se o arquivo usa fluxo de saída e strings, ele deve incluir `#include <iostream>` e `#include <string>` explicitamente.
