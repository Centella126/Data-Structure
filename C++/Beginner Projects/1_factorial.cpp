#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

//PROTOTIPOS
	
//1.Funciones sin tipo y sin parametros

	void imprime_mi_nombre(void){
		printf("Maricarmen Rios Prado\n\n\t");
		
		return;
	}
	
	void portada( void ){
		printf("UNIVERSIDAD DE GUADALAJARA\n\n\t");
		printf("Centro Universitario de los Lagos\n\n\t");
		printf("DEBIT\n\n\t");
		printf("Departamento de Ciencias Exactas y Tecnologia\n\n\t");
		printf("Ingeniería en Mecatrónica\n\n\t");
		
		return;
	}

	
//2.Funcion con tipo y con parametros
	
	int suma_dos_numeros(int a, int b){
		int resul;
		resul=a+b;
	}
	
	int suma_dos_numeros_2(int a, int b){
		
		return a + b;
	}

//3.Funcion sin tipo y con parametros

										//tipos: doble, int, char, float void
										//Para que regrese MAS de un dato, se usa VOID y en PARAMETROS se ponen todo 


//todo en uno

	void rect(float b, float h, float& a, float& p, float& d);  //con & se sabe qué variables son bidireccionales (pueden fungir de entrdas o salidas)
	
	
//Conversion de galones a MM, DL, CL, L

	void conversiones(float gal, float& ml, float& dl, float& cl, float& l);


//intercambio de variables

	void intercambio(int& a, int& b);


int main()
{
	int n,x,y;
	float area, perimetro, diagonal, m, d, c, lit;
	
	imprime_mi_nombre();
	portada();
	
	cout<<endl<<suma_dos_numeros(2,3);
	cout<<endl<<suma_dos_numeros_2(-5,9)<<endl;
	
	
	cout<<"Funciones que usan la llamada por referencia\n\n";
	
	rect(4,6.7,area,perimetro,diagonal);
	cout<<endl<<"El area del rectangulo es: "<<area<<" unidades cuadradas";
	cout<<endl<<"El perimetro del rectangulo es: "<<perimetro<<" unidades lineales";
	cout<<endl<<"La diagonal del rectangulo es: "<<diagonal<<" unidades lineales";
	cout<<endl<<endl;
	
	
	conversiones(5, m, d, c, lit);
	cout<<endl<<"La conversion de galones a ml es: "<<m<<" unidades lineales";
	cout<<endl<<"La conversion de galones a dl es: "<<d<<" unidades lineales";
	cout<<endl<<"La conversion de galones a cl es: "<<c<<" unidades lineales";
	cout<<endl<<"La conversion de galones a l es: "<<lit<<" unidades lineales";
	cout<<endl<<endl;
	
	
	x=5;
	y=7;
	intercambio(x,y);
	cout<<"x= "<<x;
	cout<<endl<<"y= "<<y;
}


	void rect(float b, float h, float& a, float& p, float& d){  //con & se sabe qué variables son bidireccionales (pueden fungir de entrdas o salidas)
		a=b*h;
		p=2*b+2*h;
		d=sqrt(pow(b,2) + pow(h,2));
		
		return;  //no se regresa nada, los valores salen por arriba
	}


	void conversiones(float gal, float& ml, float& dl, float& cl, float& l){
		ml=gal*3785;
		dl= gal*37.854;
		cl=gal*378.5;
		l=gal*3.785;
		
		return;
	}
	

	void intercambio(int& a, int& b){
		int i; //temporal, auxiliar
		
		i=a;
		a=b;
		b=i;
		
		return;
	}
	

