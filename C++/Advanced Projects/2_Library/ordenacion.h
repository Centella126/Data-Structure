#include <iostream>
using namespace std;

#define N 10

int v[N];

void cambiovariable(int* v, int i, int j){
	int aux;
	aux=v[j];
	v[j]=v[i];
	v[i]=aux;	
}

void imprimirvh(int* v, int n, int x){
	int i;
	if(x==1){
		for(i=0; i<n; i++){
			cout<<"["<<i<<"]";
		}
		cout<<endl;	
		for(i=0; i<n; i++){
			cout<<" "<<v[i]<<" ";
		}
	}
	if(x==0){
		for(i=0; i<n; i++){
			cout<<" "<<v[i]<<" ";
		}
		cout<<endl;	
	}	
	return;
}

void ointercambiodirecto(){
	int i;
	int j;
	for(i=0; i<N; i++){
		//Pasadas
		if(i<N-1){
			cout<<endl;
			cout<<"P"<<i+1<<": ";
			imprimirvh(v, N,0);
		}
		
		for(j=0; j<N; j++){
			if(v[i] < v[j]){
				cambiovariable(v,i,j);
			}			
		}
	}
}

void oselecciondirecta(int* v,int n, int y){
	int min,aux;

	for (int i = 0; i < N-1; i++) {
		min = i;
		for (int j = i + 1; j < N; j++){ 			//ver si cada uno de los terminos del arreglo son menores a min (Primer termino)
	 		if (v[j] < v[min]){
				min = j;
			}
		}	
		//Pasadas
		if(y==0){
			cout<<endl;
			cout<<"P"<<i+1<<": ";
			imprimirvh(v,N,0);			
		}
		cambiovariable(v,min,i); 	// Dentro del primer for se colocan los numeros a imprimir en el orden que van dándose 
	}
}

void oinserciondirecta(int* v, int n){
	int i, a, aux;
	for (i =1; i<n; i++){
	   aux = v[i];
	   a=i-1;
		//Pasadas
		cout<<endl;
		cout<<"P"<<i<<": ";
		imprimirvh(v, N,0);
				
	   while (a >= 0 && v[a] > aux){
	       v[a + 1] = v[a];
	       a--;
	   }
	   v[a+1] = aux;
	}
}

void oshell(int* v,int n){
	int i, j, k, aux;
	k = n/2;	
	while (k > 0) {
		for (i=k; i < N; i++) {
		j = i;
		aux = v[i];
			while ((j >= k) && (v[j - k] > aux)){
				v[j] = v[j - k];
				j = j - k;
			}
			v[j] = aux;
		}
		k /= 2;
	}	
}

void oquicksort(int* v, int primero, int ultimo){
	int i, j, central, aux;
    double pivote; 
    
    central = (primero + ultimo)/2;
    pivote = v[central];
    i = primero;
    j = ultimo;
    
    do{
        while (v[i] < pivote)i++;{
        	while (v[j] > pivote)j--;{ 
		        if (i <= j){		// intercambia a[i] con a[j]
					cambiovariable(v,i,j);
		       		i++;
		       		j--;
		    	}
			}       
		}        
	}while (i <= j);
	
	if (primero < j){
		oquicksort(v, primero, j); /* mismo proceso con sublista izqda */
	}
	if (i < ultimo){
		oquicksort(v, i, ultimo); /* mismo proceso con sublista drcha */
	}
}

void merge(int* v,int inicio, int mitad,int final){
	int i,j,k;
	int eliz=mitad-inicio+1;//para conocer el numero de elementos del primer lado(izquierda)
	int elde=final-mitad;//Para conocer el numero de elementos del segundo lado(derecho)
	int izquierda[eliz];//se crean dos vectores para agregar del vector anterior
	int derecha[elde];
	for (int i=0;i<eliz;i++){
		izquierda[i]=v[inicio+i];
	}	
	for (int j=0;j<elde;j++){
		derecha[j]=v[mitad+1+j];
	}	
	i=0;
	j=0;
	k=inicio;
	while(i<eliz && j<elde){//se encarga de mezclar ambos vectores y para que se cumpla este ciclo  la variable j y i debende de ser menor al numero de elementos en el vector iz y de
		if(izquierda[i]<=derecha[j]){//en caso de que el elemnto del vector izquierdo sea menor del vector derecho la posicion k le corrrespondera al vector izquierdoen la posicion i
			v[k]=izquierda[i];
			i++;
	    }
		else{
			v[k]=derecha[j];
			j++;
		}
		k++;
	}
	while(j<elde){//se encargaran de vaciar los vectores en caso de ser nesesario
		v[k]=derecha[j];
		j++;
		k++;
	}
	while(i<eliz){//se encargaran de vaciar los vectores en caso de ser nesesario
		v[k]=izquierda[i];
		i++;
		k++;
	}
}

void omergesort(int* v,int i,int f){
	//i es la primer variable del vec1[0] y f es la ultima variable (inicio y final)
	if(i<f){
		int m=i+(f-i)/2;//m es la mitad del vector que se nesesitara para llevar a cabo el proceso y delimitar el lado edrecho del lado izquierdo 
		omergesort(v,i,m);//la mandamos a llamar para que se valla al lado izquiero a la mitad hasta que sea nesesario
		omergesort(v,m+1,f);//La mandamos a llamar para el lado derecho 
		merge(v,i,m,f);
	}
}

