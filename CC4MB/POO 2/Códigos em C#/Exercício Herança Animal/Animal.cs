using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Channels;
using System.Threading.Tasks;

namespace Projeto
{
    internal class Animal : SerVivo
    {
        public void Mover() => Console.WriteLine("Animal: Mover() ");
        public void Respirar() => Console.WriteLine("Animal: Respirar() ");


    }
}


