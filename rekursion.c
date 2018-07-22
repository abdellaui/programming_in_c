/* Programmieren in C, RUB, WS 2016/17, Kapitel 9
   Bspl.: Rekursive Berechnung der Fakultät
   Datei: rekursion.c
   Standard: C90-C99-C11 */

/* Im Vergleich zum Skript wird der Rekursionsvorgang hier mit protokolliert. */

/* Bei einem System mit 32 bit für die verwendeten ganzzahligen Typen liefert fak(13)
   noch den korrekten Wert, bei fak(14) wird bereits der Wertebereich überschritten. */

#include <stdio.h>

/* Prototyp */
unsigned long fak (unsigned int);

int main ()
{
  unsigned int Wert;

  printf ("Gib nat. Zahl: ");
  scanf  ("%u", &Wert);
  printf ("\n");

  printf ("\nGesamtergebnis: %lu\n", fak(Wert));

  return 0;
}

unsigned long fak (unsigned int n)
{
  unsigned long hilf;
static int Zaehler = 0;

  printf ("%d. Aufruf: fak(%u)\n", ++Zaehler, n);

  if (n == 0)
    hilf = 1;
  else
    hilf = n * fak(n-1);

  printf ("Ergebnis : fak(%u) = %lu\n", n, hilf);
  return hilf;
}
