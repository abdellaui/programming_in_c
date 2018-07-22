/* Programmieren in C, RUB, WS 2016/17, Kapitel 4
   Bspl.: Ein- und Ausgabe
   Datei: ein_ausgabe.c
   Standard: C90-C99-C11 */

/* Die "üblichen Verdächtigen" werden ein- und ausgegeben. */

/* Da Formatelemente mit einem % beginnen, muss man zur tatsächlichen Ausgabe des Zeiches %
   die Ersatzdarstellung %% nutzen.
   Bspl.: %%d gibt einfach nur zwei Zeichen % und d aus.
          %d ist hingegen ein wirksames Formatelement. */

#include <stdio.h>

int main ()
{
  short s; int i; long l; float f; double d;

  printf ("Nachfolgend nur Ziffern und ggf. Vorzeichen eingeben.\n(keine Praefixe, Suffixe)\n\n");

  printf ("short\nEingabe (%%hd): ");
  scanf  ("%hd", &s);
  printf ("Ausgabe (%%hd): %hd\n", s);
  printf ("Ausgabe  (%%d): %d\n\n", s);

  printf ("int\nEingabe  (%%d): ");
  scanf  ("%d", &i);
  printf ("Ausgabe  (%%d): %d\n\n", i);

  printf ("long\nEingabe (%%ld): ");
  scanf  ("%ld", &l);
  printf ("Ausgabe (%%ld): %ld\n\n", l);

  printf ("Von jetzt ab darf auch ein Dezimalpunkt vorkommen.\n\n");

  printf ("float\nEingabe  (%%f): ");
  scanf  ("%f", &f);
  printf ("Ausgabe  (%%f): %f (mit expliziter Konvertierung)\n", (double) f);
  printf ("Ausgabe  (%%f): %f (ohne Konvertierung)\n\n", f);

  printf ("double\nEingabe (%%lf): ");
  scanf  ("%lf", &d);
  printf ("Ausgabe  (%%f): %f\n", d);

  return 0;
}
