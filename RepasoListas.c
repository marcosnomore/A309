#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//elemento de la lista
struct nodo
{
	int dato;
	struct nodo * siguiente;
};
typedef struct nodo nodo_t;

//cabecera de la lista
nodo_t *head;

nodo_t* nuevo_elemento()		//pide memoria para un nuevo elemento y devuelve el puntero
{
	nodo_t* elem=NULL;
	elem=(nodo_t*)malloc(sizeof(nodo_t));
	if(elem==NULL)
		printf("Error en la reserva de memoria");
	return elem;
}
void init(int dato)				//crea el nodo cabecera y le asigna un dato, debe ser la primera función
{
	head=nuevo_elemento();
	head->dato=dato;
	head->siguiente=NULL;
}
void insert_front(int dato)		//mete un dato al principio de la lista
{
	nodo_t *newhead;
	newhead=nuevo_elemento();	//creo un nodo y lo inicializo
	newhead->dato=dato;
	newhead->siguiente=head;	//digo que el siguiente nodo es la antigua cabeza y que la nueva cabeza es este nodo
	head=newhead;	
}
void insert_back(int dato)		//mete un dato al final de la lista
{
	nodo_t *p=head, *elem_nuevo;
	//busco el último
	while(p->siguiente!=NULL)
		p=p->siguiente;
	//genero el nuevo
	elem_nuevo=(nodo_t*)malloc(sizeof(nodo_t));
	elem_nuevo->dato=dato;
	elem_nuevo->siguiente=NULL;
	//lo pongo al final
	p->siguiente=elem_nuevo;
}
void pop_back(void)					//saca y elimina el último elemento de la lista
{
	nodo_t *p=head, *q;
	while(p->siguiente!=NULL)
	{	
		q=p;
		p=p->siguiente;
	}
	free(p);
	q->siguiente=NULL;
}
void remove_nodo(int dato)		//elimina un elemento intermedio de la lista situado en la posición "dato"
{
	nodo_t *p=head, *q; int i;
	for(i=0;i<dato;i++)
	{
		q=p;
		p=p->siguiente;
	}
	q->siguiente=p->siguiente;
	free(p);
}
int get_size(void)					//te da el tamaño de la lista
{
	int tamano=0; nodo_t *p=head;
	while(p!=NULL)
	{	
		p=p->siguiente;
		tamano++;
	}
	return(tamano);
}
void print(void);					//imprime la lista de forma ordenada

void main(void) 
{
/*	int num[10], *num_var;
	int ** matrix=0, i, n=10, m=10;
	num_var=malloc(sizeof(int)*10);		//mejor poner num_var=(int *) malloc(...) porque malloc devuelve un puntero genérico, lo transformo a puntero a entero
	
	//uso de num_var
	num_var[8]=5;
	*(num_var+1)=4;
	*num_var=10;
	
	free(num_var);
	
	matrix=(int **)malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
		matrix[i]=(int*)malloc(m*sizeof(int));

	for(i=0;i<n;i++)
		free(matrix[i]);
	free(matrix);
	matrix=NULL;
*/
	init(10);
	insert_back(5);
	insert_back(8);
	print();
	remove_nodo(3);
	pop_back();
	printf("%d", get_size());	
	system("PAUSE");
}
