#include <iostream>

using namespace std;

struct coord_t
{
	float x, y, z;
	coord_t(float x, float y, float z): x(x), y(y), z(z) {}
	ostream& print (ostream& =cout);
};

ostream& coord_t::print (ostream& o)
{
	o<<"["<<x<<","<<y<<","<<z<<"]"<<endl;
	return o;
}

class Esfera
{
public:
	float r;
	coord_t c;
	Esfera(float radio, coord_t coor): r(radio), c(coor) {;}
	Esfera(const Esfera& e): r(e.r), c(e.c) {;}
	ostream& print (ostream& =cout);
};

ostream& Esfera::print (ostream& o)
{
	o<<"Esfera con radio: "<<r<<" y coordenadas: ";
	c.print(o);
	return o;
}
