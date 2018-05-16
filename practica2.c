#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void main(void)		//programa para cambiar la cadena por "hola mundo cruel"
{
	char cadena1[]="hola mundo creeeeel", cadena2[]="cruel"; char *p;

	p=strstr(cadena1, "cr");
	strcpy(p, cadena2);
	puts(cadena1);
	
			//programa para obtener los numeros de una cadena de caracteres
	
	char cadena[]="hola 12345 3456 44 adios"; int i=0, n, npos=0; long num; char *p=cadena;
	//Tenemos dos opciones, cada una englobada entre comentarios.
/*	for(;*p!=0;p++)
	{
		if(isdigit(*p))
		{
			num=strtol(p, &p, 10);
			printf("%ld ", num);			
		}
	}
*/

/*	while(1==sscanf(p, "%*[^0123456789]%d%n", &n, &npos))
	{
		p+=npos;
		printf("%d ", n);
	}	*/
	system ("PAUSE");
}
