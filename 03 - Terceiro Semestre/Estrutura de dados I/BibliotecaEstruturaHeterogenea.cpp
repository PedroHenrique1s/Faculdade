#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct biblioteca {
	   char titulo[50];
	   char nomeLivro[50];
	   int anoPublicacao;
	   char status;	
};

int adicionar(struct biblioteca livro[50], int quant_livros){
	char opc;
	
	do{
		fflush(stdin);
		printf("\n\nDigite o titulo: ");
		gets(livro[quant_livros].titulo);
		
		fflush(stdin);
		printf("\nNome do Livro: ");
		gets(livro[quant_livros].nomeLivro);
		
		fflush(stdin);
		printf("\nDigite o ano de publicacao do Livro");
		scanf("%d",&livro[quant_livros].anoPublicacao);
		
		fflush(stdin);
		printf("\nDigite o status do livro\n [E]mprestado \n [D]evolvido ");
		livro[quant_livros].status = getch();
		
		quant_livros++;
		
		fflush(stdin);
		printf("\n\nDeseja cadastrar outro livros [s/n] ?");
		scanf("%c",&opc);
		
		
	}while(opc == 'S' || opc == 's');
	
	
	return quant_livros;
}

void mostrarLivros(struct biblioteca livro[50], int quant_livros){
	
	for(int i = 0; i < quant_livros; i++){
		
		if(livro[i].status == 'D' || livro[i].status == 'd'){
			printf("\n\nTitulo: %s",livro[i].titulo);
			printf("\nNome do Livro: %s",livro[i].nomeLivro);
			printf("\nAno de Publicacao: %d",livro[i].anoPublicacao);
			printf("\nStatus do Livro: %c",livro[i].status);
		}
		
	}
}

void sistema(struct biblioteca livro[50], int quant_livros){
	
	int opc;
	char livroDesejado[50];
	do{
		printf("\n\n[1]- Pegar livro emprestado");
		printf("\n[2]- Devolver livro");
		scanf("%d",&opc);
		switch(opc)
		{
		case 1:
			for(int i = 0; i < quant_livros; i++){
				printf("\nLivros Disponíveis");
				printf("\n\nTitulo: %s",livro[i].titulo);
				printf("\nNome do Livro: %s",livro[i].nomeLivro);
				printf("\nAno de Publicacao: %d",livro[i].anoPublicacao);
				printf("\nStatus do Livro: %c",livro[i].status);
			
				printf("Digite o titulo ou o Nome do Livro pra fazer o emprestimo dele");
				gets(livroDesejado);
				
				if(strcmp(livro[i].titulo, livroDesejado) == 0 || strcmp(livro[i].nomeLivro, livroDesejado) == 0){
					livro[i].status = 'E';
					printf("\nLivro Reservado com Sucesso");
				}
			}
			break;
		case 2:
			for(int i = 0; i < quant_livros; i++){
				printf("\n\nDigite o titulo: ");
				gets(livro[quant_livros].titulo);
				
				printf("\nNome do Livro: ");
				gets(livro[quant_livros].nomeLivro);
				
				printf("\nDigite o ano de publicacao do Livro");
				scanf("%d",&livro[quant_livros].anoPublicacao);
				
				if(livro[i].status == 'E' || livro[i].status == 'E'){
					livro[i].status = 'D';
					printf("\nLivro Devolvido com sucesso");
				}
			}
			break;
		}
	}while(opc != 2);
}

void buscaLivro(struct biblioteca livro[50],int quant_livros){
	char livroDesejado[50];
	
	printf("Digite o nome do livro ou titulo do livro desejado: ");
	gets(livroDesejado);
	
	for(int i = 0; i < quant_livros; i++){
		if(strcmp(livro[i].titulo, livroDesejado) == 0 || strcmp(livro[i].nomeLivro, livroDesejado) == 0){
			printf("\n\nTitulo: %s",livro[i].titulo);
			printf("\nNome do Livro: %s",livro[i].nomeLivro);
			printf("\nAno de Publicacao: %d",livro[i].anoPublicacao);
			printf("\nStatus do Livro: %c",livro[i].status);
		}
	}
}


void menu(struct biblioteca livro[50], int quant_livros){
	int opc;
	
	do {
		printf("[1]- CADASTRAR LIVRO\n");
		printf("[2]- FAZER EMPRESTIMO DO LIVROU OU DEVOLVER O LIVRO\n");
		printf("[3]- LISTA DE TODOS OS LIVROS DISPONIVEIS \n");
		printf("[4]- PESQUISAR LIVRO PELO TITULO OU NOME\n");
		printf("[5]- Sair\n=>");
		scanf("%d",&opc);
	
		switch(opc)
		{
			case 1:
				quant_livros = adicionar(livro,quant_livros);
				break;
			case 2:
				sistema(livro, quant_livros);
				break;
			case 3:
				mostrarLivros(livro, quant_livros);
				break;
			case 4:
				buscaLivro(livro, quant_livros);
				break;
			}
	}while(opc != 5);

}

int main()
{
	struct biblioteca livro[50];
	int quant_livros = 0;
	
	menu(livro, quant_livros);
	
	return 0;
}