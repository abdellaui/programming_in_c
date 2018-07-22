#include <iostream>
#include "count_13th.h";
#include "Weekday_statistics.h"
using namespace std;

int main()
{
    Weekday_statistics w = count_13th(1900, 399);
    cout << w.get_monday_value()<<endl;
    cout << w.get_tuesday_value()<<endl;
    cout << w.get_wednesday_value()<<endl;
    cout << w.get_thursday_value()<<endl;
    cout << w.get_friday_value()<<endl;
    cout << w.get_saturday_value()<<endl;
    cout << w.get_sunday_value()<<endl;
}
