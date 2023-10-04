//Pontuação para saber se passou ou reprovou na matéria da faculdade
//Estrutura de decisão simples if else

// inclusão biblioteca
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//programa principal 
int main()
{
	setlocale(LC_ALL,"portuguese" );
	//Declaração das variaveis 
	float notaProva1, notaProva2, mediaProva, mediaTrab, mediaFinal;
	char nomeAluno[50]; //Declaração das string
	
	//comunicação com o usuario e entrada de dados
	
	printf("\n ***Calculo Nota***\n");
	
	printf("\n Digite seu nome: ");
	fflush(stdin);
	gets(nomeAluno);  //saida para lê string 
	
	printf("\n Digite a nota da Prova 1: ");
	scanf("%f",&notaProva1);
	
	printf("\n Digite a nota da Prova 2: ");
	scanf("%f",&notaProva2);
	
	printf("\n Digite a media do trabalho: ");
	scanf("%f",&mediaTrab);
	
	//Calcular a media de prova e media final
	mediaProva= (notaProva1 + notaProva2) / 2.0;
	mediaFinal= 0.7 * mediaProva + 0.3 * mediaTrab; 
	
	//verificar se o aluno esta aprovado 
	
	system("cls");
	printf("----------------------------------------\n");
	
	if(mediaFinal >= 7.0)
	{
		printf("\n Aprovado\n");
	}
	else
	{
		printf("\n Reprovado\n");
	}
	
	//mostrar dados 
	printf("\n Nome: %s", nomeAluno);
	printf("\n\n Nota prova 1:   %2.0f pontos ",notaProva1);
	printf("\n\n Nota prova 2:   %2.0f pontos ",notaProva2);
	printf("\n\n Media trabalho: %2.0f pontos ",mediaTrab);
	printf("\n\n Media final:    %2.0f pontos ",mediaFinal);
	printf("\n\n----------------------------------------\n");
	
	system("pause");
	 
	return 0;
}
