/* Programmieren in C, RUB, WS 2016/17, Kapitel 6
   Bspl.: Vorkommen eines Wertes
   Datei: vorkommen.c
   Standard: C99-C11 */

/* Prüft das Vorkommen eines ganzzahligen Wertes in einer über die Tastatur eingegebenen Folge ganzer Zahlen */

#include <stdio.h>

int main ()
{
  int gesucht;
  printf("Gib gesuchten Wert ein:\n");
  scanf("%d",&gesucht);
  int c, wert;
  int kommtvor = 0; /* false */
  /* Ersten Wert lesen */
  printf("Eingabe: \n");
  /* Rezept für das Erkennen des Eingabeendes bei Konsoleingabe */
  c = scanf("%d",&wert);
  if (c == EOF)
    printf("Fehler: kein Wert eingegeben!");
  else
  {
    do
    {
      if (c < 1)
        printf("Fehler bei der Eingabe!\n");
      else if (wert == gesucht)
      {
        kommtvor = 1;
        /* Schleife wird beendet */
        break;
      }
      /* Ggfs. Rest der alten Eingabe überlesen und weitere Werte einlesen: */
      scanf("%*[^\n]");
      printf("Eingabe: \n");
    }
    while ( (c = scanf("%d",&wert)) != EOF);

    if (kommtvor)
      printf("Der gesuchte Wert %d kam vor", gesucht);
    else
      printf("Der gesuchte Wert %d kam NICHT vor", gesucht);
  }
  return 0;
}
