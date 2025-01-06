namespace CadastroDeCliente.Entidades;

public class Cliente 
{
    public int Id {get; set;}
    public string Nome {get; set; }  = string.Empty;
    public string CPF  {get; set; } = string.Empty;
    public string Endereco {get; set; } = string.Empty;
}