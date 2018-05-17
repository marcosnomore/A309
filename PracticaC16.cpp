#include <iostream>
#include <fstream>

using namespace std;

class Punto2D
{
private:
	double x, y;
public:
	Punto2D():x(10.0), y(20.0) {}
	Punto2D operator + (const Punto2D & );
	ostream& printf(ostream & o=cout) const;
	friend Punto2D operator + (double k, Punto2D p);
	Punto2D operator + (double k);
	
	//función independiente suma
//	friend Punto2D operator + (const Punto2D p1, const Punto2D p2);
	bool operator ! ();
};

Punto2D operator + (double k, Punto2D p)
{
	Punto2D res(p);
	res.x+=k;
	res.y+=k;
	return res;
}

Punto2D Punto2D::operator + (double k)
{
	Punto2D res(*this);
	res.x+=k;
	res.y+=k;
	return res;
}

Punto2D Punto2D::operator + (const Punto2D & b)
{
	Punto2D res(*this);
	res.x+=b.x;
	res.y+=b.y;
	return res;
}

/* Punto2D operator + (const Punto2D p1, const Punto2D p2)
{
	Punto2D res(p1);
	res.x+=p2.x;
	res.y+=p2.y;
}	*/

ostream& Punto2D::printf(ostream & o) const
{
	o<<"["<<x<<", "<<y<<"]"<<endl;
	return o;
}

bool Punto2D::operator ! ()
{
	return (x==0.0 && y==0.0);
}

int main() 
{
	Punto2D p;
	Punto2D p1;

	(p+p1).printf();
	
	ofstream f("punto.txt", ios::out);
	(p+p1).printf(f);
	f.close();
	
	Punto2D p3=3.0+p;
	p3.printf();
	
	return 0;
}
