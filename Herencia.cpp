#include <iostream>
#include <sstream>

using namespace std;

class _PuntoBase
{
public:
	enum tipo_t{ESTRELLA=0, CRUZ, CIRCULO};
	enum col_t{AZUL=0, ROJO, NEGRO};
	static string to_string_col(col_t);
	static string to_string_type(tipo_t);
	
	int get_id() const {return id;}
	
	ostream& print (ostream& o=cout) {o<<"ID: "<<id; return o;}
protected:				//la clase que hereda puede verlo y modificarlo.
	int id;
	_PuntoBase (int id): id(id) {}		//poniendo el constructor en protected se evita que el usuario cree un _PuntoBase,
										//pero si se permite que la clase heredada lo utilice.
};

string _PuntoBase::to_string_col(col_t c)
{
	string res;
	switch (c)
	{
	case AZUL:
		res="AZUL";
		break;
	case ROJO:
		res="ROJO";
		break;
	case NEGRO:
		res="NEGRO";
		break;	
	}
	
	return res;
}

string _PuntoBase::to_string_type(tipo_t c)
{
	string res;
	switch (c)
	{
	case ESTRELLA:
		res="ESTRELLA";
		break;
	case CRUZ:
		res="CRUZ";
		break;
	case CIRCULO:
		res="CIRCULO";
		break;	
	}
	
	return res;
}


class Punto:public _PuntoBase
{
private:
	double x, y;
public:
	Punto(int id, double x=0.0, double y=0.0);
	
	ostream& print (ostream& o=cout) { _PuntoBase::print(o); o<<"["<<x<<", "<<y<<"]"; return o;}
	
	Punto& operator = (const Punto&);
};

Punto& Punto::operator = (const Punto& p)
{
	cout<<"Llamando al operador asignacion de punto"<<endl;
	if(this!=&p)
	{
		this->x=p.x;
		this->y=p.y;
		this->id=p.id;
	}
	
	return *this;
}

Punto::Punto(int id, double x, double y): _PuntoBase(id), x(x), y(y)	//necesario pasar a la clase heredada en lista de inicialización
{
	//.....
}

class PuntoGordo:public Punto
{
	tipo_t forma;
	col_t color;
public:
	PuntoGordo(const Punto& p, tipo_t t, col_t c);
	ostream& print(ostream& o=cout);
	
	PuntoGordo& operator = (const PuntoGordo& p);
	
	PuntoGordo(const PuntoGordo&);
};

PuntoGordo::PuntoGordo(const PuntoGordo& p): Punto(p)
{
	//construir lo mio...
	
}

PuntoGordo& PuntoGordo::operator = (const PuntoGordo& p)
{
	cout<<"Llamando al operador asign PuntoGordo"
	if(this!=&p)
	{
		Punto::operator =(p);
		this->forma=forma;
		this->color=color;
	}
}

PuntoGordo::PuntoGordo(const Punto& p, tipo_t t, col_t c): Punto(p)
{
	this->forma =t;
	this->color =c;
}

ostream& PuntoGordo::print(ostream& o)
{
	Punto::print(o);
	o<<to_string_type(this->forma)<<" ";
	o<<to_string_col(this->color);
	
	return o;
}

void foo(Punto& p)		//función global
{
	p.print();			//si paso un punto gordo, la funcion convierte a punto y se ejecuta.
}

//test unitario
int main(void) 
{
	Punto p(8, 1.0, 3.0);
	p.print(cout);
	p._PuntoBase::print();	//Print de _PuntoBase. Lo suyo sería impedirlo poniendo la función en protected.
	
	PuntoGordo pg(p, PuntoGordo::ESTRELLA, PuntoGordo::AZUL);
	pg.print();
	
	foo(pg);				//se pierde la naturaleza del punto gordo al llamar a una función que requiere un punto, no es menor.
	
	Punto* pP=&pg;			//conversión implícita de puntogordo a punto
	pP->print();
	
	//asignar puntos
	PuntoGordo pg1(pg);		//funciona correctamente con constructor copia por defecto.
	pg1.print();
	pg1=pg;					//también copia correctamente.
	
	return 0;
}
