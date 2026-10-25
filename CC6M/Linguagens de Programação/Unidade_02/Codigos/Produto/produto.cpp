#include "produto.hpp"
#include <iostream>
#include <format>

Produto::Produto() : codigo(0), preco(0.0), quantidade(0) {}

Produto::Produto(int codigo, double preco, int quantidade)
    : codigo(codigo > 0 ? codigo : 0),
      preco(preco > 0.0 ? preco : 0.0),
      quantidade(quantidade > 0 ? quantidade : 0)
{
}

void Produto::setCodigo(int novoCodigo)
{
    if (novoCodigo >= 0)
    {
        codigo = novoCodigo;
    }
    else
    {
        std::cout << "Codigo invalido! \n";
    }
}

void Produto::setPreco(double novoPreco)
{
    if (novoPreco >= 0.0)
    {
        preco = novoPreco;
    }
    else
    {
        std::cout << "Preco invalido! \n";
    }
}

void Produto::setQuantidade(int novaQuantidade)
{
    if (novaQuantidade >= 0)
    {
        quantidade = novaQuantidade;
    }
    else
    {
        std::cout << "Quantidade invalida! \n";
    }
}

int Produto::getCodigo() const { return codigo; }
double Produto::getPreco() const { return preco; }
int Produto::getQuantidade() const { return quantidade; }

double Produto::aplicarDesconto(double percentual) const
{
    return preco - (preco * (percentual / 100));
}

double Produto::calcularValorEstoque() const
{
    return preco * quantidade;
}

void exibirValorEstoque(const Produto &produto)
{
    double valorEstoque = produto.calcularValorEstoque();
    std::cout << "Valor total do estoque: " << valorEstoque << "\n";
}

void exibirDados(const Produto &produto)
{
    std::cout << "Codigo: " << produto.getCodigo() << "\n";
    std::cout << std::format("Preco: {:.2f}\n", produto.getPreco());
    std::cout << "Quantidade: " << produto.getQuantidade() << "\n";
}

void exibirDadosComDesconto(const Produto &produto, double percentualDesconto)
{
    std::cout << "Codigo: " << produto.getCodigo() << "\n";
    std::cout << std::format("Preco: {:.2f}\n", produto.aplicarDesconto(percentualDesconto));
    std::cout << "Quantidade: " << produto.getQuantidade() << "\n";
}