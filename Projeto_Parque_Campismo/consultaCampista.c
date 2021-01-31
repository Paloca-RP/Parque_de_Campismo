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
#define TAMANHO_NOME 55

//FUNÇAO QUE PROCURA O LOTE PELO NOME DO CAMPISTA. vai receber o endereço do lote e
//VAI RETORNAR OS DADOS DO LOTE DA PESSOA QUE O UTILIZADOR PROCUROU
void consultaCampistaPeloNome(Lote mapaLotes[][NUMCOLUNAS])
{
    mostraMapaDeLotes();
    setlocale(LC_ALL, "Portuguese");
    char procura[TAMANHO_NOME];
    fflush(stdin);
    int resultado=0;
    printf("------------------------------------------------------------\n");
    printf("\tCONSULTA DE LOTE POR NOME DE CAMPISTA\n");
    printf("------------------------------------------------------------\n");
    printf("INTRODUZA O O NOME COMPLETO DO CAMPISTA QUE QUER PROCURAR: \n");
    gets(procura);

        for (int i = 0; i < NUMLINHAS; i++)
        {
            for (int j = 0; j < NUMCOLUNAS; j++)
            {
                 for (int k = 0; k < 6; k++)
                 {
                     if (strcmp(procura,mapaLotes[i][j].campistas[k].nome))
                    {
                        resultado=0;
                    }
                    else {
                        printf("NOME ENCONTRADO:\n");
                        printf("%s ESTÁ ALOCADO NO LOTE %d %d\n", mapaLotes[i][j].campistas[k].nome, i+1, j+1);
                        printf("--------------------------------------------------------------------------------------\n");
                        printf("LEGENDA: T-TENDA, A-AUTOCARAVANA, C-CARAVANA, X-SEM ELETRICIDADE, E-COM ELETRICIDADE\n");
                        printf("--------------------------------------------------------------------------------------\n");
                        printf("\t\tDADOS DO LOTE: %d %d\n", i+1, j+1);
                        printf("--------------------------------------------------------------------------------------\n");
                        printf("Dias de Alojamento:          %d    \n", mapaLotes[i][j].diasAlojamento);
                        printf("Taxa a pagar pela reserva:   %.2f   \n", mapaLotes[i][j].taxaPagar);
                        printf("Numero de Campistas no lote: %d    \n", mapaLotes[i][j].nCamp);
                        printf("Tipo de Alojamento:          %c    \n", mapaLotes[i][j].tipoAlojamento);
                        printf("Ligado a rede Eletrica?:     %c    \n", mapaLotes[i][j].energy);
                        printf("----------------------------------------------------------------------------------------\n");
                        break;
                    }
                 }
            }
        }
        printf("PARA VOLTAR AO MENU PRINCIPAL PRESSIONAR QUALQUER TECLA");
        getch();
        }

