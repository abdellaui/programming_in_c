/* Programmieren in C, RUB, WS 2016/17, Anhang A
   Bspl.: Dateien und formatierte E/A
   Datei: datei_ein_aus_formatiert.c
   Standard: C90-C99-C11 */

/* Aus dem Skript:
   Eine Folge von Gleitpunkt-Zahlen wird aus einer Textdatei gelesen.
   In eine andere Datei werden die jeweils berechneten Sinus-Werte geschrieben. */

/* Ein Ergebnis der Funktion 'fscanf' ungleich 1 beendet das Verfahren. */

#include <math.h>
#include <stdio.h>

int main ()
{
  FILE *in = fopen ("eingabe.txt", "r");

  if (in == 0)
    printf ("Problem: Die Eingabe-Datei existiert nicht!\n");
  else
  {
    FILE *out = fopen ("ausgabe.txt", "w");
    double d;
    int counter = 0;

    while (fscanf(in,"%lf",&d) == 1)
    {
      fprintf (out, "sin (%f) = %f\n", d, sin(d));
      counter++;
    }

    fclose (in);
    fclose (out);

    printf ("Erfolg: Berechnet wurden %d Werte.\n", counter);
  }

  return 0;
}
