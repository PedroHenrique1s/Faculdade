
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

float somar(float n1, float n2){
	return (n1 + n2);	
}

float subtrair(float n1, float n2){
	return (n1 - n2);	
} 

float multiplicar(float n1, float n2){
	return (n1 * n2);	
}

float dividir(float n1, float n2){
	if (n2 != 0){
		return (n1 / n2);
	}
	return 0;
}

void ler_numeros(float * n1, float * n2){
	printf("Digite N1: ");
	scanf("%f",&*n1);
	
	printf("Digite N2: ");
	scanf("%f",&*n2);	
	
}

void menu(){
	system("cls");
	printf("\n-- Calculadora Basica --");
	printf("\n\n[1]- Informar Numeros");
	printf("\n[2]- Adicao ");
	printf("\n[3]- Subtracao");
	printf("\n[4]- Multiplicacap");
	printf("\n[5]- Divisao");
	printf("\n[0]- Sair");
	printf("\n ==> ");
}


int main()
{
	float a, b;
	int opc;
	
	
	do{
		menu();
		scanf("%d", &opc);
		
		switch(opc){
			case 1: ler_numeros(&a,&b);break;
			case 2: printf("\nSoma: %0.2f", somar(a,b)); break;
			case 3: printf("\n Subtracao: %0.2f", subtrair(a,b)); break;
			case 4: printf("\nMultiplicao: %0.2f", multiplicar(a,b)); break;
			case 5: printf("\nDivisao: %0.2f", dividir(a,b)); break; 
				}
				printf("\n\n Pressione ENTER para continuar");
				getch();
					  		
	}while (opc != 0);
		

	
}