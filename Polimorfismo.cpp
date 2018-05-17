#include <iostream>

using namespace std;

class Personaje
{
	int altura;
public:
	Personaje(int altura=10): altura(altura) {}
	virtual int atacar()
	{
		cout<<"ataco como personaje"<<endl;
		return 10;
	}
	
	virtual ostream& print (ostream& o=cout) const {o<<"soy personaje"<<endl; return o;}
};

ostream& operator << (ostream& o, const Personaje& p)
{
	p.print(o);
	return o;
}

class Mago :public Personaje
{
	int atacar()
	{
		cout<<"ataco como mago"<<endl;
		return 100;
	}
	
	ostream& print (ostream& o=cout) const {o<<"soy mago"<<endl; return o;}
};

class Guerrero :public Personaje
{
public:
	int atacar()
	{
		cout<<"ataco como guerrero"<<endl;
		return 4;
	}
	ostream& print (ostream& o=cout) const {o<<"soy guerrero"<<endl; return o;}
};

void atacar (Personaje &p)
{
	p.atacar();
}

int main(int argc, char** argv) 
{
	Mago m;
	atacar(m);
	
	Guerrero g;
	atacar(g);
	
	cout<<m<<g;
	
	return 0;
}
