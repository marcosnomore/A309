#include <iostream>
#include "Listanum.h"



int main(void) 
{
	Listanum<double> l(5.0);
	l.push_back(19.2);
	l.add_elem(2.1);
	l.add_elem(3.01);
	l.add_elem(5.99);
	l.add_elem(1.003);
	
	l.print(std::cout);
	
	l.pop();
	
	l.print(std::cout);
	
	l.push_back(90.01);
	l.push_back(80.0);
	l.push_back(400.1);
	
	l.print(std::cout);
}
