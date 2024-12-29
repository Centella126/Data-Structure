#include <iostream>
#include <conio.h>

using namespace std;

#define N 3

struct fecha{
	int dd, mm, aa;
};




struct celulares{
	char id;
	float status;
	char marca[20];
	char modelo[20];
	char color[20];
	float precio;
	fecha fechaderegistro; //programamos su propio tipo, que es la struct anterior
};




void menu(void);
void encabezado(void);
void portada(void);
void altas(struct celulares* vcel, int& j);
void baja(struct celulares* vcel, int i, char op_b);
void consulta(struct celulares* vcel, int id, int j);
void reporte(struct celulares* vcel, int j);
void modificaciones(struct celulares* vcel, char op_m, int i);




int main(void) {
	portada();
	return 0;
}




void encabezado(void){
	cout<<"El celfon S. A. de C. V.";
	cout<<"\nPaseo de la Martinica No. 123";
	cout<<"\nColonia Paseos de la Montana";
	cout<<"\nLagos de Moreno, Jalisco";
	cout<<"\nTel. 347.888.01.52";
	cout<<"\nwww.diamanteazul.com.mx\n\n";
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
	cout<<"\t\t\n                             Proyecto 3. Sistema computacional ABC";
	cout<<endl;
	cout<<"\t\t\n                                 Nombre de las alumnas y codigo :";
	cout<<"\t\t\n                              Padilla Sandoval Valeria \t\t 218480301";
	cout<<"\t\t\n                           Vazquez Padilla Anahi Montserrat \t 221944033";
	cout<<endl;
	cout<<"\t\t\n                           Lagos de Moreno a 03 de noviembre del 2022";
	cout<<endl<<endl<<endl;
	system ("pause");	
	menu();
}




void menu(void){
	celulares vcel[N];
	char op_r, op_b, op_m;
	int i, j;
	char id;
	
	do{			
		system("cls");
		encabezado();
		cout<<"\n\n\t R E G I S T R O - V E N T A S  D E  C E L U L A R E S";
		cout<<"\n\n\t Altas......................................[A]";
		cout<<"\n\n\t Bajas......................................[B]";
		cout<<"\n\n\t Consulta...................................[C]";
		cout<<"\n\n\t Reporte por pantalla.......................[R]";
		cout<<"\n\n\t Modificaciones.............................[M]";
		cout<<"\n\n\t Terminar...................................[T]";
		cout<<"\n\n\t\t Elija una opcion: ";
		fflush(stdin);
		cin>>op_r; //opcion del menu de registro de ventas	
		op_r = toupper(op_r);
		
		switch (op_r){
			case 65:
				system("CLS");
				cout<<"\n\t A L T A S";
				altas(vcel, j);
				cout<<"\n\t Presiona cualquier tecla para regresar el menú principal ";
				getch();
				break;
				
			case 66:				
				system("CLS");
				encabezado();
				cout<<"\n\t B A J A S \n";
				cout<<"\n\nIngrese el id: ";
				cin>>id;
				for(i=0; i<=j; i++){  			
					if(id==vcel[i].id){
						cout<<"\n\t Lógica......................................[L]\n";
						cout<<"\n\t Física......................................[F]\n";
						cout<<"\n\t Regresar....................................[R]\n";
						cout<<"\n\t\t Elija una opción: ";									
						fflush(stdin);
						cin>>op_b; //opcion del menu de bajas
						op_b = toupper(op_b);
						
						baja(vcel, i, op_b);					
					}
				}					
				break;
				
			case 67:
				system("CLS");
				cout<<"\n\t C O N S U L T A \n";
				cout<<"\nIngrese el id: ";
				cin>>id;
				consulta(vcel, id, j);				
				cout<<"\n\t Presiona cualquier tecla para regresar el menú principal ";
				getch();
				break;	

			case 82:
				system("CLS");
				cout<<"\n\t R E P O R T E \n";
				cout<<"\n Los datos almacenados en la estructura son: \n\n\n";
				reporte(vcel, j);
				cout<<"\n\t Presiona cualquier tecla para regresar el menú principal ";
				getch();
				break;
				
			case 77:
				system("CLS");
				encabezado();
				cout<<"\n\t M O D I F I C A C I O N E S \n";
				cout<<"\nIngrese el id: ";
				cin>>id;
				for(i=0; i<=j; i++){
					if(id==vcel[i].id){
						do{	
							system("CLS");				
							cout<<"\n\t Código.................................[C]\n";
							cout<<"\n\t Marca..................................[M]\n";
							cout<<"\n\t Modelo.................................[O]\n";
							cout<<"\n\t Color..................................[L]\n";
							cout<<"\n\t Precio.................................[P]\n";
							cout<<"\n\t Regresar...............................[R]\n";
							cout<<"\n\t Elija una opción a modificar: ";
							fflush(stdin);
							cin>>op_m; //opcion del menu modificaciones
							op_m = toupper(op_m);
														
							switch (op_m){								
								case 67:
									system("CLS");
									cout<<"\n\t C Ó D I G O";
									modificaciones(vcel, op_m, i);
									cout<<"\n\n\t Presiona cualquier tecla para regresar el menú de modificaciones ";
									getch();
									break;
									
								case 77:
									system("CLS");
									cout<<"\n\t M A R C A";
									modificaciones(vcel, op_m, i);
									cout<<"\n\n\t Presiona cualquier tecla para regresar el menú de modificaciones ";
									getch();								
									break;
									
								case 79:
									system("CLS");
									cout<<"\n\t M O D E L O";
									modificaciones(vcel, op_m, i);
									cout<<"\n\n\t Presiona cualquier tecla para regresar el menú de modificaciones ";
									getch();								
									break;
								
								case 76:
									system("CLS");
									cout<<"\n\t C O L O R";
									modificaciones(vcel, op_m, i);
									cout<<"\n\n\t Presiona cualquier tecla para regresar el menú de modificaciones ";
									getch();									
									break;
									
								case 80:
									system("CLS");
									cout<<"\n\t P R E C I O";
									modificaciones(vcel, op_m, i);
									cout<<"\n\n\t Presiona cualquier tecla para regresar el menú de modificaciones ";
									getch();									
									break;
	
								case 82:
									system ("CLS");
									break;
									
								default:
									system ("CLS");
									cout<<"\n\t Esa opción no es válida ";
									system ("pause");
									break;						
							}
						}while(op_m!=82);
						
						i=j+1;	//Para que se trunque el for
					}
				}
				cout<<"\n\t Presiona cualquier tecla para regresar el menú principal";
				getch();
				break;
				
			case 84:
				system ("CLS");
				break;
				
			default:
				system ("CLS");
				cout<<"\n\t Esa opción no es válida ";
				system ("pause");
				break;	
		}
	}while(op_r!=84);
}




void altas(struct celulares* vcel, int& j){
	setlocale(LC_ALL, "spanish");
	int i=0;
	char op_a;


	do{	
		system("CLS");
		cout<<"\t\t A L T A S ";
		cout<<"\n\n Ingrese máximo 3 altas: ";
		cout<<"\n\n Celular "<<i+1<<"\n\n";
		
		cout<<"\tCodigo: ";
		fflush(stdin);
		cin>>vcel[i].id;
		
		
		cout<<"\n\tFecha de registro: ";
		cout<<"\tDia: ";
		fflush(stdin);
		cin>>vcel[i].fechaderegistro.dd;
		cout<<"\t\t\t\tMes: ";
		fflush(stdin);
		cin>>vcel[i].fechaderegistro.mm;
		cout<<"\t\t\t\tAño: ";
		fflush(stdin);
		cin>>vcel[i].fechaderegistro.aa;
		
		
		cout<<"\n\tMarca: ";
		fflush(stdin);
		gets(vcel[i].marca);
		
		cout<<"\n\tModelo: ";
		fflush(stdin);
		gets(vcel[i].modelo);
		
		cout<<"\n\tColor: ";
		fflush(stdin);
		gets(vcel[i].color);
		
		cout<<"\n\tPrecio: $";
		fflush(stdin);
		cin>>vcel[i].precio;
		
		//Status
		vcel[i].status = 1;

		cout<<"\n";

		cout<<"\n\t ¿Ingresar otro celular? [S/N] ";
		cin>>op_a;
		op_a = toupper(op_a);
		
		i++;
		
	}while(op_a==83);
	j=i;
	return;
}




void baja(struct celulares* vcel, int i, char op_b){
	switch (op_b){
		do{
			case 76:
				system("CLS");
				cout<<"\tL O G I C A\n";
				vcel[i].status=0;
				cout<<"\n\nLa baja se ha realizado con éxito";						
				cout<<"\n\t Presiona cualquier tecla para regresar el menú de bajas ";
				getch();
				break;
				
			case 70:
				system("CLS");
				cout<<"\tF I S I C A\n";
				vcel[i].fechaderegistro.dd=NULL;
				vcel[i].fechaderegistro.mm=NULL;
				vcel[i].fechaderegistro.aa=NULL;
				vcel[i].marca[20]=NULL;
				vcel[i].modelo[20]=NULL;
				vcel[i].color[20]=NULL;	
				vcel[i].precio=NULL;
				vcel[i].status=0;	
				cout<<"\n\nLa baja se ha realizado con éxito";							
				cout<<"\n\t Presiona cualquier tecla para regresar el menú de bajas ";
				getch();					
				break;
				
			case 82:
				system ("CLS");
				break;
				
			default:
				cout<<"\n\t Esa opción no es válida ";
				system ("pause");						
				break;
				
		} while(op_b!=82);
	}
}




void consulta(struct celulares* vcel, int id, int j){
	int i;
	
	for(i=0; i<j; i++){  			
		if(id==vcel[i].id){
			system("CLS");
			cout<<"Codigo: ";
			cout<<"\tFecha de registro: ";
			cout<<"\tMarca: ";
			cout<<"\tModelo: ";
			cout<<"\tColor: ";
			cout<<"\tPrecio: ";
			cout<<"\tStatus: ";
			
			cout<<"\n";	
			cout<<vcel[i].id<<"\t\t";
			cout<<vcel[i].fechaderegistro.dd<<"/";
			cout<<vcel[i].fechaderegistro.mm<<"/";
			cout<<vcel[i].fechaderegistro.aa<<"\t\t\t";
			cout<<vcel[i].marca<<"\t\t";
			cout<<vcel[i].modelo<<"\t\t";
			cout<<vcel[i].color<<"\t\t";
			cout<<vcel[i].precio<<"\t\t";
			cout<<vcel[i].status<<"\t\t";
			cout<<"\n";	
			
			i=j;	//Para que se trunque el for			
		}	
	}
}




void reporte(struct celulares* vcel, int j){
	int i;
	system("CLS");
	cout<<"Codigo: ";
	cout<<"\tFecha de registro: ";
	cout<<"\tMarca: ";
	cout<<"\tModelo: ";
	cout<<"\tColor: ";
	cout<<"\tPrecio: ";
	cout<<"\tStatus: ";
	
	for(i=0; i<j; i++){	
		cout<<"\n";	
		cout<<vcel[i].id<<"\t\t";
		cout<<vcel[i].fechaderegistro.dd<<"/";
		cout<<vcel[i].fechaderegistro.mm<<"/";
		cout<<vcel[i].fechaderegistro.aa<<"\t\t\t";
		cout<<vcel[i].marca<<"\t\t";
		cout<<vcel[i].modelo<<"\t\t";
		cout<<vcel[i].color<<"\t\t";
		cout<<vcel[i].precio<<"\t\t";
		cout<<vcel[i].status<<"\t\t";
		cout<<"\n";
	}
}




void modificaciones(struct celulares* vcel, char op_m, int i){
	if (op_m==67){
		cout<<"\n\t\t Actualización del código: ";
		cin>>vcel[i].id;
	}
	
	if (op_m==77){
		cout<<"\n\t\t Actualización de la marca: ";
		cin>>vcel[i].marca;
	}
	
	if (op_m==79){
		cout<<"\n\t\t Actualización del modelo: ";
		cin>>vcel[i].modelo;
	}
	
	if (op_m==76){
		cout<<"\n\t\t Actualización del color: ";
		cin>>vcel[i].color;
	}
	
	if (op_m==80){
		cout<<"\n\t\t Actualización del precio: ";
		cin>>vcel[i].precio;
	}	
}
