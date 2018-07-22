// Programmieren in C, RUB, WS 2016/17, Kapitel 13
// Bspl.: Ein- und Ausgabe von Strings
// Datei: ein_ausgabe_string.c
// Standard: C99-C11

// Vergleich zwischen formatierter und zeilenorientierter E/A

#include <stdio.h>
#include <string.h>

int main ()
{
  char s[11];  // effektiv 10 Zeichen + Nullzeichen

  {
    //*** Formatierte E/A ***

    printf ("Formatierte Ein-/Ausgabe\n\n");

    printf ("Geben Sie eine beliebige Zeichenfolge ein.\nEingabe  : ");
    scanf ("%10s", s);
    // Wichtig für die Sicherheit: passende Feldbreite 10 im Formatelement

    // Reste der Zeile sollen überlesen werden. (Zeichen werden gezählt.)
    int skip = 0;
    char c;
    do
    {
      scanf ("%c", &c);
      skip++;
    }
    while (c != '\n');

    printf ("Gefunden : %s\n", s);
    printf ("Laenge   : %u\n\n", strlen(s));
    printf ("Restzeile: %d Zeichen uebersprungen\n\n\n", skip);
  }

  {
    //*** Zeilenorientierte E/A ***

    puts ("Zeilenorientierte Ein-/Ausgabe\n");
    fputs ("Geben Sie eine beliebige Zeichenfolge ein.\nEingabe  : ", stdout);

    fgets (s, 11, stdin);
    // Wichtig für die Sicherheit: passende Größe 11 als Argument

    char *newline = strchr (s, '\n');
    int skip = 0;

    if (newline)  // Zeilenende gefunden = Zeiger ungleich Null = "wahr"
    {
      // Die Funktion fgets hat ein Zeilenende-Zeichen mit eingelesen.
      // Dies soll hier entfernt werden.
      *newline = '\0';
      puts ("Info     : Zeilenende-Zeichen aus String entfernt!");
    }
    else
    {
      // Die Funktion fgets hat kein Zeilenende eingelesen.
      // Reste der Zeile sollen überlesen werden. (Zeichen werden gezählt.)
      char c;
      do
      {
        c = getchar ();  // oder: c = fgetc (stdin);
        skip++;
      }
      while (c != '\n');
    }

    fputs ("Gefunden : ", stdout);
    puts (s);
    // Formatierte Ausgabe von Zahlwerten
    printf ("Laenge   : %u\n\n", strlen(s));
    printf ("Restzeile: %d Zeichen uebersprungen\n", skip);
  }

  return 0;
}
