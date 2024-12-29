//Valeria Padilla Sandoval
//Anahi Monserrat Vazquez Padilla
//8 de septiembre del 2022


#include <iostream>
using namespace std;

#define N 5
#define M 3
#define C 25

void imp_invertir(int vec1[]);
void invertir(int vec1[]);
void imp_concatenar(int vec1[], int vec2[], int vec3[]);
void concatenar(int vec1[], int vec2[], int vec3[]);
void imp_operaciones(int vec1[]);
void operaciones(int vec1[]);
void imp_vec1(int vec1[]);
void imp_cadena(char cadena[]);
void cadenaa(char cadena[], char minu, char mayu);

int main() {
	cout<<" INVERTIR VECTOR\n";
	
	int vector[N]={3,2,13,-7,6};
	int vector1[N]={3,2,13,-7,6}, vector2[M]={1,2,6}, vector3[N+M];
	int vec1[N]={3,2,13,-7,6};
	char cadena[]="me traje tajo tres trajes", minu, mayu;
	
	cout<<"Vector normal: "<<endl;
	imp_invertir(vector);
	cout<<endl;
	cout<<"Vector invertido: "<<endl;
	invertir(vector);
	imp_invertir(vector);
	
	cout<<"\n\n\n CONCATENAR DOS VECTORES\n";
	
	cout<<"Vector normal: "<<endl;
	imp_concatenar(vector1, vector2, vector3);
	cout<<endl;
	cout<<"Vector concatenado: "<<endl;
	concatenar(vector1, vector2, vector3);
	
	cout<<"\n\n\n MAYOR, MENOR, DIFERENCIAS Y MEDIA\n";
	
	cout<<"Vector normal: "<<endl;
	imp_vec1(vector1);
	cout<<endl;
	cout<<"Resultados: ";
	operaciones(vector1);
	
	cout<<"\n\n\n CADENA DE TEXTO\n";
	
	cout<<"Cadena de texto minuscula: ";
	imp_cadena(cadena);
	cout<<endl;
	cout<<"Cadena de texto mayuscula: ";
	cadenaa(cadena, minu, mayu);
	return 0;
}

void imp_invertir(int vec1[]){
	int i;
	for(i=0; i<N; i++){
		cout<<"El vector vec1["<<i<<"] = "<<vec1[i]<<endl;
	}
	return;
}

void invertir(int vec1[]){
	int i, aux;
	
	for(i=0; i>(N-i); i++){
		aux=vec1[i];
		vec1[i]=vec1[(N-1)-i];	
		vec1[(N-1)-i]=aux;
	}
	
	while(((N-1)-i)>i){
		aux=vec1[i];
		vec1[i]=vec1[(N-1)-i];	
		vec1[(N-1)-i]=aux;
		i++;
	}
}

void imp_concatenar(int vec1[], int vec2[], int vec3[]){
	int i, j;
	for(i=0; i<N; i++){
		cout<<"El vector vec1["<<i<<"] = "<<vec1[i]<<endl;
	}
	cout<<endl;
	for(j=0; j<M; j++){
		cout<<"El vector vec2["<<j<<"] = "<<vec2[j]<<endl;
	}
	return;
}

void concatenar(int vec1[], int vec2[], int vec3[]){
	int i, j, k;
	for(k=0, i=0; k<N, i<N; k++, i++){
		vec3[k]=vec1[i];
	}	

	for(k=N, j=0; k<N+M, j<M; k++, j++){
		vec3[k]=vec2[j];
	}
			
	for(k=0; k<N+M; k++){
		cout<<"El vector concatenado vec3["<<k<<"] = "<<vec3[k]<<endl;
	}
	return;
}

void imp_vec1(int vec1[]){
	int i;
	for(i=0; i<N; i++){
		cout<<"El vector vec1["<<i<<"] = "<<vec1[i]<<endl;
	}
	return;
}
void operaciones(int vec1[]){
	int numa_p, numa_d, nume_p, nume_d=nume_p, dmax_p, dmax_d=dmax_p, dmin_p, dmin_d=dmin_p, sum=0;	//numa_p (num. mayor provisional), numa_d (num. mayor definitivo), nume_p (num. menor provisional), nume_d (num. menor definitivo)				
	float prom;
	int i, j;
	
	for(i=0, j=1; i<N, j<=N-1; i++, j++){		
		if (vec1[i]>vec1[j]){
			numa_p=vec1[i];
			nume_p=vec1[j];
			
			if(vec1[j]<0){
				vec1[j]=vec1[j]*-1;
				
				if (vec1[j]>vec1[i]){
					dmax_p=vec1[j]-vec1[i];	
					dmin_p=vec1[j]-vec1[i];	
				}
				else{
					dmax_p=vec1[i]+vec1[j];
					dmin_p=vec1[i]+vec1[j];
				}
			}
			else{
				dmax_p=vec1[i]-vec1[j];
				dmin_p=vec1[i]-vec1[j];
			}			
		}
		
		else{
			numa_p=vec1[j];
			nume_p=vec1[i];
			
			if(vec1[i]<0){
				vec1[i]=vec1[i]*-1;
				
				if (vec1[i]>vec1[j]){
					dmax_p=vec1[i]-vec1[j];	
					dmin_p=vec1[i]-vec1[j];
				}
				else{
					dmax_p=vec1[j]+vec1[i];
					dmin_p=vec1[j]+vec1[i];
				}
			}
			else{
				dmax_p=vec1[j]-vec1[i];
				dmin_p=vec1[j]-vec1[i];
			}			
		}
		
		if(numa_p>numa_d){
			numa_d=numa_p;
		}
		
		if(nume_p<nume_d){
			nume_d=nume_p;
		}
		
		if(dmax_p>dmax_d){
			dmax_d=dmax_p;
		}
		
		if(dmin_p<dmin_d){
			dmin_d=dmin_p;
		}
	}

	for(i=0; i<N; i++){
		sum=sum+vec1[i];
	}	
	prom=sum/N;
	
	cout<<"\nEl dato mayor es: "<<numa_d;
	cout<<"\nEl dato menor es: "<<nume_d;
	cout<<"\nLa diferencia maxima absoluta es: "<<dmax_d;
	cout<<"\nLa diferencia minima absoluta es: "<<dmin_d;
	cout<<"\nLa media aritmetica es: "<<prom;
	
	return;
}

void imp_cadena(char cadena[]){
	cout<<endl<<cadena;
	return;
}

void cadenaa(char cadena[], char minu, char mayu){
	int i; 
	for(i=0; i<C; i++){
		minu='a';
		mayu='A';
		
		while(minu<='z'){
			if(cadena[i]==minu){
				cadena[i]=mayu;
			}
		minu++;
		mayu++;
		}
	}
	cout<<endl<<cadena;
	return;
}






