#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

#define NUMLINHAS 5
#define NUMCOLUNAS 5

#define NUMLOTES 25

#define TAMANHO_NOME 20

//TAXAS
#define TENDA 4.50
#define CARAVANA 6
#define AUTOCARAVANA 14.90
#define ELETRICIDADE 3
#define CAMPISTAS 3.50

struct clientes{
    char nome[TAMANHO_NOME];
    char apelido[TAMANHO_NOME];
    int idade;
    int rua;
    int lote;
};


char dadosReserva[NUMLINHAS*NUMCOLUNAS*6][500];

struct detalhesReserva{

    char TipoAlojamento;
    char nomeCampista[TAMANHO_NOME];
    char apelidoCampista[TAMANHO_NOME];
    char loteAlojado;
    float taxaPagar;

};
//char mapaLotes[NUMLINHAS][NUMCOLUNAS];
char mapaLotes2[NUMLINHAS][NUMCOLUNAS];

void reservarUmLote()
{
    fflush(stdin);
    struct clientes dadosClientes;
    struct detalhesReserva detalhesReserva;

    int numeroCampistas, contaCampistas=0, indiceNome=0;
    int linha, coluna, diasAlojamento;
    float somaTaxa=0;
    char tarifaUsada, tarifaUsada2;

    //printf("INSIRA A ZONA DO PARQUE QUE QUER ALOJAR: [NR_RUA][NR LOTE]");
    //scanf("%d %d", &linha, &coluna);

    do{
    printf("\nINSIRA O NUMERO DE CAMPISTAS: ");
    fflush(stdin);
    scanf(" %d", &numeroCampistas);
    }while(numeroCampistas >6 || numeroCampistas <=0);

    do{
    printf("\nTEM ELETRICIDADE?: [S]IM OU [N]AO");
    fflush(stdin);
    scanf(" %c", &tarifaUsada2);
    toupper(tarifaUsada2);
    }while(tarifaUsada2 != 'S' || tarifaUsada2 != 'N');

    if (tarifaUsada2 == 'S')
    {
        somaTaxa += ELETRICIDADE;
    }

    do{
    printf("DIAS DE ALOJAMENTO: ");
    scanf(" %d", &diasAlojamento);
    }while(diasAlojamento<=0);

    fflush(stdin);
    do{
    printf("\nINSIRA O TIPO DE ALOJAMENTO: [T]ENDA , [C]ARAVANA OU [A]UTOCARAVANA\n ");
    scanf(" %c", &tarifaUsada);
    toupper(tarifaUsada2);
    }while(tarifaUsada2 != 'T' || tarifaUsada2!= 'C' || tarifaUsada2!= 'A');

    if (tarifaUsada == 'T')
    {
        somaTaxa += TENDA;
       // mapaLotes[NUMLINHAS][NUMCOLUNAS] = 'T';
    }
    else if (tarifaUsada == 'C')
    {
        somaTaxa+= CARAVANA;
      //  mapaLotes[NUMLINHAS][NUMCOLUNAS] = 'C';

    }
    else if (tarifaUsada == 'A')
    {
        somaTaxa += AUTOCARAVANA;
      //  mapaLotes[NUMLINHAS][NUMCOLUNAS] = 'A';

    }
    fflush(stdin);
    somaTaxa = somaTaxa*diasAlojamento;
    detalhesReserva.taxaPagar= somaTaxa;

    do
    {
        fflush(stdin);
        printf("INSERIR PRIMEIRO NOME DO CLIENTE: ");
		gets(dadosClientes.nome);
		printf("\nINSERIR APELIDO DO CLIENTE: ");
		gets(dadosClientes.apelido);
        printf("\nINSERIR IDADE DO CLIENTE: ");
		scanf(" %d",&dadosClientes.idade);

		contaCampistas++;
		indiceNome++;
    }while(contaCampistas != numeroCampistas);

    printf("O TOTAL DA RESERVA É: %0.2f:", somaTaxa);

}

void consultarUmLote()
{

}

void mostraMapaDeLotes()
{
    char string1= "tx89";

    mapaLotes2[4][0] = string1;
     int linhas, colunas;


    for(linhas=0;linhas<NUMLINHAS;linhas++)
    {
        for(colunas=0; colunas<NUMCOLUNAS; colunas++)
        {
            printf("|%c|\t",mapaLotes2[linhas][colunas]);
        }
        printf("\n");
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
return 0;
}
