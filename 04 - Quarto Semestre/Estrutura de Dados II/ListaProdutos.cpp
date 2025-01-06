/*
Considere um cadastro de produtos de um estoque, com as seguintes informações
para cada produto.
- Código de identificação 
- Nome 
- Quantidade disponível em estoque 
- preço de venda 


a) Crie um conjunto de N produtos, com N fornecido pelo usuário. Armazene as
informações de cada produto.

b) Inclue a possibilidade de novos produtos serem cadastrados pelo usuário.

c) Mostre os produtos em número menor do que 5 disponiveis no estoque

d) Encontre o produto com maior preço de vendas
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct produto{
	int codigoIdent;
	char nome[30];
	int estoque;
	float precoVenda;
};


void cadastrar_produto(struct produto *prod, int itens ){
	
	
	for( int i = 0; i < itens; i++ ){
		printf("\nDigite o codigo de identificacao: ");
		scanf("%d", &prod[i].codigoIdent);
		
		printf("\nDigite o nome do produto: ");
		scanf("%s", prod[i].nome);
		
		printf("\nDigite a quantidade disponivel em estoque: ");
		scanf("%d", &prod[i].estoque);
		
		printf("\nDigite o preco do produto: ");
		scanf("%f",&prod[i].precoVenda);
		
	}
	
};

void novo_prod(struct produto *prod, int itens,int qttNova){
	
	for( int i = itens; i < qttNova; i++ ){
		printf("\nDigite o codigo de identificacao: ");
		scanf("%d", &prod[i].codigoIdent);
		
		printf("\nDigite o nome do produto: ");
		scanf("%s", prod[i].nome);
		
		printf("\nDigite a quantidade disponivel em estoque: ");
		scanf("%d", &prod[i].estoque);
		
		printf("\nDigite o preco do produto: ");
		scanf("%f",&prod[i].precoVenda);
		
	}
};

void relatorio(struct produto *prod, int quantidade){
	
	for (int i = 0; i < quantidade ; i++){
		
		if(prod[i].estoque < 5){
			printf("\nCodigo de identificacao: %d", prod[i].codigoIdent);
			printf("\nNome do produto: %s", prod[i].nome);
			printf("\nEstoque do produto: %d", prod[i].estoque);
			printf("\nPreco do produto: %.2f", prod[i].precoVenda);
		}
		
	}
	
};

void pesquisa_prod(struct produto *prod, int quantidade){
	
	float maior_valor = 1;
	char maiorProd[30];
	
	for (int i = 0; i < quantidade; i++){
		
		if(prod[i].precoVenda > maior_valor){
			maior_valor = prod[i].precoVenda;
			strcpy(maiorProd, prod[i].nome);
			
			printf("\nNome do produto de valor maior: %s", maiorProd);
			printf("\nPreco do produto: %.2f", maior_valor);
		}
		
	}
	
	
};

int main()
{
	int opc;
	int itens;
	int qttNova=0;
	struct produto *prod;
	
	do{
		printf("\n[1]- Cadastrar produtos \n[2]- Deseja adicionar novos produtos \n[3]- Mostrar produtos com o estoque de 5 quantidade \n[4]- Encontre o produto com maior preco de venda  \n\n =>");
		scanf("%d",&opc);
		
		switch(opc)
		{
		case 1:	printf("\nDigite quantos produtos vai adicionar no seu carrinho: ");
	         	scanf("%d",&itens); 
			    prod = (struct produto*) malloc(itens * sizeof(struct produto));
				cadastrar_produto(prod, itens);
			    break;
		case 2: printf("\nDigite uma nova quantidade produto que deseja: ");
				scanf("%d",&qttNova);
				prod = (struct produto*) realloc(prod, (itens + qttNova) * sizeof(struct produto));
	 	        qttNova = itens + qttNova;  
				novo_prod(prod, itens, qttNova);
				break;
	    case 3: 
			if (itens ==0 && qttNova == 0 ){
		      printf("\nNao tem produto");
			}else if (qttNova == 0){ // nao aumentou o vetor
				   relatorio(prod, itens);	
			}else relatorio(prod, qttNova);    	
	    	break;
	    case 4:
	    	if(itens == 0 && qttNova == 0){
				printf("Nao tem produto");
			}else if(qttNova == 0){
				pesquisa_prod(prod, itens);
			}else pesquisa_prod(prod, qttNova);
	    	
	    	break;
		default:
			printf("Menu invalido");
			break;
		}
	}while (opc!= 5);
	free(prod);
	
	return 0;
}