using Microsoft.AspNetCore.Mvc;
using TarefasApp.Entidades;
using TarefasApp.Contexto;
using TarefasApp.Models;

namespace TarefasApp.Controllers;
public class TarefasController(BancoDados bd) : Controller
{
    readonly BancoDados Banco = bd;

    public IActionResult Index()
    {
        TarefaModel model = new()
        {
            ListaTarefas = [.. Banco.TabelaTarefas.OrderBy(t => t.Nome)]
        };
        return View(model);
    }

    public IActionResult Criar(TarefaModel model)
    {
        model.ListaTarefas = [.. Banco.TabelaTarefas.OrderBy(t => t.Nome)];
        if (ModelState.IsValid)
        {
            Tarefa tf = new Tarefa();
            tf.Nome = model.NomeTarefa;
            tf.Status = model.StatusTarefa;
            Banco.TabelaTarefas.Add(tf);
            Banco.SaveChanges();
            TempData["mensagem"] = "TAREFA CRIADA COM SUCESSO";
            return RedirectToAction("Index");
        }
        else return View("Index", model);
    }

    [HttpGet]
    public IActionResult Editar(int id)
    {
        Tarefa tf = Banco.TabelaTarefas.Single(t => t.Id == id);
        TarefaModel model = new TarefaModel()
        {
            NomeTarefa = tf.Nome,
            StatusTarefa = tf.Status,
            ListaTarefas = [.. Banco.TabelaTarefas.OrderBy(t => t.Nome)]
        };
        return View("Editar", model);
    }

    [HttpPost]
    public IActionResult Editar(int id, TarefaModel model)
    {
        model.ListaTarefas = [.. Banco.TabelaTarefas.OrderBy(t => t.Nome)];
        if (ModelState.IsValid)
        {
            Tarefa tf = Banco.TabelaTarefas.Single(t => t.Id == id);
            tf.Nome = model.NomeTarefa;
            tf.Status = model.StatusTarefa;
            Banco.TabelaTarefas.Entry(tf).State = Microsoft.EntityFrameworkCore.EntityState.Modified;
            Banco.SaveChanges();
            TempData["mensagem"] = "TAREFA SALVA COM SUCESSO";
            return RedirectToAction("Index");
        }
        else return View("Editar", model);
    }

    public IActionResult Concluir(int id)
    {
        Tarefa tf = Banco.TabelaTarefas.Single(t => t.Id == id);
        tf.Status = 1;
        Banco.TabelaTarefas.Entry(tf).State = Microsoft.EntityFrameworkCore.EntityState.Modified;
        Banco.SaveChanges();
        TempData["mensagem"] = "TAREFA CONCLUÍDA COM SUCESSO";
        return RedirectToAction("Index");
    }

    public IActionResult Excluir(int id)
    {
        Tarefa tf = Banco.TabelaTarefas.Single(t => t.Id == id);
        Banco.TabelaTarefas.Remove(tf);
        Banco.SaveChanges();
        TempData["mensagem"] = "TAREFA EXCLUÍDA COM SUCESSO";
        return RedirectToAction("Index");
    }
}