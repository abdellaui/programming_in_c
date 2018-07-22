#include <iostream>
#include "Simple_class.cpp"

int main(){
	Simple_class x(10);
	int z = x.get();
	x.set(40);
	x.get();
	return 0;
}
