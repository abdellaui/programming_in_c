// Programmieren in C, RUB, WS 2016/17, Kapitel 13
// Bspl.: Ersetzen eines Zeichens in einem String
// Datei: zeichen_ersetzen.c
// Standard: C99-C11

// Demonstriert verschiedener Varianten

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* ersetzen(const char* s, const char c, const char durch)
{
    char ergebnis[strlen(s)];
    strcpy(ergebnis,s);
    char* hier = strchr(ergebnis,c);
    while (hier != NULL)

    {
        *hier = durch;
        hier = strchr(hier+1,c);
    }

    return ergebnis;

}

// Ersetzen "in place"
char* ersetzenIP(char s[], const char c, const char durch)
{

    char* hier = strchr(s,c);
    while (hier != NULL)
    {
        *hier = durch;
        hier = strchr(hier+1,c);

    }

    return s;
}

char* ersetzenHeap(const char* s, const char c, const char durch)
{
    char* ergebnis = (char*) calloc(strlen(s), sizeof (char));
    strcpy(ergebnis,s);
    char* hier = strchr(ergebnis,c);
    while (hier != NULL)

    {
        *hier = durch;
        hier = strchr(hier+1,c);
    }

    return ergebnis;

}

// Alternative Implementierungen mit char-arrays:

char* ersetzen2(const char* s, const char c, const char durch)
{

    int lng = strlen(s);
    char ergebnis[lng+1];
    for (int i=0; i < lng; i++)
        if(s[i] == c)
            ergebnis[i] = durch;
        else
            ergebnis[i] = s[i];

    ergebnis[lng] = '\0';

    return ergebnis;

}

char* ersetzen2IP(char s[], const char c, const char durch)
{
    int i=0;
    while(s[i] != '\0')
    {
        if(s[i] == c)
            s[i] = durch;
        i++;
    }

    return s;
}


char* ersetzen2Heap(const char* s, const char c, const char durch)
{

    int lng = strlen(s);
    char* ergebnis = (char*) calloc(lng+1, sizeof (char));
    for (int i=0; i < lng; i++)
        if(s[i] == c)
            ergebnis[i] = durch;
        else
            ergebnis[i] = s[i];

    ergebnis[lng] = '\0';

    return ergebnis;

}
int main()

{

    {
        char s[] = "Hahaha!";
        char nachher[20];
        strcpy(nachher, ersetzen(s,'a','o'));
        printf("1s     : %s\n",s);
        printf("nachher: %s\n",nachher);

    }


    {
        char s[] = "Hahaha!";
        char nachher[20];
        strcpy(nachher, ersetzenIP(s,'a','o'));
        printf("2s     : %s\n",s);
        printf("nachher: %s\n",nachher);

    }


    {
        char s[] = "Hahaha!";
        char nachher[20];
        strcpy(nachher, ersetzen2(s,'a','o'));
        printf("3s     : %s\n",s);
        printf("nachher: %s\n",nachher);

    }


    {
        char s[] = "Hahaha!";
        char nachher[20];
        strcpy(nachher, ersetzen2IP(s,'a','o'));
        printf("4s     : %s\n",s);
        printf("nachher: %s\n",nachher);
    }

    {
        char s[] = "Hahaha!";
        char nachher[20];
        strcpy(nachher, ersetzenHeap(s,'a','o'));
        printf("5s     : %s\n",s);
        printf("nachher: %s\n",nachher);

    }

    {
        char s[] = "Hahaha!";
        char nachher[20];
        strcpy(nachher, ersetzen2Heap(s,'a','o'));
        printf("6s     : %s\n",s);
        printf("nachher: %s\n",nachher);

    }

    return 0;
}
