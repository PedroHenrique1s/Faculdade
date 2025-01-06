using Microsoft.AspNetCore.Mvc;
using ProjetoAula.Models;

namespace ProjetoAula.Controllers;

public class CambioController : Controller
{
    public IActionResult Index() => View(new Cambio());

    public IActionResult Calcular(Cambio model)
    {
        if(ModelState.IsValid) model.ValorFinal = model.ValorInicial / model.Taxa;
        return View("Index", model);
    }
}