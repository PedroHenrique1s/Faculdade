using Microsoft.AspNetCore.Mvc;
using CadastroDeCliente.Entidades;
using CadastroDeCliente.Contexto;
using CadastroDeCliente.Models;

namespace CadastroDeCliente.Controllers;

public class ClientesController(BancoDados bd) : Controller
{
    readonly BancoDados Banco = bd;

    public IActionResult Index()
    {
        ClienteModel model = new()
        {
            ListaClientes = [.. Banco.TabelaClientes.OrderBy(dados => dados.Nome)]
        };
        return View(model);
    }

    public IActionResult Salvar(ClienteModel model)
    {
        model.ListaClientes = [ .. Banco.TabelaClientes.OrderBy(dados => dados.Nome)];
        if(ModelState.IsValid){

            Cliente cli  = new Cliente();
            cli.Nome = model.NomeCliente;
            cli.CPF = model.CPFCliente;
            cli.Endereco = model.EnderecoCliente;
            Banco.TabelaClientes.Add(cli);
            Banco.SaveChanges();
            TempData["mensagem"] = "Cliente criado com sucesso";
            return RedirectToAction("Index");
        }else{
            return View("Index", model);
        }
    }

    [HttpGet]

    public IActionResult Editar(int id){
        Cliente cli = Banco.TabelaClientes.Single(dados => dados.Id == id);
        ClienteModel model = new ClienteModel()
        {
            NomeCliente = cli.Nome,
            CPFCliente = cli.CPF,
            EnderecoCliente = cli.Endereco,
            ListaClientes = [.. Banco.TabelaClientes.OrderBy(dados => dados.Nome)]
        };
        return View("Editar", model);
    }

    [HttpPost]

    public IActionResult Editar(int id, ClienteModel model){
        
        model.ListaClientes = [ ..Banco.TabelaClientes.OrderBy(dados => dados.Nome)];
        if(ModelState.IsValid){

            Cliente cli = Banco.TabelaClientes.Single(dados => dados.Id == id);
            cli.Nome = model.NomeCliente;
            cli.CPF = model.CPFCliente;
            cli.Endereco = model.EnderecoCliente;
            Banco.TabelaClientes.Entry(cli).State = Microsoft.EntityFrameworkCore.EntityState.Modified;
            Banco.SaveChanges();
            TempData["mensagem"] = "Cliente editado com sucesso";
            return RedirectToAction("Index");


        }else{
            return View("Editar",model);
        }
    }

    public IActionResult Excluir(int id)
    {
        Cliente cli = Banco.TabelaClientes.Single(dados => dados.Id == id);
        Banco.TabelaClientes.Remove(cli);
        Banco.SaveChanges();
        TempData["mensagem"] = "Cliente excluido com sucesso";
        return RedirectToAction("Index");
    }

}