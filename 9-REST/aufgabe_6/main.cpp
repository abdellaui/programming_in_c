    #include <iostream >
    using namespace std ;

    int var_a = 23;

    void funktion1 () {
        cout << " Funktion 1" << endl ;
        cout << " var_a = " << var_a << endl ;
        int var_a = 99;
        cout << " var_a = " << var_a << endl ;
    }

    void funktion2 ( int var_a ) {
        cout << " Funktion 2" << endl ;
        cout << " var_a = " << var_a << endl ;
        var_a = var_a + 2;
        cout << " var_a = " << var_a << endl ;
    }

    int funktion3 () {
        cout << " Funktion 3" << endl ;
        cout << " var_a = " << var_a << endl ;
        var_a ++;
        if ( var_a > 12) {
            int var_a = 19;
            cout << " var_a = " << var_a << endl ;
        }
        else if ( var_a > 5) {
            int var_a = 0;
            cout << " var_a = " << var_a << endl ;
        }
        else {
            int var_a = 31;
            cout << " var_a = " << var_a << endl ;
        }
        cout << " var_a = " << var_a << endl ;
        return var_a ;
    }

    int main () {
        funktion1 ();
        int * pVar_a = & var_a ;
        funktion2 (* pVar_a );
        var_a = 1.5 * funktion3 ();
        cout << "Main - Funktion " << endl ;
        cout << " var_a = " << var_a << endl ;
        return 0;
      }
