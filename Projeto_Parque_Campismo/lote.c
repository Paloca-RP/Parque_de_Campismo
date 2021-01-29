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

////////////////////////////////////
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

    void editarLote(Lote mapaLotes[][NUMCOLUNAS]){
        int linha, coluna;

        mostraMapaDeLotes();
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
                 system("cls");
                printf("--------------------------------------------------------------------------------------\n");
                printf("LEGENDA: T-TENDA, A-AUTOCARAVANA, C-CARAVANA, X-SEM ELETRICIDADE, E- COM ELETRICIDADE\n");
                printf("--------------------------------------------------------------------------------------\n");
                 printf("DADOS DO LOTE: %d %d\n", linha+1, coluna+1);
                printf("--------------------------------------------------------------------------------------\n");
                printf("Dias de Alojamento:          %d    \n", mapaLotes[linha][coluna].diasAlojamento);
                printf("tTaxa a pagar pela reserva:  %.2f  \n", mapaLotes[linha][coluna].taxaPagar);
                printf("Numero de Campistas no lote: %d    \n", mapaLotes[linha][coluna].nCamp);
                printf("Tipo de Alojamento:          %c    \n", mapaLotes[linha][coluna].tipoAlojamento);
                printf("Ligado a rede El�trica?:     %c    \n", mapaLotes[linha][coluna].energy);
                printf("----------------------------------------------------------------------------------------\n");

                    printf("---DADOS-GUARDADOS-DOS-CAMPISTAS-----------\n");

                for(int i=0; i<numeroCampistas; i++)
                {
                    printf("CAMPISTA: %d \n", i+1);
                    printf("NOME :    %s \n",mapaLotes[linha][coluna].campistas[i].nome);
                    printf("IDADE :   %d \n", mapaLotes[linha][coluna].campistas[i].idade);
                    printf("NIF :     %d \n", mapaLotes[linha][coluna].campistas[i].nif);
                    printf("CC :      %d \n",  mapaLotes[linha][coluna].campistas[i].cc);
                    printf("---------------------\n");
                }
            }

            int op;
            printf("|------EDIÇÃO DO LOTE-----|\n");
            printf("|O QUE QUER ALTERAR?      |\n");
            printf("|1-DADOS DO LOTE          |\n");
            printf("|2-DADOS DOS CAMPISTAS    |\n");
            printf("|3-ADICIONAR NOVO CAMPISTA|\n");
            printf("|4-REMOVER CAMPISTA       |\n");
            printf("|5-SAIR                   |\n");
            printf("|-------------------------|\n");
            printf("INSIRA UMA OPCAO:");
            scanf("%d", &op);

            int numeroCampista;
            int i;
            char temEletridade, tipoAlojamento;
            switch(op)
            {
                case 1:
                          do{
                    printf("\nTEM ELETRICIDADE?: [S]IM OU [N]AO");
                    scanf(" %c", &temEletridade);
                    }while(temEletridade != 's' && temEletridade !='S' && temEletridade != 'N' && temEletridade !='n' );

                    if (temEletridade == 's' || temEletridade == 'S')
                    {
                        mapaLotes[linha][coluna].energy = 'e';
                    }
                    else{
                        mapaLotes[linha][coluna].tipoAlojamento = 'x';
                    }

                    do{
                            printf("\nINSIRA O TIPO DE ALOJAMENTO: [T]ENDA , [C]ARAVANA OU [A]UTOCARAVANA\n ");
                            scanf(" %c", &temEletridade);
                    }while(tipoAlojamento != 'T' && tipoAlojamento != 'C' && tipoAlojamento != 'A' && tipoAlojamento != 't' && tipoAlojamento != 'c' && temEletridade != 'a');

                    if (tipoAlojamento == 'T' || tipoAlojamento == 't')
                    {
                        mapaLotes[linha][coluna].tipoAlojamento = 'T';
                    }
                    else if (tipoAlojamento == 'C' || tipoAlojamento =='c')
                    {
                        mapaLotes[linha][coluna].tipoAlojamento = 'C';
                    }
                    else if (tipoAlojamento == 'A' || tipoAlojamento == 'a')
                    {
                        mapaLotes[linha][coluna].tipoAlojamento = 'A';
                    }
                break;
                case 2:
                        printf("Qual O numero Do campista que quer alterar?");
                        scanf(" %d", &numeroCampista);
                        numeroCampista--;
                        fflush(stdin);
                        printf("NOME: ");
                        gets(mapaLotes[linha][coluna].campistas[numeroCampista].nome);
                        printf("IDADE");
                        scanf(" %d", &mapaLotes[linha][coluna].campistas[numeroCampista].idade);
                        printf("NIF");
                        scanf("%d", &mapaLotes[linha][coluna].campistas[numeroCampista].nif);
                        printf("CC");
                        scanf(" %d", &mapaLotes[linha][coluna].campistas[numeroCampista].cc);
                        printf("Alteracoes Salvas Com Sucesso!!");
                    break;
                case 3:
                    if (mapaLotes[linha][coluna].nCamp >= 6)
                    {
                        printf("LOTE CHEIO, NÃO É POSSIVEL ADICIONAR NOVO CAMPISTA");
                    }
                    else{
                        int indice = mapaLotes[linha][coluna].nCamp;
                        mapaLotes[linha][coluna].nCamp = indice+1;
                        fflush(stdin);
                        printf("NOME: ");
                        gets(mapaLotes[linha][coluna].campistas[indice].nome);
                        printf("IDADE:");
                        scanf(" %d", &mapaLotes[linha][coluna].campistas[indice].idade);
                        printf("NIF:");
                        scanf("%d", &mapaLotes[linha][coluna].campistas[indice].nif);
                        printf("CC:");
                        scanf(" %d", &mapaLotes[linha][coluna].campistas[indice].cc);
                        printf("CAMPISTA ADICIONADO COM SUCESSO!");
                    }
                break;
                case 4:
                     printf("INSERIR O NUMERO DE CAMPISTA A REMOVER:");
                        scanf("%d", &numeroCampista);
                        numeroCampista--;

                        for (i=numeroCampista; i<6; i++)
                        {
                            mapaLotes[linha][coluna].campistas[i].cc = mapaLotes[linha][coluna].campistas[i+1].cc;
                            mapaLotes[linha][coluna].campistas[i].idade = mapaLotes[linha][coluna].campistas[i+1].idade;
                            mapaLotes[linha][coluna].campistas[i].nif = mapaLotes[linha][coluna].campistas[i+1].nif;
                            strcpy(mapaLotes[linha][coluna].campistas[i].nome, mapaLotes[linha][coluna].campistas[i+1].nome);
                        }
                        printf("CAMPISTA REMOVIDO");
                    break;
                default: getch();
            }
            fflush(stdin);
            printf("A Voltar Para o meu principal!!!");
            system("pause");
            getch();
}

void libertarLote( Lote mapaLotes[][NUMCOLUNAS]){
        int linha, coluna;
        mostraMapaDeLotes(&mapaLotes);
        printf("INSIRA A ZONA DO PARQUE QUE QUER ALOJAR: [NR_RUA][NR LOTE]");
	    scanf("%d", &linha);scanf("%d", &coluna);
        linha--;
        coluna--;
        mapaLotes[linha][coluna].nCamp = 0;
        printf("Lote está livre");

}

