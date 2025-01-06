using Microsoft.EntityFrameworkCore;
using CadastroDeCliente.Entidades;

namespace CadastroDeCliente.Contexto;

public class BancoDados(DbContextOptions<BancoDados> options) : DbContext(options)
{
    public DbSet<Cliente> TabelaClientes {get; set;}
}