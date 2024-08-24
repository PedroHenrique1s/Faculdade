namespace ExeFuncionario;

class Program
{
    static void Main(string[] args)
    {
        Cargo c1 = new Cargo();
        c1.Nome = "Analista";
        c1.Salario = 5000;

        Cargo c2 = new Cargo();
        c2.Nome = "DEV";
        c2.Salario = 3000;

        Setor s = new Setor();
        s.Nome = "Tecnologia";
        s.Sigla  = "TI";

        s.Chefe = new Funcionario();
        s.Chefe.Nome = "Chefe";
        s.Chefe.Endereco = "Rua 1";
        s.Chefe.Telefone = "123456";
        s.Chefe.Cargo = c1;
        s.Chefe.Setor = s;

        Funcionario f = new Funcionario();
        f.Nome = "João";
        f.Endereco = "Rua 2";
        f.Telefone = "123456";
        f.Cargo = c2;
        f.Setor = s;

        f.MostrarDados();

    }
}
