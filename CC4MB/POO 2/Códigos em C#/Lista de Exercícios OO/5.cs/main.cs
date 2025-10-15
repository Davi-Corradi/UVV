using System;
using System.Text;
using System.Collections.Generic;


namespace ConsoleApp
{

    internal class Program
    {
        static void TentaCadastrar(Funcionario f)
        {
            if (Funcionario.cadastrar(f))
                Console.WriteLine($"Funcionário(a) {f.getNome()} cadastrado com sucesso!");
            else
                Console.WriteLine($"Falha ao cadastrar funcionário(a) {f.getNome()}, a matrícula já existe.");
        }

        static void Main()
        {

            Console.WriteLine("--- GESTÃO DE RH ---");

            TentaCadastrar(new Funcionario(123, "Davi", "Adm", 1000f));
            TentaCadastrar(new Funcionario(1234, "Daniel", "Gordo", 10000f));
            TentaCadastrar(new Funcionario(123, "Maria", "RH", 2000f));

            /* Funcionario f1 = new Funcionario(123, "Davi", "Adm", 1000f);
            Funcionario f2 = new Funcionario(1234, "Daniel", "Gordo", 10000.55f); */

            // Funcionario.cadastrar(f2);
            // Funcionario.cadastrar(f2);

            Funcionario.consultar();
            Funcionario.listar();

            var f = Funcionario.Funcionarios[0];
            Funcionario.atualizarSalario(f, 500f);
            Console.WriteLine(f.ToString());

        }
    }
}






