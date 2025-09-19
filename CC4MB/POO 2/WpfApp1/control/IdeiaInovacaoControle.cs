using System;
using System.Collections.Generic;
using System.Linq;
using System.Printing;
using System.Text;
using System.Threading.Tasks;
using WpfApp1.model;

namespace WpfApp1.control
{
    internal class IdeiaInovacaoControle
    {
        private IdeiaInovacao ModeloPersistencia = new();
       
        public Boolean ControleCadastrarII(string area, string ideia, float custo) 
        {
            ideia = ideia + "!!!!";

            IdeiaInovacao ii = new()
            {
                Area = "",
                Ideia = "",
                Custo = 10
            };

            if (ModeloPersistencia.CadastrarII(ii))
                return true;

            return false;
        }
    }




}
