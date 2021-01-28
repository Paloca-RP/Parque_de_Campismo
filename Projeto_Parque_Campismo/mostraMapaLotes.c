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
////////////////////////////////////

	void mostraMapaDeLotes(Lote mapaLotes[][NUMCOLUNAS]){

	    printf("\nMAPA DE LOTES\n");
		int i,j;



	   for ( i=0; i<5; i++ )
	   {
		    for ( j=0; j<5; j++ )
		    {
		    	if(mapaLotes[i][j].nCamp == 0 )
                {
                    printf("...\n");
                }
		    	else
                    printf("%c%c%d \n", mapaLotes[i][j].tipoAlojamento,mapaLotes[i][j].energy, mapaLotes[i][j].nCamp);
		    }
		}

		//############################################
	  printf("************* Lotes ************* \n\n");
	  printf("   |  1  |  2  |  3  |  4  |  5  \n");

	  for ( i=0; i<NUMLINHAS; i++)
	  {
	    printf("%d -",i+1);
		    for ( j=0; j < NUMLINHAS; j++ )
		    {
		        if(mapaLotes[i][j].nCamp == 0 )
                {
                    printf("...");
                }
		      printf ("|%c%c%d \n",mapaLotes[i][j].tipoAlojamento,mapaLotes[i][j].energy, mapaLotes[i][j].nCamp);
		    }
		    printf("\n");
	  }
	  printf("Pressione uma tecla para voltar ao menu");
	  getch();
}
