#include <iostream>
#include "Operaciones_pila.h"

using namespace std;

void menu_pila(void){
	setlocale(LC_ALL, "spanish");
	
	e_pila pp;
	int x, i; 
	char op;
	inicializar(pp);
	
	
	do{
		system("CLS");
		cout<<"Su pila es la siguiente: ";
		imprimir(pp);
		cout<<endl<<endl;
		cout<<"\n\tApilar.................[A]";
		cout<<"\n\tDesapilar..............[D]";
		cout<<"\n\tInicializar............[I]";
		cout<<"\n\tPila Vacia.............[V]";
		cout<<"\n\tPila Llena.............[L]";
		cout<<"\n\tLugares Ocupados.......[O]";
		cout<<"\n\tLugares Disponibles....[S]";
		cout<<"\n\tCima Elemento..........[E]";
		cout<<"\n\tCima Posición..........[P]";
		cout<<"\n\tTerminar...............[T]";
		cout<<"\n\n\tElija una opción: ";
		fflush(stdin);
		cin>>op;
		op = toupper(op);
				
		switch(op){
			case 65:
				system("CLS");
				cout<<"\n\n\tA P I L A R";				
				cout<<"\nIngrese un dato: ";
				cin>>x;
				if(pilallena(pp)==1)
					cout<<"\n\nNo es posible apilar otro dato\n";
				else{
					apilar(pp, x);	
					cout<<"\n\nApilado correctamente\n";
				}
				cout<<endl;
				system("pause");				
				break;
			
			case 68:
				system("CLS");
				cout<<"\n\n\tD E S A P I L A R";
				if(pilavacia(pp)==1)	
					cout<<"\n\nNo es posible desapilar otro dato\n";
				else{
					desapilar(pp);
					cout<<"\n\nDesapilado correctamente\n";
				}		
				cout<<endl;
				system("pause");
				break;			
				
			case 73:
				system("CLS");
				cout<<"\n\n\tI N I C I A L I Z A R";	
				inicializar(pp);
				cout<<"\n\nInicializado correctamente\n";
				cout<<endl;
				system("pause");
				break;	
								
			case 86:
				system("CLS");
				if(pilavacia(pp)==1)
					cout<<"\n\n\t La pila está vacía\n";
				else
					cout<<"\n\n\t La pila no está vacía\n";
				cout<<endl;
				system("pause");
				break;
				
			case 76:
				system("CLS");
				if(pilallena(pp)==1)
					cout<<"\n\n\t La pila está llena\n";
				else
					cout<<"\n\n\t La pila no está llena\n";
				cout<<endl;
				system("pause");
				break;	
				
			case 79:
				system("CLS");
				cout<<"\n\n\t Lugares ocupados: "<<lugaresocupados(pp)<<endl;
				cout<<endl;
				system("pause");
				break;
				
			case 83:
				system("CLS");
				cout<<"\n\n\t Lugares disponibles: "<<lugaresdisponibles(pp)<<endl;
				cout<<endl;
				system("pause");
				break;
				
			case 69:
				system("CLS");
				if(pilavacia(pp)==1)
					cout<<"\n\n\t No hay elementos"<<endl;
				else
					cout<<"\n\n\t Elemento de la cima: "<<cimaelemento(pp)<<endl;
				cout<<endl;
				system("pause");
				break;	
				
			case 80:
				system("CLS");
				cout<<"\n\n\t Posición de la cima: "<<cimaposicion(pp)<<endl;
				cout<<endl;
				system("pause");
				break;		
							
			case 84:
				system("CLS");
				break;	
		}
	}while(op!=84);
	
	return;
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
	cout<<"\t\t\n                                    Proyecto 4. Pila estatica";
	cout<<endl;
	cout<<"\t\t\n                                 Nombre de las alumnas y codigo :";
	cout<<"\t\t\n                              Padilla Sandoval Valeria \t\t 218480301";
	cout<<"\t\t\n                           Vazquez Padilla Anahi Montserrat \t 221944033";
	cout<<endl;
	cout<<"\t\t\n                           Lagos de Moreno a 17 de noviembre del 2022";
	cout<<endl<<endl<<endl;
	system ("pause");	
	menu_pila();
	
	return;
}
