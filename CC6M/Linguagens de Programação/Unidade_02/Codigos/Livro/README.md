# Projeto Livro - Orientação a Objetos em C++ 📚

Este repositório contém a implementação da classe `Livro` em C++, demonstrando a evolução de um código monolítico para um código modularizado, seguindo as boas práticas de programação orientada a objetos (POO).

## 🗂️ Estrutura do Repositório

O projeto está dividido em duas abordagens para fins didáticos:

### 1. Abordagem Monolítica (`livro.cpp`)
* **`livro.cpp`**: Contém toda a implementação da classe (definição de atributos, construtores, métodos de acesso, modificadores e exibição) em **um único arquivo**, sem a separação de interfaces (`.h`) ou modularização avançada.

### 2. Abordagem Modularizada (`Livro.cpp`, `livro.h` e `main.cpp`)
Esta é a versão atualizada e recomendada, onde o código foi refatorado aplicando a separação de responsabilidades e encapsulamento em múltiplos arquivos:
* **`livro.h`**: Arquivo de cabeçalho contendo a declaração da classe `Livro`, seus atributos privados e protótipos de métodos.
* **`Livro.cpp`**: Arquivo de implementação contendo o código real dos métodos e construtores declarados no cabeçalho.
* **`main.cpp`**: Arquivo principal responsável por instanciar os objetos (`Livro`) e testar as funcionalidades da classe.

---

## 🚀 Como Compilar e Executar (Versão Modularizada)

Se você estiver utilizando o terminal com o compilador `g++`, você pode compilar a versão modularizada executando o seguinte comando:

```bash
g++ main.cpp Livro.cpp -o programa_livro
