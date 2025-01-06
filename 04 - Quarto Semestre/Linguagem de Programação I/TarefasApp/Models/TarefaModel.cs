using System.ComponentModel.DataAnnotations;
using TarefasApp.Entidades;
namespace TarefasApp.Models;

public class TarefaModel
{
    [Required(ErrorMessage = "Campo obrigatório")]
    public string NomeTarefa {get; set;} = "";
    public int StatusTarefa {get; set;}
    public List<Tarefa> ListaTarefas {get; set;} = [];
}