#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main ()
{
int **matrice;
int righe, colonne, r, c;
   printf("Digita il numero di righe della matrice: ");
   scanf("%d",&righe);
   printf("Digita il numero di colonne della matrice: ");
   scanf("%d",&colonne);
   //allocazione della matrice
   matrice = (int **) malloc (righe*sizeof(int *));
   for(r=0; r<righe; r++)
     matrice[r] = (int *) malloc(colonne*sizeof(int));
   //inserimento dati
   for(r=0; r<righe; r++)
     for(c=0; c<colonne; c++)
     {
       printf("Inserisci elemento di riga %d e colonna %d: ", r,c);
       scanf("%d",&matrice[r][c]);
     }
  //stampa della matrice
  for(r=0; r<righe; r++)
  {
    for(c=0; c<colonne; c++)
      printf("%d",matrice[r][c]);
    printf("\n");
  }
  //deallocazione la matrice
  for(r=0; r<righe; r++)
     free(matrice[r]);
  free(matrice);
  getchar();
  return 0;
}
