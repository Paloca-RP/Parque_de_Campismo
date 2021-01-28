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
////////////////////////////////////

	void mostraMapaDeLotes(char mapaLotes[NUMLINHAS][NUMCOLUNAS]){

	    printf("\nMAPA DE LOTES\n");
		int i,j;

	   for ( i=0; i<5; i++ )
	   {
		    for ( j=0; j<5; j++ )
		    {
		    	strcpy(mapaLotes[i][j], "...");
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
		      printf ("| %s ",mapaLotes[ i ][ j ]);
		    }
		    printf("\n");
	  }
	  printf("Pressione uma tecla para voltar ao menu");
	  getch();
}
