namespace ExeContaBancaria;

class Program
{
    static void Main(string[] args)
    {
        ContaBancaria cb = new ContaBancaria();
        Console.WriteLine($"Digite um valor para abrir a conta: ");
        cb.AbrirConta(double.Parse(Console.ReadLine()));
        Console.WriteLine("Digite um valor para sacar: ");
        cb.Sacar(double.Parse(Console.ReadLine()));
        Console.WriteLine("Digite um valor para depositar: ");
        cb.Depositar(double.Parse(Console.ReadLine()));

        ContaEspecial ce = new ContaEspecial();
        Console.WriteLine($"Digite um valor para abrir a conta: ");
        ce.AbrirConta(double.Parse(Console.ReadLine()));
        Console.WriteLine("Digite um valor para sacar: ");
        ce.Sacar(double.Parse(Console.ReadLine()));
        Console.WriteLine("Digite um valor para depositar: ");
        ce.Depositar(double.Parse(Console.ReadLine()));

        ContaPoupanca cp = new ContaPoupanca();
        Console.WriteLine($"Digite um valor para abrir a conta: ");
        cp.AbrirConta(double.Parse(Console.ReadLine()));
        cp.Render(10);

    }
}
