//Programa realizado para uma confeitaria com estrutura de repetição switch

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


char nomeCliente[30];
int	tipoDoce;
float kgDoce, valorDoceKG, ValorTotal;

int main()
{
	printf("\n***Seja Bem vindo(a) Sugar Flower***");
	printf("\n\n Qual seu nome ?\n\n ");
	gets(nomeCliente);
	
	printf("\n***Cardapio***\n");
	printf("\n[1] - Trufa nozes com chocolate");
	printf("\n[2] - Torta mousse de limao");
	printf("\n[3] - Bolo de brigadeiro");
	printf("\n[4] - Bolo Cookie de Nutella");
	
	printf("\n\nDigite o codigo do doce desejavel: ");
	scanf("%d", &tipoDoce);

	printf("\nDigite quantos KG deseja comprar: ");
	scanf("%f", &kgDoce);
		
	switch(tipoDoce)
	{
		
	
		case 1 : printf("\n Trufa Nozes com chocolate\n\n");
			if (kgDoce <= 5)
			valorDoceKG = 25.00;
			else
			{
			valorDoceKG= 22.00;
			}
			break;
		
		case 2 : printf("\n Mousse de Limao\n\n");
		if (kgDoce <= 5)
			valorDoceKG = 24.45;
		else
		{
			valorDoceKG= 22.25;
		}
		break;
		case 3 : printf("\n Bolo de Brigadeiro\n\n");
		if (kgDoce <= 5)
			valorDoceKG = 35.00;
		else
		{
			valorDoceKG= 30.00;
		}
		break;
		case 4 : printf("\n Bolo cookie de Nutella\n\n");
			if (kgDoce <= 5)
			valorDoceKG = 38.50;
			else
		{
			valorDoceKG= 36.20;
		}
		break;
		
		default: printf("\n Doce invalido");
	}
	
	ValorTotal = kgDoce * valorDoceKG;
	
	system("pause");
	system("cls");
		printf("\n\n***EXTRATO***");
	printf("\n\nNome do Cliente: %s", nomeCliente);
	printf("\nTipo Doce: [%d]", tipoDoce);
	printf("\nQuantidade (KG) comprada: %0.2f", kgDoce);
	printf("\n\nValor por KG: R$%0.2f", valorDoceKG);
	printf("\nValor Total da Compra: R$%0.2f", ValorTotal);
	printf("\n\n***FIM EXTRATO***");

	
	   	
	return 0;
}