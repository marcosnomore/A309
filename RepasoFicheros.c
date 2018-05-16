#include <stdio.h>
#include <stdlib.h>

#define N 250
#define M 4

typedef struct
{
	float x,y;
}punto_t;

punto_t lista_puntos[M];		//vector de puntos

void main(void) 
{
	int pos_punto=0;		//aqui guardaremos la posicion de un punto
	char line[N];			//aqui guardaremos las lineas de un fichero
	FILE *f=fopen("log.txt","r");		//abrimos el fichero
	if(!f)
	{
		perror("Error al leer el archivo");		//esta función imprime en pantalla el tipo de error ocurrido si se da
	}
	while(!feof(f))			//mientras no se alcance el final del fichero...
	{
		fgets(line, N, f);
		if(ferror(f))		//si el fichero da un error, lo indica en pantalla y se rompe el bucle.
		{
			perror("Error al leer la línea");
			puts("termino lectura");
			break;
		}
		
		//filtro lineas vacias
		if(line[0]=='\n'||line[0]=='\0') continue;		//rompe el bucle y pasa a la siguiente iteracion

		//seguimos el protocolo de actuación normal.
		switch(line[0])
		{
			case 'c':			//si se encuentra c al ppio de la linea, significa que es un comentario
				break;
			case 'p':			//es un dato a tener en cuenta
				sscanf(line,"%*c%f %f", &lista_puntos[pos_punto].x, &lista_puntos[pos_punto].y);	//sscanf permite transferir de un array a otro tipo de datos
				printf("(%.2f, %.2f)\n", lista_puntos[pos_punto].x, lista_puntos[pos_punto].y);		//%.2f te da solo dos decimales de precision
				pos_punto++;
				break;
			default:
				puts("PROTOCOLO ERRONEO. Dejo de leer...");
		}
		
	}
	fclose(f);
}
