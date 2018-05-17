#include <iostream>
#include <sstream>

using namespace std;

class Punto
{
private:
	float x, y;	
public:
	Punto(float a, float b): x(a), y(b) {}
	string to_string();
	friend ostream& operator << (ostream &o, const Punto& p);
	friend istream& operator >> (istream &is, Punto& p);
	//validador
	bool is_valid();
	Punto& operator ++();
	Punto operator ++(int);
};

bool Punto::is_valid()
{
	return true;
}

string Punto::to_string()
{
	stringstream sstr;
	sstr<<"["<<this->x<<", "<<this->y<<"]";
	string res(sstr.str());
	return res;	
}

ostream& operator << (ostream &o, const Punto& p)
{
	o<<"["<<p.x<<", "<<p.y<<"]";
	return o;
}

istream& operator >> (istream &is, Punto& p)
{
	char token;
	
	//leer punto
	is>>token>>p.x>>token>>p.y>>token;
	
	if(!p.is_valid())
	{
		is.setstate(ios::failbit);
	}
	
	return is;
}

Punto& Punto::operator ++()
{
	x++;
	y++;
	return *this;
}

Punto Punto::operator ++(int)
{
	Punto p(this->x, this->y);
	x++; y++;
	return p;
}

int main() 
{
	Punto p(1, 2);
	cout<<p<<endl;
	cout<<p.to_string()<<endl;
	Punto p1(3,4);
	cout<<p1++;
	cout<<p1;
	cout<<++p1;
	
	return 0;
}
