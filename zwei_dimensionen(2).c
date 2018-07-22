/* Programmieren in C, RUB, WS 2016/17, Kapitel 12
   Bspl.: Zeiger + Arrays: Konstrukte in zwei Dimensionen
   Datei: zwei_dimensionen.c
   Standard: C90-C99-C11 */

/* Aus den Skript: alternative Datenstrukturen in zwei Dimensionen */

#include <stdio.h>

/* Prototypen */
void show_1 (double [][5] );
void show_2 (double (*)[5]);
void show_3 (double *[]   );
void show_4 (double **    );

int main ()
{
  /* Beispiel Alpha: ein zweidimensionales Array */
  double alpha[3][5] = {{1.1, 1.2, 1.3, 1.4, 1.5},
                        {2.1, 2.2, 2.3, 2.4, 2.5},
                        {3.1, 3.2, 3.3, 3.4, 3.5}};

  /* Beispiel Beta: ein Zeiger auf double-Array der Länge 5 */
  double (*beta)[5] = alpha;

  /* Beispiel Gamma: ein Array aus drei double-Zeigern */
  double* gamma[3];

  /* Beispiel Delta: ein Zeiger auf Zeiger auf double */
  double** delta = gamma;

      /* Hilfsarrays nur zur Belegung von Gamma */
      double x_0[] = {7.1, 7.2, 7.3, 7.4, 7.5},
             x_1[] = {8.1, 8.2, 8.3, 8.4, 8.5},
             x_2[] = {9.1, 9.2, 9.3, 9.4, 9.5};
      gamma[0] = x_0;
      gamma[1] = x_1;
      gamma[2] = x_2;

  printf ("Beispiel 'alpha'\n\n");

  show_1 (alpha);
  show_2 (alpha);
    /* show_3 (alpha);   Argument nicht kompatibel zum Parameter */
    /* show_4 (alpha);   Argument nicht kompatibel zum Parameter */

  printf ("\nBeispiel 'beta'\n\n");

  show_1 (beta);
  show_2 (beta);
    /* show_3 (beta);    Argument nicht kompatibel zum Parameter */
    /* show_4 (beta);    Argument nicht kompatibel zum Parameter */

  printf ("\nBeispiel 'gamma'\n\n");

    /* show_1 (gamma);   Argument nicht kompatibel zum Parameter */
    /* show_2 (gamma);   Argument nicht kompatibel zum Parameter */
  show_3 (gamma);
  show_4 (gamma);

  printf ("\nBeispiel 'delta'\n\n");

    /* show_1 (delta);   Argument nicht kompatibel zum Parameter */
    /* show_2 (delta);   Argument nicht kompatibel zum Parameter */
  show_3 (delta);
  show_4 (delta);

  return 0;
}


/* Man beachte, dass die folgenden vier Funktionen verschiedene Parameter-
   Vereinbarungen, aber einen völlig identischen Funktionsrumpf besitzen!
   (Die Anweisungen nutzen in jedem Fall die Array-Notation.) */

/* Die Parameter von show_1 und show_2 sind bedeutungsgleich,
   ebenso die von show_3 und show_4. */

void show_1 (double p[][5])
{
  int i, j;
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 5; j++)
      printf ("%-4.1f", p[i][j]);
    printf ("\n");
  }
  printf ("\n");
}

void show_2 (double (*p)[5])
{
  int i, j;
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 5; j++)
      printf ("%-4.1f", p[i][j]);
    printf ("\n");
  }
  printf ("\n");
}

void show_3 (double *p[])
{
  int i, j;
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 5; j++)
      printf ("%-4.1f", p[i][j]);
    printf ("\n");
  }
  printf ("\n");
}

void show_4 (double **p)
{
  int i, j;
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 5; j++)
      printf ("%-4.1f", p[i][j]);
    printf ("\n");
  }
  printf ("\n");
}
