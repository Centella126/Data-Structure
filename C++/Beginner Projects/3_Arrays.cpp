#include <iostream>

using namespace std;

/*Grupo o colecci�n finita, homog�nea y ordenada de elementos. Un arreglo(vector, array, matriz) es un conjunto de datos o una estructura de datos homog�neos 
que se encuentran ubicados en forma consecutiva en la memoria RAM.
Es un tipo compuesto que permite almacenar un conjunto de datos del mismo tipo relacionados entre s�.

Tipos:
1) Simples
solo pueden almacenar un tipo de dato cada vez:
	int
	float
	double
	char
	void

2)Compuestos
Esta formado por varios datos a la vez:
	arreglos (matrices, cadenas)
	estructuras (registros)
	conjuntos
	
<Tipos de arreglos>
a)Unidimensional
b)Multidimensional
	- Bidimensional
	- Tridimensional
*/

const int N=5;
//#define M 20

int main() 
{
	//Escriba un c�digo en C para guardar datos en un vector.
	
	int vec[5], i, n;	//Sintaxis: tipo nombrearreglo[tama�o];
	float vec3[5], vec4[N];

	cout<<"ARREGLOS UNIDIMENSIONALES EN C\n\n";
	cout<<"Se guardan e imprimen 5 datos de tipo entero en un vector\n";
	
	vec[0] = -400;
	vec[1] = 0;
	vec[2] = 13;
	vec[3] = 6;
	vec[4] = 20000;
	
	cout<<"vec[0] = "<<vec[0]<<endl;
	cout<<"vec[1] = "<<vec[1]<<endl;
	cout<<"vec[2] = "<<vec[2]<<endl;
	cout<<"vec[3] = "<<vec[3]<<endl;
	cout<<"vec[4] = "<<vec[4]<<endl;

	
//Otra forma

	int vec2[5]={2,-4,7,10,2000};	//Sintaxis: tipo nombrearreglo[tama�o];
	
	cout<<"\n\nARREGLOS UNIDIMENSIONALES EN C V2\n\n";
	cout<<"Se guardan e imprimen 5 datos de tipo entero en un vector\n";
	
	cout<<"vec[0] = "<<vec2[0]<<endl;
	cout<<"vec[1] = "<<vec2[1]<<endl;
	cout<<"vec[2] = "<<vec2[2]<<endl;
	cout<<"vec[3] = "<<vec2[3]<<endl;
	cout<<"vec[4] = "<<vec2[4]<<endl;
	
	
//Otra forma

	//Sintaxis: tipo nombrearreglo[tama�o];
	
	cout<<"\n\nARREGLOS UNIDIMENSIONALES EN C V3\n\n";
	cout<<"Se guardan e imprimen 5 datos dados por el usuario de tipo entero en un vector\n";
	
	for(i=0; i<5; i++){
		cout<<"Da el valor para el indice "<<i<<": ";
		cin>>vec3[i];
	}

	cout<<endl;
	
	for(i=0; i<5; i++){
		cout<<"vec["<<i<<"] = "<<vec3[i]<<endl;
	}	
	
	
//Otra forma

//Est� mejor esta forma, porque se edita el tama�o de la variable desde fuera, no desde dentro del programa

	cout<<"\n\nARREGLOS UNIDIMENSIONALES EN C V4\n\n";
	cout<<"Numero de datos a capturar (maximo "<<N<<"): ";
	cin>>n;
	
	for(i=0; i<n; i++){
		cout<<"Da el valor para el indice "<<i<<": ";
		cin>>vec4[i];
	}

	cout<<endl;
	
	for(i=0; i<n; i++){
		cout<<"vec["<<i<<"] = "<<vec4[i]<<endl;
	}
	
	return 0;
}







