using Microsoft.AspNetCore.Mvc;
using ProjetoAula.Dados;
using ProjetoAula.Models;
using System.ComponentModel;
using System.Text.Json;

namespace ProjetoAula.Controllers;

public class SessaoController : Controller
{
    public IActionResult Index()
    {
        Carrinho model = new Carrinho();
        if (HttpContext.Session.Keys.Contains("carrinho")) model.ItensCarrinho = JsonSerializer.Deserialize<List<Item>>(HttpContext.Session.GetString("carrinho") ?? "") ?? [];
        return View(model);
    }

    public IActionResult Adicionar(Carrinho model)
    {
        if (HttpContext.Session.Keys.Contains("carrinho")) model.ItensCarrinho = JsonSerializer.Deserialize<List<Item>>(HttpContext.Session.GetString("carrinho") ?? "") ?? [];
        if (model.ProdutoSelecionado == 0)
        {
            ModelState.AddModelError("ProdutoSelecionado", "Selecione um produto para adicionar");
            return View("Index", model);
        }
        else
        {
            if (model.ItensCarrinho.Any(item => item.Produto.Codigo == model.ProdutoSelecionado)) model.ItensCarrinho.Single(item => item.Produto.Codigo == model.ProdutoSelecionado).Quantidade += model.QuantidadeSelecionada;
            else
            {
                model.ItensCarrinho.Add(new Item
                {
                    Produto = model.ProdutosDisponiveis.Single(p => p.Codigo == model.ProdutoSelecionado),
                    Quantidade = model.QuantidadeSelecionada
                });
            }
            model.CalcularTotal();
            HttpContext.Session.SetString("carrinho", JsonSerializer.Serialize(model.ItensCarrinho));
            return RedirectToAction("Index");
        }
    }

    public IActionResult Diminuir(int id, Carrinho model)
    {
        model.ItensCarrinho = JsonSerializer.Deserialize<List<Item>>(HttpContext.Session.GetString("carrinho") ?? "") ?? [];
        if(model.ItensCarrinho.Single(i => i.Produto.Codigo == id).Quantidade > 1) model.ItensCarrinho.Single(item => item.Produto.Codigo == id).Quantidade -= 1;
        else model.ItensCarrinho.Remove(model.ItensCarrinho.Single(i => i.Produto.Codigo == id));
        model.CalcularTotal();
        HttpContext.Session.SetString("carrinho", JsonSerializer.Serialize(model.ItensCarrinho));
        return RedirectToAction("Index");
    }

    public IActionResult Aumentar(int id, Carrinho model)
    {
        model.ItensCarrinho = JsonSerializer.Deserialize<List<Item>>(HttpContext.Session.GetString("carrinho") ?? "") ?? [];
        model.ItensCarrinho.Single(item => item.Produto.Codigo == id).Quantidade += 1;
        model.CalcularTotal();
        HttpContext.Session.SetString("carrinho", JsonSerializer.Serialize(model.ItensCarrinho));
        return RedirectToAction("Index");
    }

    public IActionResult Remover(int id, Carrinho model)
    {
        model.ItensCarrinho = JsonSerializer.Deserialize<List<Item>>(HttpContext.Session.GetString("carrinho") ?? "") ?? [];
        model.ItensCarrinho.Remove(model.ItensCarrinho.Single(i => i.Produto.Codigo == id));
        HttpContext.Session.SetString("carrinho", JsonSerializer.Serialize(model.ItensCarrinho));
        return RedirectToAction("Index");
    }
}