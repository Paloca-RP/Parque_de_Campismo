#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	char menu;
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
	scanf("%c", &menu);

if(menu == 1)
{
	system("CLS");
			printf("Ver mapa de lotes");
}
					
			if(menu == 2)	
			printf("Reservar um lote");		
			break;
		
		case 3:		
			printf("Consultar um lote");		
			break;
		
		case 4:		
			printf("Pesquisar lote por campista");		
			break;
		
		case 5:		
			printf("Editar um lote reservado");		
			break;
		
		case 6:		
			printf("Libertar um lote");		
			break;
			
		case 7:
			printf("Sair");
			break;
			
		default:		
			printf("Insira uma opção válida");
			goto menu;					
	}


}
