#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct empresa{
	char nome[40];
	char sexo;
	float novembro;
	float dezembro;
	float janeiro;
};


int cadastrarFuncionario(struct empresa funcionario[15], int quant_funcionario){
	char opc;
	
	do{
		
		fflush(stdin);
		printf("\n\nDigite o nome do funcionario: ");
		gets(funcionario[quant_funcionario].nome);
		
		fflush(stdin);
		printf("\nDigite [M] para Masculino ou [F] para Feminino ");
		funcionario[quant_funcionario].sexo = getch();
		
		fflush(stdin);
		printf("\n\nDigite sua venda mensal de Novembro: R$ ");
		scanf("%f",&funcionario[quant_funcionario].novembro);
			  
		fflush(stdin);
		printf("\nDigite sua venda mensal de Dezembro: R$ ");
		scanf("%f",&funcionario[quant_funcionario].dezembro);		
		
		fflush(stdin);
		printf("\nDigite sua venda mensal de Janeiro: R$ ");
		scanf("%f",&funcionario[quant_funcionario].janeiro);
				
		quant_funcionario++;
		
		printf("\nDeseja adicionar outro funcionario [S/N] ?");
		opc = getch();
		
	}while(opc == 'S' || opc == 's');
	
	return quant_funcionario;
}

void pontuacaoMensal(struct empresa funcionario[15], int quant_funcionario){
	int pontuacaoNovembro;
	int pontuacaoDezembro;
	int pontuacaoJaneiro;
	int total;
	
	printf("\nPontuacao Mensal dos funcionarios");
	for(int i = 0; i < quant_funcionario; i++){
		pontuacaoNovembro = funcionario[i].novembro / 100;
		pontuacaoDezembro = funcionario[i].dezembro / 100;
		pontuacaoJaneiro = funcionario[i].janeiro   / 100;
		total = pontuacaoNovembro + pontuacaoDezembro + pontuacaoJaneiro;
		
		printf("\n\nNome do Funcionario: %s", funcionario[i].nome);
		if(funcionario[i].sexo == 'M' || funcionario[i].sexo == 'm' ){
			printf("\nSexo Masculino");
		}
		if(funcionario[i].sexo == 'F' || funcionario[i].sexo == 'f'){
			printf("\nSexo Feminino");
		}
		printf("\n\nPontuacao de novembro do Funcionario: %d", pontuacaoNovembro);
		printf("\nPontuacao de dezembro do Funcionario: %d", pontuacaoDezembro);
		printf("\nPontuacao de janeiro do Funcionario: %d", pontuacaoJaneiro);
		
	}
}

void maior_menor_pontuacao(struct empresa funcionario[15], int quant_funcionario){
	int pontuacaoNovembro;
	int pontuacaoDezembro;
	int pontuacaoJaneiro;
	float maiorPontuacao = 0;
	float menorPontuacao = 1000000;
	int total;
	int contadorMaior;
	int contatorMenor; 
	
	
	for(int i = 0; i < quant_funcionario; i++){
		pontuacaoNovembro = funcionario[i].novembro / 100;
		pontuacaoDezembro = funcionario[i].dezembro / 100;
		pontuacaoJaneiro = funcionario[i].janeiro   / 100;
		total = pontuacaoNovembro + pontuacaoDezembro + pontuacaoJaneiro;
		
		if(total > maiorPontuacao){
			maiorPontuacao = total;
			contadorMaior = i;
			
		}
		
		if(total < menorPontuacao){
			menorPontuacao = total;
			contatorMenor = i;
		}
		
	}
	printf("\n\nNome do Funcionario: %s", funcionario[contatorMenor].nome);
	if(funcionario[contatorMenor].sexo == 'M' || funcionario[contatorMenor].sexo == 'm' ){
		printf("\nSexo Masculino");
	}
	if(funcionario[contatorMenor].sexo == 'F' || funcionario[contatorMenor].sexo == 'f'){
		printf("\nSexo Feminino");
	}
	printf("\nMenor Pontuacao de todos Funcionario: %.2f",menorPontuacao);
	
	printf("\n\nNome do Funcionario: %s", funcionario[contadorMaior].nome);
	if(funcionario[contadorMaior].sexo == 'M' || funcionario[contadorMaior].sexo == 'm' ){
		printf("\nSexo Masculino");
	}
	if(funcionario[contadorMaior].sexo == 'F' || funcionario[contadorMaior].sexo == 'f'){
		printf("\nSexo Feminino");
	}
	printf("\nMaior Pontuacao de todos Funcionario: %.2f",maiorPontuacao);
}

void menu(struct empresa funcionario[15], int quant_funcionario){
	int opc;
	printf("***Empresa Funcionario***");
	do{
		printf("\n\n[1]-Cadastrar funcionarios");
		printf("\n[2]-Pontuacao mensal de cada funcionario");
		printf("\n[3]-Maior pontuacao e menor Pontuacao entre os funcionarios \n\n =>");
		scanf("%d",&opc);
		switch(opc)
		{
		case 1:
			quant_funcionario = cadastrarFuncionario(funcionario, quant_funcionario);
			break;
		case 2:
			pontuacaoMensal(funcionario, quant_funcionario);
			break;
		case 3: 
			maior_menor_pontuacao(funcionario, quant_funcionario);
			break;
		}
	}while( opc ! = 4);
}


int main()
{
	struct empresa funcionario[15];
	int quant_funcionario = 0;
	
	menu(funcionario, quant_funcionario);
	
	return 0;
}