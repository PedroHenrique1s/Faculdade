//Trabalho de Estrutura de Dados

//Bibliotecas

#include <stdio.h>
#include <strings.h>
#define tam 10

//Pilha Est�tica

struct pilha
{
	char elementos[tam];
	int topo;
};

//Fun��es

//Fun��o iniciar pilha - fun��o respons�vel por atribuir ao topo -1 para que o primeiro elemento v� para posi��o [0]

void iniciarPilha(struct pilha *p)
{
	p -> topo = -1;
}

/*
Fun��o empilhar - fun��o respons�vel por adicionar informa��es dentro de uma pilha
e conferir se ela est� cheia
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
Fun��o remover - fun��o respons�vel por remover informa��es do topo
e avisar quando a pilha estiver vazia
*/

void pop(struct pilha *p)
{
	if(p -> topo == -1)
		printf("\nPilha vazia!");
	else
		p -> topo--;
}

//Fun��o mostrar topo - fun��o respons�vel por retornar o valor do topo da pilha

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
	struct pilha p; //Declara��o da vari�vel p do tipo struct pilha
	char den[100]; //Declara��o da vari�vel de denomina��o
	printf("Digite uma expressao numerica: "); //Entrada de dados do usu�rio
	gets(den);
	iniciarPilha(&p); //Iniciando a pilha
	
	//Valida��o da express�o num�rica
	
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
	
	//Resultado da valida��o
	
	if(p.topo == -1)
		printf("Expressao valida!");
	else
		printf("Expressao invalida!");
		
	return 0;
}