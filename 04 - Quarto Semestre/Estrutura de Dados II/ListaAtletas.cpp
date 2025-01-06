#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <strings.h>

struct Atleta {
	char nome[40];
	int salto1;
	int salto2;
	int salto3;
	int salto4;
	float media;
	float desvioPadrao;
	float variancia;
};

void cadastrar(struct Atleta *atleta, int inicio, int quant){
	
	for(int i = inicio; i < quant; i++){
		printf("Nome do Atleta: ");
		scanf("%s", atleta[i].nome);
		
		printf("\nSaldo 1: ");
		scanf("%d",&atleta[i].salto1);
		
		printf("\nSaldo 2: ");
		scanf("%d",&atleta[i].salto2);
		
		printf("\nSaldo 3: ");
		scanf("%d",&atleta[i].salto3);
		
		printf("\nSaldo 4: ");
		scanf("%d",&atleta[i].salto4);
		
		atleta[i].media = atleta[i].salto1 + atleta[i].salto2 + atleta[i].salto3 + atleta[i].salto4 / 4;
		atleta[i].variancia =  (pow(atleta[i].salto1 - atleta[i].media,2) + pow(atleta[i].salto2 - atleta[i].media,2) + pow(atleta[i].salto3 - atleta[i].media,2) + pow(atleta[i].salto4 - atleta[i].media,2) / 4); 
		
		atleta[i].desvioPadrao = sqrt(atleta[i].variancia);
				
	};
	
	
} ;

void relatorio(struct Atleta *atleta, int  quant){
	
	float maiorMedia = atleta[0].media;
	float menorDevioPadrao = atleta[0].desvioPadrao;
	char nomeMaior[40];
	char nomeMenor[40];
	strcpy(nomeMaior, atleta[0].nome);
	strcpy(nomeMenor, atleta[0].nome);
	
	for( int i = 1; i < quant; i++){
		
		if( maiorMedia <= atleta[i].media){
			maiorMedia = atleta[i].media;
			strcpy(nomeMaior, atleta[i].nome);
		}
		
		if( menorDevioPadrao >= atleta[i].desvioPadrao){
			menorDevioPadrao = atleta[i].desvioPadrao;
			strcpy(nomeMenor, atleta[i].nome);
		}
		   	
	}
	
	printf("\nMaior media : %.2f",maiorMedia);
	printf("\nNome do Atleta: %s",nomeMaior );
	
	printf("\nMenor Desvio Padrao : %.2f",menorDevioPadrao);
	printf("\nNome do Atleta: %s",nomeMenor );
	
	
}

int main()
{
	
	struct Atleta *atleta;
	int quant, opc, opcAltera, tam; 
	

	
	do{
		printf("\n1-Cadastrar Funcionario \n2-Modificar Atleta \n3- Relatorio dos Atletas \n4-Sair\n\n=>");
	    scanf("%d", &opc);
		switch(opc)
		{
		case 1:
			printf("\nDigite quantos atletas: ");
			scanf("%d", &quant);
			
			atleta = (struct Atleta*) malloc(quant * sizeof(struct Atleta));
			cadastrar(atleta, 0, quant);
			break;
		case 2:
			printf("\n1- Aumentar quantidade de atleta \n2- Remover quantidade de Atleta\n 3- Nao Alterar");
			scanf("%d",&opcAltera);
			
			if(opcAltera != 3){
				if(opcAltera == 1){
					printf("\nQuantos atletas novos: ");
					scanf("%d",&tam);
				}else {
					printf("\nQuantos atletas deseja remover: ");
					scanf("%d",&tam);
				}
				
				if(quant + tam == 0){
					free(atleta);
				}else if(quant + tam < 0){
					free(atleta);
				}else {
					atleta = (struct Atleta *) realloc(atleta, (quant + tam) * sizeof(struct Atleta) );
					
					if(atleta == NULL){
						printf("\nErro de Alocacao");
					}
					cadastrar(atleta, quant, quant+tam);
					quant = quant + tam;
				}				
           }
			break;
		
		case 3:
			relatorio(atleta, quant);
			break;
		}
				   
			
	}while( opc != 4 );
	
	free(atleta);
	
	
	return 0;
}