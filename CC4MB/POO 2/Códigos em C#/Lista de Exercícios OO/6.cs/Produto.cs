using System;
using System.Text;
using System.Collections.Generic;

namespace ConsoleApp
{

    internal class Produto
    {


        public string nome { get; private set; }
        public double preco { get; private set; }
        public int estoque { get; private set; }


        public Produto(string nome, double preco, int estoque)
        {
            this.nome = nome;
            this.preco = preco;
            this.estoque = estoque;
        }

        public override string ToString()
        {
            return $"Produto: {nome}, Preço: {preco}, Quantidade: {estoque}";
        }

        public void atualizar(string novoNome, double novoPreco, int novoEstoque)
        {
            this.nome = novoNome;
            this.preco = novoPreco;
            this.estoque = novoEstoque;
        }
    }
}




