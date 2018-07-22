#include <stdio.h>
#include <stdlib.h>
int main(){
  FILE *in = fopen ("eingabe.txt", "r");

  if (in == 0){
    printf ("Problem: Die Eingabe-Datei existiert nicht!\n");
  }else{
    char line[256];

    while (fgets(line, 256, in)){

            printf("%s", line);
    }

    fclose (in);
  }

  return 0;
}
