using System;
using System.Text;
using System.Collections.Generic;

namespace ConsoleApp
{

    internal class Loja
    {
        private List<Produto> produtos = new List<Produto>();

        public string nome { get; private set; }

        public Loja(string nome)
        {

            this.nome = nome;
        }
        public void adicionar(Produto p)
        {
            produtos.Add(p);
        }

        public double calcularTotal()
        {
            double total = 0;
            foreach (var p in produtos)
            {
                total += p.preco * p.estoque;
            }
            return total;
        }

        public List<Produto> getProdutos()
        {
            return produtos;
        }

        public void exibir()
        {
            Console.WriteLine($"Loja: {nome} \n");
            foreach (var p in produtos)
            {
                Console.WriteLine(p);
            }
            Console.WriteLine($"\nTotal: {calcularTotal()}");
        }
    }
}

