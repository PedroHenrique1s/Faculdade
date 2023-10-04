//Programa retirado para tirar informações das pessoas
//Estruturas de repetição while

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Variaveis 
float salario, altura, peso;
int idade; 
char sexo; 

const float ALTURA_1= 1.60 , ALTURA_2= 1.70;
const float PESO1 = 60 , PESO2 = 80;

int   contador = 0, cont_f = 0, cont_m = 0, cont_altura= 0, cont_peso= 0;
float soma_sal = 0, soma_sal_f = 0, soma_sal_m = 0;

int main(){
	   printf("\n***Programa Estudo do While***\n");
	   
	   printf("\n Digite o salario ou digite 0 para finalizar o programa: R$");
	   scanf("%f",&salario);
	   
	   while (salario > 0)
	   {
		printf("\n Altura: ");
		scanf("%f",&altura);
//Altura 		
		while(altura < 1)
		{
			printf("\n Redigite a idade: ");
			scanf("%f",&altura);
			
		}
		
		if((altura>=ALTURA_1) && (altura<=ALTURA_2))
		{
			cont_altura++;
		}
		
		printf("\n Peso: ");
		scanf("%f",&peso);
//Peso 		
		while(peso < 30)
		{
			printf("\n Redigite o peso: ");
			scanf("%f",&peso);
			
		}
		
		if ((peso < PESO1) || (peso > PESO2))
		{
			cont_peso++;
		}
		
		printf("\n Idade: ");
		scanf("%d",&idade);
//Idade		
		while(idade < 16)
		{
			printf("\n Redigite a idade: ");
			scanf("%d",&idade);
			
		}
		printf("\n [M]asculino \n [F]eminino \n\n => ");
		sexo = getch();
		fflush(stdin);
//Sexo		
		while((sexo != 'f')  && (sexo !='F') &&
	         (sexo != 'm')  && (sexo !='M'))
		{
			printf("Redigita o sexo");
			fflush(stdin);
			sexo = getch();
			
		}
		
		
		//processamento 
		contador++;
		soma_sal = soma_sal + salario;   
		   
		//proxima pessoa
		system("cls");
		printf("\n Informe outro Salario: ");
		scanf("%f",&salario);
	   }//FIM DO WHILE
	
	   //Saida
	   system("cls");
	   printf("\n---Dados Processados---");
	   printf("\n\nMedia Salario: %.2f", soma_sal/contador);
	   printf("\nQuantidade de pessoas entre %.2f e %.2f: %d",ALTURA_1,ALTURA_2,contador);
	   printf("\n %0.2f %% ", cont_altura*1.0/contador*100);
 	   printf("\n Quantidade de pessoas entre %.2f e %.2f: %d", PESO1, PESO2, cont_peso);

}//FIM DO PROGRAMA 