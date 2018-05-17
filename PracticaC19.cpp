#include <iostream>

class objeto
{
	int pos;
public:
	objeto(int pos): pos(pos) {}
};

class espada: public objeto
{
	bool filo;
public:
	espada (int pos, bool filo): objeto(pos), filo(filo) {} 
	espada (): objeto(0), filo(1000){}
};

class personaje
{
	int fuerza;
protected:
	personaje(int fuerza=100): fuerza(fuerza) {}
};

class mago: private espada, public personaje
{
	int sombrero;
public:
	mago(int s): sombrero(s){}
};

class conjurador: public mago
{
	int conjuro;
public:
	conjurador(int sombrero, int conj): mago(sombrero), conjuro(conj) {}
};

using namespace std;

void foo (objeto& o)
{
	cout<<"soy un objeto"<<endl;
}

int main(void) 
{
	conjurador c(10, 20);
	espada e(30, 100);
	
	foo(e);
	foo(c);
	return 0;
}
