/* Programmieren in C, RUB, WS 2016/17, Kapitel 12
   Bspl.: Zeiger + Arrays: Parameter / eine Dimension
   Datei: eine_dimension.c
   Standard: C90-C99-C11 */

/* Verschiedene Parameter-Vereinbarungen in einer Dimension zeigen:
   Array- und Zeiger-Notation sind gleichbedeutend. */

/* Im Gegensatz zum Skript sind hier die Basistypen der Array- bzw.
   Zeiger-Parameter konstant. */

#include <stdio.h>

/* Prototypen */
void show_1a (const int[], int);
void show_1b (const int* , int);
void show_2a (const int* , int);
void show_2b (const int[], int);

int main ()
{
  int a[] = {11, 22, 33, 44, 55};
  int *p = a;

  show_1a (a, 5);
  show_1b (a, 5);
  show_2a (a, 5);
  show_2b (a, 5);

  printf ("\n");

  show_1a (p, 5);
  show_1b (p, 5);
  show_2a (p, 5);
  show_2b (p, 5);

  return 0;
}

/* Parameter: Array-Notation / Handhabung als Array */
void show_1a (const int a[], const int size)
{
  int i;
  for (i = 0; i < size; i++)
    printf ("%d ", a[i]);
  printf ("\n");
}

/* Parameter: Zeiger-Notation / Handhabung als Array */
void show_1b (const int *a, const int size)
{
  int i;
  for (i = 0; i < size; i++)
    printf ("%d ", a[i]);
  printf ("\n");
}

/* Parameter: Zeiger-Notation / Handhabung als Zeiger */
void show_2a (const int *p, int repeat)
{
  while (repeat--)
    printf ("%d ", *p++);
  printf ("\n");
}

/* Parameter: Array-Notation / Handhabung als Zeiger */
void show_2b (const int p[], int repeat)
{
  while (repeat--)
    printf ("%d ", *p++);
  printf ("\n");
}
