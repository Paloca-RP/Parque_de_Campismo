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
    char energy;
    float taxaPagar;
    Campista campistas[6];
}Lote;
