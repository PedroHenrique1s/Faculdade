#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
    // Variáveis declaradas

    const int ano = 2010;
    const float valormedia = 15000;

    char nomeCarro[50];
    int anoCarro;
    float valor;
    char marca, corCarro, combust;

    int anoNovo = 30000, anoVelho = 0;
    int anoNovoChevrolet = 30000, anoVelhoChevrolet = 0;
    int anoNovoFiat = 30000, anoVelhoFiat = 0;
    int anoNovoVolks = 30000, anoVelhoVolks = 0;

    float maisBarato = 100000000, maisCaro = 0, somaValor = 0;
    float maisBaratoChevrolet = 100000000, maisCaroChevrolet = 0;
    float maisBaratoVolks = 100000000, maisCaroVolks = 0;
    float maisBaratoFiat = 100000000, maisCaroFiat = 0;

    int contador_geral = 0, contChevrolet = 0, contVolks = 0, contFiat = 0;
    int contBranco = 0, contPreto = 0, contVermelho = 0;
    int contcombust_Alcool = 0, contcombust_Gasolina = 0, contcombust_Diesel = 0, contcombust_Eletrico = 0;
    int cont_precoC = 0, cont_precoV = 0, cont_precoF = 0;
    int cont2010_Chevrolet = 0, cont2010_Volks = 0, cont2010_Fiat = 0;

    printf("\n***Programa Concessionaria Carro do Ano***\n");

    printf("\nDigite o valor do carro ou digite 0 para finalizar o programa R$: ");
    fflush(stdin);
    scanf("%f", &valor);

    while (valor > 0) {
        // Marca
        printf("\nEscolha o modelo que deseja\n");
        printf("\n[C]hevrolet\n[V]olkswagen\n[F]iat\n\n=> ");
        marca = getch();

        while ((marca != 'C') && (marca != 'c') && (marca != 'v') && (marca != 'V') && (marca != 'F') && (marca != 'f')) {
            printf("\nRedigite a marca novamente: ");
            fflush(stdin);
            marca = getch();
        }

        // Combustivel
        printf("Escolha o combustivel que deseja\n");
        printf("\n[A]lcool\n[G]asolina\n[D]iesel\n[E]letrico\n\n=> ");
        combust = getch();

        while ((combust != 'A') && (combust != 'a') && (combust != 'G') && (combust != 'g') && (combust != 'D') && (combust != 'd') && (combust != 'E') && (combust != 'e')) {
            printf("\nRedigite o combustivel novamente: ");
            fflush(stdin);
            combust = getch();
        }

        // Cor do carro
        printf("Escolha a cor que deseja\n");
        printf("\n[P]reto\n[B]ranco\n[V]ermelho\n\n=> ");
        corCarro = getch();

        while ((corCarro != 'P') && (corCarro != 'p') && (corCarro != 'B') && (corCarro != 'b') && (corCarro != 'V') && (corCarro != 'v')) {
            printf("\nRedigite a cor novamente: ");
            fflush(stdin);
            corCarro = getch();
        }

        // Nome do carro
        printf("\nEscreva o nome do carro: ");
        fflush(stdin);
        gets(nomeCarro);

        // Ano do carro
        printf("\nDigite o ano do carro: ");
        scanf("%d", &anoCarro);

        // Processamento geral
        contador_geral++;

        // Média de valores
        somaValor = valor + somaValor;

        // Carros em geral de ano mais novo e mais velho
        if (anoCarro > anoVelho) {
            anoVelho = anoCarro;
        }

        if (anoCarro < anoNovo) {
            anoNovo = anoCarro;
        }

        // Carros em geral mais barato e mais caro
        if (valor > maisCaro) {
            maisCaro = valor;
        }

        if (valor < maisBarato) {
            maisBarato = valor;
        }

        // Processamento Chevrolet
        if ((marca == 'C') || (marca == 'c')) {
            contChevrolet++;

            // Carro mais barato e mais caro da Chevrolet
            if (valor > maisCaroChevrolet) {
                maisCaroChevrolet = valor;
            }

            if (valor < maisBaratoChevrolet) {
                maisBaratoChevrolet = valor;
            }

            // Carro mais novo e velho da Chevrolet
            if (anoCarro > anoVelhoChevrolet) {
                anoVelhoChevrolet = anoCarro;
            }

            if (anoCarro < anoNovoChevrolet) {
                anoNovoChevrolet = anoCarro;
            }

            if (anoCarro > ano) {
                cont2010_Chevrolet++;
            }

            // Carros acima de 15 mil da Chevrolet
            if (valor > valormedia) {
                cont_precoC++;
            }
        } else if ((marca == 'V') || (marca == 'v')) {
            contVolks++;

            // Carro mais barato e mais caro da Volkswagen
            if (valor > maisCaroVolks) {
                maisCaroVolks = valor;
            }

            if (valor < maisBaratoVolks) {
                maisBaratoVolks = valor;
            }

            // Carro mais novo e mais velho da Volkswagen
            if (anoCarro > anoVelhoVolks) {
                anoVelhoVolks = anoCarro;
            }

            if (anoCarro < anoNovoVolks) {
                anoNovoVolks = anoCarro;
            }

            // Carro acima de 2010 da Volkswagen
            if (anoCarro > ano) {
                cont2010_Volks++;
            }

            // Carros acima de 15 mil da Volkswagen
            if (valor > valormedia) {
                cont_precoV++;
            }
        } else if ((marca == 'F') || (marca == 'f')) {
            contFiat++;

            // Carro mais caro e mais barato da Fiat
            if (valor > maisCaroFiat) {
                maisCaroFiat = valor;
            }

            if (valor < maisBaratoFiat) {
                maisBaratoFiat = valor;
            }

            // Carro Fiat mais velho e mais novo
            if (anoCarro > anoVelhoFiat) {
                anoVelhoFiat = anoCarro;
            }

            if (anoCarro < anoNovoFiat) {
                anoNovoFiat = anoCarro;
            }

            // Carro acima de 2010 da Fiat
            if (anoCarro > ano) {
                cont2010_Fiat++;
            }

            // Carros acima de 15 mil da Fiat
            if (valor > valormedia) {
                cont_precoF++;
            }
        } else {
            printf("Caracter invalido\n");
        }

        // Processamento combustivel
        if ((combust == 'A') || (combust == 'a')) {
            contcombust_Alcool++;
        } else if ((combust == 'G') || (combust == 'g')) {
            contcombust_Gasolina++;
        } else if ((combust == 'D') || (combust == 'd')) {
            contcombust_Diesel++;
        } else if ((combust == 'E') || (combust == 'e')) {
            contcombust_Eletrico++;
        } else {
            printf("Caracter invalido\n");
        }

        // Processamento cor do Carro
        if ((corCarro == 'B') || (corCarro == 'b')) {
            contBranco++;
        } else if ((corCarro == 'P') || (corCarro == 'p')) {
            contPreto++;
        } else if ((corCarro == 'V') || (corCarro == 'v')) {
            contVermelho++;
        } else {
            printf("Caracter invalido\n");
        }

        // Fim do while
        system("cls");
        printf("\n***Programa Concessionaria Carro do Ano***\n");
        printf("\nDigite o valor do carro ou digite 0 para finalizar o programa R$: ");
        scanf("%f", &valor);
    }

    printf("\n\n---Dados Processados---");
    printf("\nCarro mais novo: %d", anoNovo);
    printf("\nCarro mais velho: %d", anoVelho);

    printf("\n\nCarro mais novo Chevrolet: %d", anoNovoChevrolet);
    printf("\nCarro mais velho Chevrolet: %d", anoVelhoChevrolet);

    printf("\n\nCarro mais novo Volkswagen: %d", anoNovoVolks);
    printf("\nCarro mais velho Volkswagen: %d", anoVelhoVolks);

    printf("\n\nCarro mais novo Fiat: %d", anoNovoFiat);
    printf("\nCarro mais velho Fiat: %d", anoVelhoFiat);
    
	printf("\n\nCarro mais caro: %f", maisCaro);
    printf("\nCarro mais barato: %f", maisBarato);
    
    printf("\n\nCarro mais Caro da Chevrolet: %.2f", maisCaroChevrolet);
    printf("\nCarro mais Barato da Chevrolet: %.2f", maisBaratoChevrolet);
    
    printf("\n\nCarro mais Caro da Volkswagen: %.2f", maisCaroVolks);
    printf("\nCarro mais Barato da Volkswagen: %.2f", maisBaratoVolks);
    
    printf("\n\nCarro mais Caro da Fiat: %.2f", maisCaroFiat);
    printf("\nCarro mais Barato da Fiat: %.2f", maisBaratoFiat);

    printf("\n\nMedia de cores branco: %.2f %%", (contBranco * 100.0) / contador_geral);
    printf("\nMedia de cores preto: %.2f %%", (contPreto * 100.0) / contador_geral);
    printf("\nMedia de cores vermelho: %.2f %%", (contVermelho * 100.0) / contador_geral);

    printf("\nMedia de preco dos carros: %.2f", somaValor / contador_geral);

    printf("\n\nMedia de carros da Chevrolet: %.2f %% ", (contChevrolet * 100.0) / contador_geral);
    printf("\nMedia de carros da Volkswagen: %.2f %%", (contVolks * 100.0) / contador_geral);
    printf("\nMedia de carros da Fiat: %.2f %%", (contFiat * 100.0) / contador_geral);

    printf("\n\nQuantidade de carros a alcool: %d", contcombust_Alcool);
    printf("\nQuantidade de carros a gasolina: %d", contcombust_Gasolina);
    printf("\nQuantidade de carros a diesel: %d", contcombust_Diesel);
    printf("\nQuantidade de carros eletricos: %d", contcombust_Eletrico);

    printf("\n\nCarros acima do ano de 2010 da Chevrolet: %d", cont2010_Chevrolet);
    printf("\nCarros acima do ano de 2010 da Volkswagen: %d", cont2010_Volks);
    printf("\nCarros acima do ano de 2010 da Fiat: %d", cont2010_Fiat);

    printf("\n\nMedia de carros acima de 15 mil da Chevrolet: %.2f %%", (cont_precoC * 100.0) / contChevrolet);
    printf("\nMedia de carros acima de 15 mil da Volkswagen: %.2f %%", (cont_precoV * 100.0) / contVolks);
    printf("\nMedia de carros acima de 15 mil da Fiat: %.2f %%", (cont_precoF * 100.0) / contFiat);
    


    return 0;
}
