#include <stdio.h>
#include <stdlib.h>
int istEinSchaltjahr(int uJahr){
  if ((uJahr % 400) == 0){
    return 1;
  }else if ((uJahr % 100) == 0){
    return 0;
  }
  else if ((uJahr % 4) == 0){
    return 1;
  }
  return 0;
}
int getAnzahlTageImMonat(int uMonat,int uJahr){
  //                      ungült,Jan,Feb,Mrz,Apr,Mai,Jun,Jul,Aug,Sep,Okt,Nov,Dez
  int arrTageImMonat[13] = {  0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

  if (uMonat == 2)
  {
    if (istEinSchaltjahr(uJahr)){ // Februar: Schaltjahr unterscheiden
      return 29;
    }else{
      return 28;
    }
  }
  if ((uMonat >= 1) && (uMonat <= 12)){
    return arrTageImMonat[uMonat];
  }else
  {
    return 0; // ungültiger Monat !
  }
}
