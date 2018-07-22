#include <iostream>
#include "Simple_class.h"
	int Simple_class::get(){
		std::cout << eingabe << std::endl;
		return eingabe;
	}
	int Simple_class::set(int x){
		eingabe = x;
	}
