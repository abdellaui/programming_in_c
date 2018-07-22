#include <stdio.h>
void strichZiehen(int laenge){
    int j;
    printf("+");
     for (j = 0; j < laenge; j++)
        printf("-");
    printf("+\n");
}

void initArea (int len, char (*area)[len]){
    int j,a;
        for (j = 0; j < len; j++){
            for (a = 0; a < len; a++){
                    area[j][a] = ' ';
            }
        }
}

void showArea (int len, char (*area)[len]){
    strichZiehen(len);
    int j,a;
        for (j = 0; j < len; j++){
        printf("|");
            for (a = 0; a < len; a++){
            printf ("%c", area[j][a]);
            }
        printf("|\n");
        }
    strichZiehen(len);
}
