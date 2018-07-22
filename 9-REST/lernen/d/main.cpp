#include <iostream>
//Prototypen
void BerechnungPK(int As[], int anzahlBelegungen, int * a);
int main()
{
    const int Size = 4;
    int * a = new int[Size];
    int arr_Arbeitsstunden[] = { 23,4,9,13,51 };
	BerechnungPK(arr_Arbeitsstunden, Size, a);

    for (int i = 0; i < Size; i++)
    {
    std::cout<<a[i]<<std::endl;
    }

	// Ab hier ist int b = BerechnungPK(); -> da Referenz

    //system("pause");
    return 0;
}

//Personalkosten berechnen Funktion
void BerechnungPK(int As[], int anzahlBelegungen, int * a)
{
    int Pkh = 32;

    for (int i = 0; i < anzahlBelegungen; i++)
    {
        a[i] = As[i] * Pkh;
    }
}
