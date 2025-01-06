/*
Escreva programa que, após criar 2 listar encadeadas não ordenadas de números inteiros, crie uma terceira lista que seja
a fusão das 2 listas em uma unica lista ordenada. 
Mostrar a lista ordenada 
Incluir uma função que permita remover um elemento escolhido pelo usuário da lista ordernada.
Motrar a lista
*/



#include <stdio.h>
#include <stdlib.h>

struct no{
	int info;
	struct no* prox;
};

typedef struct no LISTA;


LISTA * insereInicio( LISTA *p, int num){

	LISTA *novo;
	novo = (LISTA *) malloc(sizeof(LISTA));
	novo->info = num;

	
	if( p == NULL){
		p = novo;
		novo -> prox = NULL;
	}else {
		novo -> prox = p;
		p = novo;
	}
	
	return p;
}


LISTA * insereOrdenado(LISTA *p, int num){
	LISTA * novo, *ant, *aux;
	
	novo  = (LISTA *) malloc(sizeof(LISTA));
	novo->info = num;
	
	if(p == NULL ){
		novo->prox =p;
		p = novo;
	}else {
		ant = NULL;
		aux = p;
		
		while( aux != NULL && aux->info <= novo->info ){
			ant = aux;
			aux = aux->prox;
		}
		
		if(aux == p){
			novo->prox = p;
			p = novo;
		}else {
			novo->prox = aux;
			ant->prox = novo;
		};
	};
	return p;
};



void mostrarLista(LISTA *p){
	
	LISTA *aux;
	aux = p;
	while(aux != NULL){
		printf(" %d ", aux->info);
		aux = aux->prox;
	}
}

LISTA * remove(LISTA *p, int x){
	
	LISTA *aux, *ant;
	ant = NULL;
	aux = p;
	
	while(aux != NULL && aux->info < x){
		ant = aux;
		aux = aux->prox;
	}
	
	if(aux->info == x ){
		if(aux == p){
			p = aux->prox;
		}else {
			ant->prox = aux->prox;
		}
		free(aux);
	}
	return p;
	
}

int main()
{
	int num1, num2, num3;
	char opc;
	LISTA *p1, *p2, *aux, *p3;
	p1 = NULL;
	p2 = NULL;
	p3= NULL;
	
	
	do{
		printf("Digite um numero inteiro para a primeira lista: ");
		scanf("%d",&num1);
		
		p1 = insereInicio(p1, num1);
		
		
		printf("\nDeseja inserir novamente [s/n] \n=>");
		scanf(" %c", &opc);
		
	}while(opc == 's' || opc == 'S');
	
	do {
		printf("Digite um numero inteiro para segunda lista ");
		scanf("%d", &num2);
		
		p2 = insereInicio(p2, num2);
		aux = p2;
		
		printf("\bDeseja inserir novamente [s/n] \n=>");
		scanf(" %c", &opc);
		
	}while(opc == 's' || opc == 'S');
	
	printf("\n Lista 1");
	mostrarLista(p1);
	printf("\n Lista 2");
	mostrarLista(p2);
	
	aux = p1;
	while( aux != NULL){
		p3 = insereOrdenado(p3, aux->info);	
		aux = aux->prox;
	} 
	
	aux = p2;
	while( aux != NULL){
		p3 = insereOrdenado(p3, aux->info);
		aux = aux->prox;
	}

	mostrarLista(p3);
	
	printf("Deseja remover qual numero: ");
	scanf("%d", &num3);
	remove(p3, num3);
	
	mostrarLista(p3);
	
	return 0;
}

