// Programmieren in C, RUB, WS 2016/17, Kapitel 15
// Bspl.: Dreiecksmatrix aus Strrings
// Datei: dreiecksmatrix.c
// Standard: C99-C11

// Dreiecksmatrix aus Strings als dynamische Datenstruktur, siehe Skript

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lower_triangle_matrix.h"

int main ()
{
  unsigned int laenge = 4;
  char* **delta;

  // (1) Konstruktion ****************************************

  delta = create (laenge);
  if (delta == 0)
  {
    printf ("Fehler (1) bei Konstruktion\n");
    return 1;
  }

  // Einige willkürliche Belegungen


  strcpy(delta[1][0],"10");
  strcpy(delta[3][1],"31");
  strcpy(delta[3][2],"32");

  show (delta, laenge);
  printf ("\n");

  // (2) Verlängerung *****************************************

  delta = resize (delta, laenge, 6);
  if (delta == 0)
  {
    printf ("Fehler (2) bei Verlaengerung\n");
    return 2;
  }

  // Einige willkürliche Belegungen
  strcpy(delta[4][0],"4.0");
  // Systematische Vorbelegung
  for (int i=1; i<4; i++)
    sprintf( delta[4][i], "vier-%d",i);
  strcpy(delta[5][5],"5.5");

  show (delta, 6);
  printf ("\n");

   // (2) Verkürzung *****************************************

  delta = resize (delta, laenge, 3);
  if (delta == 0)
  {
    printf ("Fehler (2) bei Verlaengerung\n");
    return 2;
  }

  // Einige willkürliche Belegungen
  strcpy(delta[2][0],"2.0");
  strcpy(delta[2][1],"zweizwei");

  show (delta, 3);
  printf ("\n");

  // (3) Freigabe *********************************************

  delta = resign (delta, laenge);

  // (4) Alternative Konstruktion *****************************

  if (create_2 (&delta, laenge))
  {
    printf ("Fehler (4) bei Erzeugung\n");
    return 4;
  }

  // Einige willkürliche Belegungen
  strcpy(delta[2][1],"2.11");
  strcpy(delta[3][3],"3.33");

  show (delta, laenge);
  printf ("\n");


  // (5) Alternative Verlängerung *****************************

  if (resize_2 (&delta, laenge, 6))
  {
    printf ("Fehler (5) bei Verlaengerung\n");
    return 5;
  }

  // Einige willkürliche Belegungen
  strcpy(delta[4][2],"4.22");
  strcpy(delta[5][4],"5.44");

  show (delta, 6);

  // (6) Alternative Freigabe *** (hier nicht erforderlich) ***

  resign_2 (&delta, laenge);

  return 0;
}

