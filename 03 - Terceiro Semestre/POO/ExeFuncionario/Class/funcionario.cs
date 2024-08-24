namespace ExeFuncionario;

class Funcionario
{
    public string Nome {get; set;}
    public string Endereco {get; set;} 
    public string Telefone {get; set;}  
    public Cargo Cargo {get; set;}
    public Setor Setor {get; set;}

    public void MostrarDados(){
        Console.WriteLine($"Nome do Funcionario:{Nome}\nEndereço:{Endereco}\nTelefone:{Telefone}\nCargo:{Cargo.Nome}\nSalario:{Cargo.Salario}");
        Setor.MostrarDados();
    }
}