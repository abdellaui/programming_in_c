// Programmieren in C, RUB, WS 2016/17, Kapitel 11
// Bspl.: Freitag, der Dreizehnte
// Datei: freitag_13.c
// Standard: C99-C11

// Berechnung von H�ufigkeiten (Wochentag des Dreizehnten eines Monats)

#include <stdio.h>
#include "zeller.h"

// Prototyp
void printWochentag (int);

int main ()
{
  /****** Schritt 1: Bestimmung der H�ufigkeiten ******/

  int zaehler[7] = {0};

  // Ausz�hlen der H�ufigkeiten (Zeitraum 400 Jahre)
  for (int jahr = 2016; jahr < 2416; jahr++)
    // jeweils f�r die 12 Monate
    for (int monat = 1; monat <= 12; monat++)
      // Erh�hung des jeweiligen Z�hlers um 1
      zaehler[wochentag(13, monat, jahr)]++;

  /****** Schritt 2: Ausgabe der H�ufigkeiten ******/

  printf ("Haeufigkeiten:\n");
  for (int i = 0; i < 7; i++)
  {
    printWochentag (i);
    printf (": %d\n", zaehler[i]);
  }

  /****** Schritt 3: Auswertung der H�ufigkeiten ******/

  // Suche nach maximaler H�ufigkeit
  int max = zaehler[0];
  for (int i = 1; i < 7; i++)
    if (max < zaehler[i])
      max = zaehler[i];

  // Ausgabe der h�ufigsten Wochentage
  printf ("\nWochentage maximaler Haeufigkeit:\n");
  int zaehlMax = 0;
  for (int i = 0; i < 7; i++)
    if (zaehler[i] == max)
    {
      zaehlMax++;
      printWochentag (i);
      printf ("\n");
    }
  if (zaehlMax == 1)
    printf ("(Es gibt nur einen Wochentag mit dieser Haeufigkeit.)\n");

  return 0;
}

// Funktion zur Ausgabe eines Wochentages
void printWochentag (int i)
{
  // F�lle orientieren sich an "Zellers Kongruenz"
  switch (i)
  {
    case 0: printf ("Samstag   ");
            break;
    case 1: printf ("Sonntag   ");
            break;
    case 2: printf ("Montag    ");
            break;
    case 3: printf ("Dienstag  ");
            break;
    case 4: printf ("Mittwoch  ");
            break;
    case 5: printf ("Donnerstag");
            break;
    case 6: printf ("Freitag   ");
  }
}
