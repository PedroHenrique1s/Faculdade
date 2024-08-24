namespace ExeMorador;

class Veiculo 
{
    public string Modelo { get; set; }
    public string Placa { get; set; }
    public Morador Proprietario { get; set; }
    public int NumeroTag { get; set; }

    public void mostrarDados(){
        Console.WriteLine($"Modelo do veiculo:{Modelo}\nPlaca:{Placa}\nNúmero da tag:{NumeroTag}");
        Proprietario.MostrarDados();
    }
}
