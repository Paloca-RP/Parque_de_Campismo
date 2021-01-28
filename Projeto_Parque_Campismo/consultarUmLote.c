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

//ESTA FUNÇÃO VAI BUSCAR OS DADOS ATUAIS DO LOTE SELECIONADO PELO UTILIZADOR
// (TODOS OS DADOS RELATIVOS A RESERVA ATUAL)
void consultarUmLote(Lote mapaLotes[][NUMCOLUNAS]){

		int linha, coluna;
		//mostraMapaDeLotes();
		 upa:
			printf("\nInsira as posiçoes:\n");
			linnhas:
			printf("Insira a linha: ");
				scanf("%d", &linha);
            if(linha <= 0 || linha > NUMLINHAS)
            {
                  printf("Numero de Linha INVALIDO");
                    goto linnhas;
            }
            else
            {
                linha--;
                coluna:
                printf("Insira a coluna: ");
                    scanf("%d", &coluna);
                    if(coluna <= 0 || coluna > NUMCOLUNAS)
                    {
                        printf("Numero de Coluna errado");
                        goto coluna;
                    }
                    else
                    {
                        coluna--;
                    }
            }

			int numeroCampistas = mapaLotes[linha][coluna].nCamp;

            if(mapaLotes[linha][coluna].nCamp == 0){
                 printf("Lote não tem dados");
                getch();
                system("cls");
                goto upa;
            }

            else{
                printf("DADOS DO LOTE: %d %d\n", linha, coluna);
                printf("---------------------------------------\n");
                printf("|Dias de Alojamento:          %d  \n", mapaLotes[linha][coluna].diasAlojamento);
                printf("|Taxa a pagar pela reserva:   %.2f \n", mapaLotes[linha][coluna].taxaPagar);
                printf("|Numero de Campistas no lote: %d \n", mapaLotes[linha][coluna].nCamp);
                printf("---------------------------------------\n");

                for(int i=0; i<numeroCampistas; i++)
                {
                    printf("------------------------------|");
                    printf("\n|DADOS DO CAMPISTA %d\n", i+1);
                    printf("|NOME :  %s\n",mapaLotes[linha][coluna].campistas[i].nome);
                    printf("|IDADE : %d\n",mapaLotes[linha][coluna].campistas[i].idade);
                    printf("|NIF :   %d\n",mapaLotes[linha][coluna].campistas[i].nif);
                    printf("|CC:     %d \n",mapaLotes[linha][coluna].campistas[i].cc);
                    printf("|-----------------------");
                }
            }
		getch();
	}
