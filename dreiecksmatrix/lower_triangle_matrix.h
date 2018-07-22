// Programmieren in C, RUB, WS 2016/17, Kapitel 15
// Bspl.: Dreiecksmatrix
// Datei: lower_triangle_matrix.h
// Standard: C99-C11

// Dreiecksmatrix als dynamische Datenstruktur, siehe Skript

// Prototypen
double **create (unsigned int);
double **resize (double**, unsigned int, unsigned int);
double **resign (double**, unsigned int);
void     show   (double**, unsigned int);

// Prototypen: alternative Rückgabe der Ergebnisse über Parameter (call by reference)
int  create_2 (double***, unsigned int);
int  resize_2 (double***, unsigned int, unsigned int);
void resign_2 (double***, unsigned int);
