#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define N 10
#define R 10
void aleatorio(int* v, int n);
void busqueda(int* v, int clave, int n, int& centinela, int& indice);
void imprimirvh(int* v, int n, int x);



int main() {
	int v[N];
	int clave;
	int centinela=-1, i;
	
	cout<<"\n\t B U S Q U E D A   S E C U E N C I A L  O   L I N E A L \n\n";
	srand(time(NULL)); //SEED RANDOMIZE 
	aleatorio(v, N);
	cout<<"Vector: \n\n";
	imprimirvh(v, N,1);
	cout<<"\n\nIngrese la clave a buscar: ",
	cin>>clave;
	busqueda(v, clave, N, centinela, i);
	
	if(centinela==-1){
		cout<<"\n\n\t El numero no se encontro ";
	}
	if(centinela==1){
		cout<<"\n\n\t El numero ha sido encontrado en el indice "<<i;
	}
	return 0;
}



void busqueda(int* v, int clave, int n, int& centinela, int& indice){
	int i;
	
	for(i=0; i<n && centinela==-1; i++){
		if(v[i]==clave){
			centinela=1;	
			indice=i;
		}
	}
	return;
}



void imprimirvh(int* v, int n, int x){
	int i;
	if(x==1){
		for(i=0; i<n; i++){
			cout<<"["<<i<<"]";
		}
		cout<<endl;	
		for(i=0; i<n; i++){
			cout<<" "<<v[i]<<" ";
		}
	}
	if(x==0){
		for(i=0; i<n; i++){
			cout<<" "<<v[i]<<" ";
		}
		cout<<endl;	
	}	
	return;
}



void aleatorio(int* v, int n){
	int i;
	
	for(i=0; i<n; i++){
		v[i]=rand() % R;
	}
	return;
}
