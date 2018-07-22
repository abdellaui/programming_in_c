/* Programmieren in C, RUB, WS 2016/17, Kapitel 6
   Bspl.: Zahlenfolge lesen
   Datei: zahlenfolgeLesen.c
   Standard: C99-C11 */

/* Liest eine Folge von Zahlenpaaren (int, float) zeilenweise über die Tastatur
   Eingabefehler und Eingabeende werden kontrolliert */

#include <stdio.h>
int main (){
  int c;
  int i;
  float f;
  printf("Eingabe:");
  // Rezept für das Erkennen des Eingabeendes bei Konsoleingabe
  c = scanf("%d%f",&i, &f);
  // Eingabeende ist EOF
  while (c != EOF)
   {
    if (c < 2) printf("Fehler bei der Eingabe!\n");
      printf("c= %d - i= %d - f= %f\n",c,i,f);
    // Rest der Zeile überlesen (einfach so glauben)
    scanf("%*[^\n]");
    // Weitere Werte einlesen:
    printf("Eingabe:");
    c = scanf("%d%f",&i, &f);
   }

 return 0;
}
