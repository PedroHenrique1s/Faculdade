namespace ExeMorador;

class Morador
{
    public string Nome { get; set; }
    public string Telefone { get; set; }
    public string CPF { get; set; }
    public int NumeroCasa { get; set; }

    public void MostrarDados(){
        Console.WriteLine($"Nome do Morador:{Nome}\nTelefone:{Telefone}:\nNumero da Casa:{NumeroCasa}");
    }
}