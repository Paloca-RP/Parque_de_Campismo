#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int menu;
	menu:
	printf("  #-----------------------------------#\n");
	printf("  #   Gestão de Parque de Campismo    #\n");
	printf("  #-----------------------------------#\n");
	printf("  #   1- Ver mapa de lotes            #\n");
	printf("  #   2- Reservar um lote             #\n");
	printf("  #   3- Consultar um lote            #\n");
	printf("  #   4- Pesquisar lote por campista  #\n");
	printf("  #   5- Editar um lote reservado     #\n");
	printf("  #   6- Libertar um lote             #\n");
	printf("  #   7- Sair                         #\n");
    printf("  #-----------------------------------#\n");
    printf("Insira uma opção:  ");
	scanf("%d", &menu);

	if(menu == 1){
		system("CLS");
		printf("Ver mapa de lotes");
		
		
	}
				
	else if(menu == 2){
		system("CLS");
		printf("Reservar um lote");
	}	
		
	else if(menu == 3){
		system("CLS");
		printf("Consultar um lote");
	}
		
	else if(menu == 4){
		system("CLS");
		printf("Pesquisar lote por campista");	
	}		
		
	else if(menu == 5){
		system("CLS");
		printf("Editar um lote reservado");	
	}
		
	else if(menu == 6){
		system("CLS");
		printf("Libertar um lote");	
	}
			
	else if(menu == 7){
		system("CLS");
		printf("Sair");
	}
	
	else{
		system("CLS");
		printf("Insira uma opção válida\n");
			goto menu;	
	}		
							
	


}
