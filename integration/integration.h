// Programmieren in C, RUB, WS 2016/17, Kapitel 9
// Bspl.: Integration
// Datei: integration_main.c
// Standard: C99-C11

// Numerische Integration

// Globale Deklaration
extern unsigned int n;

// Prototypen
// ... die zu integrierende Funktion
extern double func (double);
// ... Berechnung des Integrals in den Grenzen
extern double integral (double, double);
