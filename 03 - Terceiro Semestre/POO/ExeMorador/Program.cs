namespace ExeMorador;

class Program
{
    static void Main(string[] args)
    {
        Morador m = new Morador();
        m.Nome = "Pedro";
        m.CPF = "123456";
        m.Telefone = "123456";
        m.NumeroCasa = 35;

        Veiculo v = new Veiculo();
        v.Placa = "EAQ-2231";
        v.Modelo = "Fiat Uno";
        v.NumeroTag = 3211123;
        v.Proprietario = m;

        Checkin c = new Checkin();
        c.Data = "14/08/2024";
        c.Hora = "19:52";
        c.Veiculo = v;

        c.mostrarDados();
    }
}
