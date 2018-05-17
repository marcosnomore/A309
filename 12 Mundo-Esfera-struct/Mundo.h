#include "Esfera.h"

using namespace std;

class Mundo
{
public:
	Esfera e;
	
	ostream& print(ostream& =cout);
	Mundo(const Esfera& e);
};

Mundo::Mundo(const Esfera& e)
	: e(e)
{
	//constructor
}

ostream& Mundo::print(ostream& o)
{
	o<<"Mundo con ";
	e.print(o);
	
	return o;
}

