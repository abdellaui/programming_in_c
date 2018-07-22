// Programmieren in C, RUB, WS 2016/17, Kapitel 8
// Bspl.: Dreieck aus Sternchen ausgeben
// Datei: sternchen.c
// Standard: C99-C11

// Aus dem Skript: erstes Beispiel mit Parametern (Varianten)

#include <stdio.h>

// Prototypen
void show_1 (char, int);
void show_2 (char, int);

int main ()
{
  for (int i = 10; i >= 1; i--)
  {
    show_1 ('*', i);
    printf ("\n");
  }

  for (int i = 10; i >= 1; i--)
  {
    show_2 ('*', i);
    printf ("\n");
  }

  return 0;
}

void show_1 (const char zeichen, int anzahl)
{
  while (anzahl-- > 0)
    printf ("%c", zeichen);
}

void show_2 (const char zeichen, const int anzahl)
{
  for (int j = 1; j <= anzahl; j++)
    printf ("%c", zeichen);
}
