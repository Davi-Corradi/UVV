using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projeto
{
    internal class AgendaTelefonica
    {
        public Dictionary<string, Contato> Agenda { get; set; }

        public AgendaTelefonica() => Agenda = new Dictionary<string, Contato>();

        //public AgendaTelefonica()
        //{
        //    Agenda = new Dictionary<string, Contato>();
        //}

        public void InserirContato(string nome, Contato contato)
        {
            if (!Agenda.ContainsKey(nome))
                {
                    Agenda.Add(nome, contato);
                }
                else
                {
                    Console.WriteLine($"\n[ERRO] O contato com o nome '{nome}' já existe na agenda.");
                }
        }
            //public AgendaTelefonica(Contato contato)
            //{
            //    Agenda.Add(contato.Nome, contato);
            //}
        
        public Contato BuscarContato(string nome)
        {
            if (Agenda.TryGetValue(nome, out Contato contatoEncontrado))
             {
                 return contatoEncontrado;
             }
             
             return null;
        }

        public int QtdContatos()
        {
            return Agenda.Count;
        }

        public void ListarContatos()
        {
            if (Agenda.Count == 0){
                Console.WriteLine("A agenda não possui contatos!");
            }
            foreach(var contato in Agenda.Values){
                Console.WriteLine($"Nome: {contato.Nome} ");
                Console.WriteLine($"Apelido: {contato.Apelido} ");
                Console.WriteLine($"Telefone: {contato.NumeroTelefone} ");
                Console.WriteLine($"Quanto me deve: {contato.QuantoMeDeve} \n");
            }
        }
    }
}
