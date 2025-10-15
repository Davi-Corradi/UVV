using System;
using System.Text;
using System.Collections.Generic;


namespace ConsoleApp
{

    internal class Program
    {
        static void Main()
        {

            List<double> Temperaturas = new List<double>();

            double soma = 0;

            for (int i = 0; i < 15; i++)
            {

                double temp;
                bool entrada = false;

                do
                {
                    Console.WriteLine($"Digite a temperatura do {i + 1}º dia: ");
                    string? input = Console.ReadLine();
                    if (double.TryParse(input, out temp))
                    {
                        if (temp > 28)
                        {
                            entrada = true;
                        }
                        else
                        {
                            Console.WriteLine("Temperatura inválida! Digite a partir de 28º C");
                        }
                    }
                    else
                    {
                        Console.WriteLine("Entrada inválida! Digite um número válido.");
                    }

                } while (!entrada);

                Temperaturas.Add(temp);
                soma += temp;
            }

            double media = soma / 15;

            Console.WriteLine($"A média das temperaturas é de: {media:2F}");
        }
    }
}