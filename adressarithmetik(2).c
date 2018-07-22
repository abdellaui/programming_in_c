/* Programmieren in C, RUB, WS 2016/17, Kapitel 10/12
   Bspl.: Adressarithmetik
   Datei: adressarithmetik.c
   Standard: C90-C99-C11 */

/* Das Beispiel zeigt, dass beim Rechnen mit Adressen/Zeigern (hier: + 1)
   in Einheiten unterschiedlicher Größe je nach Basistyp gerechnet wird. */

#include <stdio.h>

int main ()
{
  int i;
  int *p = &i;

  double d;
  double *q = &d;

  double a[5];
  double b[3][5];

  printf ("int-Zeiger p rechnet in Einheiten von %d Bytes.\n",
         (int)(p+1) - (int)p);

  printf ("double-Zeiger q rechnet in Einheiten von %d Bytes.\n",
         (int)(q+1) - (int)q);

  printf ("Zeiger auf erstes Element a rechnet in Einheiten von %d Bytes.\n",
         (int)(a+1) - (int)a);

  printf ("Zeiger auf erste Zeile b rechnet in Einheiten von %d Bytes.\n",
         (int)(b+1) - (int)b);

  return 0;
}
