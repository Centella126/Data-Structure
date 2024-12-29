#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define N 5
#define R 10

void imprimirvh(int* v, int n, int x); //si x=1 aparecen los indices, si x=0 no aparecen los indices  
void aleatorio(int* v, int n);
void oinserciondirecta(int* v, int n);


int main(){
	int v[N];
	
	cout<<("\tI N S E R C I O N  D I R E C T A\n\n");
	srand(time(NULL));
	aleatorio(v, N);
	cout<<("\nVector desordenado: \n\n");
	imprimirvh(v, N,1);
	
	cout<<("\n\nPasadas:\n");
	oinserciondirecta(v,N);
	
	cout<<("\n\nVector ordenado: \n\n");
	
	imprimirvh(v, N,1);
}



void oinserciondirecta(int* v, int n){
	int i, a, aux;
	for (i =1; i<n; i++){
	   aux = v[i];
	   a=i-1;
		//Pasadas
		cout<<endl;
		cout<<"P"<<i<<": ";
		imprimirvh(v, N,0);
				
	   while (a >= 0 && v[a] > aux){
	       v[a + 1] = v[a];
	       a--;
	   }
	   v[a+1] = aux;
	}
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

