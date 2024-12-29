//BUSQUEDA HASH - ARITMETICA MODULAR - RESOLUCION DE COLISIONES POR ENCADENAMIENTO
//FLAVIO AZAEL PEREZ MAGAÑA
//DIANA VANESSA RODRIGUEZ RAMIREZ
//ESTRUCTURA DE DATOS



#include<stdlib.h>
#include<iostream>

using namespace std;


#define N 5

struct nodo{
	int datos;
	struct nodo* siguiente;
};


//PROTOTIPOS
void fHash(int valor, struct nodo* v[N]);
void busqueda_hash(int valor, struct nodo* v[N], int& i, int& centinela);
void inicio(struct nodo * v[N]);

int main (){
	int i, centinela;
	int datoBuscar;
	struct nodo*v[N];
	
	
	inicio(v);
	
	fHash(680372, v);
	fHash(740790, v);
	fHash(658866, v);
	fHash(855970, v);
	fHash(896990, v);
	
	cout << "DATO A BUSCAR: ";
	cin >> datoBuscar;
	
	
	busqueda_hash(datoBuscar, v, i, centinela);
	
	
	
	if(centinela==1){
		cout << datoBuscar << ": DATO ENCONTRADO"<<endl;
		cout << "EL DATO SE ENCUENTRA EN LA POSICION [" << i << "] DEL ARREGLO"<<endl;
	}
	else {
		cout << datoBuscar << ": DATO NO ENCONTRADO"<<endl;
	}
	return 0;
}



void inicio(struct nodo* v[]){ //INICIA EL ARREGLO EN NULL

	int i;
	for(i=0; i<N; i++)
		v[i]  = NULL;
		
}



void fHash(int valor, struct nodo* v[]){  
	
	int i;
	
	//CREA UN NUEVO NODO CON VALOR 
	
	struct nodo*nuevoNodo;
	nuevoNodo = (struct nodo *)malloc(sizeof (struct nodo));
	nuevoNodo->datos = valor;
	nuevoNodo->siguiente = NULL;
	
	
	
	//CALCULAR CLAVE / FUNCION HASH
	i = valor % N;
	
	//COMPRUEBA SI LA CADENA (INDICE) ESTÁ VACIA
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

void busqueda_hash(int valor, struct nodo*v[], int& i, int& centinela){
	
	//APLICA LA FUNCION HASH
	i = valor%N;
	
	
	//BUSCA EN LA POSICION
	struct nodo*aux = v[i];
	while(aux){
		if(aux->datos == valor)
			centinela = 1; //DATO ENCONTRADO
		aux = aux->siguiente;
	}
	centinela == 0;
}	
