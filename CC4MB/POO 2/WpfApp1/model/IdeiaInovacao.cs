using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WpfApp1.model
{
    internal class IdeiaInovacao
    {
        public string Area { get; set; }
        public string Ideia { get; set; } = string.Empty;
        public float Custo { get; set; }

        public Boolean CadastrarII(IdeiaInovacao i)
        {
            BD.BD.SalvarBD(i);
            
            return true;
        }

        public override string ToString()
        {
                return $"{Area} / {Ideia} / {Custo}";
              // return base.ToString()
        }
    }











}
