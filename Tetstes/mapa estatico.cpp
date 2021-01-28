#include<stdio.h>
#include<conio.h>

int main (void )
{
  int matriz[5][5]={0},i, j;
 
  matriz[0][0] = 'x';
 
 
 
 
  printf("\n\n******************* Mapa ********************* \n\n");  
  printf("   | 1 | 2 | 3 | 4 | 5 \n");
  for ( i=0; i<5; i++ )
  {
    printf("%d -",i+1);
	    for ( j=0; j<5; j++ )
	    {
	      printf ("| %c ",matriz[ i ][ j ]);
	    }
	    printf("\n");
  }
  
  getch();
  return(0);
}

