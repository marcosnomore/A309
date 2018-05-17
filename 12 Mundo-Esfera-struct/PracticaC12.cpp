#include <iostream>
#include "Mundo.h"


int main() 
{
	Esfera e(3,coord_t(1.0, 2.0, 3.0));
	
	Mundo m1(e);
	Mundo m2(m1);
	m1.print(cout);
	m2.print(cout);
	
	return 0;
}
