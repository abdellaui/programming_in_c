// Programmieren in C, RUB, WS 2016/17, Kapitel 13
// Bspl.: Wochentage
// Datei: wochentage.c
// Standard: C99-C11

// Arrays mit den Bezeichnungen der Wochentage anlegen und auf verschiedene Weisen ausgeben

#include <stdio.h>

// Prototypen
int show_1 (int argc, char argv[][99]);
int show_2 (int argc, char *argv[]);

int main ()
{
  char a[][99] = {"Montag", "Dienstag", "Mittwoch", "Donnerstag", "Freitag", "Samstag", "Sonntag"};

  for (int i = 0; i < 7; i++)
    puts (a[i]);
  putchar ('\n');

  for (int i = 0; i < 7; i++)
    printf ("%s\n", a[i]);
  printf ("\n");

  show_1 (7, a);
  printf ("\n\n");


  char* b[] = {"Montag", "Dienstag", "Mittwoch", "Donnerstag", "Freitag", "Samstag", "Sonntag"};

  for (int i = 0; i < 7; i++)
    puts (b[i]);
  putchar ('\n');

  for (int i = 0; i < 7; i++)
    printf ("%s\n", b[i]);
  printf ("\n");

  show_2 (7, b);

  return 0;
}

int show_1 (int argc, char argv[][99])
  // oder: (int argc, char (*argv)[99])
{
  printf ("Anzahl: %d\n\n", argc);

  for (int i = 0; i < argc; i++)
    printf ("%d: %s\n", i, argv[i]);

  return 0;
}

int show_2 (int argc, char *argv[])
  // oder: (int argc, char **argv)
{
  printf ("Anzahl: %d\n\n", argc);

  for (int i = 0; i < argc; i++)
    printf ("%d: %s\n", i, argv[i]);

  return 0;
}
