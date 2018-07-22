/* Programmieren in C, RUB, WS 2016/17, Kapitel 15
   Bspl.: Warteschlange
   Datei: schlange.c
   Standard: C90-C99-C11 */

/* Hier keine Fehler-Überprüfung bei 'calloc'! */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "schlange.h"

void anhaengen (Schlange *sz, const char *plus)
{
  if (sz->start == 0 || sz->ende == 0 || sz->zaehler == 0)
  {
    /* Erstes Element in leerer Liste */
    sz->start   = sz->ende = (struct Element*) calloc (1, sizeof(struct Element));
    sz->zaehler = 1;
  }
  else
  {
    /* Hinten anhängen */
    sz->ende->nach = (struct Element*) calloc (1, sizeof(struct Element));
    sz->ende       = sz->ende->nach;
    sz->zaehler++;
  }

  /* Echte Kopie */
  strcpy (sz->ende->inhalt, plus);
}

int entnehmen (Schlange *sz, char *minus)
{
  if (sz->start == 0 || sz->ende == 0 || sz->zaehler == 0)
    return 0;
  else
  {
    struct Element *loesch = sz->start;

    /* Echte Kopie */
    strcpy (minus, loesch->inhalt);

    /* Vorne entnehmen */
    sz->start = loesch->nach;
    if (sz->start == 0)
      sz->ende = 0;

    free (loesch);
    sz->zaehler--;
    return 1;
  }
}

void show (const Schlange ws)
{
  struct Element *p = ws.start;

  printf ("Anzahl = %d\n[Start] -> ", ws.zaehler);

  while (p)
  {
    printf ("%s -> ", p->inhalt);
    p = p->nach;
  }

  printf ("[NULL]\n\n");
}
