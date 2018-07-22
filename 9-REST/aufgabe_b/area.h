#ifndef AREA_H_INCLUDED
#define AREA_H_INCLUDED
struct Ameise{int x,y,blick;};
void strichZiehen(int laenge);
void initArea (int len, char (*area)[len]);
void showArea (int len, char (*area)[len]);
#endif // AREA_H_INCLUDED
