#include <stdio.h>

/* Prototypen */
void show_1a (int[], int);
void show_1b (int* , int);
void show_2a (int* , int);
void show_2b (int[], int);

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
void show_1a (int a[], const int size)
{
  int i;
  for (i = 0; i < size; i++)
    printf ("%d ", a[i]);
  printf ("\n");
}

/* Parameter: Zeiger-Notation / Handhabung als Array */
void show_1b (int *a, const int size)
{
  int i;
  for (i = 0; i < size; i++)
    printf ("%d ", a[i]);
  printf ("\n");
}

/* Parameter: Zeiger-Notation / Handhabung als Zeiger */
void show_2a (int *p, int repeat)
{
  while (repeat--)
    printf ("%d ", *p++);
  printf ("\n");
}

/* Parameter: Array-Notation / Handhabung als Zeiger */
void show_2b (int p[], int repeat)
{
  while (repeat--)
    printf ("%d ", *p++);
  printf ("\n");
}
