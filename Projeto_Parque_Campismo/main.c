#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#define NUMLINHAS 5
#define NUMCOLUNAS 5
#include "struct.h"
	//PAGINA DO MENU CENTRAL
	int main()
	{
	    Lote mapaLotes[NUMLINHAS][NUMCOLUNAS];
	    fflush(stdin);
		setlocale(LC_ALL, "Portuguese");
		system("color F1");
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
		    printf("Insira uma opçao que pretende:  ");
			scanf("%d", &menu);

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
			    	//consultarPorCampista();
			    	break;
                case 5:
			    	system("cls");
			    	editarLote(&mapaLotes);
			    	break;
			    case 6:
			    	system("cls");
			    	//consultarPorCampista();
			    	break;


		    }
	} while (menu != 7);
	return 0;
	}


