/* Programmieren in C, RUB, WS 2016/17, Kapitel 15
   Bspl.: Warteschlange
   Datei: warten.c
   Standard: C90-C99-C11 */

/* Warteschlange als dynamische Datenstruktur, siehe Skript */

/* Die main-Funktion orientiert sich am Beispiel "Temperatur" aus Kapitel 6
   bzw. an calculator.c im Beispiel "Bruchrechnung" aus Kapitel 14. */

#include <stdio.h>
#include <string.h>
#include "schlange.h"

int main ()
{
  Schlange liste = {0};

  char name[31];
  unsigned char op;

  printf ("Geben Sie jeweils ein:\n"
          "  + und einen Namen (max. 30 Zeichen) zum Eintragen\n"
          "  - zur Entnahme\n"
          "  X zur Beendigung des Programms.\n\n");

  while (1)
  {
    printf ("Eingabe: ");
    scanf (" %c", &op);

    if (op == 'X' || op == 'x') break;

    switch (op)
    {
      case '+': fgets (name, 31, stdin);
                {
                  char *p = strchr (name, '\n');
                  if (p)
                    *p = '\0';
                }
                anhaengen (&liste, name);
                show (liste);
                break;

      case '-': if (entnehmen(&liste, name))
                  printf ("Entnommen: %s\n", name);
                else
                  printf ("Liste ist bereits leer!\n");
                show (liste);
                break;

      default : printf ("Keine zulaessige Operation\n");
    }
  }

  return 0;
}
