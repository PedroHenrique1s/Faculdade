using System.ComponentModel.DataAnnotations;    
using CadastroDeCliente.Entidades;
namespace CadastroDeCliente.Models;

public class ClienteModel
{
    [Required(ErrorMessage = "Campo nome obrigatório")]
    public string NomeCliente {get; set; } = "";

    [Required(ErrorMessage = "Campo CPF obrigatório")]
    public string CPFCliente {get; set; } = "";

    [Required(ErrorMessage = "Campo Endereço obrigatório")]
    public string EnderecoCliente {get; set; } = "";

    public List<Cliente> ListaClientes {get; set; } = [];
}