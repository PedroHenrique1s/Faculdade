using System.ComponentModel.DataAnnotations;

namespace ProjetoAula.Models;

public class Cambio
{
    [Range(0.01, double.MaxValue, ErrorMessage = "O valor deve ser de no mínimo 1 centavo")]
    public double ValorInicial {get; set;}
    public double Taxa {get; set;}
    public double ValorFinal {get; set;}
}