// Programmieren in C, RUB, WS 2016/17, Kapitel 11
// Bspl.: Freitag, der Dreizehnte
// Datei: freitag_13.c
// Standard: C99-C11

// Berechnung von Häufigkeiten (Wochentag des Dreizehnten eines Monats)

#include <stdio.h>
#include "zeller.h"

// Prototyp
void printWochentag (int);

int main ()
{
  /****** Schritt 1: Bestimmung der Häufigkeiten ******/

  int zaehler[7] = {0};

  // Auszählen der Häufigkeiten (Zeitraum 400 Jahre)
  for (int jahr = 2016; jahr < 2416; jahr++)
    // jeweils für die 12 Monate
    for (int monat = 1; monat <= 12; monat++)
      // Erhöhung des jeweiligen Zählers um 1
      zaehler[wochentag(13, monat, jahr)]++;

  /****** Schritt 2: Ausgabe der Häufigkeiten ******/

  printf ("Haeufigkeiten:\n");
  for (int i = 0; i < 7; i++)
  {
    printWochentag (i);
    printf (": %d\n", zaehler[i]);
  }

  /****** Schritt 3: Auswertung der Häufigkeiten ******/

  // Suche nach maximaler Häufigkeit
  int max = zaehler[0];
  for (int i = 1; i < 7; i++)
    if (max < zaehler[i])
      max = zaehler[i];

  // Ausgabe der häufigsten Wochentage
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
  // Fälle orientieren sich an "Zellers Kongruenz"
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
