// Programmieren in C, RUB, WS 2016/17, Kapitel 15
// Bspl.: Dreiecksmatrix aus Strings
// Datei: lower_triangle_matrix.h
// Standard: C99-C11

// Dreiecksmatrix aus Strings als dynamische Datenstruktur, siehe Skript

// Prototypen
char***create (unsigned int);

char* **resize (char* **, unsigned int, unsigned int);
char* **resign (char* **, unsigned int);
void     show  (char* **, unsigned int);


// Prototypen: alternative Rückgabe der Ergebnisse über Parameter (call by reference)
int  create_2 (char* ***, unsigned int);
int  resize_2 (char* ***, unsigned int, unsigned int);
void resign_2 (char* ***, unsigned int);


