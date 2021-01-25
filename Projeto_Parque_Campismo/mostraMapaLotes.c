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
#include "struct.h"
////////////////////////////////////

void mostraMapaDeLotes(Lote mapaLotes[][NUMCOLUNAS]){

	    printf("\nMAPA DE LOTES\n");
		int i,j;

	   for ( i=0; i<5; i++ )
	   {
		    for ( j=0; j<5; j++ )
		    {
                strcpy(mapaLotes[i][j].tipoAlojamento, "...");
		    }
		}

		{
		    mapaLotes[i][j].tipoAlojamento;
		    /*
			strcpy(mapaLotes2[0][0], "tx1");
			strcpy(mapaLotes2[0][1], "tx1");
			strcpy(mapaLotes2[0][2], "tx1");
			strcpy(mapaLotes2[0][3], "tx1");
			strcpy(mapaLotes2[0][4], "tx1");

			strcpy(mapaLotes2[1][0], "tx1");
			strcpy(mapaLotes2[1][1], "tx1");
			strcpy(mapaLotes2[1][2], "tx1");
			strcpy(mapaLotes2[1][3], "tx1");
			strcpy(mapaLotes2[1][4], "tx1");

			strcpy(mapaLotes2[2][0], "tx1");
			strcpy(mapaLotes2[2][1], "tx1");
			strcpy(mapaLotes2[2][2], "tx1");
			strcpy(mapaLotes2[2][3], "tx1");
			strcpy(mapaLotes2[2][4], "tx1");

			strcpy(mapaLotes2[3][0], "tx1");
			strcpy(mapaLotes2[3][1], "tx1");
			strcpy(mapaLotes2[3][2], "tx1");
			strcpy(mapaLotes2[3][3], "tx1");
			strcpy(mapaLotes2[3][4], "tx1");

			strcpy(mapaLotes2[4][0], "tx1");
			strcpy(mapaLotes2[4][1], "tx1");
			strcpy(mapaLotes2[4][2], "tx1");
			strcpy(mapaLotes2[4][3], "tx1");
			strcpy(mapaLotes2[4][4], "tx1")*/}
		//############################################
	  printf("************* Lotes ************* \n\n");
	  printf("   |  1  |  2  |  3  |  4  |  5  \n");

	  for ( i=0; i<NUMLINHAS; i++)
	  {
	    printf("%d -",i+1);
		    for ( j=0; j < NUMLINHAS; j++ )
		    {
		      printf ("| %s ",mapaLotes[i][j].tipoAlojamento);
		    }
		    printf("\n");
	  }
	  printf("Pressione uma tecla para voltar ao menu");
	  getch();
	}
