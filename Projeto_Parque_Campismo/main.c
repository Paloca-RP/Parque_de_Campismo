#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define NUMLINHAS 5
#define NUMCOLUNAS 5

char mapaParqueEstacionamento[NUMLINHAS][NUMCOLUNAS];

void reservarUmLote()
{

}

void consultarUmLote()
{

}

void mostraMapaDeLotes()
{
    fflush(stdin);
    int numero;
    printf("INSERIR UM NUMERO:");
    scanf("%d", &numero);
    if (numero == 0)
    {
        system("cls");
        return main();
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


} while (opcao != 7);
}


