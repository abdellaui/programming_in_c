/* Programmieren in C, RUB, WS 2016/17, Kapitel 17
   Bspl.: Bit-Operationen
   Datei: bit_operationen.c
   Standard: C90-C99-C11 */

/* Beispiele aus dem Skript */

#include <stdio.h>

int main()
{
  {
    /* Bit-Komplement */
    int i=230, j;

    j = ~i;
    printf ("i = %d\nj = %d\n\n", i, j);
  }
  {
    /* Bitverschiebung nach links */
    int i=230, j, k;

    j = i << 1;
    k = i << 4;
    printf ("i = %d\nj = %d\nk = %d\n\n", i, j, k);
  }
  {
    /* Bitverschiebung nach rechts */
    int i=230, j, k;

    j = i >> 1;
    k = i >> 4;
    printf ("i = %d\nj = %d\nk = %d\n\n", i, j, k);
  }
  {
    /* Bitweises AND */
    short i=230, j=31, k;

    k = i & j;
    printf ("i = %hd\nj = %hd\nk = %hd\n\n", i, j, k);
  }
  {
    /* Bitweises XOR */
    short i=230, j=31, k;


    k = i ^ j;
    printf ("i = %hd\nj = %hd\nk = %hd\n\n", i, j, k);
  }
  {
    /* Bitweises OR */
    short i=230, j=31, k;

    k = i | j;
    printf ("i = %hd\nj = %hd\nk = %hd\n\n", i, j, k);
  }
  {
    /* Bitverschiebung nach links und Zuweisung: <<= */
    int i=230;

    printf ("i(alt) = %d\n", i);
    i <<= 1;
    printf ("i(neu) = %d\n\n", i);
  }

  {
    /* Bitweise Ausgabe eines ganzahligen Wertes */
    int i = 2802;

    int bitpos = 8 * sizeof i - 1;

    printf ("dez.: %d\n", i);
    printf ("hex.: %x\n", i);
    printf ("okt.: %o\n", i);

    printf ("bin.: ");
    for (; bitpos >= 0; bitpos--)
    {
      printf ("%d", i >> bitpos & 1);
      if (bitpos%4 == 0)
        printf (" ");
    }
    printf ("\n");
  }

  return 0;
}
