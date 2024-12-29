#include <iostream>
#include <stdio.h> //para etiquetas y goto
#include <conio.h> //para el getch();
#include <stdlib.h>
#include <time.h>
using namespace std;

#define N 10	//tamaño vector
#define R 10	//rango de valores aleatorio v[i]=rand() % R;

struct nodo{ //para hash
	int datos;
	struct nodo* siguiente;
};

void aleatorio(int* v, int n);
void imprimirvh(int* v, int n, int x);	//Vectores horizontales, cuando x==1 se imprimen los índices, en las pasadas no se imprimen los indices
void cambiovariable(int* v, int i, int j); 

void portada();
void ointercambiodirecto_main(int* v);
void ointercambiodirecto(int* v, int n);
void oinserciondirecta_main(int* v);
void oinserciondirecta(int* v, int n);
void oselecciondirecta_main(int* v);
void oselecciondirecta(int* v,int n, int y); //cuando y==0 imprime las pasadas, sirve para que al ordenar en busqueda binaria no se impriman las pasadas
void oshell_main(int* v);
void oshell(int* v, int n);
void oquicksort_main(int* v);
void oquicksort(int* v, int primero, int ultimo);
void omergesort_main(int* v);
void merge(int* v,int inicio, int mitad,int final);
void omergesort(int* v,int i,int f);
void bsecuencial_main(int* v);
void bsecuencial(int* v, int clave, int n, int& centinela, int& indice);
void blineal_main(int* v);
void blineal(int* v, int clave, int n, int& centinela, int& indice);
void bbinaria_main(int* v);
int bbinaria(int* v, int clave);
void bhash_main(int* v);
void bhash_fHash(int valor, struct nodo* v[N]);
void bhash(int valor, struct nodo* vec[N], int& i, int& centinela);
void bhash_inicio(struct nodo * v[N]);

int main() {
	int v[N];
	char op_oyb, op_bus, op_ord, op_dir, op_ind;
	
	portada();
	
	ordenacionybusqueda:
		system("cls");
		cout<<"\n\n\t O R D E N A C I O N  Y  B U S Q U E D A";
		cout<<"\n\t\t [O]rdenacion";
		cout<<"\n\t\t [B]usqueda";
		cout<<"\n\t\t [T]erminar";
		cout<<"\n\t\t Elija una opcion: ";
		cin>>op_oyb; //opcion del menu de ordenacion y busqueda	
	
		switch (op_oyb){
			case 'O': case 'o':
				ordenacion:
					system("CLS");
					cout<<"\n\t O R D E N A C I O N ";
					cout<<"\n\t [D]irectos ";
					cout<<"\n\t [I]ndirectos / Logaritmicos ";
					cout<<"\n\t [R]egresar ";
					cout<<"\n\t\t Elija una opcion: ";
					cin>>op_ord; //opcion del menu de ordenacion
		
					switch(op_ord){
						case 'D': case 'd':
							directos:		
								system("CLS");
								cout<<"\n\t D I R E C T O S ";
								cout<<"\n\t [I]ntercambio ";
								cout<<"\n\t [S]eleccion ";
								cout<<"\n\t I[N]cersion ";
								cout<<"\n\t [R]egresar ";
								cout<<"\n\t\t Elija una opcion: ";
								cin>>op_dir; //opcion del menu de directos
								
								switch(op_dir){
									case 'I': case 'i':
										system("CLS");
										cout<<"\n\t I N T E R C A M B I O ";
										ointercambiodirecto_main(v);
										cout<<endl;
										cout<<"\n\t Presiona cualquier tecla para regresar el menu de ordenacion directa ";
										getch();
										system("CLS");
										goto directos;
									break;	
									
									case 'S': case 's':
										system("CLS");
										cout<<"\n\t S E L E C C I O N ";
										oselecciondirecta_main(v);
										cout<<endl;
										cout<<"\n\t Presiona cualquier tecla para regresar el menu de ordenacion directa ";
										getch();
										system("CLS");
										goto directos;
									break;
									
									case 'N': case 'n':
										system("CLS");
										cout<<"\n\t I N C E R S I O N ";
										oinserciondirecta_main(v);
										cout<<endl;
										cout<<"\n\t Presiona cualquier tecla para regresar el menu de ordenacion directa ";
										getch();
										system("CLS");
										goto directos;
									break;
									
									case 'R': case 'r':
										system("CLS");
										goto ordenacion;
									break;
									
									default: 
										cout<<"\n\t Esa opcion no es valida ";
										system ("pause");
										goto directos;
								}
						break;
				
						case 'I': case 'i':
							indirectos:
								system("CLS");
								cout<<"\n\t I N D I R E C T O S ";
								cout<<"\n\t [S]hell / Incrementos decrecientes ";
								cout<<"\n\t [Q]uickSort / Rapido ";
								cout<<"\n\t [M]ergeSort / Mezcla ";
								cout<<"\n\t [R]egresar ";
								cout<<"\n\t\t Elija una opcion: ";
								cin>>op_ind; //opcion del menu de indirectos
								
								switch(op_ind){
									case 'S': case 's':
										system("CLS");
										cout<<"\n\t S H E L L ";
										oshell_main(v);
										cout<<endl;
										cout<<"\n\t Presiona cualquier tecla para regresar el menu de ordenacion indirecta ";
										getch();
										system("CLS");
										goto indirectos;
									break;	
									
									case 'Q': case 'q':
										system("CLS");
										cout<<"\n\t Q U I C K S O R T ";
										oquicksort_main(v);
										cout<<endl;
										cout<<"\n\t Presiona cualquier tecla para regresar el menu de ordenacion indirecta ";
										getch();
										system("CLS");
										goto indirectos;
									break;
									
									case 'M': case 'm':
										system("CLS");
										cout<<"\n\t M E R G E S O R T ";
										omergesort_main(v);
										cout<<endl;
										cout<<"\n\t Presiona cualquier tecla para regresar el menu de ordenacion indirecta ";
										getch();
										system("CLS");
										goto indirectos;
									break;
									
									case 'R': case 'r':
										system("CLS");
										goto ordenacion;
									break;
									
									default: 
										cout<<"\n\t Esa opcion no es valida ";
										system ("pause");
										goto indirectos;
								}
						break;
						
						case 'R': case 'r':
							system("CLS");
							goto ordenacionybusqueda;
						break;
						
						default: 
							cout<<"\n\t Esa opcion no es valida ";
							system ("pause");
							goto ordenacion;
					}
			case 'B': case 'b':
				busqueda:
					system("CLS");
					cout<<"\n\t B U S Q U E D A";
					cout<<"\n\t [L]ineal / Secuencial ";
					cout<<"\n\t [B]inaria / Dicotomica ";
					cout<<"\n\t [H]ash / Transformacion de claves ";
					cout<<"\n\t [R]egresar ";
					cout<<"\n\t\t Elija una opcion: ";
					cin>>op_bus; //opcion del menu de busqueda
		
					switch(op_bus){
						case 'L': case 'l':
							system("CLS");
							cout<<"\n\t L I N E A L ";
							blineal_main(v);
							cout<<endl;
							cout<<"\n\t Presiona cualquier tecla para regresar el menu de busqueda ";
							getch();
							system("CLS");
							goto busqueda;
						break;	
						
						case 'B': case 'b':
							system("CLS");
							cout<<"\n\t B I N A R I A ";
							bbinaria_main(v);
							cout<<endl;
							cout<<"\n\t Presiona cualquier tecla para regresar el menu de busqueda ";
							getch();
							system("CLS");
							goto busqueda;
						break;
						
						case 'H': case 'h':
							system("CLS");
							cout<<"\n\t H A S H ";
							bhash_main(v);
							cout<<endl;
							cout<<"\n\t Presiona cualquier tecla para regresar el menu de busqueda ";
							getch();
							system("CLS");
							goto busqueda;
						break;
						
						case 'R': case 'r':
							system("CLS");
							goto ordenacionybusqueda;
						
						default: 
							cout<<"\n\t Esa opcion no es valida ";
							system ("pause");
							goto busqueda;
					}			
			case 'T': case 't':
				system("cls");
				return 0;
			break;
				
			default: 
				cout<<"\n\t Esa opcion no es valida ";	
				system ("pause");
				goto ordenacionybusqueda;	
		}
}

void portada(){
	cout<<"\t\t\n                                    UNIVERSIDAD DE GUADALAJARA";
	cout<<endl;
	cout<<"\t\t\n                               Centro Universitario de los Lagos";
	cout<<endl;
	cout<<"\t\t\n              Division de Estudios de la Biodiversidad e Innovacion Tecnologica";
	cout<<endl;
	cout<<"\t\t\n                         Departamento de Ciencias Exactas y Tecnologia";
	cout<<endl;
	cout<<"\t\t\n                                        Calendario 2022B";
	cout<<endl;
	cout<<"\t\t\n                             Carrera: Ingenieria Mecatronica IMEC";
	cout<<endl;
	cout<<"\t\t\n                                  Materia: Estructura de datos";
	cout<<endl;
	cout<<"\t\t\n                                   Tema: Ordenacion y busqueda";
	cout<<endl;
	cout<<"\t\t\n                                 Nombre de las alumnas y codigo :";
	cout<<"\t\t\n                              Padilla Sandoval Valeria \t\t 218480301";
	cout<<"\t\t\n                           Vazquez Padilla Anahi Montserrat \t 221944033";
	cout<<endl;
	cout<<"\t\t\n                           Lagos de Moreno a 14 de octubre del 2022";
	cout<<endl<<endl<<endl;
	system ("pause");
}

void ointercambiodirecto_main(int* v){
	system("CLS");
	cout<<("\tI N T E R C A M B I O  D I R E C T O\n\n");
	srand(time(NULL));
	aleatorio(v,N);
	cout<<("\nVector desordenado: \n\n");
	imprimirvh(v, N,1);
	
	cout<<("\n\nPasadas:\n");
	ointercambiodirecto(v, N);
	
	cout<<("\n\nVector ordenado: \n\n");
	imprimirvh(v, N,1);
}

void ointercambiodirecto(int* v, int n){
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

void oinserciondirecta_main(int* v){
	system("CLS");
	cout<<("\tI N S E R C I O N  D I R E C T A\n\n");
	srand(time(NULL));
	aleatorio(v, N);
	cout<<("\nVector desordenado: \n\n");
	imprimirvh(v, N,1);
	
	cout<<("\n\nPasadas:\n");
	oinserciondirecta(v,N);
	
	cout<<("\n\nVector ordenado: \n\n");
	
	imprimirvh(v, N,1);
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

void oselecciondirecta_main(int* v){
	system("CLS");
	cout<<"\n\tS E L E C C I O N  D I R E C T A\n\n";
	srand(time(NULL));
	aleatorio (v,N);
	cout<<"\nVector desordenado: \n\n";
	imprimirvh(v, N,1);
	
	cout<<"\n\n\nPasadas:\n"; 
	oselecciondirecta(v,N,0);
	
	cout<<"\n\nVector ordenado: \n\n";
	imprimirvh(v, N,1);
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

void oshell_main(int* v){
	system("CLS");
	cout<<"\n\tO R D E N A C I O N  S H E L L\n";
	srand(time(NULL));	
	aleatorio(v,N);
	cout<<("\n\nVector desordenado: \n\n");
	imprimirvh(v,N,1);
	
	cout<<("\n\nVector ordenado: \n\n");
	oshell(v,N);
	imprimirvh(v,N,1);
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

void oquicksort_main(int* v){
	system("CLS");
	cout<<"\n\tO R D E N A C I O N  Q U I C K S O R T\n";
	srand(time(NULL));	
	aleatorio(v, N);	
	cout<<("\nVector desordenado: \n\n");
	imprimirvh(v,N,1);	
	
	cout<<("\n\nVector ordenado: \n\n");
	oquicksort(v, 0, N-1);
	imprimirvh(v,N,1);
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

void omergesort_main(int* v){
	system("CLS");
	cout<<"\n\tO R D E N A C I O N  M E R G E S O R T\n";
	srand(time(NULL)); //SEED RANDOMIZE
	aleatorio(v,N); 	
	cout<<("\nVector desordenado:\n\n");
	imprimirvh(v,N,1);
	
	cout<<("\n\nVector ordenado: \n\n");
	omergesort(v,0,N); 
	imprimirvh(v,N,1);
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

void blineal_main(int* v){
	system("cls");
	int clave;
	int centinela=-1;
	int i;
	
	cout<<"\n\t B U S Q U E D A   S E C U E N C I A L  O   L I N E A L \n\n";
	srand(time(NULL)); //SEED RANDOMIZE 
	aleatorio(v, N);
	cout<<"Vector: \n\n";
	imprimirvh(v, N, 1);
	
	cout<<"\n\nIngrese el dato a buscar: ",
	cin>>clave;
	blineal(v, clave, N, centinela, i);
	
	if(centinela==-1){
		cout<<"\n\tDato no encontrado\n\n";
	}
	if(centinela==1){
		cout<<"\n\tEl numero ha sido encontrado en el indice "<<i<<"\n\n";
	}
}

void blineal(int* v, int clave, int n, int& centinela, int& indice){
	int i;
	
	for(i=0; i<n && centinela==-1; i++){
		if(v[i]==clave){
			centinela=1;	
			indice=i;
		}
	}
}

void bbinaria_main(int* v){
	system("cls");
	int clave;
	int i;
	srand(time(NULL)); //SEED RANDOMIZE 
	aleatorio(v, N);
	
	cout<<"\n\t B U S Q U E D A   B I N A R I A \n\n";
	
	cout<<"Vector desordenado: \n\n";
	imprimirvh(v,N,1);
	
	cout<<"\n\n\nVector ordenado: \n\n";
	oselecciondirecta(v,clave,1);
	imprimirvh(v,N,1);	
		
	cout<<"\n\nIngrese el dato a buscar: ",
	cin>>clave;
	
	if(bbinaria(v, clave) == -1){
		cout<<"\n\tDato no encontrado\n\n";
	}
	else{
		cout<<"\n\tEl dato "<<clave<<" se encontro en el indice: "<<bbinaria(v, clave)<<"\n\n";
	}
}

int bbinaria( int* v, int clave){
	int c, i=0, d=N-1;
	int bandera=0;
		
	while( i <= d ){
		c = (i+d)/2;
		if( v[c] == clave )	//if( c == db )
			return c;
		else
			if( clave > v[c] )	//if( db > c )
				i = c + 1;
			else
				d = c - 1;
	}		
	return -1;
}

void bhash_main(int* v){
	int i, centinela;
	int datoBuscar;
	struct nodo*vec[N];
	
	bhash_inicio(vec);
	
	bhash_fHash(680372, vec);
	bhash_fHash(740790, vec);
	bhash_fHash(658866, vec);
	bhash_fHash(855970, vec);
	bhash_fHash(896990, vec);
	
	cout <<"\nCLAVE A BUSCAR: ";
	cin >> datoBuscar;
	
	bhash(datoBuscar, vec, i, centinela);
	
	if(centinela==1){
		cout << datoBuscar << ": CLAVE ENCONTRADA"<<endl;
		cout << "LA CLAVE SE ENCUENTRA EN LA POSICION [" << i << "] DEL ARREGLO"<<endl;
	}
	else {
		cout << datoBuscar << ": CLAVE NO ENCONTRADA"<<endl;
	}
}

void bhash_inicio(struct nodo* v[]){ //INICIA EL ARREGLO EN NULL
	int i;
	for(i=0; i<N; i++)
		v[i]  = NULL;
}

void bhash_fHash(int valor, struct nodo* v[]){  
	int i;

	//CREA UN NUEVO NODO CON VALOR 
	
	struct nodo*nuevoNodo;
	nuevoNodo = (struct nodo *)malloc(sizeof (struct nodo));
	nuevoNodo->datos = valor;
	nuevoNodo->siguiente = NULL;
	
	//CALCULAR CLAVE / FUNCION HASH
	i = valor % N;
	
	//COMPRUEBA SI LA CADENA (INDICE) ESTÃ  VACIA
	if (v[i] == NULL)
		v[i] = nuevoNodo;
	else { //COLISION
		struct nodo* aux = v[i];
		while ( aux->siguiente){
			aux = aux -> siguiente;
		}
		aux->siguiente = nuevoNodo;
	}
}

void bhash(int valor, struct nodo*v[], int& i, int& centinela){
	
	//APLICA LA FUNCION HASH
	i = valor%N;
	
	//BUSCA EN LA POSICION
	struct nodo*aux = v[i];
	while(aux){
		if(aux->datos == valor){
			centinela = 1; //DATO ENCONTRADO
		}
		aux = aux->siguiente;
	}
	centinela == 0;
}	

void aleatorio(int* v, int n){
	int i;
	
	for(i=0; i<n; i++){
		v[i]=rand() % R;
	}
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

void cambiovariable(int* v, int i, int j){
	int aux;
	aux=v[j];
	v[j]=v[i];
	v[i]=aux;	
}
