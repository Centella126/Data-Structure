//Padilla Sandoval Valeria
//Vázquez Padilla Anahí Montserrat
//3. Recursividad
//25 de agosto 2022

#include <iostream>

using namespace std;


float sumatoria_i(int n);
float sumatoria_r(int n);

float multiplicatoria_i(int num);
float multiplicatoria_r(int num);

float pot_i(float b, int p);
float pot_r(float b, int p);

float fibonacci_i(int lim);
float fibonacci_r(int lim);

int main() 
{
	float x, a, base, f;
	int potencia, i;

	cout<<"SUMATORIA\n\n";
	
	cout<<"Digita un entero positivo: ";
	cin>>x; 	
	cout<<"La sumatoria de 1 hasta "<<x<<" es: "<<sumatoria_i(x)<<endl;  //iterativo
	cout<<"La sumatoria de 1 hasta "<<x<<" es: "<<sumatoria_r(x)<<endl;  //recursivo
	

	cout<<"\n\nMULTIPLICATORIA\n\n";
	
	cout<<"Digita un entero positivo: ";
	cin>>a; 	
	cout<<"La multiplicatoria de 1 hasta "<<a<<" es: "<<multiplicatoria_i(a)<<endl;  //iterativo	
	cout<<"La multiplicatoria de 1 hasta "<<a<<" es: "<<multiplicatoria_r(a)<<endl;	 //recursivo


	cout<<"\n\nPOTENCIA\n\n";
	
	cout<<"Digita un numero: ";
	cin>>base; 	
	cout<<"Digita una potencia: ";
	cin>>potencia; 
	cout<<"El valor de "<<base<<" elevado a  "<<potencia<<" es: "<<pot_i(base, potencia)<<endl;  //iterativo
	cout<<"El valor de "<<base<<" elevado a  "<<potencia<<" es: "<<pot_r(base, potencia)<<endl;  //recursivo
		
	
	cout<<"\n\nFIBONACCI\n\n";
	
	cout<<"Digita el numero de terminos de la serie: ";
	cin>>f; 
	for(i=1; i<=f; i++){
		cout<<fibonacci_r(i)<<" ";	//iterativo
	}	
	cout<<endl;	
	for(i=1; i<=f; i++){
		cout<<fibonacci_i(i)<<" ";  //recursivo
	}
	
	return 0;
}


float sumatoria_i(int n){
	int i=1, suma=0;
	
	while(i<=n){
		suma=suma+i;
		i++;
	}
	return suma;
}

float sumatoria_r(int n){
	if(n<=0){
		return 0;
	}
	else{
		return n+sumatoria_r(n-1);
	}
}


float multiplicatoria_i(int num){
	int i;
	float mul=1;
	
	if(num==0){				
		return 1;
	}
	else{
		for(i=1; i<=num; i++){
			mul=mul*i;
		}
		return mul;
	}
}

float multiplicatoria_r(int num){
	if(num<=0){
		return 1;
	}
	else{
		return num*multiplicatoria_r(num-1);
	}
}


float pot_i(float b, int p){
	int i;
	float resul=1;
	
	if(p==0){
		return 1;
	}
	else{
		for(i=1; i<=p; i++){
			resul=resul*b;
		}
		return resul;
	}
}

float pot_r(float b, int p){
	if(p==0){
		return 1;
	}
	else{
		return b*pot_r(b,p-1);
	}
}


float fibonacci_i(int lim){	
	int i, a=0, b=1, resul=0;
	
	while(i<=lim-2){
		resul=a+b;
		b=a;
		a=resul;
		i++;
	}
	return resul;
}

float fibonacci_r(int lim){	
	if(lim==1){
		return 0;
	}
	else if (lim==2 || lim==3){
		return 1;
	}
	else{
		return fibonacci_r(lim-1) + fibonacci_r(lim-2);
	}
}
