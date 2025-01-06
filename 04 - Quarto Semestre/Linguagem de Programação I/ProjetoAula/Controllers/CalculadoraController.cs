using Microsoft.AspNetCore.Mvc;
using ProjetoAula.Models;

namespace ProjetoAula.Controllers;

public class CalculadoraController : Controller
{
    public IActionResult Index() => View(new Calculadora());

    public IActionResult Somar(Calculadora model)
    {
        if (ModelState.IsValid) TempData["resultado"] = $"RESULTADO: {model.N1 + model.N2}";
        return RedirectToAction("Index");
    }

    public IActionResult Subtrair(Calculadora model)
    {
        if (ModelState.IsValid) TempData["resultado"] = $"RESULTADO: {model.N1 - model.N2}";
        return RedirectToAction("Index");
    }

    public IActionResult Multiplicar(Calculadora model)
    {
        if (ModelState.IsValid) TempData["resultado"] = $"RESULTADO: {model.N1 * model.N2}";
        return RedirectToAction("Index");
    }

    public IActionResult Dividir(Calculadora model)
    {
        if (ModelState.IsValid)
        {
            if (model.N2 == 0)
            {
                ModelState.AddModelError("N2", "Impossível dividir por zero");
                return View("Index", model);
            }
            else TempData["resultado"] = $"RESULTADO: {model.N1 / model.N2}";
        }
        return RedirectToAction("Index");
    }
}