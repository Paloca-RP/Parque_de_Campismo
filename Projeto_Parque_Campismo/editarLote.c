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


void editarLote(Lote mapaLotes[][NUMCOLUNAS]){
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
                printf("\7\t------------------------------------\n");
                printf("\tDias de Alojamento:           %d    \n", mapaLotes[linha][coluna].diasAlojamento);
                printf("\tTaxa a pagar pela reserva:    %.2f    \n", mapaLotes[linha][coluna].taxaPagar);
                printf("\tNumero de Campistas no lote:  %d   \n", mapaLotes[linha][coluna].nCamp);
                printf("\t--------------------------------------\n");

                for(int i=0; i<numeroCampistas; i++)
                {
                    printf("\t---DADOS GUARDADOS---\n");
                    printf("\t  CAMPISTA: %d \n", i+1);
                    printf("\t  NOME :    %s \n",mapaLotes[linha][coluna].campistas[i].nome);
                    printf("\t  IDADE :   %d \n", mapaLotes[linha][coluna].campistas[i].idade);
                    printf("\t  NIF :     %d \n", mapaLotes[linha][coluna].campistas[i].nif);
                    printf("\t  CC :      %d \n",  mapaLotes[linha][coluna].campistas[i].cc);
                    printf("\t---------------------\n");
                }
            }
            int op;
            printf("\t|------EDIÇÃO DO LOTE-----|\n");
            printf("\t|O QUE QUER ALTERAR?      |\n");
            printf("\t|1-DADOS DO LOTE          |\n");
            printf("\t|2-DADOS DOS CAMPISTAS    |\n");
            printf("\t|3-ADICIONAR NOVO CAMPISTA|\n");
            printf("\t|3-REMOVER CAMPISTA       |\n");
            printf("\t|4-SAIR                   |\n");
            printf("\t|-------------------------|\n");
            printf("\tINSIRA UMA OPCAO:");
            scanf("%d", &op);

            int numeroCampista;
            switch(op)
            {
                case 1:
                printf("OLA");
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

                    break;
                case 3:
                    //////////////////////////////////////
                    printf("Qual a posição a excluir?");
                    int pos, *p;
                    scanf("%d", &pos);
                    pos-- ; //para ajustar aos indices que começam em 0

                    if (pos >= 0 && pos < mapaLotes[linha][coluna].nCamp){ //se a posição é valida
                     //andar todos um para trás a partir da posição a remover
                        for (int i = pos; i <  mapaLotes[linha][coluna].nCamp - 1; ++i){
                            p[i] = p[i + 1];
                        }
                        p = realloc(p, --mapaLotes[linha][coluna].nCamp * sizeof(Campista)); //reduzir o tamanho do array em 1 unidade
                    }
                break;
                case 4: getch();break;
                default: getch();
            }
            fflush(stdin);
            printf("Alteracoes Salvas Com Sucesso!!");
            system("pause");
            getch();
}
