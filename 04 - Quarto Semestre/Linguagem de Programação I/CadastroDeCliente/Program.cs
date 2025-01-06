//Progama Feito por Pedro Henrique Nascimento de Souza e Kenzo Aleixo
using Microsoft.EntityFrameworkCore;
using CadastroDeCliente.Contexto;

var builder = WebApplication.CreateBuilder(args);

builder.Services.AddControllersWithViews();
builder.Services.AddDbContext<BancoDados>(
    options => options.UseSqlite(builder.Configuration.GetConnectionString("Default"))
);

var app = builder.Build();

app.UseHttpsRedirection();
app.UseStaticFiles();
app.UseRouting();
app.UseAuthorization();

app.MapControllerRoute(
    name: "default",
    pattern: "{controller=Clientes}/{action=Index}/{id?}");

app.Run();
