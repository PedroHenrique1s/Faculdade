#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


	
int main(){
	
	//Variáveis declaradas 

	const int ano = 2010; 
	const float valormedia = 15.000;
	 
	
	char nomeCarro[50];
	int anoCarro;
	float valor;
	char marca, corCarro, combust;
	
	
	int anoNovo = 30000, anoVelho = 0;
	int anoNovoChevrolet= 30000, anoVelhoChevrolet = 0;
	int anoNovoFiat= 30000,anoVelhoFiat = 0; 
	int anoNovoVolks= 30000, anoVelhoVolks = 0;
	
	float maisBarato = 100000000, maisCaro = 0, somaValor= 0;
	float maisBaratoChevrolet = 100000000, maisCaroChevrolet= 0;
	float maisBaratoVolks = 100000000, maisCaroVolks= 0;
	float maisBaratoFiat = 100000000, maisCaroFiat= 0;
	
	int contador_geral= 0, contChevrolet =0, contVolks=0, contFiat=0;
	int contBranco=0, contPreto=0, contVermelho=0;
	int contcombust_Alcool=0, contcombust_Gasolina=0, contcombust_Diesel=0, contcombust_Eletrico=0;
	int cont_precoC=0 , cont_precoV=0, cont_precoF=0;
	int cont2010_Chevrolet = 0, cont2010_Volks = 0,cont2010_Fiat=0;
	
	
	printf("\n***Programa Concecionaria Carro do Ano***");
	printf("\n \nDigite o valor do carro ou digite 0 para finalizar o programa R$");
	fflush(stdin);
	scanf("%f",&valor);
	
	while(valor > 0)
	{
		
		
		//marca
		 	
		printf("\n Escolhe o modelo que deseja\n ");
		printf("\n [C]hevrolet \n [V]olkswagen \n [F]iat \n\n =>");
		marca = getch();  
			  	  		
		while(
		(marca != 'C' ) && (marca != 'c') && 
		(marca != 'v') && (marca != 'V') && 
		(marca != 'F') && (marca != 'f') ){
			printf("\nRedigita a marca novamente \n ");
			fflush(stdin);
			marca = getch();
		}
		
		
		//Combustivel
		
		printf("Escolhe o combustivel que deseja\n");
		printf("\n [A]lcool \n [G]asolina \n [D]isel \n [E]letrico \n\n =>");
		combust = getch();
		
		while(
		(combust != 'A' ) && (combust != 'a') && 
		(combust != 'G') && (combust != 'g') && 
		(combust != 'D') && (combust != 'd') && 
		(combust != 'E') && (combust != 'e') ){
			printf("\nRedigita a combustivel novamente\n ");
			fflush(stdin);
			combust = getch();
		}
		
		//Cor do carro 
		
		printf("Escolhe a cor que deseja\n");
		printf("\n [P]reto \n [B]ranco \n [V]ermelho \n\n =>");
		corCarro = getch();
		
		while(
		(corCarro != 'P' ) && (corCarro != 'p') && 
		(corCarro != 'B') && (corCarro != 'b') && 
		(corCarro != 'V') && (corCarro != 'v') ){
		printf("\nRedigita a cor novamente \n ");
		fflush(stdin);
		corCarro = getch();
		}		
		
		
		
		//Nome do carro
		
		printf("\n Escreva o nome do carro: ");
		fflush(stdin);
		gets(nomeCarro);
		
		//ano do carro
		printf("\n Digite o ano do carro: ");
		scanf("%d",&anoCarro);
		
		//Processamento geral 
		
		contador_geral++;
		
		//Média de valores 
		
		somaValor = valor + somaValor;
		
		//Carros em geral de ano mais novo e mais velho
		
		if (anoCarro > anoVelho){
			anoVelho = anoCarro;
		};
		
		if (anoCarro < anoNovo){
			anoNovo = anoCarro;
		};
		
		//Carros em geral mais barato e mais caro 
		
		if (valor > maisCaro){
			maisCaro = valor;
		};
		
		if (valor < maisBarato){
			maisBarato = valor;
		};
		
		//Processamento chevrolet
		
		if((marca == 'C') && (marca == 'c')){
			
			contChevrolet++;
			
			//Carro mais barato e mais caro da chevrolet
			
			if(valor > maisCaroChevrolet){
				maisCaroChevrolet = valor;
			}
			
			if(valor > maisBaratoChevrolet){
				maisBaratoVolks = valor;
			}
			
			//Carro mais novo e velho da chevrolet 
			
			if(anoCarro > anoVelhoChevrolet){
				anoVelhoChevrolet = anoCarro;
			};
			
			if(anoCarro < anoNovoChevrolet){
				anoNovoChevrolet = anoCarro;
			};
			
			if( anoCarro > ano){
				cont2010_Chevrolet++;
			}
			
			//Carros acima de 15 mil da chevrolet 
			
			if(valor > valormedia){
				cont_precoC++;
			};
			
		}else if ((marca == 'V') && (marca == 'v')){
			contVolks++;
			
			//Carro mais barato e mais caro da volks
			
			if(valor > maisCaroVolks){
				maisCaroVolks = valor;
			}
			
			if(valor < maisBaratoVolks){
				maisBaratoVolks = valor;
			}
			
			//Carro mais novo e mais velho da volks 
			
			if(anoCarro > anoVelhoVolks){
				anoVelhoVolks = anoCarro;
			};
			
			if(anoCarro < anoNovoVolks){
				anoNovoVolks = anoCarro;
			};
			
			//Carro acima de 2010 volks 
			
			if(anoCarro > ano){
				cont2010_Volks++;
			}
			
			//Carros acima de 15 mil volks
			if(valor > valormedia){
				cont_precoV++;
			};
			
		}else if ((marca == 'F') && (marca == 'f')){
			contFiat++;
			
			//Carro mais caro e mais barato da fiat
			
			if(valor > maisCaroFiat){
				maisCaroFiat = valor;
			}
			
			if(valor < maisBaratoVolks){
				maisBaratoFiat = valor; 
			}
			
			//Carro fiat mais velho e mais novo
			
			if(anoCarro > anoVelhoFiat){
				anoVelhoFiat = anoCarro;
			};
			
			if(anoCarro < anoNovoFiat){
				anoNovoFiat = anoCarro;
			};
			
			//Carro acima de 2010 da fiat
			
			if(anoCarro > ano){
				cont2010_Fiat++;
			};
			
			//Carros acima de 15 mil da fiat
			
			if(valor > valormedia){
				cont_precoF++;
			};
		}else
		{
			printf("caracter invalido");
		}
		
		//Processamento combustivel 
		
		if((combust == 'A') && (combust == 'a')){
			contcombust_Alcool++;
			
		}else if((combust == 'G') && (combust == 'g')){
			contcombust_Gasolina++;
		}else if((combust == 'D') && (combust == 'd')){
			contcombust_Diesel++;
		}else if((combust == 'E') && (combust == 'e')){
			contcombust_Eletrico++;
		}else
		{
			printf("caracter invalido");
		}
		
		//Processamento cor do Carro
		
		if((corCarro == 'B') && (corCarro == 'b')){
				contBranco++;
		}else if((corCarro == 'P') && (corCarro == 'p')){
				contPreto++;
		}else if((corCarro == 'V') && (corCarro == 'v')){
				contVermelho++;
		}else
		{
			printf("caracter invalido");
		}
		
		
			
		

	//FIM do while	
	system("cls");
	printf("\n***Programa Concecionaria Carro do Ano***");
	printf("\n\nDigite o valor do carro ou digite 0 para finalizar o programa R$");
	scanf("%f",&valor);			
	}
	
	printf("\n\n---Dados Processados---");
	printf("\nCarro mais novo: %d",anoNovo);
	printf("\nCarro mais velho: %d",anoVelho);
	
	printf("\n\nCarro mais novo chevrolet: %d",anoNovoChevrolet);
	printf("\nCarro mais velho chevrolet: %d",anoVelhoChevrolet);
	
	printf("\n\nCarro mais novo volkswagen: %d",anoNovoVolks);
	printf("\nCarro mais velho volkswagen: %d",anoVelhoVolks);
	
	printf("\n\nCarro mais novo fiat: %d",anoNovoFiat);
	printf("\nCarro mais velho fiat: %d",anoVelhoFiat);
	
	printf("\n\nMedia de cores branco: %.2f %%", contBranco*1.0/contador_geral*100);
	printf("\nMedia de cores preto: %.2f %%", contPreto*1.0/contador_geral*100);
	printf("\nMedia de cores vermelho: %.2f %%", contVermelho*1.0/contador_geral*100);
	
	printf("\nMedia de preco dos carros: %.2f %%", somaValor*1.0/contador_geral*100);
	
	printf("\n\nMedia de carros da chevrolet: %.2f %% ",contChevrolet*1.0/contador_geral*100);
	printf("\nMedia de carros da volkwagen: %.2f %%",contVolks*1.0/contador_geral*100);
	printf("\nMedia de carros da fiat: %.2f %%",contFiat*1.0/contador_geral*100);
	
	printf("\n\nQuantidade de carros a alcool: %d", contcombust_Alcool);
	printf("\nQuantidade de carros a gasolina: %d", contcombust_Gasolina);
	printf("\nQuantidade de carros a diesel: %d", contcombust_Diesel);
	printf("\nQuantidade de carros eletricos: %d", contcombust_Eletrico);
	
	printf("\n\nCarros acima do ano de 2010 da chevrolet: %d", cont2010_Chevrolet);
	printf("\nCarros acima do ano de 2010 da volkswagen: %d", cont2010_Volks);
	printf("\nCarros acima do ano de 2010 da fiat: %d", cont2010_Fiat);
	
	printf("\n\nMedia de carros acima de 15 mil da chevrolet: %f", ((cont_precoC*1.0)/contador_geral*100)) ;
	printf("\nMedia de carros acima de 15 mil da volkwagem: %f", ((cont_precoV*1.0)/(contador_geral*100)) );
	printf("\nMedia de carros acima de 15 mil da fiat: %f", ((cont_precoF*1.0)/(contFiat*100)) );
	
	
	
		

	return 0;
}