#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define N 10
#define R 10

int bbinaria( int* v, int clave);
void oselecciondirecta(int* v,int n, int y); //si y=0 se imprimen las pasadas
void cambiovariable(int* v, int i, int j);
void aleatorio(int* v, int n);
void imprimirvh(int* v, int n, int x);


main(){
	int v[N]; 
	int clave;
	int i;
	srand(time(NULL)); //SEED RANDOMIZE 
	aleatorio(v, N);
	
	cout<<"\n\t B U S Q U E D A   B I N A R I A \n\n";
	
	cout<<"Vector desordenado: \n\n";
	imprimirvh(v,N,1);
	cout<<"\n\n\nVector ordenado: \n\n";
	oselecciondirecta(v,clave,1);
	imprimirvh(v,N,1);		
	cout<<"\n\nIngrese la clave a buscar: ",
	cin>>clave;
	
	if( bbinaria(v, clave) == -1){
		cout<<"\n\tDato no encontrado\n\n";
	}
	else{
		cout<<"\n\tEl dato "<<clave<<" se encontro en la posicion: "<<bbinaria(v, clave)<<"\n\n";
	}
	
	return 0;
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



void oselecciondirecta(int* v,int n, int y){ //ordenación por selección directa
	int min,aux;

	for (int i = 0; i < N-1; i++) {
		min = i;
		for (int j = i + 1; j < N; j++){ 			//ver si cada uno de los terminos del arreglo son menores a min (Primer termino)
	 		if (v[j] < v[min]){
				min = j;
			}
	 	}	
		if(y==0){
			cout<<endl;
			cout<<"P"<<i+1<<": ";
			imprimirvh(v,N,0);			
		}
	 	cambiovariable(v,min,i); 	// Dentro del primer for se colocan los numeros a imprimir en el orden que van dándose 
	}
}



void cambiovariable(int* v, int i, int j){
	int aux;
	aux=v[j];
	v[j]=v[i];
	v[i]=aux;	
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
