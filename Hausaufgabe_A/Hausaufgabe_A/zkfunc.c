#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int zellersKon(double q,double m,int jahr)
        {
            double h = 0;
            double J = 0;
            double K = 0;
            switch((int)m){  // Januar Februar werden vom Vorjahr betrachted und sind mit 13/14 versehen -> Wikipedia (ab 15.12.2016)
                case 1:
                    m = 13;  // 1 (Januar) -> 13
                    jahr--;  // Vorjahr
                    break;
                case 2:
                    m = 14; // 2 (Februar) -> 14
                    jahr--; // Vorjahr
                    break;
            }
            J = jahr / 100; // Erste 2 Ziffern
            K = jahr % 100; // Letzte 2 Ziffern

            h = (int)(q + floor(( (m + 1) * 13 ) /5) + K + floor(K / 4) + floor(J / 4) + 5 * J)%7; // Formel laut Wikipedia (ab 15.12.2016) -> Gaussklammer->floor
            return h;
        }
