//Listanum.h: interface for the Listanum class.

#include <iostream>

template<class T>		//también vale template<typename T> sirve para definir un tipo genérico y así convertir en genérica la clase
class Listanum
{
static const int MYMAX=0x1FFFFFFF;

private:
	int capacity;		//atributo nuevo para gestionar la capacidad, cambiar funciones.
	int nElem;
	T *lista;
public:
	Listanum(int capacity);		//esta es una funcion constructora (constructor), sirve para inicializar la clase. siempre va en el apartado público.
	Listanum(const Listanum& c);
	void add_elem(T dato);
	T get_elem(int pos);
	int size();
	T pop();
	std::ostream& print(std::ostream& o);
	~Listanum();
	int push_back(int dato); 	//añadir un dato al final y, si no cabe, doblar capacidad y añadir elemento.
	void set_capacity(int capacity); 	//establece la capacidad a una nueva, si la nueva capacidad es menor no hace nada.
};

//surge un problema al definir las funciones con tipo genérico, la solución es añadir cosas al final del .cpp o poner las definiciones en el .h

using namespace std;

template<class T>
inline
Listanum<T>::Listanum(int capacity)
	:capacity(capacity)
{
	nElem=0;
	lista=new T[capacity];
}

template<class T>
inline
Listanum<T>::Listanum(const Listanum& c)
	:capacity(c.capacity)
{
	nElem=c.nElem;
	lista=new T[capacity];
	for(int i=0; i<nElem; i++)
		lista[i]=c.lista[i];
}

template<class T>
inline
void Listanum<T>::add_elem(T dato)
{
	if(nElem<capacity)
		lista[nElem++]=dato;
}

template<class T>
inline
T Listanum<T>::get_elem(int pos)
{
	if(pos<capacity)
		return lista[pos];
}

template<class T>
inline
int Listanum<T>::size()
{
	return nElem;
}

template<class T>
inline
T Listanum<T>::pop(void)
{
	nElem--;
	return lista[nElem];
}

template<class T>
inline
ostream & Listanum<T>::print(ostream & o)
{
	o<<"[ ";
	for(int i=0; i<nElem; i++)
	{
		o<<lista[i]<<" ";
	}
	o<<"]"<<" ["<<nElem<<"]"<<endl;
	return o;
}

template<class T>
inline
Listanum<T>::~Listanum()
{
	if(lista!=NULL)
		delete lista;
}

template<class T>
inline
int Listanum<T>::push_back(int dato)
{
	if(nElem<capacity)
		lista[nElem++]=dato;
	else
	{
		T *p=new T[2*capacity];
		for(int i=0; i<capacity;i++)
			p[i]=lista[i];
		delete [] lista;
		lista=p;
		lista[nElem++]=dato;
	}
	
	return dato;
}

template<class T>
inline
void Listanum<T>::set_capacity(int capacity)
{
	if(capacity>this->capacity)
	{
		T *p=new T[capacity];
		for(int i=0; i<this->capacity;i++)
			p[i]=lista[i];
		delete [] lista;
		lista=p;
	}
}
