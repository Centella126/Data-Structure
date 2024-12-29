#include <iostream>
#include <stdlib.h> 
#include <time.h>
using namespace std;

#define N 3  //Tamaño de los vectores para todas las funciones excepto por la conversion decimal-binario
#define M 8  //Tamaño del vector de salida para la conversion decimal-binario
#define R 50 //parametro de los numeros aleatorios (rand() % R)

void imprimirv(int* vec, int n);
void aleatorio(int* vec, int n);
void resta_vec(int* v1, int* v2, int* v3, int n);
void producto_punto(int* v1, int* v2, int* v3, float& resul_escalar, int n);
float imprimir_prod_punto(float resul_escalar);
void escalar_vector(int* v1, int* v2, int n);
void producto_cruz(int* v1, int* v2, int* v3, int n);
void binario(int* v1, int* v2, int n);
void imprimir_binario(int* v1, int n);


int main()
{
	int v1[N];
	int v2[N];
	int v3[N];
	float resul_escalar;
	srand(time(NULL));
	aleatorio(v1, N);
	aleatorio(v2, N);
	
	cout<<"RESTA DE VECTORES\n";
	cout<<"Vector 1\n";
	imprimirv(v1, N);
	cout<<endl;
	cout<<"Vector 2\n";
	imprimirv(v2, N);
	cout<<endl;
	cout<<"Resultado"<<endl;
	resta_vec(v1, v2, v3, N);
	imprimirv(v3, N);
	
	cout<<"\n\nPRODUCTO PUNTO\n";
	cout<<"Vector 1\n";
	imprimirv(v1, N);
	cout<<endl;
	cout<<"Vector 2\n";
	imprimirv(v2, N);
	cout<<endl;
	cout<<"Resultado"<<endl;
	producto_punto(v1, v2, v3, resul_escalar, N);
	imprimir_prod_punto(resul_escalar);
	
	cout<<"\n\n\nESCALAR POR VECTOR\n";
	cout<<"Vector 1\n";
	imprimirv(v1, N);
	cout<<endl;
	cout<<"Escalar\n";
	imprimirv(v2, 1);
	cout<<endl;
	cout<<"Resultado"<<endl;
	escalar_vector(v1, v2, N);
	imprimirv(v1, N);

	cout<<"\n\n\nPRODUCTO CRUZ\n";
	cout<<"Vector 1\n";
	imprimirv(v1, N);
	cout<<endl;
	cout<<"Vector 2\n";
	imprimirv(v2, N);
	cout<<endl;
	cout<<"Resultado"<<endl;
	producto_cruz(v1, v2, v3, N);
	imprimirv(v3, N);	
	
	cout<<"\n\n\nDECIMAL A BINARIO\n";
	cout<<"Numero decimal\n";
	imprimirv(v2, 1);
	cout<<endl;
	cout<<"Resultado"<<endl;
	binario(v1, v2, M);
	imprimir_binario(v1, M);
	
	return 0;
}


void imprimirv(int* vec, int n){
	int i;
	for(i=0; i<n; i++){
		cout<<"El vector vec["<<i<<"] = "<<vec[i]<<endl;
	}
	return;
}



void aleatorio(int* vec, int n){
	int i;
	for(i=0; i<n; i++){
		vec[i]=rand()%R;
	}
	return;
}



void resta_vec(int* v1, int* v2, int* v3, int n){
	int i;
	for(i=0; i<n; i++){
		v3[i]=(v1[i]-v2[i]);
	}
	return;
}



void producto_punto(int* v1, int* v2, int* v3, float& resul_escalar, int n){
	int i;
	for(i=0; i<n; i++){
		v3[i]=v1[i]*v2[i];
		resul_escalar=resul_escalar+v3[i];
	}
	return;
}



float imprimir_prod_punto(float resul_escalar){
	cout<<"El producto punto es: "<<resul_escalar;
	return 0;
}



void escalar_vector(int* v1, int* v2, int n){
	int i;
	for(i=0; i<n; i++){
		v1[i]=v2[0]*v1[i];
	}
	return;
}



void producto_cruz(int* v1, int* v2, int* v3, int n){
	 //el prodcuto cruz solo puede ser de tamaño 2 o 3
	if(n==2){
		v3[0]=v1[1]*0-v2[1]*0;
		v3[1]=-(v1[0]*0-v2[0]*0);
		v3[2]=v1[0]*v2[1]-v2[0]*v1[1];		
	}
	if(n==3){
		v3[0]=v1[1]*v2[2]-v2[1]*v1[2];
		v3[1]=-(v1[0]*v2[2]-v2[0]*v1[2]);
		v3[2]=v1[0]*v2[1]-v2[0]*v1[1];
	}
	else{
		cout<<"\nNo es posible calcular producto cruz con la longitud escogida";
	}
	return;
}



void binario(int* v1, int* v2, int n){
	int i;
	for(i=0; i<n; i++){
		v1[i]=v2[0]%2;
		v2[0]=v2[0]/2;
	}
}



void imprimir_binario(int* v1, int n){
	int i, aux;	
	for(i=0; i<M/2; i++){
		aux=v1[i];
		v1[i]=v1[M-1-i];
		v1[M-1-i]=aux;
	}
	for(i=0; i<n; i++){
		if((i+1)%4==0){
			cout<<v1[i]<<"  ";
		}
		else{
			cout<<v1[i]<<" ";
		}
	}
	return;	
}
