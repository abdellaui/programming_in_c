/* Programmieren in C, RUB, WS 2016/17, Kapitel 11
   Bspl.:Binäres Suchen
   Datei: binaere_suche.c
   Standard: C90-C99-C11 */

#include "binaere_suche.h"

int binaere_suche(int erstes, int letztes, double a[], double gesucht, int* position)
{
   if (erstes > letztes)
      return 0;
   int mitte = erstes + (letztes - erstes)/2;
   if (gesucht == a[mitte])
   {
      *position = mitte;
      return 1;
   }
   else if (gesucht < a[mitte])
      return binaere_suche(erstes, mitte-1, a, gesucht, position);
   else
      return binaere_suche(mitte+1, letztes, a, gesucht, position);
}

