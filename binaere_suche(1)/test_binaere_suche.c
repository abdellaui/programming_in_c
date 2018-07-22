/* Programmieren in C, RUB, WS 2016/17, Kapitel 11
   Bspl.:Binäres Suchen
   Datei: test_binaere_suche.c
   Standard: C90-C99-C11 */

#include <stdio.h>
#include <stdlib.h>
#include "binaere_suche.h"

/* Prorotyp */
int istSortiert (int laenge, double a[]);

int main()
{
   double werte[] = {3.1, 4.2, 5.3, 6.4, 7.5, 11};
   int laenge = 6;
   /* Alternativ: Einlesen */

   if (!istSortiert(laenge, werte))
   {
      printf("Die Werte sind nicht aufsteigend sortiert !\n");
      return 1;
      /* Alternativ: Sortieren */
   }
   else
   {
      double gesucht;
      int position;
      printf("Gib nächsten zu findenden Wert ein:");
      char c = scanf("%lf", &gesucht);
      if (binaere_suche(0, laenge-1, werte, gesucht, &position))
         printf("Der gesuchte Wert %f kommt an Position %d vor!\n", gesucht, position);
      else
         printf("Der gesuchte Wert %f kommt nicht vor!\n",gesucht);
   }

   return 0;
}

int istSortiert (int laenge, double a[])
{
   double letztes = a[0];
   for (int i = 1; i < laenge; i++)
      if (a[i] < letztes)
         return 0;
      else
         letztes = a[i];
   return 1;
}

