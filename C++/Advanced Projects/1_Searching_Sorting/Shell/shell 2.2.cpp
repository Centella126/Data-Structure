#include<iostream>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

#define N 5
#define R 10

void oshell(int* v,int n);
void aleatorio(int* v, int n);
void imprimirvh(int* v, int n, int x);

int main(){
	int v[N];
	
	cout<<"\n\tO R D E N A C I O N  S H E L L\n";
	srand(time(NULL));	
	aleatorio(v,N);
	cout<<("\n\nVector desordenado: \n\n");
	imprimirvh(v,N,1);
	cout<<("\n\nVector ordenado: \n\n");
	oshell(v,N);
	imprimirvh(v,N,1);
	
	return 0;
}



void oshell(int* v,int n){
	int i, j, k, aux;
	k = n/2;
	
	while (k > 0) {
		for (i=k; i < N; i++) {
		j = i;
		aux = v[i];
			while ((j >= k) && (v[j - k] > aux)){
				v[j] = v[j - k];
				j = j - k;
			}
			v[j] = aux;
		}
		k /= 2;
	}	
}



void aleatorio(int* v, int n){
	int i;
	
	for(i=0; i<n; i++){
		v[i]=rand() % R;
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
