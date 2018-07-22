/* Programmieren in C, RUB, WS 2016/17, Kapitel 8/10
   Bspl.: Vergleich der Parameter-Übergabetechniken
   Datei: call_by_reference.c
   Standard: C90-C99-C11 */

/* Aus dem Skript: Das Beispiel zeigt eine Parameter-Übergabe
   über einen Zeiger ("call by reference") im Vergleich
   zur normalen Übergabe ("call by value"). */

#include <stdio.h>

/* Prototypen */
void belege_by_value     (double);
void belege_by_reference (double*);

int main ()
{
  double z = 0.0;

  belege_by_value (z);
  printf ("Wert z = %f\n\n", z);

  belege_by_reference (&z);
  printf ("Wert z = %f\n", z);

  return 0;
}

void belege_by_value (double x)
{
  x = 55.5;
  printf ("belege: call by value\n");
  printf ("Wert x = %f\n", x);
}

void belege_by_reference (double *x)
{
  *x = 55.5;
  printf ("belege: call by reference\n");
  printf ("Wert *x = %f\n", *x);
}
