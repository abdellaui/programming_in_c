/* Programmieren in C, RUB, WS 2016/17, Kapitel 7-8
   Bspl.: Zahl in Worten (voller Bereich)
   Datei: zahl_worte.c
   Standard: C90-C99-C11 */

/* Funktion (inWorten) setzt eine natürliche Zahl in Worte um und gibt diese aus. */

/* Zahlen unterhalb von 1 Billion werden aus algorithmischer Sicht berücksichtigt.
   Der Wertebereich (unsigned int) endet jedoch bereits bei ca. 4 Milliarden (32 bit). */

#include <stdio.h>
#include "zahl_worte.h"


/* Ausgabe einer einstelligen Zahl (1-9) */

static void ziffer (int i)
{
  switch (i)
  {
    case 1: printf ("ein");    break;
    case 2: printf ("zwei");   break;
    case 3: printf ("drei");   break;
    case 4: printf ("vier");   break;
    case 5: printf ("fuenf");  break;
    case 6: printf ("sechs");  break;
    case 7: printf ("sieben"); break;
    case 8: printf ("acht");   break;
    case 9: printf ("neun");
  }
}


/* Ausgabe einer dreistelligen Zahl (1-999)
   Der zweite Parameter ergänzt "ein" um eine weiteren Buchstaben. */

static void von_1_bis_999 (int zahl, char einsPlus)
{
  /* Hunderter-Stelle */
  int hun  = zahl / 100;

  if (hun != 0)
  {
    ziffer (hun);
    printf ("hundert");
  }

  /* Einer- und Zehner-Stelle */
  zahl = zahl % 100;
  switch (zahl)
  {
    /* Sonderfälle: 1, 11, 12, 16, 17 */
    case  1: printf ("ein");
             if (einsPlus != 0)
               printf ("%c", einsPlus);
             break;
    case 11: printf ("elf");
             break;
    case 12: printf ("zwoelf");
             break;
    case 16: printf ("sechzehn");
             break;
    case 17: printf ("siebzehn");
             break;
    default:
             /* Einer-Stelle */
             ziffer (zahl % 10);

             if (zahl > 20 && zahl%10 != 0)
               printf ("und");

             /* Zehner-Stelle */
             switch (zahl / 10)
             {
               case 1: printf ("zehn");     break;
               case 2: printf ("zwanzig");  break;
               case 3: printf ("dreissig"); break;
               case 6: printf ("sechzig");  break;
               case 7: printf ("siebzig");  break;
               case 4:
               case 5:
               case 8:
               case 9: ziffer (zahl / 10); printf ("zig");
             }
  }
}


/* Ausgabe im vollen Bereich (unsigned int) */

void inWorten (unsigned int zahl)
{
  int block;

  const int tausend   = 1000,
            million   = tausend * tausend,
            milliarde = tausend * million;

  /* Sonderfall Null */
  if (zahl == 0)
  {
    printf ("Null");
    return;
  }

  /* Umsetzung erster Ziffernblock (Milliarden) */
  block = zahl / milliarde;
  if (block != 0)
  {
    von_1_bis_999 (block, 'e');
    if (block == 1)
      printf (" Milliarde ");
    else
      printf (" Milliarden ");
  }

  /* Umsetzung zweiter Ziffernblock (Millionen) */
  zahl %= milliarde;
  block = zahl / million;
  if (block != 0)
  {
    von_1_bis_999 (block, 'e');
    if (block == 1)
      printf (" Million ");
    else
      printf (" Millionen ");
  }

  /* Umsetzung dritter Ziffernblock (Tausender) */
  zahl %= million;
  block = zahl / tausend;
  if (block != 0)
  {
    von_1_bis_999 (block, 0);
    printf ("tausend ");
  }

  /* Umsetzung vierter Ziffernblock */
  zahl %= tausend;
  if (zahl != 0)
    von_1_bis_999 (zahl, 's');
}
