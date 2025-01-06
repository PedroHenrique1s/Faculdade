namespace ProjetoAula.Dados;

public class Item
{
    public Produto Produto {get; set;} = new();
    private int qtd;
    public int Quantidade {get => qtd; set{
        qtd = value;
        CalcularSubtotal();
    }}
    public double Subtotal {get; private set;}

    private void CalcularSubtotal() => Subtotal = Quantidade * Produto.Preco;
}