// Programmieren in C, RUB, WS 2016/17, Kapitel 11/12
// Bspl.: Spielfeld
// Datei: area.h
// Standard: C99-C11

#include <stdio.h>
#include "area.h"

void initArea (int len, char (*area)[len])  // oder: char area[][len]
{
  for (int i = 0; i < len; i++)
    for (int j = 0; j < len; j++)
      area [i][j] = ' ';
}

static void horLine (int len)
{
  // "Zeichnen" der oberen bzw. unteren Begrenzung
  printf ("+");
  for (int j = 0; j < len; j++)
    printf ("-");
  printf ("+\n");
}

void showArea (int len, char (*area)[len])  // oder: char area[][len]
{
  horLine (len);
  for (int i = 0; i < len; i++)
  {
    printf ("|");    // linke Begrenzung anzeigen

    for (int j = 0; j < len; j++)
      printf ("%c", area[i][j]);

    printf ("|\n");  // rechte Begrenzung anzeigen
  }
  horLine (len);
}
