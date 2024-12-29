#include <stdio.h> //standard input/output
#include <stdlib.h> //standard library
#include <time.h>
using namespace std;


#define N 5
#define M 3

void imprimev(int* v, int n); 	//Prototipos		//la n es para que se cambie al tamaño del vector que se ocupa, para no poner otro for o así
void invertirv(int* v);
void concatenarv(int* v1, int* v2, int* vc); 	//el * es para representar un puntero... es la dirección del espacio donde se guardarán los valores 
void aleatorio(int* v, int n);

int main()
{
 	int v[N];
 	int w[M];
 	int z[N+M];
 	aleatorio(v, N);	//No hay problema si es con v o con w, solo es el parametro
 	aleatorio(w, M);
 	
 	printf("FUNCIONES EN C QUE UTILIZAN VECTORES COMO PARAMETROS\n\n");
 	printf("Vector inicial:\n");
 	imprimev(v, N);
 	invertirv(v);
 	printf("\nVector invertido:\n");
 	imprimev(v, N);
 	
 	printf("\n\nVector concatenado:\n");
 	concatenarv(v, w, z);
	imprimev(z, N+M);
	 	
	return 0;
}



void imprimev(int* vec, int n){
	int i;
	
	for(i=0; i<n; i++){
		printf("vec[%i]=%i\n", i, *vec++);		//*vec++ ... el ordenador conoce cual direccion es la que sigue 
												//en enteros cada dato vale 4 bits, entonces una direc es 20 y la otra seria 24 
												//los float ocupan 8, los double 16, y los char ocupan 1 bite
	}
	
	return;
}



void invertirv(int* vec){
	int i, aux;
	
	for(i=0; i<N/2; i++){
		aux=vec[i];
		vec[i]=vec[N-1-i];
		vec[N-1-i]=aux;
	}
	
	return;
}



void concatenarv(int* v1, int* v2, int* vc){
	int i, j;
	
	for(i=0; i<N; i++){
		vc[i]=v1[i];
	}
	
	for(i=N; i<N+M; i++){
		vc[i]=v2[i-N];		//i comienza en 5, pero debemos dar el valor de v2 en su posición inicial
	}
	return;
}



void aleatorio(int* v, int n){
	int i;
	
	srand(time(NULL));		//Seed randomize 
	for(i=0; i<n; i++){
		v[i]=rand() % 10; 	//%10, da valores de 0 a 9
	}
}
