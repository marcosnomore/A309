#include <iostream>
#include <string>

using namespace std;

class IObjeto
{
public:
	virtual string get_name() = 0;	//función virtual pura. Todas las clases derivadas tienen que tener una función definida con el mismo nombre y argumentos.
	virtual int get_grosor() = 0;
};

class Armas: public IObjeto
{
	int grosor;
	
public:
	int get_grosor() {return grosor;}
};

class Espada: public Armas
{
	string name;
	
public:
	Espada(string str="Tizona"): name(str) {}
	string get_name() {return name;}
};

string foo(IObjeto * o)		//caso de uso de la jerarquía
{
	return(o->get_name());
}

class IFibo
{
public:
	virtual int fibo(int n)=0;
};

class FiboA: public IFibo
{
	int fibo(int n){cout<<"soy fibo A"<<endl; return 0;}
};

class FiboB: public IFibo
{
	int fibo(int n){cout<<"soy fibo B"<<endl; return 0;}
};

class FiboEngine
{
	IFibo* pf;
public:
	FiboEngine(IFibo* p): pf(p){}
	int fibo(int n)
	{
		return pf->fibo(n);
	}
};

int main() 
{
	Espada e;
	
	IObjeto * po= new Espada("Excalibur");
	
	cout<<foo(&e)<<endl;
	cout<<foo(po)<<endl;
	
	FiboEngine f=new FiboA;
	f.fibo(10);
	
	FiboEngine f1=new FiboB;
	f1.fibo(20);
	
	return 0;
}
