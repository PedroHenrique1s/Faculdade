#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct boletin {
	   char nome[40];
	   float provaIntermediaria;
	   float provaSemestral;
	   float trabalho;	
};


void pesquisa_aluno(struct boletin aluno[30], int quant_aluno){
	char buscaAluno[40];
	float media;
	float pesoP1;
	float pesoP2;
	float trab;
	
	fflush(stdin);
	printf("Digite o nome do aluno que deseja procurar");
	gets(buscaAluno);
	
	for(int i = 0; i < quant_aluno; i++){
		
		pesoP1 = (aluno[i].provaIntermediaria * 3.5)/10 ;
		pesoP2 = (aluno[i].provaSemestral * 3.5)/10 ;
		trab   = (aluno[i].trabalho * 3)/10  ;
		media = pesoP1 + pesoP2 + trab ;
		//condição para comparar string
		if (strcmp(aluno[i].nome, buscaAluno) == 0){
			printf("\n\nNome do Aluno: %s",aluno[i].nome);
			printf("\nNota da Prova Intermediaria: %.2f",aluno[i].provaIntermediaria);
			printf("\nNota da Prova Semestral: %.2f",aluno[i].provaSemestral);
			printf("\nNota do Trabalho: %.2f",aluno[i].trabalho);
			printf("\nMedia: %.f", media);
		}
	}
}
void visualizar_aprovados_reprovados(struct boletin aluno[30], int quant_aluno){
	float media;
	float pesoP1;
	float pesoP2;
	float trab;
	
	for(int i = 0; i < quant_aluno; i++){
		
		pesoP1 = (aluno[i].provaIntermediaria * 2)/10 ;
		pesoP2 = (aluno[i].provaSemestral * 3)/10 ;
		trab   = (aluno[i].trabalho * 1)/10 ;
		media = pesoP1 + pesoP2 + trab / 3;
		//condição para comparar string
		if (media >= 6){
			printf("Lista de Aprovados\n");
			printf("\nNome do Aluno: %s",aluno[i].nome);
			printf("\nNota da Prova Intermediaria: %.2f",aluno[i].provaIntermediaria);
			printf("\nNota da Prova Semestral: %.2f",aluno[i].provaSemestral);
			printf("\nNota do Trabalho: %.2f",aluno[i].trabalho);
			printf("\nMedia: %.f", media);
		}else {
			printf("\n\nLista de Reprovados \n");
			printf("\nNome do Aluno: %s",aluno[i].nome);
			printf("\nNota da Prova Intermediaria: %.2f",aluno[i].provaIntermediaria);
			printf("\nNota da Prova Semestral: %.2f",aluno[i].provaSemestral);
			printf("\nNota do Trabalho: %.2f",aluno[i].trabalho);
			printf("\nMedia: %.f", media);
		}
	}
	
	
}

int cadastrar_Aluno(struct boletin aluno[30], int quant_aluno){
	char opc;
	
	do{
		fflush(stdin);
		printf("\nDigite seu nome: ");
		gets(aluno[quant_aluno].nome);
		
		fflush(stdin);
		printf("\nDigite sua nota da prova intermediaria: ");
		scanf("%f",&aluno[quant_aluno].provaIntermediaria);
		
		fflush(stdin);
		printf("\nDigite sua nota da prova semestral: ");
		scanf("%f",&aluno[quant_aluno].provaSemestral);
		
		fflush(stdin);
		printf("\nDigite sua nota do trabalho: ");
		scanf("%f",&aluno[quant_aluno].trabalho);
		
		quant_aluno++;
		
		printf("\nDeseja cadastrar outro aluno (S/N)? = ");
		scanf(" %c", &opc);
		
	}while( opc == 's' || opc == 'S');
	
	
	return quant_aluno;
}

void menu(struct boletin aluno[30], int quant_aluno){
	int opc ;
	
	printf("***Modelo Boletinho***");
	do{
		
		printf("\n[1]- CADASTRAR ALUNOS");
		printf("\n[2]- PESQUISAR A MEDIA DE DETERMINADO ALUNO");
		printf("\n[3]- VISUALIZAR APROVADOS E REPROVADOS\n =>");
		scanf("%d",&opc);
		switch(opc)
		{
		case 1:
			quant_aluno = cadastrar_Aluno(aluno,quant_aluno);
			break;
		case 2:
			pesquisa_aluno(aluno, quant_aluno);
			break;
		case 3:
			visualizar_aprovados_reprovados(aluno, quant_aluno);
			break;
		}
		
	}while(opc != 4);
}


int main()
{
	struct boletin aluno[30];
	int quant_aluno = 0;
	
	menu(aluno, quant_aluno);
	
	
	return 0;
}