using static System.Net.Mime.MediaTypeNames;

namespace Projeto
{
    internal class Program
    {
        static void Main(string[] args)
        {

            Conta cc = new(1000, 1, 100);
            Cliente c1 = new("Vinicius", "123", "UVV");

            cc.Correntista = c1;

            Console.WriteLine($"Saldo: {cc.Saldo}");
            cc.Depositar(200);
            Console.WriteLine($"Saldo Novo: {cc.Saldo}");

            Console.WriteLine("");
        }
    }
}