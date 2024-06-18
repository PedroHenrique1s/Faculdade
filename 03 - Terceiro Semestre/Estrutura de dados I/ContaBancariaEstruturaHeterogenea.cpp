#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct cadastro {
	char numeroConta[3];
	char nomeCliente[30];
	float saldo;	
};


int cadastrar_conta(struct cadastro conta[15], int quant_conta){
	char opc;

	do{
		fflush(stdin);
		printf("\nDigite o numero da sua conta: ");
		gets(conta[quant_conta].numeroConta);
 		
 		fflush(stdin);
 		printf("\nDigite seu nome: ");
 		gets(conta[quant_conta].nomeCliente);
 		
 		fflush(stdin);
 		printf("\nDigite o saldo da conta: R$");
 		scanf("%f",&conta[quant_conta].saldo);
 		
		quant_conta++;	
		
		printf("\nDeseja cadastrar outro veiculo (S/N)? = ");
		scanf(" %c", &opc);	
	}while(opc == 'S' || opc == 's');
	

	return quant_conta;
}

void contaMaiorSaldo(struct cadastro conta[15], int quant_conta){
	float maiorSaldo = 0;
	int indiceMaiorSaldo = -1;

	for(int i = 0; i < quant_conta ; i++){
		if(conta[i].saldo > maiorSaldo){
			if(conta[i].saldo > maiorSaldo){
				maiorSaldo = conta[i].saldo;
				indiceMaiorSaldo = i;
			}
		}
		
	}
	
    if (indiceMaiorSaldo != -1) {
		printf("\nMAIOR SALDO"); 
		printf("\nNome do Cliente: %s", conta[indiceMaiorSaldo].nomeCliente);
	    printf("\nNumero da conta: %s", conta[indiceMaiorSaldo].numeroConta);
	    printf("\nSaldo da Conta: R$ %.2f", conta[indiceMaiorSaldo].saldo);
	} else {
        printf("\nNenhuma conta encontrada.\n");
    }
	
}

void busca_cliente(struct cadastro conta[15], int quant_conta){
	char buscaAluno[40];
	
	fflush(stdin);
	printf("\nDigite o nome do cliente que deseja procura: ");
	scanf("%s",buscaAluno);
	
	
	for(int i = 0; i < quant_conta; i++){
		if(strcmp(conta[i].nomeCliente, buscaAluno) == 0){
			printf("\nNome do Cliente: %s",conta[i].nomeCliente);
			printf("\nnumero da conta: %s",conta[i].numeroConta);
			printf("\nSaldo da Conta: R$ %.f",conta[i].saldo);
		}
	}
}

void visualiazarClienteNegativado(struct cadastro conta[15], int quant_conta){
	
	for(int i = 0; i < quant_conta; i++){
		if(conta[i].saldo < 0){
			fflush(stdin);
			printf("\nClientes Negativados");
			printf("\nNome do Cliente: %s",conta[i].nomeCliente);
			printf("\nnumero da conta: %s",conta[i].numeroConta);
			printf("\nSaldo da Conta: R$ %.f",conta[i].saldo);	
		}
	}
	
}


void menu(struct cadastro conta[15] , int quant_conta){
 	int opc;
 	
 	printf("***Programa Conta Bancaria***");
 	do{
		 fflush(stdin);
		 printf("\n[1]- CADASTRAR CONTA");
		 printf("\n[2]- PESQUISA POR CLIENTE");
		 printf("\n[3]- VISUALIZAR A CONTA DOS CLIENTES COM SALDO NEGATIVO");
		 printf("\n[4]- MOSTRAR A CONTA COM MAIOR SALDO");
		 printf("\n[5] - Sair \n\n=> ");
		 scanf("%d",&opc);
		 
		 switch(opc)
		 {
		 case 1:
		 	quant_conta = cadastrar_conta(conta, quant_conta);
			 break;
		 case 2:
		 	busca_cliente(conta, quant_conta);
		 	break;
		 case 3:
		 	 visualiazarClienteNegativado(conta,quant_conta);
		 	break;
		 case 4: 
		 	contaMaiorSaldo(conta,quant_conta);
		 	break;
		 }
	 }while(opc != 5 );
}

int main()
{
	struct cadastro conta[15];
	int quant_conta = 0;
	
	menu(conta, quant_conta);
	return 0;
}