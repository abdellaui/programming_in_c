// Programmieren in C, RUB, WS 2016/17, Kapitel 15
// Bspl.: Dreiecksmatrix
// Datei: lower_triangle_matrix.h
// Standard: C99-C11

// Dreiecksmatrix als dynamische Datenstruktur, siehe Skript

#include <stdio.h>
#include <stdlib.h>
#include "lower_triangle_matrix.h"

double **create (unsigned int len)
{
    double **pp = (double**) malloc (len * sizeof(double*));
    if (pp == 0)
        return 0;  // Fehler in 1. Dimension

    for (unsigned int i = 0; i < len; i++)
    {
        pp[i] = (double*) calloc (i+1, sizeof(double));
        if (pp[i] == 0)
        {
            resign (pp, len);
            return 0;  // Fehler in 2. Dimension
        }
    }

    return pp;
}

double **resize (double **pp, unsigned int alt, unsigned int neu)
{
    pp = (double**) realloc (pp, neu * sizeof(double*));
    if (pp == 0)
        return 0;  // Fehler in 1. Dimension

    for (unsigned int i = alt; i < neu; i++)
    {
        pp[i] = (double*) calloc (i+1, sizeof(double));
        if (pp[i] == 0)
        {
            resign (pp, neu);
            return 0;  // Fehler in 2. Dimension
        }
    }

    return pp;
}

double **resign (double **pp, unsigned int len)
{
    if (pp)
    {
        for (unsigned int i = 0; i < len; i++)
            if (pp[i])
                free (pp[i]);

        free (pp);
    }

    return 0;
}

void show (double **pp, unsigned int len)
{
    for (unsigned int i = 0; i < len; i++)
    {
        for (unsigned int j = 0; j <= i; j++)
            printf ("[%u][%u] %4.2f  ", i, j, pp[i][j]);
        printf ("\n");
    }
}


// Alternativen (1. Parameter: call by reference)

int create_2 (double ***ppp, unsigned int len)
{
    *ppp = (double**) malloc (len * sizeof(double*));
    if (*ppp == 0)
        return 1;  // Fehler in 1. Dimension

    for (unsigned int i = 0; i < len; i++)
    {
        (*ppp)[i] = (double*) calloc (i+1, sizeof(double));
        if ((*ppp)[i] == 0)
        {
            resign_2 (ppp, len);
            return 2;  // Fehler in 2. Dimension
        }
    }

    return 0;  // okay
}

int resize_2 (double ***ppp, unsigned int alt, unsigned int neu)
{
    *ppp = (double**) realloc (*ppp, neu * sizeof(double*));
    if (*ppp == 0)
        return 1;  // Fehler in 1. Dimension

    for (unsigned int i = alt; i < neu; i++)
    {
        (*ppp)[i] = (double*) calloc (i+1, sizeof(double));
        if ((*ppp)[i] == 0)
        {
            resign_2 (ppp, neu);
            return 2;  // Fehler in 2. Dimension
        }
    }

    return 0;  // okay
}

void resign_2 (double ***ppp, unsigned int len)
{
    if (*ppp)
    {
        for (unsigned int i = 0; i < len; i++)
            if ((*ppp)[i])
                free ((*ppp)[i]);

        free (*ppp);
        *ppp = 0;
    }

}
