/* Programmieren in C, RUB, WS 2016/17, Kapitel 14
   Bspl.: Punkte und Strecken
   Datei: punkte_strecken.c
   Standard: C90-C99-C11 */

/* Siehe Skript Kapitel 14 (Abschnitt über geschachtelte Strukturen) */

#include <stdio.h>
#include <stdlib.h>

int main ()
{
  /* Beispiel 1 */
  {
    struct Punkt
    {
      double x, y;
    };

    struct Strecke
    {
      struct Punkt start, ziel;
    };

    struct Strecke s = {{1.0, 2.0}, {3.0, 4.0}};

    printf ("s.start.x = %f\n", s.start.x);
    printf ("s.start.y = %f\n", s.start.y);
    printf ("s.ziel.x  = %f\n", s.ziel.x);
    printf ("s.ziel.y  = %f\n", s.ziel.y);
    printf ("\n");
  }

  /* Beispiel 2 */
  {
    struct Strecke
    {
      struct {double x, y;} start, ziel;
    };

    struct Strecke s = {{1.0, 2.0}, {3.0, 4.0}};

    printf ("s.start.x = %f\n", s.start.x);
    printf ("s.start.y = %f\n", s.start.y);
    printf ("s.ziel.x  = %f\n", s.ziel.x);
    printf ("s.ziel.y  = %f\n", s.ziel.y);
    printf ("\n");
  }

  /* Beispiel 3 */
  {
    struct
    {
      struct {double x, y;} start, ziel;
    }
      s = {{1.0, 2.0}, {3.0, 4.0}};

    printf ("s.start.x = %f\n", s.start.x);
    printf ("s.start.y = %f\n", s.start.y);
    printf ("s.ziel.x  = %f\n", s.ziel.x);
    printf ("s.ziel.y  = %f\n", s.ziel.y);
    printf ("\n");
  }

  /* Beispiel 4 */
  {
    struct Punkt;

    struct Strecke
    {
      struct Punkt *start, *ziel;
    };

    struct Punkt
    {
      double x, y;
    };

    struct Punkt p1 = {1.0, 2.0}, p2 = {3.0, 4.0};

    struct Strecke s;
    s.start = &p1;
    s.ziel  = &p2;

    printf ("s.start->x = %f\n", s.start->x);
    printf ("s.start->y = %f\n", s.start->y);
    printf ("s.ziel->x  = %f\n", s.ziel->x);
    printf ("s.ziel->y  = %f\n", s.ziel->y);
    printf ("\n");
  }

  /* Beispiel 5 (nicht aus dem Skript) */
  {
    static const struct
    {
      struct {const double x, y;} start, ziel;
    }
      s = {{1.0, 2.0}, {3.0, 4.0}};

    printf ("static & const:\n");
    printf ("s.start.x = %f\n", s.start.x);
    printf ("s.start.y = %f\n", s.start.y);
    printf ("s.ziel.x  = %f\n", s.ziel.x);
    printf ("s.ziel.y  = %f\n", s.ziel.y);
  }

  return 0;
}
