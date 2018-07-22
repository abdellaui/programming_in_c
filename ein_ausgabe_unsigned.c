/* Programmieren in C, RUB, WS 2016/17, Kapitel 4
   Bspl.: Ein- und Ausgabe
   Datei: ein_ausgabe_unsigned.c
   Standard: C90-C99-C11 */

/* Die unsigned-Datentypen werden ein- und ausgegeben. */

/* Siehe auch: ein-ausgabe.c */

#include <stdio.h>

int main ()
{
  unsigned short s; unsigned int i; unsigned long l;

  printf ("Bei den Zahltypen nur Ziffern eingeben.\n"
          "(keine Vorzeichen, Praefixe, Suffixe)\n\n");

  printf ("unsigned short\nEingabe (%%hu): ");
  scanf  ("%hu", &s);
  printf ("Ausgabe (%%hu): %hu\n", s);
  printf ("Ausgabe  (%%u): %u\n\n", s);

  printf ("unsigned int\nEingabe  (%%u): ");
  scanf  ("%u", &i);
  printf ("Ausgabe  (%%u): %u\n\n", i);

  printf ("unsigned long\nEingabe (%%lu): ");
  scanf  ("%lu", &l);
  printf ("Ausgabe (%%lu): %lu\n", l);

  return 0;
}
