#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

const int TAM = 5;
float salarios[TAM];
char opc;

float calcular_media(){
	float soma = 0;
	for(int i = 0; i < TAM; i++){
		soma = soma + salarios[i];
	}
	
	return soma/TAM;
}

void paradinha(){
 	printf("\nCadastro realizado com sucesso !");
	printf("\n\n Pressione [ENTER] para continuar");
	getch();
}

void menu(){
	
	system("cls");
	printf("\n[A]- Cadastrar");
	printf("\n[B]- Visualizar");
	printf("\n[C]- Visualizar Media Salarial");
	printf("\n[D]- Visualizar Maior e Menor");
	printf("\n[E]- Porcentagem Salarios inferior a Media");
	printf("\n[S]- Sair");
	printf("\n\n=>");
} //Fim da função 

void cadastrar(){
	system("cls");
	printf("\n*** Cadastrar Salario ***");
	for(int i = 0; i < TAM; i++){
		printf("\n\nDigite o salario %d: ", i+1);
		scanf("%f", &salarios[i]);
	}
 

} //Fim da função

void visualizar(){
	system("cls");
	printf("\n\n***Visualizar Salarios***");
	for(int i = 0; i < TAM; i++){
		printf("\n\nSalario %d: %0.2f", i+1, salarios[i]);
	}
	
	printf("\n\nCadastro realizado com sucesso !");
	printf("\n\n Pressione [ENTER] para continuar");
	getch();
} //Fim da função 

void visualizar_media(){
	
	system("cls");
	printf("*** Visualizar Media Salarial***");
	
	printf("\nMedia Salarial: %0.2f", calcular_media());
	printf("\n\n Pressione [ENTER] para continuar");
	getche();
	
}

void visualizar_mm(){
	float maior_sal = 0, menor_sal = 100000;
	int cont_maior = 0, cont_menor = 0;
	
	for( int i = 0; i < TAM; i++){
		
		if(salarios[i] >= maior_sal){
			if(salarios[i] > maior_sal){
			    maior_sal = salarios[i];
			    cont_maior = 1;				
			}else
			{
				cont_maior++;
			}
		}
		
		if( salarios[i] <= menor_sal){
			if(salarios[i] < menor_sal){
				menor_sal = salarios[i];
				cont_menor = 1;
			}else
			{
				cont_menor++;
			}
		}
		
		system("cls");
		printf("\n***Visualizar Salarios***");
		
		printf("\n\nMaior Salario: %0.2f",maior_sal);
		printf("\n%d ganham esse salario",cont_maior);
		
		printf("\n\nMenor Salario: %0.2f",menor_sal);
		printf("\n%d ganham esse salario",cont_menor);
		
		printf("\n\n Pressione [ENTER] para continuar");
		getch();
	} //Fim do For
} //Fim da Função 

void visualizar_inferiores(){
	float media, soma= 0, cont_abaixo = 0;
	
	
	
	for( int i = 0; i < TAM; i++){
		soma = soma + salarios[i];
	}
	
	media = soma/TAM;
	
	for (int i = 0; i < TAM; i++){
		if(salarios[i] < media){
			cont_abaixo++;
		}
	}
	
	system("cls");
	printf("\n***Visualizar Salarios***");
	printf("\n\nSalario abaixo da media %0.2f%%", cont_abaixo*100.0/TAM);
	
}

int main()
{
	
	//Menu 
	do{
		menu();
		opc = getche();
		
		switch (opc){
			case 'A': case 'a': cadastrar();  break;
			case 'B': case 'b': visualizar(); break;
			case 'C': case 'c': visualizar_media(); break; 
			case 'D': case 'd': visualizar_mm(); break;
			case 'E': case 'e': visualizar_inferiores(); break;
		}
		
		paradinha();
		
	}while ((opc != 's') && (opc != 'S'));
	
	

}