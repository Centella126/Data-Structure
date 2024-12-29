#include <iostream> 

using namespace std;

#define N 5


struct e_pila{
	int datos[N];
	int cima;
};


void portada(void);
void menu(void);
void apilar(struct e_pila& pp, int x);
int desapilar(struct e_pila& pp);
void inicializar(struct e_pila& pp);
int pilavacia(struct e_pila pp);
int pilallena(struct e_pila pp);
int lugaresocupados(struct e_pila pp);
int lugaresdisponibles(struct e_pila pp);
int cimaelemento(struct e_pila pp);
int cimaposicion(struct e_pila pp);
void imprimir(struct e_pila pp);


int main(void) {		
	menu();
	return 0;
}


void menu(void){
	setlocale(LC_ALL, "spanish");
	
	e_pila pp;
	inicializar(pp);
	int x, i; 
	char op;
	
	
	do{
		system("CLS");
		cout<<"Su pila es la siguiente: ";
		imprimir(pp);
		cout<<endl<<endl;
		cout<<"\n\tApilar.................[A]";
		cout<<"\n\tDesapilar..............[D]";
		cout<<"\n\tInicializar............[I]";
		cout<<"\n\tPila Vacia.............[V]";
		cout<<"\n\tPila Llena.............[L]";
		cout<<"\n\tLugares Ocupados.......[O]";
		cout<<"\n\tLugares Disponibles....[S]";
		cout<<"\n\tCima Elemento..........[E]";
		cout<<"\n\tCima Posicion..........[P]";
		cout<<"\n\tTerminar...............[T]";
		cout<<"\n\n\tElija una opcion: ";
		cin>>op;
		op = toupper(op);
				
		switch(op){
			case 65:
				system("CLS");
				cout<<"\n\n\tA P I L A R";				
				cout<<"\nIngrese un dato: ";
				cin>>x;
				if(pilallena(pp)==1)
					cout<<"\n\nNo es posible apilar otro dato";
				else{
					apilar(pp, x);	
					cout<<"\n\nApilado correctamente";					
				}
				system("pause");				
				break;
			
			case 68:
				system("CLS");
				cout<<"\n\n\tD E S A P I L A R";
				if(pilavacia(pp)==1)	
					cout<<"\n\nNo es posible desapilar otro dato\n";
				else{
					desapilar(pp);
					cout<<"\n\nDesapilado correctamente\n";					
				}		
				system("pause");
				break;			
				
			case 73:
				system("CLS");
				cout<<"\n\n\tI N I C I A L I Z A R";	
				inicializar(pp);
				cout<<"\n\nInicializado correctamente\n";
				system("pause");
				break;	
								
			case 86:
				system("CLS");
				if(pilavacia(pp)==1)
					cout<<"\n\n\t La pila está vacía\n";
				else
					cout<<"\n\n\t La pila no está vacía\n";
				system("pause");
				break;
				
			case 76:
				system("CLS");
				if(pilallena(pp)==1)
					cout<<"\n\n\t La pila está llena\n";
				else
					cout<<"\n\n\t La pila no está llena\n";
				system("pause");
				break;	
				
			case 79:
				system("CLS");
				cout<<"\n\n\t Lugares ocupados: "<<lugaresocupados(pp)<<endl;
				system("pause");
				break;
				
			case 83:
				system("CLS");
				cout<<"\n\n\t Lugares disponibles: "<<lugaresdisponibles(pp)<<endl;
				system("pause");
				break;
				
			case 69:
				system("CLS");
				cout<<"\n\n\t Elemento de la cima: "<<cimaelemento(pp)<<endl;
				system("pause");
				break;	
				
			case 80:
				system("CLS");
				cout<<"\n\n\t Posición de la cima: "<<cimaposicion(pp)<<endl;
				system("pause");
				break;		
							
			case 84:
				system("CLS");
				break;	
		}
	}while(op!=84);
}



void apilar(struct e_pila& pp, int x){
	pp.cima++;
	pp.datos[pp.cima]=x;
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
}
