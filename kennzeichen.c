// Programmieren in C, RUB, WS 2016/17, Kapitel 14
// Bspl.: KFZ-Kennzeichen
// Datei: kennzeichen.c
// Standard: C99-C11

// Siehe Skript Kapitel 14 (im Text fortlaufendes Beispiel)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//*** Vereinbarung des Strukturtyps (global) ***
struct KfzKenn
{
  char *ort;
  char bubu[3];
  unsigned int zahl;
};

// Prototypen
void show (const struct KfzKenn);
void folgeZahl (struct KfzKenn *);
struct KfzKenn scanKfzKennzeichen ();

int main ()
{
  //*** Vereinbarung/Initialisierung einer Strukturvariablen ***

  struct KfzKenn meinAuto = {"BO", "C", 2013};

  printf ("Start Demo\n");
  show (meinAuto);

  //*** Zugriffe ***********************************************

  printf ("\nZugriffe auf Komponenten\n");
  meinAuto.ort = "EN";
  strcpy (meinAuto.bubu, "TE");
  meinAuto.zahl = 99;
  show (meinAuto);

  //*** Wertzuweisung ******************************************

  struct KfzKenn meinKrad;

  printf ("\nWertzuweisung\n");
  meinKrad = meinAuto;
  meinKrad.ort     = "HER";
  meinKrad.bubu[0] = 'N';
  show (meinAuto);
  show (meinKrad);

  //*** Aufruf Funktionen **************************************

  printf ("\nAufruf Funktionen\n");
  show (meinAuto);
  folgeZahl (&meinAuto);
  show (meinAuto);

  //*** Aufruf Eingabe-Funktion ********************************

  printf ("\nAufruf Eingabe-Funktion\n");
  meinKrad = scanKfzKennzeichen ();
  printf ("Funktionsergebnis gespeichert\n");
  show (meinKrad);

  //*** Array von Strukturen ***********************************

  struct KfzKenn fuhrpark[500] = {{""}};

  printf ("\nArray von Strukturen\n");
  printf ("Gesamtlaenge %d Bytes\n", sizeof fuhrpark);
  fuhrpark[222]         = meinAuto;
  fuhrpark[222].bubu[0] = 'G';
  show (fuhrpark[222]);

  return 0;
}

//*** Funktion mit Parameter vom Strukturtyp ***
void show (const struct KfzKenn k)
{
  printf ("Kennzeichen: %s %s %d\n", k.ort, k.bubu, k.zahl);
}

//*** Funktion mit Parameter vom Zeigertyp ***
void folgeZahl (struct KfzKenn *p)
{
  p->zahl++;
}

//*** Funktion mit Strukturtyp als Ergebnis ***
struct KfzKenn scanKfzKennzeichen ()
{
  struct KfzKenn k;

  printf ("Keine Leerzeichen eingeben!\n");
  printf ("Laengen beachten!\n");

  k.ort = (char*) calloc (4, sizeof(char));
  printf ("Ort (max 3): ");
  scanf  ("%3s", k.ort);

  printf ("Buchstaben (max 2): ");
  scanf  ("%2s", k.bubu);

  printf ("Zahl: ");
  scanf  ("%u", &k.zahl);

  printf ("\nGelesen wurde\n");
  show (k);

  return k;
}
