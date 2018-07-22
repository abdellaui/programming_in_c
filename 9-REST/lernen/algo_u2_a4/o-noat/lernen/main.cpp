#include <iostream>
#include <math.h>
class Weekday_statistics{
        int monday;
        int tuesday;
        int wednesday;
        int thursday;
        int friday;
        int saturday;
        int sunday;
    public:
        Weekday_statistics();
        // SETTER
        void set_monday_value(int);
        void set_tuesday_value(int);
        void set_wednesday_value(int);
        void set_thursday_value(int);
        void set_friday_value(int);
        void set_saturday_value(int);
        void set_sunday_value(int);
        // GETTER
        int get_monday_value();
        int get_tuesday_value();
        int get_wednesday_value();
        int get_thursday_value();
        int get_friday_value();
        int get_saturday_value();
        int get_sunday_value();
};

Weekday_statistics::Weekday_statistics(){
    this->monday = 0;
    this->tuesday = 0;
    this->wednesday = 0;
    this->thursday = 0;
    this->friday = 0;
    this->saturday = 0;
    this->sunday = 0;
};

// SETTER
void Weekday_statistics::set_monday_value(int x){
    this->monday = x;
    };
void Weekday_statistics::set_tuesday_value(int x){
    this->tuesday = x;
    };
void Weekday_statistics::set_wednesday_value(int x){
    this->wednesday = x;
    };
void Weekday_statistics::set_thursday_value(int x){
    this->thursday = x;
    };
void Weekday_statistics::set_friday_value(int x){
    this->friday = x;
    };
void Weekday_statistics::set_saturday_value(int x){
    this->saturday = x;
    };
void Weekday_statistics::set_sunday_value(int x){
    this->sunday = x;
    };

// GETTER
int Weekday_statistics::get_monday_value(){
    return this->monday;
    };
int Weekday_statistics::get_tuesday_value(){
    return this->tuesday;
    };
int Weekday_statistics::get_wednesday_value(){
    return this->wednesday;
    };
int Weekday_statistics::get_thursday_value(){
    return this->thursday;
    };
int Weekday_statistics::get_friday_value(){
    return this->friday;
    };
int Weekday_statistics::get_saturday_value(){
    return this->saturday;
    };
int Weekday_statistics::get_sunday_value(){
    return this->sunday;
    };

    Weekday_statistics count_13th(int start_year, int year_offset){
  Weekday_statistics obj; // Ruckgabewert init.
  int tageImMonat;
  int monat = 1;
  int wochentag = 1;
  const int arrTageImMonat[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};  // Tage der Monate
  for(int k = 0; k<year_offset+1; k++){ // Schleife für offset
      for(int i=1; i<=12; i++){  // Schleife für 12 Monate in einem Jahr
          tageImMonat = arrTageImMonat[monat-1];  // Anzahl Tage im Monat via Array-Index-1 ermitteln
          if(monat==2){  // Wenn Monat = Februar -> Schaltjahrprüfung
              if ((start_year % 400) == 0){
                tageImMonat = 29;
              }else if ((start_year % 100) == 0){
                tageImMonat = 28;
              }else if ((start_year % 4) == 0){
                tageImMonat = 29;
              }
          }
          for(int x=1; x <= tageImMonat; x++){  // Schleife für Tage im Monat
            if(x==13){  // Wenn Tag = 13 dann, -- selbsterklärend --
              switch(wochentag){
              case 1: obj.set_monday_value(obj.get_monday_value()+1);
                  break;
              case 2: obj.set_tuesday_value(obj.get_tuesday_value()+1);
                  break;
              case 3: obj.set_wednesday_value(obj.get_wednesday_value()+1);
                  break;
              case 4: obj.set_thursday_value(obj.get_thursday_value()+1);
                  break;
              case 5: obj.set_friday_value(obj.get_friday_value()+1);
                  break;
              case 6: obj.set_saturday_value(obj.get_saturday_value()+1);
                  break;
              case 7: obj.set_sunday_value(obj.get_sunday_value()+1);
                  break;
              }
            }
            wochentag = (wochentag%7)+1; // 7er-Periode [1,7]
          }
           monat = (monat%12)+1;  // 12er-Periode [1,12]
      }
      start_year++;
  }
  return obj;
}
int main(){
    Weekday_statistics J = count_13th(1900,1);
    std::cout << " Mo :"<< J.get_monday_value() << std::endl;
    std::cout << " Di :"<< J.get_tuesday_value() << std::endl;
    std::cout << " Mi :"<< J.get_wednesday_value() << std::endl;
    std::cout << " Do :"<< J.get_thursday_value() << std::endl;
    std::cout << " Fr :"<< J.get_friday_value() << std::endl;
    std::cout << " Sa :"<< J.get_saturday_value() << std::endl;
    std::cout << " So :"<< J.get_sunday_value() << std::endl;
}
