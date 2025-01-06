//Trabalho Avaliativo de Estrutura de Dados - CCO 2024

//Gestão de Estoque

//Kenzo Aleixo
//Pedro Henrique Souza
//Pedro Schiabel


/* OBJETIVO: implementar um sistema de gestão de estoque para uma pequena loja utilizando listas encadeadas dinâmicas. O sistema deve
armazenar, manuipular e consultarinfotmações sobre o produto, permitindo inserção, remoção, busca, atualização e relatório completo
dos dados armazenados

Descrição do Problema: a loja possui diversos produtos, e cada produto contém as seguintes informações:
* ID do produto (inteiro)
* Nome do produto (string)
* Quantidade em estoque (inteiro)
* Preço unitário (float)
* Data de validade (struct com dia, mês e ano)

Especificações:
1. Estrutura de Dados: Defina uma estrutura Produto para representar cada produto e implemente uma lista encadeada dinâmica que armazene as informações dos produtos.
2. Funções Requeridas:
* Adicionar Produto: Função que insere um novo produto na lista. A inserção deve ser feita de forma ordenada pelo nome do produto.
* Remover Produto: Função que remove um produto da lista dado o ID. A função deve exibir uma mensagem de erro se o produto não existir.
* Buscar Produto: Função que exibe as informações de um produto específico com base no nome.
* Atualizar Produto: Função que permite atualizar a quantidade ou o preço de um
oroduto específico
* Listar Produtos: Função que exibe todos os produtos, incluindo todos os detalhes de cada produto.
* Relatório de Vencimento Próximo: Função que exibe um relatório de produtos cuja
validade expira em menos de 30 dias.
* Filtros Dinâmicos: Permitir que o usuário filtre a listagem por quantidade (ex: todos os produtos com estoque abaixo de 10) 
*/


//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define
#define tam 50

//Agrupar variavéis do tipo data
struct data
{
	int dia;
	int mes;
	int ano;
};
//Definindo um novo nome para struct data
typedef struct data DATA;

//Agrupar variaveis do tipo produtos 
struct produtos
{
	int id;
	char nome[tam];
	int qtd;
	float preco;
	DATA data;
};
//Definindo um novo nome para struct produtos
typedef struct produtos PRODUTOS;

//Agrupar variáveis do tipo no
struct no
{
	PRODUTOS info;
	struct no *prox;
};
//Definindo um novo nome para struct no
typedef struct no LISTA;

//Função Cadastrar Produto 
PRODUTOS cadastrarProduto(PRODUTOS produto)
{
	printf("\nDigite o nome do produto: ");
	fflush(stdin);
	gets(produto.nome);
	printf("\nDigite o id do produto: ");
	scanf("%d", &produto.id);
	printf("\nDigite a quantidade do produto: ");
	scanf("%d", &produto.qtd);
	printf("\nDigite o preco do produto: ");
	scanf("%f", &produto.preco);
	printf("\nDigite o dia da validade do produto: ");
	scanf("%d", &produto.data.dia);
	printf("\nDigite o mes da validade do produto: ");
	scanf("%d", &produto.data.mes);
	printf("\nDigite o ano da validade do produto: ");
	scanf("%d", &produto.data.ano);
	
	return produto;
}

// Lista Encadeada 
LISTA* insereInicio(LISTA *p, PRODUTOS prod)
{
	LISTA *novo;
	novo = (LISTA*)malloc(sizeof(LISTA));

	novo->info.id = prod.id;
	strcpy(novo->info.nome, prod.nome);
	novo->info.qtd = prod.qtd;
	novo->info.preco = prod.preco;
	novo->info.data.dia = prod.data.dia;
	novo->info.data.mes = prod.data.mes;
	novo->info.data.ano = prod.data.ano;
	

	novo->prox = p;
	p = novo;
	
	return p;
}

//Lista ordenada
LISTA* insereOrdenado(LISTA *p, PRODUTOS prod)
{
	//Ponteiro para o novo nó a ser alocado
	LISTA *novo, *ant, *aux;
	
	//Alocação dinâmica de memória
	novo = (LISTA*)malloc(sizeof(LISTA));
	
	//Inserção da informação no novo nó
	novo->info.id = prod.id;
	strcpy(novo->info.nome, prod.nome);
	novo->info.qtd = prod.qtd;
	novo->info.preco = prod.preco;
	novo->info.data.dia = prod.data.dia;
	novo->info.data.mes = prod.data.mes;
	novo->info.data.ano = prod.data.ano;
	
	//Encadeamento
	if(p == NULL)
	{
		novo -> prox = p;
		p = novo;
	}
	else 
	{
		ant = NULL;
		aux = p;
		
		//Ordem alfabética
		while(aux != NULL && strcmp(aux -> info.nome, novo -> info.nome) < 0)
		{
			ant = aux;
			aux = aux -> prox;
		}
		if(aux == p)
		{
			novo -> prox = p;
			p = novo;
		}
		else
		{
			novo -> prox = aux;
			ant -> prox = novo;
		}
	}
	return p;
}

//Função remove
LISTA* removeProdutos(LISTA *p, int id)
{
	//Declaração de variáveis
	LISTA *aux, *ant;
	ant = NULL;
	aux = p;
	
	//Estrutura de repetição e condição para o encontro do ID do produto
	while(aux != NULL && aux->info.id != id)
	{
		ant = aux;
		aux = aux->prox;
	}
	
	// validação para achar o id do produto
	if(aux->info.id == id)
	{
		if(aux == p)
			p = aux -> prox;
		else 
			ant->prox = aux -> prox;
		free(aux);
		printf("\n\nProduto removido com sucesso");
	}
	else
		printf("\nProduto nao existe");
	return p;
}

void mostrarLista(LISTA *p)
{
	//Declaração de variáveis
	LISTA *aux;
	
	aux = p;
	
	//aux for diferente de zero. Mostar a lista de produtos cadastrados 
	while(aux != NULL)
	{
		printf("\nId do produto: %d", aux->info.id);
		printf("\nNome do produto: %s", aux->info.nome);
		printf("\nQuantidade do produto: %d", aux->info.qtd);
		printf("\nPreco do produto: %.2f", aux->info.preco);
		printf("\nData da validade do produto: %d/%d/%d\n", aux->info.data.dia,aux->info.data.mes,aux->info.data.ano);
		aux = aux->prox;
	}
}

LISTA* buscarProduto(LISTA *p, char prodPesquisado[tam])
{
	//Declaração de variáveis
	LISTA *aux, *ant;
	
	ant = NULL;
	aux = p;
	
	while(aux != NULL && strcmp(aux->info.nome, prodPesquisado) != 0)
	{
		ant = aux;
		aux = aux->prox;
	}
	
	if(aux != NULL && strcmp(aux->info.nome, prodPesquisado) == 0)
	{
		if(aux == p)
			p = aux -> prox;
		else
			ant->prox = aux -> prox;

		printf("\nNome do produto pesquisado:  %s", aux->info.nome);
		printf("\n\nID do produto pesquisado:  %d", aux->info.id);
		printf("\n\nQuantidade do produto pesquisado:  %d", aux->info.qtd);
		printf("\n\nPreco do produto pesquisado:  %.2f", aux->info.preco);
		printf("\n\nValidade do produto pesquisado: %d/%d/%d \n", aux->info.data.dia,aux->info.data.mes,aux->info.data.ano);
	}
	else
		printf("\nProduto nao existe");
	
	return p;
}

LISTA* atualizarProduto(LISTA* p, int id)
{
	//Declaração de variáveis
	LISTA *aux, *ant;
	int opc, qtd;
	float preco;
	
	ant = NULL;
	aux = p;
	
	//Atualizando o produto atraves do Id
	while(aux != NULL && aux -> info.id != id)
	{
		ant = aux;
		aux = aux->prox;
	}
	
	if(aux -> info.id == id)
	{
		printf("\n[1] - Atualizar quantidade: \n[2] - Atualizar preco: \n\n->");
		scanf("%d", &opc);
		if(opc == 1)
		{
			printf("\nDigite a quantidade atualizada: ");
			scanf("%d", &qtd);
			aux -> info.qtd = qtd;
			printf("\nQuantidade do produto atualizado com sucesso: %s", aux -> info.nome);
		}
		else if(opc == 2)
		{
			printf("\nDigite o preco atualizado: ");
			scanf("%f", &preco);
			aux -> info.preco = preco;
			printf("\nPreco do produto atualizado com sucesso: %s", aux -> info.nome);
		}
		else
		{
			printf("\nOpcao invalida!");
		}
	}
	else
		printf("\nProduto nao existe");
	return p;
}

// relatório de vencimento
void validadeProduto(LISTA *p){
	
	DATA limite, date;
	LISTA *aux;
	
	aux = p;
	
	printf("Digite o dia atual: ");
	scanf("%d", &date.dia);	
	printf("Digite o mes atual: ");
	scanf("%d", &date.mes);
	printf("Digite o ano atual: ");
	scanf("%d", &date.ano);
	//validação de dias, mes e anos. Data limite
	if(date.dia == 30){
		limite.dia = 1;
		limite.mes = date.mes;
		limite.ano = date.ano;
	}else{
		limite.dia = 30 - date.dia;
		limite.mes = date.mes - 1;
		limite.ano = date.ano; 
        if(limite.mes == 0){
			limite.mes = 12;
			limite.ano = date.ano - 1;
		}
   }
   // data limite
   printf("\nData limite = %d/%d/%d \n ", limite.dia, limite.mes, limite.ano);
   while(aux != NULL){
   	// Mostrar produtos pesquisados pela data de validadde 
   		if(limite.dia <= aux->info.data.dia && limite.mes <= aux->info.data.mes && limite.ano <= aux->info.data.ano){
   			printf("\nNome do produto pesquisado:  %s", aux->info.nome);
			printf("\n\nID do produto pesquisado:  %d", aux->info.id);
			printf("\n\nQuantidade do produto pesquisado:  %d", aux->info.qtd);
			printf("\n\nPreco do produto pesquisado:  %.2f", aux->info.preco);
			printf("\n\nValidade do produto pesquisado: %d/%d/%d \n", aux->info.data.dia,aux->info.data.mes,aux->info.data.ano);
		}
   		aux = aux->prox;
   }
			
}

//Filtro Dinâmico
LISTA* filtroDinamico(LISTA *p, int qtdDesejado){
	
	LISTA *aux, *ant;
	ant = NULL;
	aux = p;

//	validação de quantidades 
	while(aux != NULL && aux->info.qtd != qtdDesejado){
		// mostrar produtos com a quantidade desejada 
		if(aux->info.qtd <= qtdDesejado){
			printf("\nNome do produto pesquisado:  %s", aux->info.nome);
			printf("\n\nID do produto pesquisado:  %d", aux->info.id);
			printf("\n\nQuantidade do produto pesquisado:  %d", aux->info.qtd);
			printf("\n\nPreco do produto pesquisado:  %.2f", aux->info.preco);
			printf("\n\nValidade do produto pesquisado: %d/%d/%d \n", aux->info.data.dia,aux->info.data.mes,aux->info.data.ano);
		}
		aux = aux->prox;
	}
	

	return p;
}

int main()
{
	//Declaração de variáveis
	LISTA *p1;
	PRODUTOS prod;
	int opc, id, idAtualizacao, qtdDesejado;
	char opcProd, prodPesquisado[tam];
	
	//Inicialização da pilha p1 como NULL
	p1 = NULL;
	
	//Menu
	do
	{
		printf("\n[1] - Adicionar produto\n[2] - Remover produto\n[3] - Buscar produto\n[4] - Atualizar produto\n[5] - Listar produtos\n[6] - Relatorio de vencimento proximo\n[7] - Filtros dinamicos\n[8] - Sair\n\n=>");
		scanf("%d", &opc);
		switch(opc)
		{
			//Adicionar Produto
			case 1:
				
				do
				{
					prod = cadastrarProduto(prod);
					
					
					p1 = insereOrdenado(p1, prod);
					printf("\nDeseja inserir novamente? [S/N] \n=>");
					scanf(" %c", &opcProd);
				}while(opcProd == 'S' || opcProd == 's');
				
				
				break;
			
			//Remover Produto
			case 2: 
				
				printf("\nDigite o id do produto que deseja remover: ");
				scanf("%d", &id);
				
				removeProdutos(p1, id);
				break;
			
			//Buscar Produto
			case 3:
				
				fflush(stdin);
				printf("\nDigite em minusculo o nome do produto que deseja buscar: ");
				gets(prodPesquisado);
				
				buscarProduto(p1, prodPesquisado);
				break;
			
			//Atualizar Produto
			case 4: 
				
				printf("\nDigite o id do produto para atualiza-lo (Quantidade ou Preco): ");
				scanf("%d", &idAtualizacao);
				atualizarProduto(p1, idAtualizacao);
				break;
			
			//Listar Produtos
			case 5: mostrarLista(p1);
				break;
			
			//Relatório de Vencimento Próximo
			case 6:	
					validadeProduto(p1);
				break;
			
			//Filtros Dinâmicos
			case 7:
				
				printf("\nBusque o produto pela quantidade que deseja: ");
				scanf("%d", &qtdDesejado);
				
				filtroDinamico(p1, qtdDesejado);
				break;
		}
	}while(opc != 8);
	
	return 0;
}