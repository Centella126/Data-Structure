#include<iostream>
#include<conio.h>
#include<iomanip>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define N 5

void oquicksort(int* v, int primero, int ultimo);
void aleatorio(int* v, int n);
void imprimirvh(int* v,int i, int x);
void cambiovariable(int* v, int i, int j);

int main(){
	int v[N];

	cout<<"\n\tO R D E N A C I O N  Q U I C K S O R T\n";
	srand(time(NULL));	
	aleatorio(v, N);	
	cout<<("\nVector desordenado: \n\n");
	imprimirvh(v,N,1);	
	cout<<("\n\nVector ordenado: \n\n");
	oquicksort(v, 0, N-1);
	imprimirvh(v,N,1);
	
	return 0;
}


void oquicksort(int* v, int primero, int ultimo){
    int i, j, central, aux;
    double pivote; 
    
    central = (primero + ultimo)/2;
    pivote = v[central];
    i = primero;
    j = ultimo;
    
    do{
        while (v[i] < pivote)i++;{
			
        	while (v[j] > pivote)j--;{ 
        		
		        if (i <= j){		// intercambia a[i] con a[j]
					cambiovariable(v,i,j);
		       		i++;
		       		j--;
		    	}
		   }       
		}        
	}while (i <= j);
	if (primero < j)
	oquicksort(v, primero, j); /* mismo proceso con sublista izqda */
			
	if (i < ultimo)
	oquicksort(v, i, ultimo); /* mismo proceso con sublista drcha */
}
	
	
	
void aleatorio(int* v, int n){
	for(int i=0; i<n; i++)
 		v[i] = rand() % 10;
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



void cambiovariable(int* v, int i, int j){
	int aux;
	aux=v[j];
	v[j]=v[i];
	v[i]=aux;	
}
