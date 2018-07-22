// Programmieren in C, RUB, WS 2016/17, Kapitel 11
// Bspl.: Bestimmung des Wochentags zu einem Datum
// Datei: zeller.c
// Standard: C99-C11

// Verfahren für Daten ab dem Jahr 1583
// http://de.wikipedia.org/wiki/Zellers_Kongruenz

#include "zeller.h"
#include <stdio.h>

int wochentag (int tag, int monat, int jahr)
{
  // Sonderfälle Januar und Februar
  if (monat == 1 || monat == 2)
  {
    monat += 12;
    jahr -= 1;
  }

  // Zerlegung der Jahreszahl
  int j = jahr / 100;
  int k = jahr % 100;

  // Bestimmung des Wochentages
  // Ergebnisse: 0-6 für Samstag-Freitag
  return (tag + (monat+1)*13/5 + k + k/4 + j/4 + 5*j) % 7;
}
