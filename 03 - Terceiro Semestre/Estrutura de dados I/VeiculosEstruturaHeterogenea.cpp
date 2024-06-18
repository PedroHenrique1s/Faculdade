#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct veiculo 
{
	char marca[40];
	char modelo[40];
	char cor[30];
	char tipoDirecao[30];
	int ano;
	int kmAtual;
	int nPortas;
	float valor;	
};

int CadastrarCarro(struct veiculo carro[50], int num_carros){
	char op;
	
	do {
		fflush(stdin);
		printf("\nQual a marca do carro: ");
		gets(carro[num_carros].marca);
		
		fflush(stdin);
		printf("\nDigite o modelo do carro: ");
		gets(carro[num_carros].modelo);
		
		fflush(stdin);
		printf("\nDigite a cor do carro: ");
		gets(carro[num_carros].cor);
		
		fflush(stdin);
		printf("\nDigite o tipo de direcao do carro: ");
		gets(carro[num_carros].tipoDirecao);
		
		fflush(stdin);
		printf("\nDigite o ano do carro: ");
		scanf("%d", &carro[num_carros].ano);

		fflush(stdin);
		printf("\nDigite o km atual do carro: ");
		scanf("%d", &carro[num_carros].kmAtual);
		
		fflush(stdin);
		printf("\nDigite o numero de portas do carro: ");
		scanf("%d", &carro[num_carros].nPortas);

		fflush(stdin);
		printf("\nDigite o valor do carro: ");
		scanf("%f", &carro[num_carros].valor);


		num_carros++;
		
		printf("\nDeseja cadastrar outro veiculo (S/N)? = ");
		scanf(" %c", &op);
		
	}while( op == 'S' || op == 's' );
	
	return num_carros;
}

void mostrar(struct veiculo carro[50], int num_carros){
	
	for(int i = 0; i < num_carros; i++){
		printf("\n Marca: %s",carro[i].marca);
		printf("\n Modelo: %s",carro[i].modelo);
		printf("\n Cor: %s",carro[i].cor);
		printf("\n Tipo de Direcao: %s",carro[i].tipoDirecao);
		printf("\n Ano do Veiculo: %d",carro[i].ano);
		printf("\n Km atual: %d",carro[i].kmAtual);
		printf("\n Nr de Portas: %d",carro[i].nPortas);
		printf("\n Valor do veiculo: %f",carro[i].valor);
	}
	
}

void pesquisarValor(struct veiculo carro[50], int num_carros){
	float vMax,vMin;
	int i;
	
	printf("\n\nDigite o valor mínimo para o carro: ");
	scanf("%f",&vMin);
	
	printf("Digite o valor maximo: ");
	scanf("%f",&vMax);
	
	for(i = 0; i < num_carros; i++){
		if(carro[i].valor >= vMin && carro[i].valor <= vMax){
			printf("\n Marca: %s",carro[i].marca);
			printf("\n Modelo: %s",carro[i].modelo);
			printf("\n Cor: %s",carro[i].cor);
			printf("\n Tipo de Direcao: %s",carro[i].tipoDirecao);
			printf("\n Ano do Veiculo: %d",carro[i].ano);
			printf("\n Km atual: %d",carro[i].kmAtual);
			printf("\n Nr de Portas: %d",carro[i].nPortas);
			printf("\n Valor do veiculo: %f",carro[i].valor);
		}
	}
}

void pesquisarModelo(struct veiculo carro[50], int num_carros){
	char modelo_procurado[30];
	
	fflush(stdin);
	printf("Por qual modelo voce procura ? \n");
	gets(modelo_procurado);
	
	for(int i = 0; i < num_carros; i++){
		//condição para comparar string
		if (strcmp(carro[i].modelo, modelo_procurado) == 0)
		{
			printf("\n Marca: %s",carro[i].marca);
			printf("\n Modelo: %s",carro[i].modelo);
			printf("\n Cor: %s",carro[i].cor);
			printf("\n Tipo de Direcao: %s",carro[i].tipoDirecao);
			printf("\n Ano do Veiculo: %d",carro[i].ano);
			printf("\n Km atual: %d",carro[i].kmAtual);
			printf("\n Nr de Portas: %d",carro[i].nPortas);
			printf("\n Valor do veiculo: %f",carro[i].valor);
		}
	}
}

void pesquisarKM(struct veiculo carro[50],int num_carros){
	int kmVeiculoDeseja;
	
	printf("Digite o km do veiculo desejado: ");
	scanf("%d", &kmVeiculoDeseja);
	
	for(int i = 0; i < num_carros; i++){
		if(carro[i].kmAtual < kmVeiculoDeseja ){
			printf("\n Marca: %s",carro[i].marca);
			printf("\n Modelo: %s",carro[i].modelo);
			printf("\n Cor: %s",carro[i].cor);
			printf("\n Tipo de Direcao: %s",carro[i].tipoDirecao);
			printf("\n Ano do Veiculo: %d",carro[i].ano);
			printf("\n Km atual: %d",carro[i].kmAtual);
			printf("\n Nr de Portas: %d",carro[i].nPortas);
			printf("\n Valor do veiculo: %f",carro[i].valor);
		}
	}
}


void menu(struct veiculo carro[50], int num_carros){
	int opc;
	
	do {
		printf("[1]- CADASTRAR CARRO\n");
		printf("[2]- PESQUISAR POR FAIXA DE VALOR\n");
		printf("[3]- PESQUISAR POR MODELO \n");
		printf("[4]- PESQUISAR POR KM\n");
		printf("[5]- Sair\n=>");
		scanf("%d",&opc);
	
		switch(opc)
		{
			case 1:
				num_carros = CadastrarCarro(carro, num_carros);
				break;
			case 2:
				pesquisarValor(carro, num_carros);
				break;
			case 3:
				pesquisarModelo(carro, num_carros);
				break;
			case 4:
				pesquisarKM(carro, num_carros);
				break;
			}
	}while(opc != 5);
	
	
}

int main()
{	
	struct veiculo carro[50];
	int num_carros = 0;
		
	menu(carro,num_carros);
	
	return 0;
}