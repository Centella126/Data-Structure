#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

#define N 5 
#define R 10 

//Prototipos
void oselecciondirecta(int* v,int n, int y);
void aleatorio(int* v, int n);
void imprimirvh(int* v, int n, int x);
void cambiovariable(int* v, int i, int j);

main(){
	int v[N];
	
	printf("\n\tS E L E C C I O N  D I R E C T A\n\n");
	srand(time(NULL));
	aleatorio (v,N);
	cout<<"\nVector desordenado: \n\n";
	imprimirvh(v, N,1);
	
	cout<<"\n\n\nPasadas:\n"; 
	oselecciondirecta(v,N,0);
	
	cout<<"\n\nVector ordenado: \n\n";
	imprimirvh(v, N,1);
	return 0;
}



void oselecciondirecta(int* v,int n, int y){
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
