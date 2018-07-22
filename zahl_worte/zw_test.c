/* Programmieren in C, RUB, WS 2016/17, Kapitel 7-8
   Bspl.: Zahl in Worten (voller Bereich)
   Datei: zw_test.c
   Standard: C90-C99-C11 */

/* Test: Setzt eine vorzeichenlose ganze Zahl in Worte um. */

#include <stdio.h>
#include "zahl_worte.h"

int main ()
{
  unsigned int zahl;

  printf ("Gib eine Zahl ein: ");
  scanf ("%u", &zahl);

  printf ("\nDie Zahl %u lautet:\n", zahl);
  inWorten (zahl);
  printf ("\n");

  return 0;
}
