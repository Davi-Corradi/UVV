using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp
{
    internal class Program
    {
        static void Main(string[] args)
        {

            int escolha;
            double temp;
            double resultado;

            do
            {

                Console.WriteLine("Digite a conversão que deseja fazer: \n");
                Console.WriteLine("Celsius -> Farenheit (1)");
                Console.WriteLine("Farenheit -> Celsius  (2)");
                Console.WriteLine("Celsius -> Kelvin (3)");
                Console.WriteLine("Kelvin -> Celsius(4)");
                Console.WriteLine("Sair(0)");

                escolha = int.Parse(Console.ReadLine());

                if (escolha == 0)
                {
                    Console.WriteLine("Saindo...");
                    return;
                }

                if (escolha < 1 || escolha > 4)
                {
                    Console.WriteLine("\nErro! Digite somente números de 1 a 4 para a conversão.\n");
                }

            } while (escolha < 1 || escolha > 4);

            Console.WriteLine("Digite a temperatura: ");
            temp = double.Parse(Console.ReadLine());

            switch (escolha)
            {

                case 1:
                    resultado = ((temp * 1.8) + 32);
                    Console.WriteLine($"Temperatura em Celsius {temp}º convertida para Farenheit: {resultado:F2} ºF");
                    break;

                case 2:
                    resultado = ((temp - 32) / 1.8);
                    Console.WriteLine($"Temperatura em Farenheit {temp}º convertida para Celsius: {resultado:F2} ºC");
                    break;

                case 3:
                    resultado = (temp + 273.15);
                    Console.WriteLine($"Temperatura em Celsius {temp}º convertida para Kelvin: {resultado:F2} K");
                    break;

                case 4:
                    resultado = (temp - 273.15);
                    Console.WriteLine($"Temperatura em Kelvin {temp}º convertida para Celsius: {resultado:F2} ºC");
                    break;

                default:
                    Console.WriteLine("Erro! Verifique o número da conversão escolhida.");
                    break;
            }
        }
    }
}