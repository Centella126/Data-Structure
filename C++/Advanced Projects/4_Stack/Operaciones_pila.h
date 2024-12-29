#include <iostream> 

using namespace std;

#define N 5

struct e_pila{
	int datos[N];
	int cima;
};




void apilar(struct e_pila& pp, int x){	
	pp.cima++;
	pp.datos[pp.cima]=x;
	return;
}



int desapilar(struct e_pila& pp){
	pp.datos[pp.cima];
	return pp.cima--;
}



void inicializar(struct e_pila& pp){
	pp.cima = -1;
	return;
}



int pilavacia(struct e_pila pp){
	if(pp.cima==-1)
		return 1;
	else 
		return 0;
}



int pilallena(struct e_pila pp){
	if(pp.cima==N-1)
		return 1;
	else 
		return 0;
}



int lugaresdisponibles(struct e_pila pp){
	return N-pp.cima-1;
}



int lugaresocupados(struct e_pila pp){
	return pp.cima+1;
}



int cimaelemento(struct e_pila pp){
	return pp.datos[pp.cima];
}



int cimaposicion(struct e_pila pp){
	return pp.cima;
}



void imprimir(struct e_pila pp){
	int i;
	for(i=pp.cima; i>=0; i--){
		cout<<endl;
		cout<<"["<<i<<"]";
		cout<<pp.datos[i];
	}
	return;
}
