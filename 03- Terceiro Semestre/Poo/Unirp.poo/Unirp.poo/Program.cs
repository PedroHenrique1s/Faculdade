using System;
namespace Unirp.poo;

class Program
{
    static void Main(string[] args)
    {
        //Criando a instituição
        Instituicao unirp = new Instituicao();
        unirp.Nome = "UNIRP";
        unirp.DataFundacao = "01/01/1996";
        unirp.QuantidadeCursos = 15;
        unirp.AreaAtuacao = "TI";
        unirp.QuantidadeAnos = 58;

        //Mostrar dados
        unirp.MostrarDados();

        //Criando o curso de ciência da Computação
        Curso ciencia = new Curso();
        ciencia.Nome = "Ciência da Computação";
        ciencia.Faculdade = unirp;
        ciencia.CargaHoraria = 3500;
        ciencia.QuantidadeSemestre = 8;

        //Mostrar dados
        ciencia.MostrarDados();
    }
}