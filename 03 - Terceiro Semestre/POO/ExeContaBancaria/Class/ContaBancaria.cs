namespace exeContaBancaria;

public class ContaBancaria {
    
    public string NumeroConta { get; set; }
    public string NomeTitular { get; set; }
    protected double Saldo;

    public  virtual void AbrirConta(double depositoInicial){
        Saldo = depositoInicial;
        VerSaldo();
    }

    public void Depositar(double valorDeposito){
        Saldo += valorDeposito;
        VerSaldo();
    }

    public virtual void Sacar(double valorSaque){
        Saldo -= valorSaque;
        VerSaldo();
    }

    protected void VerSaldo(){
        Console.WriteLine($"Saldo{Saldo:F}");
    }
    
}