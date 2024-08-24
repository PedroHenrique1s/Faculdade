namespace ExeMorador;

class Checkin
{
   public string Data { get; set; }
    public string Hora { get; set; }
    public Veiculo Veiculo { get; set; }

    public void mostrarDados(){
        Console.WriteLine($"\nData do checkin:{Data}\nHora:{Hora}\nDados do Veiculo: ");
        Veiculo.mostrarDados();
    } 
}