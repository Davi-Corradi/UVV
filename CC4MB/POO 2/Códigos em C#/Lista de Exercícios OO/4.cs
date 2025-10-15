using System;
using System.Text;
using System.Collections.Generic;


namespace ConsoleApp
{

    internal class Program
    {
        static void Main()
        {

            Console.WriteLine("--- Supermercado Filho da Mãe ---");

            double precoTotalCesta = 0;
            double precoTotalAlimentacao = 0;
            double precoTotalLimpeza = 0;
            double precoTotalHigiene = 0;



            const int PROD = 20;

            for (int i = 0; i < PROD; i++)
            {
                double preco;
                char codigo = ' ';
                bool entrada;

                do
                {

                    Console.WriteLine($"Digite o preço do {i + 1}º produto");
                    string? input = Console.ReadLine();
                    entrada = double.TryParse(input, out preco);

                    if (!entrada || preco <= 0)
                    {
                        Console.WriteLine("Erro! Por Favor digite um número! ");
                    }
                } while (!entrada || preco <= 0);


                do
                {
                    Console.WriteLine($"Digite o código do {i + 1}º produto");
                    string? input2 = Console.ReadLine();

                    if (!string.IsNullOrEmpty(input2) && input2.Length == 1)
                    {
                        codigo = char.ToUpper(input2[0]);

                        if (codigo == 'L' || codigo == 'A' || codigo == 'H')
                        {
                            entrada = true;
                        }
                        else
                        {
                            entrada = false;
                            Console.WriteLine("Erro. Por Favor digite apeanas caracteres válidos!");
                        }
                    }

                    else
                    {
                        entrada = false;
                        Console.WriteLine("Erro. Por favor, tente novamente");
                    }

                } while (!entrada);

                precoTotalCesta += preco;

                switch (codigo)
                {
                    case 'L':
                        precoTotalLimpeza += preco;
                        break;
                    case 'A':
                        precoTotalAlimentacao += preco;
                        break;
                    case 'H':
                        precoTotalHigiene += preco;
                        break;
                }
            }


            Console.WriteLine("\n--- Visão Geral da Cesta Básica ---");
            Console.WriteLine($"Preço Total da Cesta: R${precoTotalCesta:F2}");
            Console.WriteLine($"Preço Total de Limpeza: R${precoTotalLimpeza:F2}");
            Console.WriteLine($"Preço Total de Alimentação: R${precoTotalAlimentacao:F2}");
            Console.WriteLine($"Preço Total de Higiene: R${precoTotalHigiene:F2}");

        }
    }
}