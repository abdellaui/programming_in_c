#include <iostream>
# include <cmath>
  using namespace std;
  // ****************************************
  // Hier bitte die Funktion
   double geom(int laenge , double a[]){
    double ruckgabe = 1.;
   for(int x = 0; x<laenge; x++) {
        if(a[x]<0){
            ruckgabe=0;
            break;
        }
        ruckgabe *= a[x];
   }

   ruckgabe = pow(ruckgabe,1./laenge);
   return ruckgabe;
   }
  // fuer das geometrische Mittel ergaenzen
  // *****************************************
  int main () {
    const int anzahl = 12;
    double a[ anzahl ] = {13.2 ,31.67 ,81.22 ,25.51 ,91.78 ,35.99 ,75.17 ,44.0 ,68.5 ,16.5 ,39.1 ,31.45};
    // Hier bitte geom () aufrufen und das Ergebnis ausgeben;
   cout << geom(anzahl ,a);
    return 0;
  }
