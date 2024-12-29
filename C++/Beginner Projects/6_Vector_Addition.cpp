#include <iostream>
#include <stdlib.h> 
#include <time.h>
using namespace std;

#define N 5

void suma_vec(int* vec1, int* vec2, int* vec3, int n);
void imprimir(int* vec, int n);
void aleatorio(int* vec, int n);

int main() 
{
	int vec1[N];
	int vec2[N];
	int vec3[N];
	srand(time(NULL));
	aleatorio(vec1, N);
	aleatorio(vec2, N);
	
	cout<<"SUMA DE VECTORES\n\n";
	cout<<"Vector 1\n";
	imprimir(vec1, N);
	cout<<endl;
	cout<<"Vector 2\n";
	imprimir(vec2, N);
	cout<<endl;
	cout<<"Resultado"<<endl;
	suma_vec(vec1, vec2, vec3, N);
	imprimir(vec3, N);
	
	return 0;
}



void imprimir(int* vec, int n){
	int i;
	for(i=0; i<n; i++){
		cout<<"El vector vec["<<i<<"] = "<<vec[i]<<endl;
	}
	return;
}



void suma_vec(int* vec1, int* vec2, int* vec3, int n){
	int i;
	for(i=0; i<n; i++){
		vec3[i]=(vec1[i]+vec2[i]);
	}
	return;
}



void aleatorio(int* vec, int n){
	int i;
	 
	for(i=0; i<n; i++){
		vec[i]=rand() % 10; 	//%10, da valores de 0 a 9
	}
}
