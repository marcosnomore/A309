#include <stdio.h>
#include <stdlib.h>

#define N 4

typedef struct nodo
{
	float x, y;
	struct nodo *siguiente;
}punto;

punto* obtener_dato (void)		//pregunta al usuario por las coordenadas de un punto, es una función robusta, no admite otra cosa que no sean números
{
	punto *a;
	a=(punto*)malloc(sizeof(punto));
	a->siguiente=NULL;
	a->x=200;
	a->y=200;
	while((a->x<-100)||(a->x>100)||(a->y<-100)||(a->y>100))
	{
		printf("Introduzca las coordenadas x e y de un punto: ");
		fflush(stdin);
		scanf("%f %f", &a->x, &a->y);
		fflush(stdin);
		if((a->x<-100)||(a->x>100)||(a->y<-100)||(a->y>100))
			printf("Punto no válido, las coordenadas deben estar entre -100 y 100.\n");
	}
	return(a);
}

void main(void) 
{
	punto *v, *head; int i=0; punto centroide={0,0};
	char respuesta;
	do
	{
		v=obtener_dato();
		if(i==0)				//La primera vez que se pide un dato (estamos a la cabeza de la lista) se guarda la dirección de memoria de la cabeza en head
			head=v;
		centroide.x=centroide.x+v->x;
		centroide.y=centroide.y+v->y;
		i++;					//se cuenta el número de puntos en la lista para poder hacer el cálculo del centroide
		printf("Desea introducir otro punto?: (S/N) ");
		fflush(stdin);
		scanf("%c", &respuesta);
		fflush(stdin);
	}while(respuesta=='S'||respuesta=='s');			//el bucle solo se repite si el usuario introduce que S o s, si introduce cualquier otra cosa, se corta
	
	centroide.x=centroide.x/i;
	centroide.y=centroide.y/i;
	printf("[%f, %f] \n", centroide.x, centroide.y);
	system("PAUSE");
}
