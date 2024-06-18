#include <stdio.h>
#include <string.h>

struct cadastro {
	char nome[40];
	char sexo;
	int horas;
};

int cadastrarProfessor(struct cadastro professor[20], int quant){
	char opc; 
	
	do{
		printf("\nDigite o nome: ");
		gets(professor[quant].nome);
		fflush(stdin);
		printf("\n[M]asculino ou [F]eminino: ");
		scanf("%c",&professor[quant].sexo);
		fflush(stdin);
		printf("\nHoras ministradas: ");
		scanf("%d",&professor[quant].horas);
		fflush(stdin);
		
		quant++;
		
		
		printf("\nDeseja cadastrar outro prof [s/n]? ");
		scanf("%c", &opc);
		fflush(stdin);
	}while(opc == 's' || opc == 'S'  );
	return quant;
}

void calculo(struct cadastro professor[20], int quant){
	float horasTrabalhada = 85, salarioBruto, salarioLiquido, somaSalario= 0, media;
	int contadorFeminino = 0;
	
	for(int i = 0; i < quant; i++){
		salarioBruto = horasTrabalhada * professor[i].horas;
		
		if(professor[i].sexo == 'm' || professor[i].sexo == 'M'){
			
			if(professor[i].horas <= 70){
				salarioLiquido = salarioBruto * 0.90;
			}else {
				salarioLiquido = salarioBruto * 0.92;
			}
		}
		
		if(professor[i].sexo == 'F' || professor[i].sexo == 'f'){
			
			if(professor[i].horas <= 70){
				salarioLiquido = salarioBruto * 0.93;
			}else {
				salarioLiquido = salarioBruto * 0.95;
			}
			
			 somaSalario = somaSalario + salarioLiquido;
			
			contadorFeminino++;
		}
		
		printf("\n\nNome: %s", professor[i].nome);
		printf("\n\nSalario Bruto: %f", salarioBruto);
		printf("\n\nSalario Liquido: %f", salarioLiquido);
		
	}
	
	media = somaSalario / contadorFeminino;
	
	printf("\nmedia dos salarios feminino: %f",media);
}


int main()
{
	struct cadastro professor[20];
	int quant = 0;
	
	quant =  cadastrarProfessor(professor, quant);
	calculo(professor, quant);
	return 0;
}