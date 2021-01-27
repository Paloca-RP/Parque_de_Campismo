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
                printf("---------------------------------------|\n");
                printf("|\nDias de Alojamento:           %d    |\n", mapaLotes[linha][coluna].diasAlojamento);
                printf("|Taxa a pagar pela reserva:      %f    |\n", mapaLotes[linha][coluna].taxaPagar);
                printf("|Numero de Campistas no lote     %d:   |\n", mapaLotes[linha][coluna].nCamp);
                printf("---------------------------------------|\n");

                for(int i=0; i<numeroCampistas; i++)
                {
                    printf("---------DADOS GUARDADOS--- --|\n");
                    printf("|CAMPISTA %d                  |\n", i+1);
                    printf("|NOME : %s                    |\n",mapaLotes[linha][coluna].campistas[i].nome);
                    printf("|IDADE : %d                   |\n", mapaLotes[linha][coluna].campistas[i].idade);
                    printf("|NIF : %d                     |\n", mapaLotes[linha][coluna].campistas[i].nif);
                    printf("|CC: %d                       |\n",  mapaLotes[linha][coluna].campistas[i].cc);
                    printf("------------------------------|\n");
                }
            }
            int op;
            printf("\n-------EDIÇÃO DO LOTE---|\n");
            printf("|O QUE QUER ALTERAR?      |\n");
            printf("|1-DADOS DO LOTE          |\n");
            printf("|2-DADOS DOS CAMPISTAS    |\n");
            printf("|3-ADICIONAR NOVO CAMPISTA|\n");
            printf("|3-REMOVER CAMPISTA       |\n");
            printf("|4-SAIR                   |\n");
            printf("|-------------------------|\n");
            printf("INSIRA UMA OPCAO:");
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
                case 3: printf("TESTE");break;
                case 4: getch();break;
                default: getch();
            }
            fflush(stdin);
            printf("Alteracoes Salvas Com Sucesso!!");
            system("pause");
            getch();
}
