// Programmieren in C, RUB, WS 2016/17, Kapitel 11/12/14
// Bspl.: Langtons Ameise
// Datei: ameise.c
// Standard: C99-C11

// Siehe: http://de.wikipedia.org/wiki/Ameise_(Turingmaschine)

#include <stdio.h>
#include "area.h"

// Vereinbarungen zur Ameise
#define OBEN 0
#define RECHTS 1
#define UNTEN 2
#define LINKS 3

struct Ameise
{
  int x, y;
  int blick;
};

/* Statt der obigen PP-Makros für die Richtungen kann man alternativ auch eine
   Aufzählung (Kapitel 5) als Blickrichtung in die Struktur aufnehmen.
   (Obige Vereinbarungen zur Ameise dann entsprechend entfernen.)

   struct Ameise
   {
     int x, y;
     enum {OBEN, RECHTS, UNTEN, LINKS} blick;
   };
*/

// Prototyp
int nextStep (struct Ameise *, int len, char(*)[len]);  // oder: char [][len]

int main ()
{
  // Eingaben
  int laenge;
  printf ("Rastergroesse: ");
  scanf ("%d", &laenge);

  if (laenge < 1)
  {
    printf ("Zu klein!\n");
    return 9998;
  }

  int maxSchritte;
  printf ("Schrittzahl  : ");
  scanf ("%d", &maxSchritte);

  if (maxSchritte < 1)
  {
    printf ("Zu klein!\n");
    return 9999;
  }

  printf ("\n");

  // Raster anlegen
  char raster[laenge][laenge];
  initArea (laenge, raster);

  // Die Ameise und ihr Anfangsstatus
  struct Ameise ameise;
  ameise.x = ameise.y = laenge/2;
  ameise.blick = UNTEN;

  // Durchführung der Schritte
  int s;
  for (s = 1; s <= maxSchritte; s++)
    if (!nextStep (&ameise, laenge, raster))
      break;

  // Infos zum Abschluss ausgeben
  if (s <= maxSchritte)
    printf ("Rand des Rasters ueberschritten beim %d. Schritt!\n\n", s);
  else
    printf ("%d Schritte ausgefuehrt.\n\n", maxSchritte);

  // Anzeige des Rasters
  showArea (laenge, raster);

  return 0;
}

int nextStep (struct Ameise *pa, int len, char (*area)[len])  // oder: char area[][len]
{
  // Ameise ändert Feld im Raster und dreht sich.
  if (area[pa->x][pa->y] == ' ')
  {
    area[pa->x][pa->y] = '#';         // Einfärben
    pa->blick = (pa->blick + 1) % 4;  // Rechts-Drehung
  }
  else
  {
    area[pa->x][pa->y] = ' ';         // Einfärben
    if (pa->blick == OBEN)            // Links-Drehung
      pa->blick = LINKS;
    else
      pa->blick--;
  }

  // Ameise macht einen Schritt in Blickrichtung:
  // vertikal: x-Koordinate, horizontal: y-Koordinate
  // (return-Wert 0 bei Überschreitung des Rasters)
  switch (pa->blick)
  {
    case OBEN:   --pa->x;
                 if (pa->x == -1)
                   return 0;
                 break;
    case RECHTS: ++pa->y;
                 if (pa->y == len)
                   return 0;
                 break;
    case UNTEN:  ++pa->x;
                 if (pa->x == len)
                   return 0;
                 break;
    case LINKS:  --pa->y;
                 if (pa->y == -1)
                   return 0;
  }

  return 1;  // Schritt wurde innerhalb des Rasters durchgeführt.
}
