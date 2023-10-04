//Programa realizado para informação das pessoas 
//Estrutura de repetição com FOR

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

const int n=3;
int idade, soma_idade=0, contador_18anos=0, idade_Maior=0;
float altura, peso, soma_Altura=0 ,soma_Peso=0, contador_f=0, contador_m=0;
char sexo; 

int main()
{
	for( int i= 1 ; i<= n ; i++){
		printf("\n***Programa Empresa***");	
		printf("\n\nDigite sua Idade: ");
		scanf("%d",&idade);
		fflush(stdin);
		
		printf("\nDigite sua Altura: ");
		scanf("%f",&altura);
		fflush(stdin);
		
		printf("\nDigite seu Peso: ");
		scanf("%f",&peso);
		fflush(stdin);
		
		printf("\nQual seu sexo [M] masculino [F] feminino  ");
		sexo = getch();
		
		soma_idade= soma_idade + idade;
		soma_Peso= soma_Peso + peso;
		soma_Altura= soma_Altura + altura;
	
		if(idade > idade_Maior){
			idade_Maior= idade;
		}
			
		if (idade > 18 ){
			contador_18anos++;
		};
		
		if (sexo == 'f' || sexo == 'F'){
			contador_f++;
		} 
		else{
			contador_m++;
		}
		system("cls");
	}
	system("pause");
	system("cls");
	
	printf("\n Quantidade de Pessoas que tem mais de 18 anos: %d", contador_18anos);
	printf("\n Pessoa mais velha: %d",idade_Maior );
	printf("\n\n Media da idade: %d",soma_idade/n );
	printf("\n Media de altura: %.2f ",soma_Altura/n );
	printf("\n Media do peso: %.2f ",soma_Peso/n );
	printf("\n\n porcentagem do sexo masculino: %.2f ",(contador_m*1.0)/(n*100));
	printf("\n porcentagem do sexo feminino: %.2f ",(contador_f*1.0)/(n*100));

	return 0;
}