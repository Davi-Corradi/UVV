
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projeto
{
    internal class SerVivo
    {
        public int Tamanho { get; set; }

        public void Nascer() => Console.WriteLine("Ser Vivo: Nascer()");
        public void Crescer() => Console.WriteLine("Ser Vivo: Crescer()");
        public void Morrer() => Console.WriteLine("Ser Vivo: Morrer()");
    }
}

