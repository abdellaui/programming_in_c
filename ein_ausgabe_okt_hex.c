// Programmieren in C, RUB, WS 2016/17, Kapitel 17
// Bspl.: E/A oktal und hexadezimal
// Datei: ein_ausgabe_okt_hex.c
// Standard: C99-C11

// Das Beispiel zeigt die Wirkung der verschiedenen Formatelemente.
// Die Eingabe wird zunächst sicher auf einen String eingelesen,
// danach mit 5 verschiedenen Formatelementen bewertet
// und auch entsprechend wieder ausgegeben.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char s[21];
  char *res;
  char *fstrings[] = {"%d", "%i", "%o", "%x", "%X"};

  printf ("Eingabe: ");
  res = fgets (s, 21, stdin);
  printf ("Gelesen: res=%s", res);
  printf ("Gelesen:   s=%s\n\n", s);

  for (int i = 0; i < 5; i++)
  {
    int x;

    printf ("Lesen mit %s und ...\n", fstrings[i]);
    sscanf (s, fstrings[i], &x);

    for (int j = 0; j < 5; j++)
    {
      char fneu[30] = "  Ausschreiben mit %s: ";
      strcat (fneu, fstrings[j]);
      strcat (fneu, "\n");
      printf (fneu, fstrings[j], x);
    }

    printf ("\n");
  }

  return 0;
}
