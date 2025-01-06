using System.ComponentModel.DataAnnotations;
namespace ProjetoAula.Models;

public class Imc
{
    [Required(ErrorMessage = "Campo obrigatório")]
    [Range(2.5, 300, ErrorMessage = "O peso deve estar entre 2,5 e 300 kg")]
    public double Peso {get; set;}
    [Required(ErrorMessage = "Campo obrigatório")]
    [Range(0.45, 2.5, ErrorMessage = "A altura deve estar entre 45 cm e 2 metros")]
    public double Altura {get; set;}
    public double Resultado {get; private set;}

    public void Calcular() => Resultado = Peso / (Altura * Altura);
}