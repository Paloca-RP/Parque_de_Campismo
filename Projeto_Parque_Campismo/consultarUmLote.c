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

//ESTA FUNÇÃO VAI BUSCAR OS DADOS ATUAIS DO LOTE (TODOS OS DADOS RELATIVOS A RESERVA ATUAL)
void consultarUmLote(Lote mapaLotes[][NUMCOLUNAS]){

		int linha, coluna;
		//mostraMapaDeLotes();
			printf("\nInsira as posiçoes:\n");
			printf("Insira a linha: ");
				scanf("%d", &linha);
			linha--;
			printf("Insira a coluna: ");
				scanf("%d", &coluna);
			coluna--;
			int numeroCampistas = mapaLotes[linha][coluna].nCamp;

                printf("DADOS DO LOTE: %d %d\n", linha, coluna);
                printf("---------------------------------------|");
                printf("|\nDias de Alojamento:           %d    |\n", mapaLotes[linha][coluna].diasAlojamento);
                printf("|Taxa a pagar pela reserva:      %f    |\n", mapaLotes[linha][coluna].taxaPagar);
                printf("|Numero de Campistas no lote     %d:   |\n", mapaLotes[linha][coluna].nCamp);
                printf("---------------------------------------|");

			for(int i=0; i<numeroCampistas; i++)
            {
                printf("------------------------------|");
                printf("|DADOS DO CAMPISTA %d         |\n", i+1);
                printf("|NOME : %s                    |\n",mapaLotes[linha][coluna].campistas[i].nome);
                printf("|IDADE : %d                   |\n",mapaLotes[linha][coluna].campistas[i].idade);
                printf("|NIF : %d                     |\n",mapaLotes[linha][coluna].campistas[i].nif);
                printf("|CC: %d                       |\n",mapaLotes[linha][coluna].campistas[i].cc);
                printf("------------------------------|");
            }
		getch();
	}
