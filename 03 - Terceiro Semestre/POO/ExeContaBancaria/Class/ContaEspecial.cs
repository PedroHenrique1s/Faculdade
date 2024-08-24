namespace exeContaBancaria;

public class ContaEspecial: ContaBancaria 
{
    private double Limite;

    public override void AbrirConta(double depositoInicial)
    {
        Limite = 2 * depositoInicial;
        base.AbrirConta(depositoInicial);
    }

    public override void Sacar(double valorSaque){
        if(valorSaque > Limite) Console.WriteLine("Limite Indisponível");
        else {
            Limite -= valorSaque;
            base.Sacar(valorSaque);
        }
    }

}