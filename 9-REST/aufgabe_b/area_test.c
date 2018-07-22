// Programmieren in C, RUB, WS 2016/17, Kapitel 11/12
// Bspl.: Spielfeld
// Datei: area_test.c
// Standard: C99-C11

// Test der Spielfeld-Funktionen initArea und showArea

#include <stdio.h>
#include "area.h"

int nextStep (struct Ameise *, int len, char (*)[len]){
    if(ameise->x < len && ameise->x >= 0 && ameise->y < len && ameise->y >= 0){
        if(area[ameise->y][ameise->x]==' '){
            area[ameise->y][ameise->x]='#';
            if(ameise->blick==3){
                ameise->blick=0;
            }else{
                ameise->blick++;
            }
        }else{
            area[ameise->y][ameise->x]=' ';
            if(ameise->blick==0){
                ameise->blick=3;
            }else{
                ameise->blick--;
            }
        }
            switch(ameise->blick) {
                case 0: ameise->y--; break;
                case 1: ameise->x++; break;
                case 2: ameise->y++; break;
                case 3: ameise->x--; break;
                default: printf("Fehler\n"); break;
            }
        return 1;
    }else{
        return 0;
    }
}
int main ()
{
  /*

  char test [][5] = {"ABCDE",
                     "BCDEA",
                     "CDEAB",
                     "DEABC",
                     "EABCD"};
  showArea (5, test);
  initArea (5, test);
  showArea (5, test);
  printf ("\n");
*/

  // Eingabe
  int laenge;
  long schritt;
  printf ("Rastergroesse: ");
  scanf ("%d", &laenge);
  printf ("Schrittzahl: ");
  scanf ("%ld", &schritt);
  if (laenge < 1 || schritt < 1)
  {
    printf ("Rastergroesse oder Schrittzahl zu klein!\n");
    return 9999;
  }

  printf ("\n");
  char raster[laenge][laenge];
  initArea (laenge, raster);


  struct Ameise ameise={laenge/2,laenge/2,2};

  for(long x = 0; x <schritt;x++){
    if(!nextStep(&ameise, laenge, raster)){
        printf ("Rand ueberschritten bei : %ld\n",x);
        break;
    }
  }
  showArea(laenge, raster);

  return 0;
}
