/* Programmieren in C, RUB, WS 2016/17, Kapitel 6
   Bspl.: Häufigkeit eines Wertes
   Datei: werthaeufigkeit-do.c
   Standard: C99-C11 */

/* Bestimmt die Häufigkeit des Auftretens eines ganzzahligen Wertes in einer über die Tastatur eingegebenen Folge ganzer Zahlen */

#include <stdio.h>

int main ()
{
  int gesucht;
  printf("Gib gesuchten Wert ein:\n");
  scanf("%d",&gesucht);
  int c;
  int wert;
  int anzahl = 0;
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
       anzahl++;
     /* GGfs. Rest der alten Eingabe überlesen und weitere Werte einlesen: */
     scanf("%*[^\n]");
     printf("Eingabe: \n");
    }
    while ( (c = scanf("%d",&wert)) != EOF);
      if (anzahl > 0)
        printf("Der gesuchte Wert %d kam %d mal vor", gesucht, anzahl);
      else
        printf("Der gesuchte Wert %d kam NICHT vor", gesucht);
  } /* Ende else */
  return 0;
}
