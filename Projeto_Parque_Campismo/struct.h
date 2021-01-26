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


typedef struct{
   char nome[TAMANHO_NOME];
   int idade;
   int cc;
   int nif;
}Campista;

typedef struct{
    char tipoAlojamento;
    int nCamp;
    int diasAlojamento;
    float taxaPagar;
    Campista campistas[6];
}Lote;

//void inicializarMapa(Lote mapaLotes[][NUMCOLUNAS]);
//void gravarLote();
//void carregaLote();



