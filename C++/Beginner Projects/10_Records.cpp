#include <iostream>

using namespace std;

#define N 5

struct fecha{
	int dd;
	int mm;
	int aa;
};

struct platillo{
	char id[5];			//En las cadenas, la computadora deja un espacio para el enter, si se quiere un id de 4 se le deben poner 5 espacios
	char nombrep[30];		//nombre platillo
	char guarnicion[60];
	char tiempo[15];
	float precio;
	fecha fechaderegistro;
	int status; //0 o 1 para que aparezca o no
};

int main() 
{
	platillo plat1;		//AWESOME!!! podemos definir tipos nuevos de datos
	platillo vplats[N]; 		//Se define un vector
	int i;
	
	cout<<"ESTRUCTURAS (REGISTROS) EN LENGUAJE C\n\n";
	cout<<"Se capturan e imprimen los datos para un platillo\n\n";
	
	for(i=0; i<N; i++){
		system("CLS");
		cout<<"Ingrese el id del platillo "<<i+1<<": ";
		fflush(stdin);
		gets(vplats[i].id);							//gets() ES EXCLUSIVO PARA LEER CADENAS... get String
	 	cout<<"\nNombre del platillo "<<i+1<<": ";
	 	fflush(stdin);							//El fflush sirve para quitar la basura del buffer
		gets(vplats[i].nombrep);
		cout<<"\nGuarnicion del platillo "<<i+1<<": ";
		fflush(stdin);
		gets(vplats[i].guarnicion);
		cout<<"\nTiempo del platillo (Entrada/Plato fuerte/postre) "<<i+1<<": ";
		fflush(stdin);
		gets(vplats[i].tiempo);
		cout<<"\nPrecio del platillo "<<i+1<<": $";
		cin>>vplats[i].precio;	
		cout<<"\nFecha de registro "<<i+1<<": ";
		cout<<"\nDía "<<i+1<<": ";
		cin>>vplats[i].fechaderegistro.dd;		
		cout<<"\nMes "<<i+1<<": ";
		cin>>vplats[i].fechaderegistro.mm;
		cout<<"\nAno "<<i+1<<": ";
		cin>>vplats[i].fechaderegistro.aa;			
	}

	system("CLS");
	cout<<"\n\nLos datos almacenados en la estructura son: \n\n";
	cout<<"ID\tNombre\tGuarnicion\tTiempo\tPrecio";
	for(i=0; i<N; i++){
		cout<<"\n"<<vplats[i].id;
		cout<<"\t "<<vplats[i].nombrep;
		cout<<"\t "<<vplats[i].guarnicion;
		cout<<"\t\t "<<vplats[i].tiempo;
		cout<<"\t$"<<vplats[i].precio;		
	}
	
	return 0;
}
