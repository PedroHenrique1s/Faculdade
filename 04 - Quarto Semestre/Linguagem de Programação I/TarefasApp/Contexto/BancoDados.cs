using Microsoft.EntityFrameworkCore;
using TarefasApp.Entidades;

namespace TarefasApp.Contexto;

public class BancoDados(DbContextOptions options) : DbContext(options)
{
    public DbSet<Tarefa> TabelaTarefas {get; set;}
}