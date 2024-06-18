#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct funcionario
{
	char nome[40];
	int nro_dependentes;
	float salarioporHora;
	int horasTrabalhada;	
};

void mostrarDados(struct funcionario trabalhador[40], int num_funcionario){
	
	float salarioBruto;
	float valorDependente = 198.50;
	float salarioMin = 1.350;
	float inss;
	float ir;
	float soma;
	float salarioLiquido;
	
	for(int i = 0; i < num_funcionario; i++){
		salarioBruto = (trabalhador[i].salarioporHora * trabalhador[i].horasTrabalhada) + (valorDependente * trabalhador[i].nro_dependentes );
		
		if(salarioBruto > salarioMin){
			inss = salarioBruto * 0.1;
		}else {
			inss = 300;
		}
		
		soma = salarioBruto - inss;
		
		if(soma <= 1.500){
			ir = 0;
			salarioLiquido = soma - ir;
		}else if(soma  <= 3.500){
			ir = soma * 0.1;
			salarioLiquido = soma - ir;
		}else{
			ir = soma * 0.2;
			salarioLiquido= soma - ir;
		};
		
		printf("\n\nNome: %s",trabalhador[i].nome);
		printf("\nSalario por hora: %.2f ",trabalhador[i].salarioporHora);
		printf("\nHoras Trabalhada: %d ",trabalhador[i].horasTrabalhada);
		printf("\nSalario Bruto: R$%.2f ",salarioBruto);
		printf("\nDesconto INSS: R$%.2f ",inss);
		printf("\nDesconto Imposto de Renda: R$%.2f ",ir);
		printf("\nSalário Liquido: R$%.2f ",salarioLiquido);
		
		
			
	}
}


int cadastrarFuncionario(struct funcionario trabalhador[40], int num_funcionario){
	char op;

	printf("***PROGRAMA HOLERITE***");
	do{
		
		fflush(stdin);
		printf("\n\nDigite seu primeiro nome: ");
		gets(trabalhador[num_funcionario].nome);
		
		fflush(stdin);
		printf("\nDigite o numero de depentes: ");
		scanf("%d", &trabalhador[num_funcionario].nro_dependentes);
		
		fflush(stdin);
		printf("\nDigite o salario por hora recebida: R$ ");
		scanf("%f", &trabalhador[num_funcionario].salarioporHora);
		
		fflush(stdin);
		printf("\nDigite a hora trabalhada no total: ");
		scanf("%d",&trabalhador[num_funcionario].horasTrabalhada);
		
		
		num_funcionario++;
		
		printf("\nDeseja cadastrar outro funcionario (S/N)? = ");
		scanf(" %c", &op);
		
		
	}while(op == 'S' || op == 's');
	
	mostrarDados(trabalhador, num_funcionario);
	
	
	return num_funcionario;
}


int main()
{
	struct funcionario trabalhador[40];
	int num_funcionario = 0;
	
	num_funcionario = cadastrarFuncionario(trabalhador, num_funcionario);
	
	return 0;
}