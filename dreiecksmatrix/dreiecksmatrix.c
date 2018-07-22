// Programmieren in C, RUB, WS 2016/17, Kapitel 15
// Bspl.: Dreiecksmatrix
// Datei: dreiecksmatrix.c
// Standard: C99-C11

// Dreiecksmatrix als dynamische Datenstruktur, siehe Skript

#include <stdio.h>
#include <stdlib.h>
#include "lower_triangle_matrix.h"

int main ()
{
  unsigned int laenge = 4;
  double **delta;

  // (1) Konstruktion ****************************************

  delta = create (laenge);
  if (delta == 0)
  {
    printf ("Fehler (1) bei Konstruktion\n");
    return 1;
  }

  // Einige willkürliche Belegungen
  delta[1][0] = 1.0;
  delta[3][1] = 3.1;
  delta[3][2] = 3.2;

  show (delta, laenge);
  printf ("\n");

  // (2) Verlängerung *****************************************

  delta = resize (delta, laenge, 3);
  if (delta == 0)
  {
    printf ("Fehler (2) bei Verlaengerung\n");
    return 2;
  }

  // Einige willkürliche Belegungen
  //delta[4][0] = 4.0;
  delta[2][2] = 2.22;

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
  delta[2][1] = 2.11;
  delta[3][3] = 3.33;

  show (delta, laenge);
  printf ("\n");

  // (5) Alternative Verlängerung *****************************

  if (resize_2 (&delta, laenge, 6))
  {
    printf ("Fehler (5) bei Verlaengerung\n");
    return 5;
  }

  // Einige willkürliche Belegungen
  delta[4][2] = 4.22;
  delta[5][4] = 5.44;

  show (delta, 6);

  // (6) Alternative Freigabe *** (hier nicht erforderlich) ***

  resign_2 (&delta, laenge);

  // Anwendung: Pascalsches Dreieck

printf("\nGib die Groesse der Matrix ein:\n");
scanf("%d", &laenge);

if (laenge <= 2)
    {
    printf("Zu kleiner Wert: %d\n", laenge);
    return 12;
    }
delta = create(laenge);
if (delta == 0)
  {
    printf ("Fehler (7) bei Konstruktion\n");
    return 33;
  }

delta[0][0] = delta[1][0] = delta[1][1] = 1.0;

for (int i=2; i < laenge; i++)
{
    delta[i][0] = delta[i][i] = 1.0;
    for (int j=1; j<=i-1; j++)
        delta[i][j] = delta[i-1][j-1] + delta[i-1][j];

}

unsigned int zeile;
printf("Gib die auszugebende Zeile (0..groesse-1): \n");
scanf("%d", &zeile);

while ( zeile < laenge)
    {
printf("\nPolynom-Koeffizienten des Grades %d: \n", zeile);
for (int j=0; j < zeile; j++)
    printf("%04f - ", delta[zeile][j]);
    printf("\n");
    printf("Gib die auszugebende Zeile (1..groesse): \n");
    scanf("%d", &zeile);

    }
return 0;

}
