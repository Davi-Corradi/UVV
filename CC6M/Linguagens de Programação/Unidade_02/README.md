# Unidade 02 - Linguagens de Programação (UVV - CC6M)

Esta pasta contém os códigos desenvolvidos para os estudos da Unidade 02, focados em Programação Orientada a Objetos em C++.

## 📁 Arquivos na Pasta

### 1. `conta.cpp` (Versão Inicial)
* **Descrição:** Primeira versão do sistema de produtos. 
* **Características:** O método `aplicarDesconto` altera permanentemente o preço salvo na memória (sem o modificador `const`), o que fazia o cálculo do estoque refletir diretamente o valor com desconto.

### 2. `teste.cpp` (Versão Atualizada / Refatorada)
* **Descrição:** Versão aprimorada e corrigida do código.
* **Melhorias implementadas:**
  * Uso do modificador `const` no método `aplicarDesconto` para proteger a integridade do preço original na memória.
  * O cálculo do valor total do estoque permanece correto, baseando-se sempre no preço original de tabela.
  * Separação de variáveis no `main` (`desconto` e `desconto2`) para evitar sobrescrita de dados.
  * Criação da função auxiliar `exibirDadosComDesconto` para exibir o preço reduzido de forma visual apenas no momento da impressão.
