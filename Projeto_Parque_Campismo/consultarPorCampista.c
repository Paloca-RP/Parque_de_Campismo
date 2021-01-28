/*
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include "struct.h"

//CONSTANTES
#define NUMLINHAS 5
#define NUMCOLUNAS 5
#define TAMANHO_STRING 5

#define NUMLOTES 25
#define TAMANHO_NOME 20

//TAXAS A APLICAR
#define TENDA 4.50
#define CARAVANA 6
#define AUTOCARAVANA 14.90
#define ELETRICIDADE 3
#define CAMPISTAS 3.50

void consultarPorCampista(){

		//nome do campista
		char nomeficheiro[50];
		printf("Inisra o nome do Campista: ");
		scanf("%s", nomeficheiro);

	//variaveis de Transicaoo de ficheiro para o programa
		char nome[100];
	    char apelido[100];
	    int numcampistas;
		float somaTaxa;
		char tarifaUsada2;
		char tarifaUsada;
		int linha1;
		int coluna1;

		FILE *fp;
		fp = fopen(nomeficheiro,"r");

		if(fp != NULL){

			fscanf(fp, "Nome : %s , Apelido : %s , Total : %.2f , Electricidade : %c , Alojamento : %c , Campistas : %d , Linha : %d , Coluna : %d ", nome, apelido, &somaTaxa, tarifaUsada2, tarifaUsada, &numcampistas, &linha1, &coluna1 );

			printf("Nome: %s\n", nome );
			printf("Apelido: %s\n", apelido );
			printf("Numero de campistas: %d\n",numcampistas );
			printf("Total da Reserva: %.2f\n", somaTaxa );
			printf("Electricidade: %c\n", tarifaUsada2 );
			printf("Alojamento: %c\n", tarifaUsada );
			printf("Linha: %d\n", linha1 );
			printf("Coluna: %d\n", coluna1 );

		    fclose(fp);
		}
		else{
		    printf("Campista n�o existe");
		}
        getch();
	}
*/
