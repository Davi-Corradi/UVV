#pragma once

class Produto
{
private:
    int codigo{0};
    double preco{0.0};
    int quantidade{0};

public:
    Produto();
    Produto(int codigo, double preco, int quantidade);

    void setCodigo(int novoCodigo);
    void setPreco(double novoPreco);
    void setQuantidade(int novaQuantidade);

    int getCodigo() const;
    double getPreco() const;
    int getQuantidade() const;

    double aplicarDesconto(double percentual) const;
    double calcularValorEstoque() const;
};

void exibirDados(const Produto &produto);
void exibirValorEstoque(const Produto &produto);
void exibirDadosComDesconto(const Produto &produto, double percentualDesconto);