using Microsoft.AspNetCore.Mvc;
using ProjetoAula.Models;

namespace ProjetoAula.Controllers;

public class ImcController : Controller
{
    public IActionResult Index() => View(new Imc());

    public IActionResult Calcular(Imc model)
    {
        //if(ModelState.IsValid) model.Calcular();
        //return View("Index", model);
        TempData["Mensagem"] = "BOA NOITE";
        TempData["Data"] = DateTime.Now;
        return RedirectToAction("Index", "Cambio");
    }
}