#include <iostream>
#include <string>
using namespace std;

class Prozessor{
public:
	virtual string name() = 0;
};
class ARM: public Prozessor{
public:
	string name(){return "ARM";};
	virtual int procbitw() = 0;
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
	ARM *HetQuadCore[n_c] = {new ARMv7, new ARMv7, new ARMv8, new ARMv8}
	for(int i=0;i<n_c;i++){
	cout << HetQuadCore[i]->procbitw() << endl;
	cout << HetQuadCore[i]->procfun() << endl;
	}
	return 0;
}
