// Programmieren in C, RUB, WS 2016/17, Kapitel 11
// Bspl.: Parameterübergabe bei Arrays
// Datei: array_parameter.c
// Standard: C99-C11

// Aus dem Skript: Übergabe eines zweidimensionalen Arrays

#include <stdio.h>

// Prototypen
void show      (int[][3]);
  void show    (int p[][3]);                // alternativ
  void show    (int p[3][3]);               // alternativ

// Prototypen (möglich in C99, ggf. auch in C11)
void show_99   (int lng, int[][lng]);
  void show_99 (int lng, int p[][lng]);     // alternativ
  void show_99 (int lng, int p[lng][lng]);  // alternativ

int main ()
{
  int b[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

  show (b);
  printf ("\n");

  show_99 (3, b);
  return 0;
}

void show (int p[][3])
{
  int i, j;
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
      printf ("[%d,%d] -> %d  ", i, j, p[i][j]);
    printf ("\n");
  }
}

// Variable Array-Längen, speziell in der 2. Dimension
void show_99 (int lng, int p[][lng])
{
  for (int i = 0; i < lng; i++)
  {
    for (int j = 0; j < lng; j++)
      printf ("[%d,%d] -> %d  ", i, j, p[i][j]);
    printf ("\n");
  }
}
