#include <stdio.h>

const int TAM = 5;

int idades[TAM];
int soma = 0, maior_idade = 0, cont_maior = 0, menor_idade = 200, cont_menor = 0,media;
int cont_acima = 0, cont_abaixo = 0, cont_igual = 0; 


void display(){
	for(int i = 0; i < TAM; i++){
		printf("\n Idade %d: %d", i+1, idades[i]);
	}
}

void imprimir_resultados(){
	printf("\n\n Media: %d",media );
	printf("\n Maior idade: %d",maior_idade );
	printf("\n Menor Idade: %d",menor_idade );
	
	printf("\n Quantidade de pessoas mais idosa: %d",cont_maior );
	printf("\n Quantidade de pessoas mais jovem: %d",cont_menor );
	
	printf("\n\n Porcentagem acima da media: %0.2f", cont_acima*100.0/TAM);
	printf("\n Porcentagem abaixo da media: %0.2f", cont_abaixo*100.0/TAM);
	printf("\n Porcentagem igual a media: %0.2f", cont_igual*100.0/TAM);	
}

void idade_Menor_Maior(int i){
	//Processamento
	soma = soma + idades[i]; //Soma das idades	

	//Encontrar maior idade
	if(idades[i] >= maior_idade){
		if(idades[i] >= maior_idade){
			maior_idade = idades[i];
			cont_maior = 1;
		}
		else
		{
			cont_maior++;
		}
	}
	
	//Encontrar menor idade 
	 if (idades[i] <= menor_idade){
		 if(idades[i] <= menor_idade){
			 menor_idade = idades[i];
			 cont_menor = 1;
		 }else
		 {
			 cont_menor++;
		 }
	 }
}

void comparador_media(){
	media = soma/TAM;
	
	//Média acima, Média abaixo, Média; 
	for(int i = 0 ; i < TAM ; i++){
		if(idades[i] > media)
			cont_acima++;
		else if(idades[i] < media)
			cont_abaixo++;
		else
			cont_igual++;
	}	
}

int main()
{
	for(int i = 0; i < TAM; i++){
		printf("\nDigite a idade %d:", i+1);
		scanf("%d", &idades[i]);
	

	
	idade_Menor_Maior(i);
		
	
	}//fim do for
	

	//Comparar média
	comparador_media();
	
	//Saida
 	imprimir_resultados();
	
	return 0;
}