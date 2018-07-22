// Programmieren in C, RUB, WS 2016/17, Kapitel 2
// Bspl.: Wertbereiche und Speicherbedärfe einiger Datentypen
// Datei: wertebereiche.c
// Standard: C99-C11

// Ausgeschrieben werden die Grenzen (kleinster bzw. größter Wert) einiger Datentypen.

// Für Gleitpunkt-Typen wird zusätzlich die Genauigkeit ausgegeben.

// Ferner wird für einige Variablen der Speicherbedarf bestimmt.

#include <float.h>
#include <limits.h>
#include <stdio.h>

int main ()
{
  // Variablen
  char c; short s; int i; long l;
  float f; double d; long double ld;


  // Ganzzahlige Typen

  printf ("Kleinster char-Wert     : %d\n"  , CHAR_MIN);
  printf ("Groesster char-Wert     : %d\n\n", CHAR_MAX);

  printf ("Kleinster int-Wert      : %d\n"  , INT_MIN );
  printf ("Groesster int-Wert      : %d\n\n", INT_MAX );
  printf ("Groesster unsigned int  : %u\n\n", UINT_MAX);


  // Gleitpunkt-Typen
  // Formatelement %e und %Le zur Ausgabe mit Exponentialteil

  printf ("Kleinste positive Werte:\n");
  printf ("  fuer Datentyp float   : %e\n"   , FLT_MIN );
  printf ("  fuer Datenytp double  : %e\n"   , DBL_MIN );
  printf ("  fuer long double      : %Le\n\n", LDBL_MIN);

  printf ("Groesste Werte (absolut):\n");
  printf ("  fuer Datentyp float   : %e\n"   , FLT_MAX );
  printf ("  fuer Datenytp double  : %e\n"   , DBL_MAX );
  printf ("  fuer long double      : %Le\n\n", LDBL_MAX);


  // Formatelement %2d legt 2 Dezimalstellen für die Ausgabe fest.

  printf ("Genauigkeit float       : %2d Dezimalziffern\n"  , FLT_DIG );
  printf ("Genauigkeit double      : %2d Dezimalziffern\n"  , DBL_DIG );
  printf ("Genauigkeit long double : %2d Dezimalziffern\n\n", LDBL_DIG);


  // Es wird bei der Ausgabe angenommen, dass das Ergebnis von sizeof
  // als unsigned int verwertbar ist (Referenzsystem). Daher wird das
  // Formatelement %2u (= 2 Dezimalstellen, vorzeichenlos) benutzt.

  printf ("Ein char-Wert   benoetigt %2u Byte(s).\n", sizeof c );
  printf ("Ein short-Wert  benoetigt %2u Byte(s).\n", sizeof s );
  printf ("Ein int-Wert    benoetigt %2u Byte(s).\n", sizeof i );
  printf ("Ein long-Wert   benoetigt %2u Byte(s).\n", sizeof l );
  printf ("Ein float-Wert  benoetigt %2u Byte(s).\n", sizeof f );
  printf ("Ein double-Wert benoetigt %2u Byte(s).\n", sizeof d );
  printf ("Ein long double benoetigt %2u Byte(s).\n", sizeof ld);

  return 0;
}
