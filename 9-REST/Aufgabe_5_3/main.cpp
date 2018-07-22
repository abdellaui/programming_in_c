# include <iostream>

using namespace std;
void tester(char word[6]){
    for(unsigned int x = 0; word[x]!='\0'; x++){
        cout << word[x];
        }
}

void invers(char word[6]){
    int anzahl = 0;
    char zwischenSpeicher[100];
    for(unsigned int x = 0; word[x]!='\0'; x++){anzahl++;}
    for(unsigned int x = 0; x < anzahl; x++){
         zwischenSpeicher[anzahl-1-x] = word[x];
        }
        word = zwischenSpeicher;
        tester(word);
}

int main () {
        // Aufruf Ihrer Funktionen und Ausgabe des Ergebnis
        char word[] = { 'E', 'l', 'e', 'f', 'a', 'n', 't', '\0' };
        invers(word);
return 0;
}
