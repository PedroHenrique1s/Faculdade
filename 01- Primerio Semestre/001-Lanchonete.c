//Programa Realizado em Ling C com estruta de decisão Switch, 

#include <stdio.h>
#include <stdlib.h>


 int lanche, bebida,qntLanche, qntBebida;
 float somaLanche, somaBebida, lanches,bebidas, somaTotal;

int main()
{
	printf("\n***Programa Lanche***\n");
	printf("\n\n ***Cardapio dos Lanche*** \n\n 1100- Hot dog R$ 10,00 \n 1210- X burguer R$17,00 \n 1305- X salada R$23,00 \n 1307- X salada Bacon R$27,50");
	printf("\n\n Digite qual codigo do lanche: ");
	scanf("%d",&lanche);
	
	printf("\n Digite a quantidade de lanche: ");
	scanf("%d",&qntLanche);

	switch(lanche) 
	{
		case 1100: lanches=10.00 * qntLanche ;
			printf("\nPreco pago: %.2f \n\n", lanches);
		break;
		case 1210: lanches=17.00* qntLanche;
			printf("\nPreco pago: %.2f \n\n", lanches);
		break;
		case 1305: lanches=23.00* qntLanche;
			printf("\nPreco pago: %.2f \n\n", lanches);
		break;
		case 1307: lanches=27.50* qntLanche;
			printf("\nPreco pago: %.2f \n\n", lanches);
		break;
		default: printf("\n  lanche invalido\n\n");
	
	}
		system("pause");
		system("cls");
		
		printf("\n***Cardapio Bebidas***");
		printf("\n\n 12-Coca lata R$5.00 \n 13-Coca Ks R$3.00 \n 14- Fanta guarana R$5.00 \n 15- Fanta Uva R$4.50 \n 16-Cotuba Lata R$4.00");
		
		printf("\n\n Código da bebida: ");
		scanf("%d",&bebida);
		
		printf("\n Quantidade: ");
		scanf("%d",&qntBebida);
		
		switch(bebida) 
	{
		case 12: bebidas=5.00 * qntBebida ;
			printf("\nPreco pago da bebida: %.2f \n\n", bebidas);
		break;
		case 13: bebidas=3.00 * qntBebida;
			printf("\nPreco pago da bebida: %.2f \n\n", bebidas);
		break;
		case 14: bebidas=5.00 * qntBebida;
			printf("\nPreco pago da bebida: %.2f \n\n", bebidas);
		break;
		case 15: bebidas=4.50 * qntBebida;
			printf("\nPreco pago da bebida: %.2f \n\n",bebidas);
		break;
		case 16: bebidas=3.00 * qntBebida;
			printf("\nPreco pago da bebida: %.2f \n\n", bebidas);
		break;
	
		default: printf("\n bebida invalida invalido\n\n");
	
	}
		
		somaTotal= lanches + bebidas;
		printf("\n Preco a se pagar \n R$ %.2f",somaTotal);

			
		
			
	
	return 0;
}