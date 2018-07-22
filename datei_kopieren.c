/* Programmieren in C, RUB, WS 2016/17, Anhang A
   Bspl.: Erstellen einer Dateikopie
   Datei: datei_kopieren.c
   Standard: C90-C99-C11 */

/* Aus dem Skript: zeichenweise Kopie einer Textdatei */

/* Wichtig: Das Ergebnis der Funktion 'fgetc' wird auf einer int-
   Variablen gespeichert und kann somit am Dateiende auch sicher
   auf EOF abgefragt werden. */

/* Windows: Die Kombination der zwei Zeichen CR+LF wird als ein
   Zeilenende erfasst. Der Zähler 'counter' zählt dann nur ein
   Zeichen und liefert entsprechend einen kleinern Wert unterhalb
   der Dateigröße. Will man dies umgehen und die tatsächliche
   Dateigröße (in Bytes) ausgeben, so muss man die Modi auf "rb"
   und "wb" setzen. */

#include <stdio.h>

int main ()
{
  FILE *in = fopen ("quelle.txt", "r");

  if (in == 0)
    printf ("Problem: Die Eingabe-Datei existiert nicht!\n");
  else
  {
    FILE *out = fopen ("kopie.txt", "w");
    int c;
    int counter = 0;

    while ((c=fgetc(in)) != EOF)
    {
      fputc (c, out);
      counter++;
    }

    fclose (in);
    fclose (out);

    printf ("Erfolg: Kopiert wurden %d Zeichen.\n", counter);
  }

  return 0;
}
