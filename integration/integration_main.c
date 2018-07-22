// Programmieren in C, RUB, WS 2016/17, Kapitel 9
// Bspl.: Integration
// Datei: integration_main.c
// Standard: C99-C11

// Numerische Integration

// Die Funktion 'integral' (implementiert in: integration.c)
// integriert die Funktion 'func' (in dieser Datei).

#include <math.h>
#include <stdio.h>
#include "integration.h"

int main ()
{
  // Grenzen
  double a, b;

  printf ("Grenze links     : ");
  scanf  ("%lf", &a);
  printf ("Grenze rechts    : ");
  scanf  ("%lf", &b);
  printf ("Anzahl Intervalle: ");
  scanf  ("%u", &n);

  printf ("Ergebnis         : %f\n", integral(a,b));
  return 0;
}

// Diese Funktion wird numerisch integriert.
double func (double x)
{
  return exp (-x*x);
}
