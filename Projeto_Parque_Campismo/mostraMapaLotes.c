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
//FUNCAO RESPONSAVEL PARA MOSTRAR O MAPA DE LOTES
//VAI SER MOSTRADO AO UTILIZADOR OS TIPOS DE ALOJAMENTO
//SE TEM LIGACAO A REDE ELETRICA E O NUMERO DE CAMPISTAS NO LOTE

 void mostraMapaDeLotes(Lote mapaLotes[][NUMCOLUNAS]){

        printf("\nMAPA DE LOTES\n");
        int i,j;

        //############################################
      printf("\t\t\t************* Lotes ************* \n\n");
      printf("\t 1\t|\t 2\t|\t 3\t|\t 4\t|\t 5\t|\n");

      for ( i=0; i<NUMLINHAS; i++)
      {
        printf("%d -",i+1);
            for ( j=0; j < NUMLINHAS; j++ )
            {
                if(mapaLotes[i][j].nCamp == 0 )
                {
                    printf("\t...\t|");
                }
                else
                    printf ("\t%c%c%d\t|",mapaLotes[i][j].tipoAlojamento,mapaLotes[i][j].energy, mapaLotes[i][j].nCamp);
            }
            printf("\n");
      }
      printf("Pressione qualquer tecla do seu teclado\n");
      getch();
}
