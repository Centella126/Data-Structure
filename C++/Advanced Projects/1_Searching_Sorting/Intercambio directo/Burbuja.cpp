
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define N 5
#define R 10

void ointercambiodirecto(int* v, int n);
void imprimirvh(int* v, int n, int x);
void aleatorio(int* v, int n);
void cambiovariable(int* v, int i, int j);


int main() {
	int v[N];
	
	cout<<("\tI N T E R C A M B I O  D I R E C T O\n\n");
	srand(time(NULL));
	aleatorio(v,N);
	cout<<("\nVector desordenado: \n\n");
	imprimirvh(v, N,1);
	
	cout<<("\n\nPasadas:\n");
	ointercambiodirecto(v, N);
	
	cout<<("\n\nVector ordenado: \n\n");
	imprimirvh(v, N,1);
	
	return 0;
}



void ointercambiodirecto(int* v, int n){
	int i;
	int j;
	for(i=0; i<N; i++){
		
		if(i<N-1){
			cout<<endl;
			cout<<"P"<<i+1<<": ";
			imprimirvh(v, N,0);
		}
		
		for(j=0; j<N; j++){
			if(v[i] < v[j]){
				cambiovariable(v,i,j);
			}			
		}

	}
	return;
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



void aleatorio(int v[], int n){
	int i;
	
	for(i=0; i<n; i++){
		v[i]=rand() % R;
	}
	return;
}

/*
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define N 5

int ordenamientointercambio(int vector [N]);
void imprimirVector(int vector [N]);
void aleatorio(int* v, int n);
void intercambiov(int vector[N], int i, int j);

int main() {
	int vprueba[N];
	printf("\n\t\t\tINTERCAMBIO DIRECTO\n\n");
	srand(time(NULL));
	aleatorio(vprueba,N);
	printf("\tVector desordenado: \n\t\n \t\t ");
	imprimirVector(vprueba);
	cout<<"\n";
	
	printf("\tOrdenamiento: \n\t\n\t ");
	ordenamientointercambio(vprueba);
}

int ordenamientointercambio(int vector[N]){
	int i;
	int j, k;
	
	for(i=0; i<N; i++){
		cout<<"\tP"<<i;
		for(j=0; j<N; j++){
			intercambiov(vector, i,j);
			printf("\t%i  ",vector[j]);
		}
			cout<<"\n\t";
	}
 	
} 


void intercambiov(int vector[N], int i, int j){
	int aux;
	if(vector[i]<vector[j]){
				aux=vector[j];
				vector[j]=vector[i];
				vector[i]=aux;
			
			}
			
}
void imprimirVector(int vector[N]){
	int i;
	int j;
		for(i=0; i<N; i++){
			printf("\t%i  " ,vector[i]);	
	}
	cout<<"\n";
}

void aleatorio(int* v, int n){
	int i;
	for(i=0;i<n;i++){
		v[i]=rand() %10;
	}
}
*/
