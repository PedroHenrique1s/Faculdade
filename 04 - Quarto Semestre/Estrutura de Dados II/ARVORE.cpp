#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no_arv //Criação do nó ARVORE
{
	int info;
	struct no_arv *esq;
	struct no_arv *dir;
};
typedef struct no_arv ARVORE;

ARVORE *cria_arv_vazia (void)
{
	return NULL;
}

ARVORE *cria_arv(int x, ARVORE *sae, ARVORE *sad)
{
	ARVORE *r;
	r = (ARVORE*) malloc(sizeof (ARVORE)); //Alocação dinamica de memoria
	r->info = x;
	r->esq = sae;
	r->dir = sad;
	
	return r; 
}

void pre_ordem (ARVORE *r)
{
	if (r != NULL)
	{
		printf("\n%d \n", r->info);
		pre_ordem(r->esq);
		pre_ordem(r->dir);
	}
}

void in_ordem (ARVORE *r)
{
	if (r != NULL)
	{
		in_ordem(r->esq);
		printf("\n%d \n", r->info);
		in_ordem(r->dir);
	}
}

void pos_ordem (ARVORE *r)
{
	if (r != NULL)
	{
		pos_ordem(r->esq);
		pos_ordem(r->dir);
		printf("\n%d \n", r->info);
	}
}

int main()
{
	ARVORE *r;
	ARVORE *r1, *r2, *r3, *r4, *r5;
	
	r = cria_arv_vazia();
	
	//Montagem da arvore
	r1 = cria_arv(3, cria_arv_vazia(), cria_arv_vazia());
	r2 = cria_arv(8, cria_arv_vazia(), cria_arv_vazia());
	r3 = cria_arv(2, cria_arv_vazia(), cria_arv_vazia());
	r4 = cria_arv(1, cria_arv_vazia(), r1);
	r5 = cria_arv(5, r2, r3);
	r = cria_arv(7, r4, r5);
	
	printf("\n Percurso em pre-ordem \n");
	pre_ordem(r);
	printf("\n Percurso em in-ordem \n");
	in_ordem(r);
	printf("\n Percurso em pos-ordem \n");
	pos_ordem(r);
}
