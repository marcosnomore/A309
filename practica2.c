#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void main(void)		//programa para cambiar la cadena por "hola mundo cruel"
{
	char cadena1[]="hola mundo creeeeel", cadena2[]="cruel"; char *p;

	p=strstr(cadena1, "cr");
	strcpy(p, cadena2);
	puts(cadena1);
	
	system ("PAUSE");
}
