using System;
using System.Text;
using System.Collections.Generic;


namespace ConsoleApp
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Loja loja = new Loja("Loja do Mestre André");

            Produto p1 = new Produto("Camisa", 60.00, 30);
            Produto p2 = new Produto("Celular", 1000.00, 20);
            Produto p3 = new Produto("Caneta", 10.00, 50);

            loja.adicionar(p1);
            loja.adicionar(p2);
            loja.adicionar(p3);

            p3.atualizar("Borracha", 3.0, 50);

            loja.exibir();
        }
    }
}

