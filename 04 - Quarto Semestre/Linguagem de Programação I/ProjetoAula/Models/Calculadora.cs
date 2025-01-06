using System.ComponentModel.DataAnnotations;

namespace ProjetoAula.Models;

public class Calculadora
{
    [Required(ErrorMessage = "Campo obrigatório")]
    public double N1 { get; set; }
    [Required(ErrorMessage = "Campo obrigatório")]
    public double N2 { get; set; }
}