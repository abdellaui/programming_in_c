#ifndef SIMPLE_CLASS_H_INCLUDED
#define SIMPLE_CLASS_H_INCLUDED
class Simple_class{
	int eingabe;
public:
	Simple_class(int x) : eingabe(x){};
	int get();
	int set(int x);
};
#endif // SIMPLE_CLASS_H_INCLUDED
