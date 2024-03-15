using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Unirp.poo
{
    internal class Curso
    {
        public string Nome { private get; set; }
        public int QuantidadeSemestre { private get; set; }
        public int CargaHoraria { private get; set; }
        public Instituicao Faculdade { private get; set; }
        public Curso() { }

        public void MostrarDados()
        {
            Console.WriteLine($"{Nome}\n{QuantidadeSemestre}\n{CargaHoraria}\n");
            Faculdade.MostrarDados();
        }
    }
}
