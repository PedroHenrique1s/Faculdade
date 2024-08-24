namespace exeContaBancaria;
public class ContaPoupanca: ContaBancaria 
{
    public void Render(double taxa){
        Saldo += Saldo * (taxa/100);
        VerSaldo();
    }
}