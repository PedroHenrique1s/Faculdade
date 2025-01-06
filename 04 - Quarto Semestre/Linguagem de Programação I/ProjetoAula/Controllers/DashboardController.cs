using Microsoft.AspNetCore.Mvc;

namespace ProjetoAula.Controllers;

public class DashboardController : Controller
{
    public IActionResult Index() => View();
}	