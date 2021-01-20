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
