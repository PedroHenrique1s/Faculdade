/*
Escreva um programa que crie duas contendo nome e cpfde pessoas.
Inclua  uma função que verifica se cada umadas listas está ordenada por nome
ou não. A ordem pode ser crescente ou descrescente. Caso seja desordenada, 
criar uma nova lista dessa, mas agora ordenada. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa{
	char nome[40];
	int cpf;
};

typedef struct pessoa PESSOA;

struct no{
	PESSOA info;
	struct no *prox;
};

typedef struct no LISTA;


LISTA* insereInicio(LISTA* p, PESSOA pessoa){
	
	LISTA *novo;
 	novo = (LISTA*) malloc(sizeof(LISTA));
 	strcpy(novo->info.nome, pessoa.nome);
	novo->info.cpf = pessoa.cpf;
 	
 	if(p == NULL){
		 p = novo;
		 novo->prox = NULL;
	}else {
		novo->prox = p;
		p = novo;
	}
	
	return p;
}

/LISTA insereOrdenado(LISTA *p, PESSOA pessoa){
	LISTA *novo, *ant, *aux;
	
	novo = (LISTA*) malloc(sizeof(LISTA));
	strcpy(novo->info.nome, pessoa.nome);
	strcpy(novo->info.cpf, pessoa.cpf);
	
	if(p == NULL){
		novo->prox = p;
		p = novo;
	}else {
		ant = NULL;
		aux = p;
		
		while(aux != NULL
			if(strcmp(ant->info.nome, aux->info.nome) == -1)){
				aux = p1->prox;
				ant = p1
			
				if(aux == p){
					novo->prox = p;
					p = novo;
				}else {
					novo->prox = aux;
					ant->prox = novo;
				}
				   	
          }
			
		}
	}
	
	return p;
}
*/

void mostrarPessoas(LISTA *p){
	
	LISTA *aux;
	
	aux = p;while(aux != NULL
			if(strcmp(ant->info.nome, aux->info.nome) == -1)){
				aux = p1->prox;
				ant = p1
			
				if(aux == p){
					novo->prox = p;
					p = novo;
				}else {
					novo->prox = aux;
					ant->prox = novo;
				}
				   	
          }
	
	while(aux != NULL){
		printf("\n\nNome: %s", aux->info.nome);
		printf("\nCPF: %d", aux->info.cpf);
		
		aux = aux->prox;
	}
	
}



int main()
{
	
	PESSOA pessoa;
	LISTA *p1, *p2;
	char opc; 
	p1 = NULL;
	p2 = NULL;
		
	do{
		fflush(stdin);
		printf("Digite o nome: ");
		gets(pessoa.nome);
		
		printf("Digite o CPF: ");
		scanf("%d",&pessoa.cpf);
		
		p1 = insereInicio(p1, pessoa);
		
		printf("Deseja inserir novamente [s/n]: ");
		scanf(" %c", &opc);
		
	}while(opc == 's' || opc == 'S');
	
	
	
	
	/*aux = p1; 
	while( aux != NULL){
		p1 = insereOrdenado(p1, pessoa);
		aux = aux->prox;
	}
	*/
	mostrarPessoas(p1);
	

	return 0;
}