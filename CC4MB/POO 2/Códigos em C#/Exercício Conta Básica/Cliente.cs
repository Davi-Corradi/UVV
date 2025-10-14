using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace Projeto
{
    internal class Cliente(string nome, string cpf, string endereco)
    {
        public string Nome { get; set; } = nome;
        public string Cpf { get; set; } = cpf;
        public string Endereco { get; set; } = endereco;

        public Cliente Correntista { get; set; }

    }
}