using Projeto;

namespace Projeto
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("=== SerVivo ===");
            SerVivo sv = new();

            sv.Nascer();
            sv.Crescer();
            sv.Morrer();

            Console.WriteLine("\n=== Animal ===");
            Animal animal = new Animal();

            animal.Nascer();
            animal.Crescer();
            animal.Mover();
            animal.Respirar();

        }
    }
}
