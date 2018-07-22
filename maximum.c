/* Programmieren in C, RUB, WS 2016/17, Kapitel 6
   Bspl.: Maximum einer Zahlenfolge
   Datei: maximum.c
   Standard: C90-C99-C11 */

/* Bestimmt das Maximum einer über die Tastatur eingegebenen Folge reeller Zahlen */

#include <stdio.h>

int main ()
{
  int c;
  double wert, maximum;

  // Ersten Wert lesen
  printf("Eingabe: \n");
  c = scanf("%lf",&maximum);
  if (c == EOF)
    printf("Fehler: kein Wert eingegeben!");
  else
  {
    /* Weitere Werte einlesen: */
    printf("Eingabe: \n");
    while( (c = scanf("%lf",&wert)) != EOF)
    {
      if (wert > maximum)
        maximum = wert;
      printf("Eingabe: \n");
    };
    printf("Maximaler Wert ist %f", maximum);
  }
  return 0;
}
