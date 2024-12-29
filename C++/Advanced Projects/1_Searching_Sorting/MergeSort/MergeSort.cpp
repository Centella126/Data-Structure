#include <iostream>
#include <time.h>
#include<stdlib.h>

using namespace std;

#define N 5
#define R 10

void imprimirvh(int* v,int n);
void aleatorio(int* v,int n);
void merge(int* v,int inicio, int mitad,int final);
void omergesort(int* v,int i,int f);

main(){
	int v[N];
	
	cout<<"\n\tO R D E N A C I O N  M E R G E S O R T\n";
	srand(time(NULL)); //SEED RANDOMIZE
	aleatorio(v,N);//funcion de aleatorio para el primer vector 	
	cout<<("\nVector desordenado:\n\n");
	imprimirvh(v,N);
	cout<<("\n\nVector ordenado: \n\n");
	omergesort(v,0,N); 	//¿Por qué debe de ser (v,0,N)?
	imprimirvh(v,N);
	
	return 0;
}



void merge(int* v,int inicio, int mitad,int final){
	int i,j,k;
	int eliz=mitad-inicio+1;//para conocer el numero de elementos del primer lado(izquierda)
	int elde=final-mitad;//Para conocer el numero de elementos del segundo lado(derecho)
	int izquierda[eliz];//se crean dos vectores para agregar del vector anterior
	int derecha[elde];
	for (int i=0;i<eliz;i++)
		izquierda[i]=v[inicio+i];
	for (int j=0;j<elde;j++)
		derecha[j]=v[mitad+1+j];
	i=0;
	j=0;
	k=inicio;
	while(i<eliz && j<elde)//se encarga de mezclar ambos vectores y para que se cumpla este ciclo  la variable j y i debende de ser menor al numero de elementos en el vector iz y de
	{
		if(izquierda[i]<=derecha[j])//en caso de que el elemnto del vector izquierdo sea menor del vector derecho la posicion k le corrrespondera al vector izquierdoen la posicion i
			{
			v[k]=izquierda[i];
			i++;
	    	}
		else
			{
			v[k]=derecha[j];
			j++;
			}
		k++;
	}
	while(j<elde)//se encargaran de vaciar los vectores en caso de ser nesesario
	{
		v[k]=derecha[j];
		j++;
		k++;
	}
	while(i<eliz)//se encargaran de vaciar los vectores en caso de ser nesesario
 {
		v[k]=izquierda[i];
		i++;
		k++;
	}
}



void omergesort(int* v,int i,int f){
	//i es la primer variable del vec1[0] y f es la ultima variable (inicio y final)
	if(i<f)
	{
		int m=i+(f-i)/2;//m es la mitad del vector que se nesesitara para llevar a cabo el proceso y delimitar el lado edrecho del lado izquierdo 
		omergesort(v,i,m);//la mandamos a llamar para que se valla al lado izquiero a la mitad hasta que sea nesesario
		omergesort(v,m+1,f);//La mandamos a llamar para el lado derecho 
		merge(v,i,m,f);
	}	
}



void imprimirvh(int* v, int n){
	int i;
	
	for(i=0; i<n; i++){
		cout<<"["<<i<<"]";
	}
	cout<<endl;	
	for(i=0; i<n; i++){
		cout<<" "<<v[i]<<" ";
	}	
	return;
}



void aleatorio(int* v, int n){
	int i;
	
	for(i=0; i<n; i++){
		v[i]=rand() % R;
	}
	return;
}
