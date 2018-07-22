/* Programmieren in C, RUB, WS 2016/17, Kapitel 15
   Bspl.: Warteschlange
   Datei: schlange.h
   Standard: C90-C99-C11 */

/* Der Typ 'Schlange' wird hier mittels 'typedef' vereinbart (Kapitel 16). */

struct Element
{
  char inhalt[31];
  struct Element *nach;
};

typedef struct
{
  struct Element *start, *ende;
  int zaehler;
}
Schlange;

/* Prototypen */
extern void anhaengen (Schlange*, const char*);
extern int  entnehmen (Schlange*, char*);
extern void show      (const Schlange);
