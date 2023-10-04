//Programa Realizado para uma Loja fazer médias de peixe 
//estrutura de decisão else if 

#include <stdio.h>

int main() {

	int qtdPeixe;
	float valorPeixe, valorFinal;

	printf("***Seja bem vindo(a) - Pedro Peixes***");
	
	printf("\n\n***Promocao do dia*** \n \n Na compra de 5 peixe valor R$8.00 \n Compra ate 10 peixes e pagua R$6,50 \n Ate 100 Peixes valor R$5.00");
	
	printf("\n\nQual a quantidade de peixes voce gostaria de comprar?");
	printf("\nDigite: ");
	scanf("%d", &qtdPeixe);


	if (qtdPeixe < 5) {
		valorPeixe = 8.00;
		valorFinal = qtdPeixe * valorPeixe;
		printf("Valor do peixe: R$%0.2f", valorPeixe);
		printf("\nVoce acaba de adquirir %d peixes.", qtdPeixe);
		printf("\nTotal da Compra: R$%0.2f", valorFinal);

	} else if (qtdPeixe >=5 && qtdPeixe < 10) {
		valorPeixe = 6.50;
		valorFinal = qtdPeixe * valorPeixe;
		printf("Valor do peixe: R$%0.2f", valorPeixe);
		printf("\nVoce acaba de adquirir %d peixes.", qtdPeixe);
		printf("\nTotal da Compra: R$%0.2f", valorFinal);

	} else if (qtdPeixe >= 10 && qtdPeixe <= 100) {
		valorPeixe = 5.00;
		valorFinal = qtdPeixe * valorPeixe;
		printf("Valor do peixe: R$%0.2f", valorPeixe);
		printf("\nVoce acaba de adquirir %d peixes.", qtdPeixe);
		printf("\nTotal da Compra: R$%0.2f", valorFinal);

	} else {
		valorPeixe = 5.00;
		valorFinal = qtdPeixe * valorPeixe;
		printf("Valor do peixe: R$%0.2f", valorPeixe);
		printf("\nVoce acaba de adquirir %d peixes.", qtdPeixe);
		printf("\nTotal da Compra: R$%0.2f", valorFinal);
	}
}