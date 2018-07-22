// Programmieren in C, RUB, WS 2016/17, Kapitel 15
// Bspl.: Dreiecksmatrix aus Strings
// Datei: lower_triangle_matrix.h
// Standard: C99-C11

// Dreiecksmatrix aus Strings als dynamische Datenstruktur, siehe Skript

#include <stdio.h>
#include <stdlib.h>
#include "lower_triangle_matrix.h"

char***create (unsigned int len)
{
  char***pp = (char***) malloc (len * sizeof(char**));
  if (pp == 0)
    return 0;  // Fehler in 1. Dimension

  for (unsigned int i = 0; i < len; i++)
  {
    pp[i] = (char**) calloc (i+1, sizeof(char*));
    if (pp[i] == 0)
    {
      resign (pp, len);
      return 0;  // Fehler in 2. Dimension
    }
      for (unsigned int j = 0; j < i+1; j++)
        pp[i][j] = (char*) calloc(10, sizeof(char));
    }

  return pp;
}


char* **resize (char* **pp, unsigned int alt, unsigned int neu)
{
  pp = (char***) realloc (pp, neu * sizeof(char**));
  if (pp == 0)
    return 0;  // Fehler in 1. Dimension

  for (unsigned int i = alt; i < neu; i++)
  {
    pp[i] = (char**) calloc (i+1, sizeof(char*));
    if (pp[i] == 0)
    {
      resign (pp, neu);
      return 0;  // Fehler in 2. Dimension
    }
         for (unsigned int j = 0; j < i+1; j++)
        pp[i][j] = calloc(10, sizeof(char));

  }

  return pp;
}

char* **resign (char* **pp, unsigned int len)
{
  if (pp)
  {
    for (unsigned int i = 0; i < len; i++)
      if (pp[i])
      {
        for (unsigned j=0; j<i; j++)
            if(pp[i][j])
            free(pp[i][j]);
        free (pp[i]);
      }
    free (pp);
  }

  return 0;
}

void show (char* **pp, unsigned int len)
{
  for (unsigned int i = 0; i < len; i++)
  {
    for (unsigned int j = 0; j <= i; j++)
      printf ("[%u][%u] %s  ", i, j, pp[i][j]);
    printf ("\n");
  }
}


// Alternativen (1. Parameter: call by reference)

int create_2 (char* ***ppp, unsigned int len)
{
  *ppp = (char***) malloc (len * sizeof(char**));
  if (*ppp == 0)
    return 1;  // Fehler in 1. Dimension

  for (unsigned int i = 0; i < len; i++)
  {
    (*ppp)[i] = (char**) calloc (i+1, sizeof(char*));
    if ((*ppp)[i] == 0)
    {
      resign_2 (ppp, len);
      return 2;  // Fehler in 2. Dimension
    }
          for (unsigned int j = 0; j < i+1; j++)
        (*ppp)[i][j] = (char*) calloc(10, sizeof(char));
  }

  return 0;  // okay
}


int resize_2 (char* ***ppp, unsigned int alt, unsigned int neu)
{
  *ppp = (char***) realloc (*ppp, neu * sizeof(char**));
  if (*ppp == 0)
    return 1;  // Fehler in 1. Dimension

  for (unsigned int i = alt; i < neu; i++)
  {
    (*ppp)[i] = (char**) calloc (i+1, sizeof(char*));
    if ((*ppp)[i] == 0)
    {
      resign_2 (ppp, neu);
      return 2;  // Fehler in 2. Dimension
    }
    for (unsigned int j = 0; j < i+1; j++)
        (*ppp)[i][j] = calloc(10, sizeof(char));

  }

  return 0;  // okay
}


void resign_2 (char* ***ppp, unsigned int len)
{
  if (*ppp)
  {
    for (unsigned int i = 0; i < len; i++)
      if ((*ppp)[i])
      {
        for (unsigned j=0; j<i; j++)
            if((*ppp)[i][j])
            free((*ppp)[i][j]);
        free ((*ppp)[i]);
      }

    free (*ppp);
    *ppp = 0;
  }
}
