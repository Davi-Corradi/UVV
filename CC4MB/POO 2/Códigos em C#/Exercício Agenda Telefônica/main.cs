using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projeto
{
    internal class Program
    {
        static void Main(string[] args)
        {

            Contato contato = new Contato("Vinicius", "123", "Vini", 1000);
            Contato contato2 = new Contato("Daniel", "1234", "Meio Fio", 10000);
            Contato contato3 = new Contato("Hans", "12345", "Holf", 100);
            
            AgendaTelefonica agendaTelefonica = new AgendaTelefonica();

            agendaTelefonica.InserirContato(contato.Nome, contato);
            agendaTelefonica.InserirContato(contato2.Nome, contato2);
            agendaTelefonica.InserirContato(contato3.Nome, contato3);

            
            Console.WriteLine($"Minha agenda tem {agendaTelefonica.QtdContatos()} contatos \n");
            Console.WriteLine("São eles: \n");
            
            agendaTelefonica.ListarContatos();
            
            
            Console.WriteLine("Buscando o contato 'Daniel': ");
            
            Contato contatoBuscado = agendaTelefonica.BuscarContato("Daniel");

            if (contatoBuscado != null)
            {
                Console.WriteLine("\n--- Contato Encontrado ---");
                Console.WriteLine(contatoBuscado); 
                Console.WriteLine("--------------------------");
            }
            else
            {
                Console.WriteLine("O contato não foi encontrado na agenda.");
            }
        }
    }
}