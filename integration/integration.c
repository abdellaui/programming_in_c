// Programmieren in C, RUB, WS 2016/17, Kapitel 9
// Bspl.: Integration
// Datei: integration.c
// Standard: C99-C11

// Numerische Integration

#include "integration.h"

// Global: vorläufige Definition => Definition
unsigned int n;

// Berechnung des Integrals per Reckteckverfahren
double integral (double a, double b)
{
  double breite = (b - a) / n;
  double flaeche = 0;

  for (int i = 0; i < n; i++)
    flaeche += breite * func (a + (i+0.5)*breite);

  return flaeche;
}

// Alternative nach Ausklammern der Intervallbreite
// double integral (double a, double b)
// {
//   double breite = (b - a) / n;
//   double fSumme = 0;
//
//   for (int i = 0; i < n; i++)
//     fSumme += func (a + (i+0.5)*breite);
//
//   return breite * fSumme;
// }
