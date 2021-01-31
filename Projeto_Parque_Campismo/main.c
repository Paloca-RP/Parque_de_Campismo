#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#define NUMLINHAS 5
#define NUMCOLUNAS 5
#include "struct.h"

	//PAGINA DO MENU CENTRAL// ONDE ESTÁ A NAVEGAÇÃO PARA TODA A APLICAÇÃO
	int main()
	{
	    setlocale(LC_ALL, "Portuguese");

        Lote mapaLotes[NUMLINHAS][NUMCOLUNAS];
        //AQUI ESTA A SER INICIALIZADO POR DEFAULT O NUMERO DE CAMPISTAS EM CADA LOTE A 0
        //QUANDO O PROGRAMA ARRANCA
        for (int i=0; i<5; i++ )
           {
                for (int j=0; j<5; j++ )
                {
                    mapaLotes[i][j].nCamp = 0;
                }
           }
            fflush(stdin);
            int menu;
	    do
	    {
	    	system("CLS");
			printf("  |-----------------------------------|\n");
			printf("  |   Gestao de Parque de Campismo    |\n");
			printf("  |-----------------------------------|\n");
			printf("  |   1- Ver mapa de lotes            |\n");
			printf("  |   2- Reservar um lote             |\n");
			printf("  |   3- Consultar um lote            |\n");
			printf("  |   4- Pesquisar lote por campista  |\n");
			printf("  |   5- Editar um lote reservado     |\n");
			printf("  |   6- Libertar um lote             |\n");
			printf("  |   7- Sair                         |\n");
		    printf("  |-----------------------------------|\n");
		    printf("Insira uma opcao que pretende:  ");
			scanf("%d", &menu);

            //AQUI ESTAO AS LIGACOES PARA AS FUNCIONALIDADES DA APLICACAO
		    switch(menu)
		    {
			    case 1:
			        system("cls");
			        mostraMapaDeLotes(&mapaLotes);
			        break;
			    case 2:
			        system("cls");
			        reservarUmLote(&mapaLotes);
			        break;
			    case 3:
			        system("cls");
			        consultarUmLote(&mapaLotes);
			        break;
			    case 4:
			    	system("cls");
			    	consultaCampistaPeloNome(&mapaLotes);
			    	break;
                case 5:
			    	system("cls");
			    	editarLote(&mapaLotes);
			    	break;
			    case 6:
			    	system("cls");
			    	libertarLote(&mapaLotes);
			    	break;
		    }
	} while (menu != 7);
	return 0;
	}


