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
#include "struct.h"


    //Esta função vai receber todos os dados relativos á reserva
	void reservarUmLote(Lote mapaLotes[][NUMCOLUNAS]){
        setlocale(LC_ALL, "Portuguese");
	    int numeroCampistas, contaCampistas=0, indiceNome=0, linha = 0, coluna = 0, diasAlojamento;
	    float somaTaxa=0;
	    char tarifaUsada, tarifaUsada2;

	    Lote lote;

	     do{
		    printf("\nINSIRA O NUMERO DE CAMPISTAS: ");
		    scanf(" %d", &numeroCampistas);
	    }while(numeroCampistas <=0 || numeroCampistas > 6);

	    printf("INSIRA A ZONA DO PARQUE QUE QUER ALOJAR: [NR_RUA][NR LOTE]");
	    scanf("%d", &linha);scanf("%d", &coluna);

	       //DECREMENTO DO INDICE DA MATRIZ. Por exemplo se a pessoa insere 1-2 vai ser no indice 0-1 da matriz//
            linha--;
            coluna--;
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
	        lote.energy = 'e';
	    }
        else{
            lote.energy = 'x';
        }

        do{
		    printf("\nINSIRA O TIPO DE ALOJAMENTO: [T]ENDA , [C]ARAVANA OU [A]UTOCARAVANA\n ");
		    scanf(" %c", &tarifaUsada);
        }while(tarifaUsada != 'T' && tarifaUsada != 'C' && tarifaUsada != 'A' && tarifaUsada != 't' && tarifaUsada != 'c' && tarifaUsada != 'a');

	    if (tarifaUsada == 'T' || tarifaUsada == 't')
	    {
	        somaTaxa += TENDA;
	        lote.tipoAlojamento = 'T';
	    }
	    else if (tarifaUsada == 'C' || tarifaUsada =='c')
	    {
	        somaTaxa+= CARAVANA;
	        lote.tipoAlojamento = 'C';
	    }
	    else if (tarifaUsada == 'A' || tarifaUsada == 'a')
	    {
	        somaTaxa += AUTOCARAVANA;
	        lote.tipoAlojamento = 'A';
	    }

            //FORMULA PARA CALCULO DA TAXA A PAGAR
		    somaTaxa = somaTaxa*diasAlojamento+(numeroCampistas*CAMPISTAS);


		    lote.diasAlojamento = diasAlojamento;
		    lote.taxaPagar= somaTaxa;
		    lote.nCamp = numeroCampistas;

            printf("O TOTAL A PAGAR DA RESERVA É DE %.2f EUROS", somaTaxa);

            for(int i=0; i<numeroCampistas;i++)
            {
                Campista campista;

                fflush(stdin);
                printf("\nINSERIR NOME COMPLETO DO CLIENTE: ");
                gets (campista.nome);
                printf("\nINSERIR IDADE DO CLIENTE: ");
                scanf("%d", &campista.idade);
                printf("\nINSERIR NUMERO DE IDENTIFICAÇÃO CIVIL: ");
                scanf("%d", &campista.cc);
                printf("\nINSERIR NIF: ");
                scanf("%d", &campista.nif);
                lote.campistas[i] = campista;
           }

            mapaLotes[linha][coluna] = lote;

	}
