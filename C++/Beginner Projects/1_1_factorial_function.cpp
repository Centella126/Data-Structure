#include <iostream>
using namespace std;

float factorial(int num, float fac){
	
		for (int i=1; i<=num; i++){
		fac=fac*i;
		}
	return fac;
}

int main() 
{
	
}

int factorial(){
	cout<<"Ingrese un numero: ";
	cin>>num;

	cout<<"El factorial de "<<num<<" es: "<<factorial;

	
	return 0;
}
