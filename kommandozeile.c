
// Programmieren in C, RUB, WS 2016/17, Kapitel 13
// Bspl.: Kommandozeile
// Datei: kommandozeile.c
// Standard: C99-C11

// Bestandteile der Kommandozeile werden ausgeschrieben bzw. ausgewertet.

// main-Funktion mit Parametern

#include <stdio.h>

int main (int argc, char* argv[])
// oder: (int argc, char** argv)
{
  printf ("Anzahl: %d\n\n", argc);

  for (int i = 0; i < argc; i++)
    printf ("%d: %s\n", i, argv[i]);



  // Auswertung des ersten Paramaters als ganze Zahl
  if (argc >= 1)

  {

    int erg;

    sscanf(argv[1], "%d", &erg);

    printf("erster Parameter: %d\n", erg);

  }

  return 0;
}
