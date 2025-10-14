using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projeto
{
    internal class Conta(double limite, int numero, double saldo)
    {

        public double Limite { get; set; } = limite;
        public double Numero { get; set; } = numero;
        public double Saldo { get; set; } = saldo;
        public Cliente Correntista { get; internal set; }


        //public Conta(double Limite, int Numero, double Saldo)
        //{
        //    this.Limite = Limite;  
        //    this.Numero = Numero;   
        //    this.Saldo = Saldo; 
        //}

        public bool Sacar(double valor)
        {
            //if (Correntista == null)
            //{
            //    return valor;
            //}

            if (Saldo > valor)
            {
                Saldo = Saldo - valor;
                return true;
            }
            return false;
        }

        public void Depositar(double valor) => Saldo += valor;
        //    public void Depositar(double valor)
        //    {
        //        //Saldo = Saldo + valor;
        //        //Saldo += valor;

        //    }


        private bool VerificarTransacao(double valor) => Saldo > valor;

        //private bool VerificarTransacao(double valor)
        //{
        //    return Saldo > valor;  
        //}


        //private bool VerificarTransacao(double valor)
        //{
        //    if (Saldo > valor)
        //    {
        //        return true;
        //    }
        //}
    }
}
