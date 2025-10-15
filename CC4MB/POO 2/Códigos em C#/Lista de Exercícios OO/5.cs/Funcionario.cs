using System;
using System.Text;
using System.Collections.Generic;

namespace ConsoleApp
{

    internal class Funcionario
    {

        public static List<Funcionario> Funcionarios = new List<Funcionario>();

        /*  private int Matricula {get; set;}
            private string Nome {get; set;}
            private string cargoAtual {get; set;} 
            private float salarioAtual {get; set;} */

        private int Matricula;
        private string Nome;
        private string cargoAtual;
        private float salarioAtual;

        public int getMatricula() { return Matricula; }
        public string getNome() { return Nome; }
        public string getCargoAtual() { return cargoAtual; }
        public float getSalarioAtual() { return salarioAtual; }


        public Funcionario(int matricula, string nome, string cargoAtual, float salarioAtual)
        {
            this.Matricula = matricula;
            this.Nome = nome;
            this.cargoAtual = cargoAtual;
            this.salarioAtual = salarioAtual;
        }

        public static bool cadastrar(Funcionario f)
        {
            foreach (var func in Funcionarios)
            {
                if (func.Matricula == f.Matricula)
                {
                    Console.WriteLine($"\nFuncionário(a) com matrícula {f.Matricula} já cadastrado!");
                    return false;
                }
            }
            Funcionarios.Add(f);
            return true;
        }

        public static void listar()
        {
            Console.WriteLine("\nLista de funcionários cadastrados: \n");

            foreach (var f in Funcionarios)
            {
                Console.WriteLine($"Nome: {f.getNome()} \nMatrícula: {f.getMatricula()} \nCargo: {f.getCargoAtual()} \nSálario: R$ {f.getSalarioAtual()} \n");
            }
        }

        public static void consultar()
        {
            Console.WriteLine("\nConsultando a lista de funcionários!");
        }


        public static void atualizarSalario(Funcionario f, float valor)
        {
            f.salarioAtual += valor;
            Console.WriteLine($"\nSalário atualizado do funcionário {f.getNome()}: R$ {f.getSalarioAtual()}");
        }
        public override string ToString()
        {
            return $"Nome: {Nome} " +
                $"\nMatrícula: {Matricula}" +
                $"\nCargo: {cargoAtual}" +
                $"\nSalário: R$ {salarioAtual}";
        }
    }
}

