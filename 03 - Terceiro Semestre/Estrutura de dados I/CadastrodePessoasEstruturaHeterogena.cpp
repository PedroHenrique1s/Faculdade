#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cadastro{
	char nome[40];
	float altura;
	int anoNascimento;
};

int cadastrar_Pessoa(struct cadastro pessoa[40], int quant_pessoa){
	char opc;
	
	do{
		fflush(stdin);
		printf("\n\nDigite o nome da pessoa: ");
		gets(pessoa[quant_pessoa].nome);
		
		fflush(stdin);
		printf("\nDigite sua Altura: ");
		scanf("%f",&pessoa[quant_pessoa].altura);
		
		fflush(stdin);
		printf("\nDigite o ano que nasceu: ");
		scanf("%d",&pessoa[quant_pessoa].anoNascimento);
		
		quant_pessoa++;
		
		printf("\n\nDeseja cadastrar outra pessoa [s/n] ?");
		scanf("%s",&opc);
		
	}while(opc == 'S' || opc == 's');
	
	return quant_pessoa;
}

void mostrarPessoas(struct cadastro pessoa[40], int quant_pessoa){
	
	for(int i = 0 ; i < quant_pessoa; i++){
		printf("\n\nNome: %s",pessoa[i].nome);
		printf("\nAltura: %f",pessoa[i].altura);
		printf("\nAno que nasceu: %d",pessoa[i].anoNascimento);
	};
	
}

void pesquisaAno(struct cadastro pessoa[40], int quant_pessoa){
	int anoPesquisa;
	
	printf("Digite o ano de nascimento para ver pessoas com esta data de nascimento: ");
	scanf("%d",&anoPesquisa);
	
	for(int i = 0; i < quant_pessoa ; i++){
		if(anoPesquisa == pessoa[i].anoNascimento){
			printf("\n\nNome: %s",pessoa[i].nome);
			printf("\nAltura: %f",pessoa[i].altura);
			printf("\nAno que nasceu: %d",pessoa[i].anoNascimento);	
		};
	};
	
}

 void menu(struct cadastro pessoa[40], int quant_pessoa){
	 int opc;
	 
	 do{
		 printf("\n\n[1] - Cadastrar Pessoas");
		 printf("\n[2]- Mostrar todos cadastrados");
		 printf("\n[3]- Pesquisar quantas pessoas tem em uma data de nascimento");
		 printf("\n[4] - Sair");
		 scanf("%d",&opc);
		 
		 switch(opc)
		 {
		 case 1:
		 	quant_pessoa = cadastrar_Pessoa(pessoa, quant_pessoa);
			 break;
		 case 2:
		 	mostrarPessoas(pessoa, quant_pessoa);
		 	break;
		 case 3:
		 	pesquisaAno(pessoa, quant_pessoa);
		 	break;
		 }
	 }while(opc != 4);
 }


int main()
{
	struct cadastro pessoa[40];
	int quant_pessoa = 0;
	
	menu(pessoa,quant_pessoa);
	
	return 0;
}