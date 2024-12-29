#include <iostream>
#include <stdlib.h>
using namespace std;

#define N 10

struct nodo{ //para hash
	int datos;
	struct nodo* siguiente;
};


void blineal(int* v, int clave, int n, int& centinela, int& indice){
	int i;
	
	for(i=0; i<n && centinela==-1; i++){
		if(v[i]==clave){
			centinela=1;	
			indice=i;
		}
	}
}

int bbinaria( int* v, int clave){
	int c, i=0, d=N-1;
	int bandera=0;
		
	while( i <= d ){
		c = (i+d)/2;
		if( v[c] == clave )	//if( c == db )
			return c;
		else
			if( clave > v[c] )	//if( db > c )
				i = c + 1;
			else
				d = c - 1;
	}		
	return -1;
}

void bhash_inicio(struct nodo* v[]){ //INICIA EL ARREGLO EN NULL
	int i;
	for(i=0; i<N; i++)
		v[i]  = NULL;
}

void bhash_fHash(int valor, struct nodo* v[]){  
	int i;

	//CREA UN NUEVO NODO CON VALOR 
	
	struct nodo*nuevoNodo;
	nuevoNodo = (struct nodo *)malloc(sizeof (struct nodo));
	nuevoNodo->datos = valor;
	nuevoNodo->siguiente = NULL;
	
	//CALCULAR CLAVE / FUNCION HASH
	i = valor % N;
	
	//COMPRUEBA SI LA CADENA (INDICE) ESTÃ  VACIA
	if (v[i] == NULL)
		v[i] = nuevoNodo;
	else { //COLISION
		struct nodo* aux = v[i];
		while ( aux->siguiente){
			aux = aux -> siguiente;
		}
		aux->siguiente = nuevoNodo;
	}
}

void bhash(int valor, struct nodo*v[], int& i, int& centinela){
	
	//APLICA LA FUNCION HASH
	i = valor%N;
	
	//BUSCA EN LA POSICION
	struct nodo*aux = v[i];
	while(aux){
		if(aux->datos == valor){
			centinela = 1; //DATO ENCONTRADO
		}
		aux = aux->siguiente;
	}
	centinela == 0;
}	
