//Programa Realizado para Peso ideal 
//Utilização para anotação de string para declarar 

#include <stdio.h>
#include <conio.h> // getchar, getcher, getch para string e caracter 
#include <locale.h> // identificar a lingua e pontuação 

int main()
{
	setlocale(LC_ALL,"portuguese");
	char sexo; 
	float altura, pesoIdeal;
	
	printf("\n Digite sua altura em Metro: ");
	scanf("%f",&altura);
	
	printf("\n Digite seu sexo [M/F]: ");
	fflush(stdin);
	sexo = getchar(); // mesmo que 'scanf' ("%c"), sexo
	if (sexo == 'f' || sexo == 'F')
	{
		pesoIdeal = 62.1 * altura - 44.7;
	}
	else 
	{
		pesoIdeal=  72.7*altura- 58.0;
	}
	printf("\n\n Seu peso ideal é %.2f kg \n\n", pesoIdeal);
	
	
	return 0;
}