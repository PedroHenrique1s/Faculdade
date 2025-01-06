/*
Crie uma lsita que armazena caracteres, e na qual os nós 
são inseridos sempre no inicio da lista. O usuário deve ser perguntado, 
a cada nó inserido, se deseja inserir novo nó 

Ao terminar de criar a lista: 
a) Mostre os elementos da lista criada;
b) conte e informe quantos nós possuem um vogal maiuscolo armazenada
*/


#include <stdio.h>
#include <stdlib.h>

struct no {
	char info;
	struct no *prox;
};

typedef struct no LISTA;



LISTA* insereLista(LISTA *p, char c){
	
	LISTA *novo;
	novo = (LISTA*) malloc(sizeof(LISTA));
	
	novo->info = c;
	
	if(p == NULL){
		p = novo;
		novo->prox = p;
	}else {
		novo->prox = p;
		p = novo;
	}
	
	return p;
}

void mostraLista(LISTA *p, char n){
	
	LISTA *aux;
	aux = p;
		
	while(aux != NULL){
		printf("%c", aux->info);
		aux = aux->prox;
		
	};
}
 

int contaVogal(LISTA *p, char c){
	
	LISTA *aux;
	aux = p;
	int contador = 0;
	
	while( aux != NULL){
		
		if( (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')){
			contador++;
		}
	}
	
	return contador;
	
}


int main()
{
	char c, opc;
	int n;
	LISTA *p;
	
	p = NULL;
	
	do{
		printf("\nDigite um caracter:  ");
		scanf(" %c", n);
		
		p = insereLista(p, n);
		
		printf("\nDeseja inserir novo: (S/N)");
		scanf("%c",&opc);
		
			 		
	}while((opc == 'S') || (opc == 's') ); 
	
	mostraLista(p);
	
	n = contaVogal(p, c);
	printf("\nLista contem %d vogais", n);
	
	
	return 0;
}