#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

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


void consultarUmLote(){

		int linha, coluna;
		//mostraMapaDeLotes();
			printf("\nInsira as posiçoes:\n");
			printf("Insira a linha: ");
				scanf("%d", &linha);
			linha--;
			printf("Insira a coluna: ");
				scanf("%d", &coluna);
			coluna--;

		getch();
		printf("ola");
	}

