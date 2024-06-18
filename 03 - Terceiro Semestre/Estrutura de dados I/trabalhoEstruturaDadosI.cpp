//Trabalho de Estrutura de Dados

//Bibliotecas

#include <stdio.h>
#include <strings.h>
#define tam 10

//Pilha Estática

struct pilha
{
	char elementos[tam];
	int topo;
};

//Funções

//Função iniciar pilha - função responsável por atribuir ao topo -1 para que o primeiro elemento vá para posição [0]

void iniciarPilha(struct pilha *p)
{
	p -> topo = -1;
}

/*
Função empilhar - função responsável por adicionar informações dentro de uma pilha
e conferir se ela está cheia
*/

void push(struct pilha *p, char c)
{
	if(p -> topo == tam - 1)
		printf("Pilha cheia!");
	else
	{
		p -> topo++;
		p -> elementos[p -> topo] = c;
	}
}

/*
Função remover - função responsável por remover informações do topo
e avisar quando a pilha estiver vazia
*/

void pop(struct pilha *p)
{
	if(p -> topo == -1)
		printf("\nPilha vazia!");
	else
		p -> topo--;
}

//Função mostrar topo - função responsável por retornar o valor do topo da pilha

char funcTopo(struct pilha *p)
{
	char valorTopo;
	if((p -> topo) > -1)
	{
		valorTopo = p -> elementos[p -> topo];
		return valorTopo;
	}
}

//Main

int main()
{
	struct pilha p; //Declaração da variável p do tipo struct pilha
	char den[100]; //Declaração da variável de denominação
	printf("Digite uma expressao numerica: "); //Entrada de dados do usuário
	gets(den);
	iniciarPilha(&p); //Iniciando a pilha
	
	//Validação da expressão numérica
	
	for(int i = 0; i < strlen(den); i++) 
	{
		if(den[i] == '{' || den[i] == '[' || den[i] == '(')
		{
			push(&p, den[i]);
		}
		if(funcTopo(&p) == '(' && den[i] == ')')
		{
			pop(&p);
		}
		else if(funcTopo(&p) != '(' && den[i] == ')')
		{
			push(&p, den[i]);
		}
		else if(funcTopo(&p) == '[' && den[i] == ']')
		{
			pop(&p);
		}
		else if(funcTopo(&p) != '[' && den[i] == ']')
		{
			push(&p, den[i]);
		}
		else if(funcTopo(&p) == '{' && den[i] == '}')
		{
			pop(&p);
		}
		else if(funcTopo(&p) != '{' && den[i] == '}')
		{
			push(&p, den[i]);
		}
	}
	
	//Resultado da validação
	
	if(p.topo == -1)
		printf("Expressao valida!");
	else
		printf("Expressao invalida!");
		
	return 0;
}