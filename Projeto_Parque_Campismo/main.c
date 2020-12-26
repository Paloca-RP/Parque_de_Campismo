#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define NUMLINHAS 5
#define NUMCOLUNAS 5

struct clientes{
    char nome[100];
    int idade;
};

char mapaLotes[NUMLINHAS][NUMCOLUNAS];

void reservarUmLote(nome, idade)
{
	clientes nome[100];
nome
	printf("insira o nome:  ");
		gets(nome1);
	printf("insira idade: ");
		scanf("%d", &idade1);
		
	printf(" %c, %d", nome, idade);
}

void consultarUmLote()
{

}

void mostraMapaDeLotes()
{
	char x[10];
	printf("insira um numero:   ");
	scanf("%s", &x);
	mapaLotes[0][0] = x;
	
    printf("----1----2----3----4--------------\n");
    printf("1|%c    |%c    |%c    |%c    |\n", mapaLotes[0][0], mapaLotes[0][1], mapaLotes[0][2], mapaLotes[0][3], mapaLotes[0][4]);
    printf("2|%c    |%c    |%c    |%c    |\n", mapaLotes[1][0], mapaLotes[1][1], mapaLotes[1][2], mapaLotes[1][3], mapaLotes[1][4]);
    printf("3|%c    |%c    |%c    |%c    |\n", mapaLotes[2][0], mapaLotes[2][1], mapaLotes[2][2], mapaLotes[2][3], mapaLotes[2][4]);
    printf("4|%c    |%c    |%c    |%c    |\n", mapaLotes[3][0], mapaLotes[3][1], mapaLotes[3][2], mapaLotes[3][3], mapaLotes[3][4]);
    printf("5|%c    |%c    |%c    |%c    |\n", mapaLotes[4][0], mapaLotes[4][1], mapaLotes[4][2], mapaLotes[4][3], mapaLotes[4][4]);


    int op;
    printf("PRETENDE SAIR DESTE MENU? SE SIM CLIQUE NA TECLA '0' : ");
    scanf("%d", &op);

   switch(op)
   {
	    case 0:
		    system("cls");
		    main();
	    break;
        
		default:
        	printf("OPCAO INVALIDA! TENTE NOVAMENTE");
        break;
   }
}

//PAGINA DO MENU CENTRAL
int main()
{
    fflush(stdin);
	setlocale(LC_ALL, "Portuguese");
    int menu;
    do
    {
	printf("  #-----------------------------------#\n");
	printf("  #   Gestao de Parque de Campismo    #\n");
	printf("  #-----------------------------------#\n");
	printf("  #   1- Ver mapa de lotes            #\n");
	printf("  #   2- Reservar um lote             #\n");
	printf("  #   3- Consultar um lote            #\n");
	printf("  #   4- Pesquisar lote por campista  #\n");
	printf("  #   5- Editar um lote reservado     #\n");
	printf("  #   6- Libertar um lote             #\n");
	printf("  #   7- Sair                         #\n");
    printf("  #-----------------------------------#\n");
    printf("Insira uma opçao que pretende:  ");
	scanf("%d", &menu);

    switch(menu)
    {
    case 1:
        system("cls");
        mostraMapaDeLotes();
        break;
    case 2:
        system("cls");
        reservarUmLote();
        break;
    case 3:
        system("cls");
        consultarUmLote();
        break;

    }


}while (menu != 7);
}
