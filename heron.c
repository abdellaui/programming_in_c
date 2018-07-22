// Programmieren in C, RUB, WS 2016/17, Kapitel 7-8
// Bspl.: Heron-Verfahren
// Datei: heron.c
// Standard: C99-C11

// Verfahren zur angenäherten Berechnung einer Quadratwurzel
// http://de.wikipedia.org/wiki/Heron-Verfahren

#include <math.h>
#include <stdio.h>

// Prototyp
double heron (double zahl);

int main ()
{
  double zahl;

  printf ("Eingabe nicht-negative Zahl: ");
  scanf  ("%lf", &zahl);

  printf ("\nDie Wurzel von %f ist laut Funktion heron: %f\n", fabs(zahl), heron(zahl));
  printf ("\nDie Wurzel von %f ist laut Funktion sqrt : %f\n", zahl, sqrt(zahl));

  return 0;
}

double heron (double zahl)
{
  if (zahl < 0)
  {
    return NAN;
  }

  double xAlt;
  double x = (zahl + 1.0) / 2.0;

  do
  {
    // Bisherigen x-Wert merken
    xAlt = x;
    // Neuen x-Wert berechnen
    x = (x + zahl/x) / 2.0;
  }
  while (fabs(x-xAlt) >= 1E-5);  // 1E-5 = 1.0E-5 = 0.00001

  return x;
}
