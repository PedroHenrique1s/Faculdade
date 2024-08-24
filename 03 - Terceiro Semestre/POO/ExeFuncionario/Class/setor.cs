namespace ExeFuncionario;

class Setor
{
    public string Nome { get; set; }
    public string Sigla { get; set;}
    public Funcionario Chefe { get; set; }

    public void MostrarDados(){
        Console.WriteLine($"Nome do Setor:{Nome}\n Sigla:{Sigla}\nChefe:{Chefe.Nome}");
    }
}