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

char mapaLotes2[NUMLINHAS][NUMCOLUNAS][TAMANHO_STRING];

struct clientes{
    char nome[TAMANHO_NOME];
    char apelido[TAMANHO_NOME];
    int idade;
    int rua;
    int lote;
};

struct detalhesReserva{

    char TipoAlojamento;
    char nomeCampista[TAMANHO_NOME];
    char apelidoCampista[TAMANHO_NOME];
    char loteAlojado;
    float taxaPagar;

};

/////////////////////////////////////////////////////////////////////////////

	void reservarUmLote(){

	    fflush(stdin);
	    struct clientes dadosClientes;
	    struct detalhesReserva detalhesReserva;

	    int numeroCampistas, contaCampistas=0, indiceNome=0, linha = 0, coluna = 0, diasAlojamento;
	    float somaTaxa=0;
	    char tarifaUsada, tarifaUsada2;

        //Aqui começa a inserção dos dados da reserva
	    printf("INSIRA A ZONA DO PARQUE QUE QUER ALOJAR: [NR_RUA][NR LOTE]");
	    scanf("%d", &linha);scanf("d", &coluna);

        mapaLotes2[linha][coluna];

	    do{
		    printf("\nINSIRA O NUMERO DE CAMPISTAS: ");
		    scanf(" %d", &numeroCampistas);
	    }while(numeroCampistas <=0);

	    do{
		    printf("DIAS DE ALOJAMENTO: ");
		    scanf(" %d", &diasAlojamento);
	    }while(diasAlojamento<=0);

	    do{
		    printf("\nTEM ELETRICIDADE?: [S]IM OU [N]AO");
		    scanf(" %c", &tarifaUsada2);
        }while(tarifaUsada2 != 's' && tarifaUsada2 !='S' && tarifaUsada2 != 'N' && tarifaUsada2 !='n' );

	    if (tarifaUsada2 == 's' || tarifaUsada2 == 'S')
	    {
	        somaTaxa += ELETRICIDADE;
	    }

        do{
		    printf("\nINSIRA O TIPO DE ALOJAMENTO: [T]ENDA , [C]ARAVANA OU [A]UTOCARAVANA\n ");
		    scanf(" %c", &tarifaUsada);
        }while(tarifaUsada != 'T' && tarifaUsada != 'C' && tarifaUsada != 'A' && tarifaUsada != 't' && tarifaUsada != 'c' && tarifaUsada != 'a');

	    if (tarifaUsada == 'T' || tarifaUsada == 't')
	    {
	        somaTaxa += TENDA;
	    }
	    else if (tarifaUsada == 'C' || tarifaUsada =='c')
	    {
	        somaTaxa+= CARAVANA;
	    }
	    else if (tarifaUsada == 'A' || tarifaUsada == 'a')
	    {
	        somaTaxa += AUTOCARAVANA;
	    }

		    somaTaxa = somaTaxa*diasAlojamento+(numeroCampistas*CAMPISTAS);
		    detalhesReserva.taxaPagar= somaTaxa;

			printf("O TOTAL A PAGAR DA RESERVA É DE %.2f EUROS", somaTaxa);
			char nome2[50];
	    do
	    {
	        fflush(stdin);
	        printf("\nINSERIR PRIMEIRO NOME DO CLIENTE: ");
			gets(nome2);
			printf("\nINSERIR APELIDO DO CLIENTE: ");
			gets(dadosClientes.apelido);
	        printf("\nINSERIR IDADE DO CLIENTE: ");
			scanf(" %d",&dadosClientes.idade);

			contaCampistas++;
			indiceNome++;
	    } while(contaCampistas != numeroCampistas);

	    //GRAVA�AO DOS DADOS DO CLIENTE NO FICHEIRO
	    FILE *ficheiro;
 	    ficheiro = fopen(nome2, "w");
	    //fprintf(ficheiro, "%s\n%s\n%.2f\n%2c\n%c\n%d\n%d", nome2,dadosClientes.apelido, somaTaxa, tarifaUsada2, tarifaUsada, linha,coluna);
		fprintf(ficheiro, "Nome : %s , Apelido : %s , Total : %.2f , Electricidade : %c , Alojamento : %c , Campistas : %d , Linha : %d , Coluna : %d ",nome2, dadosClientes.apelido, somaTaxa, tarifaUsada2, tarifaUsada, numeroCampistas, linha, coluna);
	    fclose(ficheiro);

	    //FICA A FALTAR CRIAR O FICHEIRO PARA O LOTE
	}

/////////////////////////////////////////////////////////////////////////////

	void mostraMapaDeLotes(){

	    printf("\nMAPA DE LOTES\n");
		int i,j;

	   for ( i=0; i<5; i++ )
	   {
		    for ( j=0; j<5; j++ )
		    {
		    	strcpy(mapaLotes2[i][j], "...");
		    }
		}
		//############################################ TESTES
		{
			strcpy(mapaLotes2[0][0], "tx1");
			strcpy(mapaLotes2[0][1], "tx1");
			strcpy(mapaLotes2[0][2], "tx1");
			strcpy(mapaLotes2[0][3], "tx1");
			strcpy(mapaLotes2[0][4], "tx1");

			strcpy(mapaLotes2[1][0], "tx1");
			strcpy(mapaLotes2[1][1], "tx1");
			strcpy(mapaLotes2[1][2], "tx1");
			strcpy(mapaLotes2[1][3], "tx1");
			strcpy(mapaLotes2[1][4], "tx1");

			strcpy(mapaLotes2[2][0], "tx1");
			strcpy(mapaLotes2[2][1], "tx1");
			strcpy(mapaLotes2[2][2], "tx1");
			strcpy(mapaLotes2[2][3], "tx1");
			strcpy(mapaLotes2[2][4], "tx1");

			strcpy(mapaLotes2[3][0], "tx1");
			strcpy(mapaLotes2[3][1], "tx1");
			strcpy(mapaLotes2[3][2], "tx1");
			strcpy(mapaLotes2[3][3], "tx1");
			strcpy(mapaLotes2[3][4], "tx1");

			strcpy(mapaLotes2[4][0], "tx1");
			strcpy(mapaLotes2[4][1], "tx1");
			strcpy(mapaLotes2[4][2], "tx1");
			strcpy(mapaLotes2[4][3], "tx1");
			strcpy(mapaLotes2[4][4], "tx1");}
		//############################################
	  printf("************* Lotes ************* \n\n");
	  printf("   |  1  |  2  |  3  |  4  |  5  \n");

	  for ( i=0; i<NUMLINHAS; i++)
	  {
	    printf("%d -",i+1);
		    for ( j=0; j < NUMLINHAS; j++ )
		    {
		      printf ("| %s ",mapaLotes2[ i ][ j ]);
		    }
		    printf("\n");
	  }
	  printf("Pressione uma tecla para voltar ao menu");
	  getch();
	}

/////////////////////////////////////////////////////////////////////////////

	void consultarUmLote(){

		int linha, coluna;
		mostraMapaDeLotes();
			printf("\nInsira as posiçoes:\n");
			printf("Insira a linha: ");
				scanf("%d", &linha);
			linha--;
			printf("Insira a coluna: ");
				scanf("%d", &coluna);
			coluna--;

		printf(" %s ", mapaLotes2[linha][coluna]);

		getch();
		printf("ola");
	}

/////////////////////////////////////////////////////////////////////////////

	void consultarPorCampista(){

		//nome do campista
		char nomeficheiro[50];
		printf("Inisra o nome do Campista: ");
		scanf("%s", nomeficheiro);

	//variaveis de Transicaoo de ficheiro para o programa
		char nome[100];
	    char apelido[100];
	    int numcampistas;
		float somaTaxa;
		char tarifaUsada2;
		char tarifaUsada;
		int linha1;
		int coluna1;

		FILE *fp;
		fp = fopen(nomeficheiro,"r");

		if(fp != NULL){

			fscanf(fp, "Nome : %s , Apelido : %s , Total : %.2f , Electricidade : %c , Alojamento : %c , Campistas : %d , Linha : %d , Coluna : %d ", nome, apelido, &somaTaxa, tarifaUsada2, tarifaUsada, &numcampistas, &linha1, &coluna1 );

			printf("Nome: %s\n", nome );
			printf("Apelido: %s\n", apelido );
			printf("Numero de campistas: %d\n",numcampistas );
			printf("Total da Reserva: %.2f\n", somaTaxa );
			printf("Electricidade: %c\n", tarifaUsada2 );
			printf("Alojamento: %c\n", tarifaUsada );
			printf("Linha: %d\n", linha1 );
			printf("Coluna: %d\n", coluna1 );

		    fclose(fp);
		}
		else{
		    printf("Campista n�o existe");
		}
        getch();
	}

/////////////////////////////////////////////////////////////////////////////

	//PAGINA DO MENU CENTRAL
	int main()
	{
	    fflush(stdin);
		setlocale(LC_ALL, "Portuguese");
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
			    case 4:
			    	system("cls");
			    	consultarPorCampista();
			    	break;

		    }
	} while (menu != 7);
	return 0;
	}


