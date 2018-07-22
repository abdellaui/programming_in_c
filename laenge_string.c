/* Programmieren in C, RUB, WS 2016/17, Kapitel 13
   Bspl.: L�ngen von Strings
   Datei: laenge_string.c
   Standard: C90-C99-C11 */

/* sizeof liefert nicht die effektive Stringl�nge.
   bei einem Array           : Gr��e des Arrays (in Bytes)
   bei einem Zeiger/Parameter: Speichergr��e f�r einen Zeiger */

#include <stdio.h>
#include <string.h>

int main ()
{
  char s[5] = "Hallo";
  char *p    = "Hallo";

  printf ("strlen(s) liefert: %u\n", strlen(s));
  printf ("strlen(p) liefert: %u\n", strlen(p));

  printf ("sizeof s  liefert: %u\n", sizeof s);
  printf ("sizeof p  liefert: %u\n", sizeof p);

  return 0;
}
