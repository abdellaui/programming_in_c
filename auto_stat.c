/* Programmieren in C, RUB, WS 2016/17, Kapitel 9
   Bspl.: Vergleich automatische/statische Speicherklasse
   Datei: auto_stat.c
   Standard: C90-C99-C11 */

/* Aus dem Skript: Das Programm zeigt insbesondere das unterschiedliche Verhalten
   einer automatischen zu einer statischen lokalen Variablen. */

#include <stdio.h>

/* Prototyp */
void sub (int);

int main ()
{
  int i;

  for (i = 1; i <= 4; i++)
    sub (i);

  return 0;
}

void sub (int p)
{
  int a = 0;     /* automatische Speicherklasse, explizit mit Null initialisiert */
  static int s = 5;  /* statische Speicherklasse, implizit mit Null initialisiert */

  a++; s++;
  printf ("p=%d a=%d s=%d\n", p, a, s);
}
