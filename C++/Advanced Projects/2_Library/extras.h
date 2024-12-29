#include <iostream>
#include <conio.h> //para el getch();
#include <stdlib.h>
#include <time.h>
#include "ordenacion.h"
#include "busqueda.h"
using namespace std;

#define R 10

void aleatorio(int* v, int n){
	int i;
	
	for(i=0; i<n; i++){
		v[i]=rand() % R;
	}
}

void menu(void){
	srand(time(NULL));
	char op_oyb, op_bus, op_ord, op_dir, op_ind;
	int clave;
	int centinela;
	int datoBuscar;
	int i;	
	
	do{
		system("cls");
		cout<<"\n\n\t O R D E N A C I O N  Y  B U S Q U E D A";
		cout<<"\n\t\t [O]rdenacion";
		cout<<"\n\t\t [B]usqueda";
		cout<<"\n\t\t [T]erminar";
		cout<<"\n\t\t Elija una opcion: ";		
		fflush(stdin);
		cin>>op_oyb; //opcion del menu de ordenacion y busqueda	
		op_oyb = toupper(op_oyb);
		
		switch (op_oyb){
			case 79: //O-rdenacion
				do{
					system("CLS");
					cout<<"\n\t O R D E N A C I O N ";
					cout<<"\n\t [D]irectos ";
					cout<<"\n\t [I]ndirectos / Logaritmicos ";
					cout<<"\n\t [R]egresar ";
					cout<<"\n\t\t Elija una opcion: ";					
					fflush(stdin);
					cin>>op_ord; //opcion del menu de ordenacion
					op_ord = toupper(op_ord);

						switch(op_ord){
							case 68: //D-irectos
								do{
									system("CLS");
									cout<<"\n\t D I R E C T O S ";
									cout<<"\n\t [I]ntercambio ";
									cout<<"\n\t [S]eleccion ";
									cout<<"\n\t I[N]cersion ";
									cout<<"\n\t [R]egresar ";
									cout<<"\n\t\t Elija una opcion: ";									
									fflush(stdin);
									cin>>op_dir; //opcion del menu de directos
									op_dir = toupper(op_dir);
									
									switch(op_dir){
										case 73: //I-ntercambio
											system("CLS");
											cout<<("\tI N T E R C A M B I O  D I R E C T O\n\n");
											aleatorio(v,N);
											cout<<("\nVector desordenado: \n\n");
											imprimirvh(v, N,1);										
											cout<<("\n\nPasadas:\n");
											ointercambiodirecto();										
											cout<<("\n\nVector ordenado: \n\n");
											imprimirvh(v, N,1);	
											cout<<"\n\t Presiona cualquier tecla para regresar el menu de ordenacion directa ";
											getch();
											system("CLS");									
											break;
											
										case 83: //S-eleccion		
											system("CLS");
											cout<<"\n\tS E L E C C I O N  D I R E C T A\n\n";
											aleatorio (v,N);
											cout<<"\nVector desordenado: \n\n";
											imprimirvh(v, N,1);
											cout<<"\n\n\nPasadas:\n"; 
											oselecciondirecta(v,N,0);
											cout<<"\n\nVector ordenado: \n\n";
											imprimirvh(v, N,1);
											cout<<"\n\t Presiona cualquier tecla para regresar el menu de ordenacion directa ";
											getch();
											system("CLS");										
											break;
											
										case 78: //i-N-cersion
											system("CLS");
											cout<<("\tI N S E R C I O N  D I R E C T A\n\n");
											aleatorio(v, N);
											cout<<("\nVector desordenado: \n\n");
											imprimirvh(v, N, 1);											
											cout<<("\n\nPasadas:\n");
											oinserciondirecta(v,N);											
											cout<<("\n\nVector ordenado: \n\n");											
											imprimirvh(v, N,1);
											cout<<"\n\t Presiona cualquier tecla para regresar el menu de ordenacion directa ";
											getch();
											system("CLS");										
											break;
								
											
										case 82: //R-egresar
											system ("cls");
											break;
											
										default:
											cout<<"\n\t Esa opcion no es valida ";
											system ("pause");
											break;
									}
								} while (op_dir!=82);
								
								break;
								
							case 73: //I-ndirectos	
								do{
									system("CLS");
									cout<<"\n\t I N D I R E C T O S ";
									cout<<"\n\t [S]hell / Incrementos decrecientes ";
									cout<<"\n\t [Q]uickSort / Rapido ";
									cout<<"\n\t [M]ergeSort / Mezcla ";
									cout<<"\n\t [R]egresar ";
									cout<<"\n\t\t Elija una opcion: ";									
									fflush(stdin);
									cin>>op_ind; //opcion del menu de indirectos
									op_ind = toupper(op_ind);
									
									switch(op_ind){
										case 83: //S-hell
											system("CLS");
											cout<<"\n\tO R D E N A C I O N  S H E L L\n";
											aleatorio(v,N);
											cout<<("\n\nVector desordenado: \n\n");
											imprimirvh(v,N,1);											
											cout<<("\n\nVector ordenado: \n\n");
											oshell(v,N);
											imprimirvh(v,N,1);
											cout<<"\n\t Presiona cualquier tecla para regresar el menu de ordenacion directa ";
											getch();
											system("CLS");										
											break;
									
										case 81: //M-ergeSort
											system("CLS");
											cout<<"\n\tO R D E N A C I O N  Q U I C K S O R T\n";	
											aleatorio(v, N);	
											cout<<("\nVector desordenado: \n\n");
											imprimirvh(v,N,1);												
											cout<<("\n\nVector ordenado: \n\n");
											oquicksort(v, 0, N-1);
											imprimirvh(v,N,1);
											cout<<"\n\t Presiona cualquier tecla para regresar el menu de ordenacion directa ";
											getch();
											system("CLS");									
											break;
											
										case 77: //Q-uickSort
											system("CLS");
											cout<<"\n\tO R D E N A C I O N  M E R G E S O R T\n";
											aleatorio(v,N); 	
											cout<<("\nVector desordenado:\n\n");
											imprimirvh(v,N,1);											
											cout<<("\n\nVector ordenado: \n\n");
											omergesort(v,0,N); 
											imprimirvh(v,N,1);
											cout<<"\n\t Presiona cualquier tecla para regresar el menu de ordenacion directa ";
											getch();
											system("CLS");		
											break;
											
										case 82: //R-egresar
											system ("cls");										
											break;
										
										default:
											cout<<"\n\t Esa opcion no es valida ";
											system ("pause");									
											break;
									}
								}while(op_ind!=82);
								
								break;
								
							case 82: //R-egresar
								system ("cls");	
								break;
							
							default:
								cout<<"\n\t Esa opcion no es valida ";
								system ("pause");
								break;
						}
				} while(op_ord!=82);
				
				break;
			
			case 66: //B-usqueda	
				do{
					system("CLS");
					cout<<"\n\t B U S Q U E D A";
					cout<<"\n\t [L]ineal / Secuencial ";
					cout<<"\n\t [B]inaria / Dicotomica ";
					cout<<"\n\t [H]ash / Transformacion de claves ";
					cout<<"\n\t [R]egresar ";
					cout<<"\n\t\t Elija una opcion: ";					
					fflush(stdin);
					cin>>op_bus; //opcion del menu de busqueda	
					op_bus = toupper(op_bus);
					
					switch(op_bus){
						case 76: //L-ineal
							system("cls");	
							centinela=-1;
							cout<<"\n\t B U S Q U E D A   S E C U E N C I A L  O   L I N E A L \n\n";
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
							cout<<endl;
							cout<<"\n\t Presiona cualquier tecla para regresar el menu de busqueda ";
							getch();
							system("CLS");															
							break;
						
						case 66: //B-inaria
							system("cls");
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
							cout<<endl;
							cout<<"\n\t Presiona cualquier tecla para regresar el menu de busqueda ";
							getch();
							system("CLS");							
							break;
							
						case 72: //H-ash
							system("cls");
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
							cout<<endl;
							cout<<"\n\t Presiona cualquier tecla para regresar el menu de busqueda ";
							getch();
							system("CLS");							
							break;
							
						case 82: //R-egresar
							system ("cls");
							break;
							
						default: 
							cout<<"\n\t Esa opcion no es valida ";
							system ("pause");
							break;
					}
				} while(op_bus != 82);
				
				break;
	
			case 84: //T-erminar
				system ("cls");
				break;
			
			default:
				cout<<"\n\t Esa opcion no es valida ";	
				system ("pause");
				break;
		}
	} while (op_oyb != 84);
}


void portada(void){
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
	cout<<"\t\t\n                             Tema: Ordenacion y busqueda con librerias";
	cout<<endl;
	cout<<"\t\t\n                                 Nombre de las alumnas y codigo :";
	cout<<"\t\t\n                              Padilla Sandoval Valeria \t\t 218480301";
	cout<<"\t\t\n                           Vazquez Padilla Anahi Montserrat \t 221944033";
	cout<<endl;
	cout<<"\t\t\n                           Lagos de Moreno a 27 de octubre del 2022";
	cout<<endl<<endl<<endl;
	system ("pause");
	menu();
}
