using System.ComponentModel.DataAnnotations;
using ProjetoAula.Dados;

namespace ProjetoAula.Models;

public class Carrinho
{
    public Produto[] ProdutosDisponiveis { get; set; } = new Produto[3];
    public int QuantidadeSelecionada { get; set; } = 1;
    [Range(1, int.MaxValue, ErrorMessage = "Selecione um produto")]
    public int ProdutoSelecionado { get; set; }
    private List<Item> itens = [];
    public List<Item> ItensCarrinho
    {
        get => itens; set
        {
            itens = value;
            CalcularTotal();
        }
    }
    public double Total { get; private set; }

    public Carrinho()
    {
        ProdutosDisponiveis[0] = new Produto{
            Codigo = 1,
            Nome = "BOLA DE FUTEBOL",
            Preco = 15
        };
        ProdutosDisponiveis[1] = new Produto{
            Codigo = 2,
            Nome = "BONECA",
            Preco = 40
        };
        ProdutosDisponiveis[2] = new Produto{
            Codigo = 3,
            Nome = "CARRINHO",
            Preco = 30
        };
    }

    public void CalcularTotal()
    {
        foreach (var item in ItensCarrinho) Total += item.Subtotal;
    }
}