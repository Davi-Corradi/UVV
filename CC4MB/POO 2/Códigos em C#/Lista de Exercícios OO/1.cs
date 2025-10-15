﻿using System;
using System.Collections.Generic;

namespace ConsoleApp
{
    internal class Program
    {
        static void Main(string[] args)
        {
            List<int> Idades = new List<int>();

            int idade;
            double a = 0, b = 0, c = 0, d = 0, e = 0;

            do
            {
                Console.WriteLine("Digite sua idade: (Ou digite um número negativo ou 0 para encerrar)");
                idade = int.Parse(Console.ReadLine());

                if (idade <= 0)
                    break;

                Idades.Add(idade);

                if (idade <= 15)
                    a++;
                else if (idade <= 30)
                    b++;
                else if (idade <= 45)
                    c++;
                else if (idade <= 60)
                    d++;
                else
                    e++;

            } while (true);

            double total = Idades.Count;

            Console.WriteLine("\nFaixas etárias:");
            Console.WriteLine($"Até 15 anos: {a}");
            Console.WriteLine($"Até 30 anos: {b}");
            Console.WriteLine($"Até 45 anos: {c}");
            Console.WriteLine($"Até 60 anos: {d}");
            Console.WriteLine($"Acima de 60 anos: {e}");

            if (total > 0)
            {
                Console.WriteLine("\nPorcentagem de pessoas por cada faixa etária:");
                Console.WriteLine($"Até 15 anos: {(a / total) * 100:F2}%");
                Console.WriteLine($"16 a 30 anos: {(b / total) * 100:F2}%");
                Console.WriteLine($"31 a 45 anos: {(c / total) * 100:F2}%");
                Console.WriteLine($"46 a 60 anos: {(d / total) * 100:F2}%");
                Console.WriteLine($"Acima de 60 anos: {(e / total) * 100:F2}%");
            }
            else
            {
                Console.WriteLine("Nenhuma idade foi inserida.");
            }
        }
    }
}