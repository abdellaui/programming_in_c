/* Programmieren in C, RUB, WS 2016/17, Kapitel 6
   Bspl.: Grosses Einmaleins
   Datei: einmaleins.c
   Standard: C99-C11
*/

#include <stdio.h>

int main ()
{
  for (int i = 11; i <= 20; i++)
  {
    for (int j = 11; j <= 20; j++)
      printf ("%2d*%2d=%3d ", i, j, i*j);
    printf ("\n");
  }

  return 0;
}
