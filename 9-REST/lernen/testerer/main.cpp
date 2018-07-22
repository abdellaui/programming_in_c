#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Prozessor{
public:
	virtual string name() = 0;
	virtual int procbitw() = 0;
	virtual string procfun(){return "asdasd";};
};
class ARM: public Prozessor{
public:
	string name(){return "ARM";};
	int procbitw(){return 345;};
	string procfun(){return "basic";};
};
class ARMv7: public ARM{
public:
	int procbitw(){return 32;};
	string procfun(){return "VFP";};
};
class ARMv8: public ARM{
public:
	int procbitw(){return 64;};
	string procfun(){return "VFP, NEON";};
};

int main(){

	const unsigned int n_c = 4;
	Prozessor*HetQuadCore[n_c] = {new ARMv7, new ARMv7, new ARMv8, new ARMv8};
	for(int i=0; i<n_c; i++){
	cout << HetQuadCore[i]->procbitw() << endl;
	cout << HetQuadCore[i]->procfun() << endl;
	}
	/*ARMv8* Core32 = (ARMv8*) HetQuadCore[0];
	for(int i = 0; i < n_c; i++){
            cout << Core32->procfun() << endl;
            cout << "Bitwidth is " << HetQuadCore[i]->procbitw() << endl;
        Core32++;
*/

	return 0;
}
