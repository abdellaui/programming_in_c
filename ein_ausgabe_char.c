/* Programmieren in C, RUB, WS 2016/17, Kapitel 4
   Bspl.: Ein- und Ausgabe
   Datei: ein_ausgabe_char.c
   Standard: C90-C99-C11 */

/* Die char-Datentypen werden ein- und ausgegeben. */

/* Siehe auch: ein-ausgabe.c */

#include <stdio.h>

int main ()
{
  signed char sc; unsigned char uc; int i;

  printf ("Geben Sie zu Testzwecken zwei deutsche Umlaute ein: ");

  scanf  ("%c", &sc);
  printf ("\nsigned char\n");
  printf ("Zeichen 1 (%%c): %c\n",   sc);
  printf ("Zeichen 1 (%%d): %d\n",   sc);
  printf ("Zeichen 1 (%%u): %u\n\n", sc);

  printf ("Welcher ganzzahlige Wert liegt wirklich vor? ");
  i = sc;
  printf ("%d\n", i);


  scanf  ("%c", &uc);
  printf ("\nunsigned char\n");
  printf ("Zeichen 2 (%%c): %c\n",   uc);
  printf ("Zeichen 2 (%%d): %d\n",   uc);
  printf ("Zeichen 2 (%%u): %u\n\n", uc);

  printf ("Welcher ganzzahlige Wert liegt wirklich vor? ");
  i = uc;
  printf ("%d\n\n", i);

  printf ("Alles klar?\n");

  return 0;
}
