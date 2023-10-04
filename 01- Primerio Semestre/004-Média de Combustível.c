//Programa Realizado para média de combustivel 

#include <stdio.h>
#include <stdlib.h>


	const float PORCENTAGEM= 0.7;
	float qntKM, qntCombustivel, media, custo, valorPAGO, qntKMrodado,kmInicial, kmFinal, alcool,gasolina, mediaC, mediaKM;
	
	int main()
	{
		
		
		printf("\n***Gasolina ou Alcool qual esta compensando ?*** \n");
		printf("----------------------------------------");
		
		printf("\n\nQuanto esta a Gasolina R$ ");
		scanf("%f",&gasolina);
		
		printf("\nQuanto esta o Alcool R$ ");
		scanf("%f",&alcool);
		
		mediaC = alcool / gasolina;
		
		printf("\n\n Se a media estiver maior que 0.70 compensa gasolina se for menor compensa Alcool");
		printf("\n\n Media combustivel: %0.2f",mediaC);
		if (mediaC>= PORCENTAGEM)
			printf("\n\n Ultimamente compensa gasolina");
		
		else
		{
			printf("\n\n Ultimamente compensa Alcool\n\n");
		}
		printf("\n\n ----------------------------------------");
				
		system("pause");
		system("cls");
		
		
		printf("\n*** Calculo da media do combustivel ***\n");
		printf("----------------------------------------");
			
		printf("\n\n Quanto que pagou no litro do combustivel R$");
		scanf(" %f",&custo);
		
		printf("\n Quantos litros: ");
		scanf("%f",&qntKM);
		
		valorPAGO = custo * qntKM;
		
		printf("\n Marque quantos KM antes de abastecer: ");
		scanf(" %f",&kmInicial);
		
		printf("\n Qual o km atual do veiculo: ");
		scanf(" %f", &kmFinal);
		
		qntKMrodado= kmFinal - kmInicial;
		printf("\n\n Quantidade de km que percorreu com esse abastecimento: %.2f KM",qntKMrodado);
		
		printf("\n\n----------------------------------------");
		
		system("pause");
		system("cls");
		
		printf("\n\n ***Sua media atual ***");
		printf("\n----------------------------------------");
		
		media= qntKMrodado / qntKM;
		
		printf("\n\n Digite sua media desejavel de km por litro: ");
		scanf("%f",&mediaKM);
		
		printf("\n\nPreco pago do combustivel: R$ %.2f ", valorPAGO);
		
		printf("\n\nSua media: %.2f km por litro", media);
		
		if	(media >= mediaKM)
			printf("\n\nEconomico \n");
		
		else
		{
			printf("\n\nMedia esta baixa\n\n");
		}
		printf("\n----------------------------------------");
		system("pause");		

		return 0;
	}
	