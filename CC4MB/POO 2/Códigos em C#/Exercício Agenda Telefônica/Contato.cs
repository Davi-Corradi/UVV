
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projeto
{
    internal class Contato
    {
        public string Nome { get; set; }
        public string NumeroTelefone { get; set; }
        public string Apelido { get; set; }

        public int QuantoMeDeve { get; set; }

        public Contato(string nome, string numeroTelefone, string apelido, int quantoMeDeve)
        {
            Nome = nome;
            NumeroTelefone = numeroTelefone;
            Apelido = apelido;
            QuantoMeDeve = quantoMeDeve;
        }
        
        override public string ToString(){
            return $"Nome: {Nome}\n" +
                   $"Número: {NumeroTelefone}\n" +
                   $"Apelido: {Apelido}\n" +
                   $"Dívida: R$ {QuantoMeDeve:F2}";
        }
    }
}

