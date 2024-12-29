#include <stdio.h> //standar input/output
using namespace std;


#define N 5
#define M 3

void imprimev(int v[], int n); 	//Prototipos		//la n es para que se cambie al tamaño del vector que se ocupa, para no poner otro for o así
void invertirv(int v[]);
void concatenarv(int v1[], int v2[], int vc[]);

int main()
{
 	int v[N]={1,2,3,4,5};
 	int w[M]={6,7,8};
 	int z[N+M];
 	
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



void imprimev(int vec[], int n){
	int i;
	
	for(i=0; i<n; i++){
		printf("vec[%i]=%i\n", i, vec[i]);
	}
	
	return;
}



void invertirv(int vec[]){
	int i, aux;
	
	for(i=0; i<N/2; i++){
		aux=vec[i];
		vec[i]=vec[N-1-i];
		vec[N-1-i]=aux;
	}
	
	return;
}



void concatenarv(int v1[], int v2[], int vc[]){
	int i, j;
	
	for(i=0; i<N; i++){
		vc[i]=v1[i];
	}
	
	for(i=N; i<N+M; i++){
		vc[i]=v2[i-N];		//Porque i comienza en 5, pero debemos dar el valor de v2 en su posición inicial
	}
	return;
}
