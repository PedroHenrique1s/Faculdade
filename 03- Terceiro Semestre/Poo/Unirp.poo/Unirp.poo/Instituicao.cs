using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Unirp.poo
{
    internal class Instituicao
    {
        public Instituicao() { }
        public string Nome { private get; set; }
        public string DataFundacao { private get; set; }
        public int QuantidadeAnos { private get; set; }
        public string AreaAtuacao { private get; set; }
        public int QuantidadeCursos { private get; set; }

        public void MostrarDados()
        {
            Console.WriteLine($"{Nome}\n{DataFundacao}\n{QuantidadeAnos}\n{AreaAtuacao}\n{QuantidadeCursos}");
        }
    }
}
