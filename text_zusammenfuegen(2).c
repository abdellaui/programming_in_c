// Programmieren in C, RUB, WS 2016/17, Anhang A
// Bspl.: Zerlegten Text wieder zusammenfügen
// Datei: text_zusammenfuegen.c
// Standard: C99-C11

// Ein in zwei Dateien zerlegter Text wird Zeichen für Zeichen wieder restauriert.

#include <stdio.h>

int main ()
{
  /*** Dateien öffnen ***/

  FILE *teil_1 = fopen ("teil_1.txt", "r");

  if (teil_1 == 0)
  {
    printf ("Fehler: Datei teil_1.txt nicht vorhanden\n");
    return 1;
  }

  FILE *teil_2 = fopen ("teil_2.txt", "r");

  if (teil_2 == 0)
  {
    printf ("Fehler: Datei teil_2.txt nicht vorhanden\n");
    return 2;
  }

  FILE *ausgabe = fopen ("Chistory.html", "w");

  /*** Restauration ***/

  int c;
  int zaehler = 0; // ... für die Anzahl der Zeichen
  int wechsel = 0; // ... für die Anzahl der Zeilenwechsel

  while (1)
  {
    // Zeichen aus 1. Datei
    c = fgetc (teil_1);
    if (c == EOF) break;

    // Zeichen in Zieldatei ausschreiben & zählen
    fputc (c, ausgabe);
    zaehler++;

    // Zeilenumbruch zählen
    wechsel += (c == '\n');

    // Zeichen aus 2. Datei
    c = fgetc (teil_2);
    if (c == EOF) break;

    // Zeichen in Zieldatei ausschreiben & zählen
    fputc (c, ausgabe);
    zaehler++;

    // Zeilenumbruch zählen
    wechsel += (c == '\n');
  }

  /*** Abschluss ***/

  fclose (teil_1);
  fclose (teil_2);
  fclose (ausgabe);

  printf ("Anzahl %d Zeichen inkl. %d Zeilenwechsel\n", zaehler, wechsel);

  return 0;
}
