#include <stdio.h>
#include <stdlib.h>
#include "datumrechner.h"
#include "zkfunc.h"
int main(){
    char *nameTage[] = {"Samstag","Sonntag","Montag","Dienstag","Mittwoch","Donnerstag","Freitag","Fehler"};
    char *nameMonate[] = {"Fehleingabe","Januar","Februar","Maerz","April","Mai","Juni","Juli","August","September","Oktober","November","Dezember"};
    int tagHaeufigkeit[7] = {0};  // Speicher für die Haeufigkeit der jeweiligen Tage-> Anfangswert 0
    int extremaTage[7];           // Maximal Haeufigkeit Speicher -> 7 Felder siehe Taganzahl
    int monateGesamt = 4800, gesuchterTag = 13, zaehler = 0, maxi = 0, jahr, tag, monat, monatEingabe, jahrEingabe;
    printf("Eingabe Datum [TT.MM.JJJJ]:\n");
    scanf("%2d.%2d.%4d", &tag, &monat, &jahr);
    if(tag>=1&&tag<=getAnzahlTageImMonat(monat,jahr)&&monat>=1&&monat<=12&&jahr>=1582){ // Datum->Jahr muss größer/gleich als 1582 sein da siehe Wikipedia greg. Kalender. Datum->Tag und Datum->Monat müssen im Verhältnis gültig sein z.b. hat Feb. bei Schaltjahren 29 Tage.
        printf("\nDer %d. %s %d ist ein %s.\n\n", tag,nameMonate[monat],jahr,nameTage[zellersKon((double)tag,(double)monat, jahr)]);
        if(tag>13){             //Wenn Datum->Tag > 13  (Man zählt diesen Monat nicht mit)
            printf("Hinweis: Da die Eingabe des Tages > 13 ist, wird ab dem naechstem Monat ggbfs. Jahr nach dem 13. Tag der jeweiligen Monate, der naechsten 400 Jahre, berechnet!\n\n");
            if(monat==12){      //\-> \-> Wenn Datum->Monat == 12
                monat=1;        //    \-> dann Datum->Monat = 1 und Datum->Jahr +=1
                jahr++;
            }else{
                monat++;        //\-> dann Datum->Monat +=1
            }
        }
        monatEingabe=monat;
        jahrEingabe=jahr;
        for(int x=0;x<monateGesamt;x++){
            //printf("Kom: %d\n",zellersKon(13,(long)monat, jahr));
            tagHaeufigkeit[zellersKon(gesuchterTag,(double)monat, jahr)] += 1;  //Rückgabewert 0-6 -> Setzte Array->tagHaeufigkeit in Feld mit jeweiligem Rückgabewert Wert +=1
            if(monat%12==0){// Wenn Monat = 12
            monat=1;         // \-> dann setzte Monat = 1
            jahr++;          // \-> und Jahr += 1
            }else{
            monat++;         // \-> sonst setzte Monat += 1;
            }
        }
        for(int c=0; c<7; c++){
            if(tagHaeufigkeit[c]>maxi){ // Selektion maximal Wert
                maxi = tagHaeufigkeit[c];
            }
        }
    for(int z=0;z<7;z++){ // Ausgabe der jeweiligen Felder von 0-6 in Array->tagHaeufigkeit
        if(tagHaeufigkeit[z]==maxi){ // Wenn maximal Wert mit eigeneim Wert übereinstimmt, dann speichere es im Zwischenspeicher "Array"->extremaTage im Feld = 0
            extremaTage[zaehler] = z;
            zaehler++;                       // \-> Dann setzte Zähler um 1 hoch, sodass ggbfs. nächster Wert im Feld +1 gespeichert wird.
        }
        printf("    %d / %d    %s\n",tagHaeufigkeit[z],monateGesamt,nameTage[z]);
    }
    printf("\nZwischen %d. %s %d und %d. %s %d hat / haben die maximale Haeufigkeit:\n\n",gesuchterTag,nameMonate[monatEingabe],jahrEingabe,gesuchterTag,nameMonate[monat],jahr);
    for(int a=0;a<zaehler;a++){ // Ausgabe der jeweiligen Felder mit maximalen Wert im Feldbereich 0 bis Wert von zaehler.
        printf("    %s\n\n", nameTage[extremaTage[a]]);
        }
    }else{
    printf("Bitte gebe ein gueltiges Datum im gregorianischen Kalender ein (Jahr > 1581)! Beachte auf die Formatierung [TT.MM.JJJJ]!");
    }

    return 0;
}
