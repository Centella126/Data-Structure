#include <iostream>
#include <string.h>	//Para manejar cadenas de datos

using namespace std;

#define MAX 5

typedef int entero;	//Redefinir el tipo int como entero
typedef char caracter; 

struct e_pacientdata{
	caracter code [3];
	caracter name [30];
	entero age;
};


struct e_queue{
	e_pacientdata pacients[MAX];
	entero front, back;
};

void front(void);
void menu(void);
void inqueue(struct e_queue& dq, e_pacientdata x);		
void outqueue(struct e_queue dq);		//*
entero queueempty(struct e_queue dq);			
entero queuenoempty(struct e_queue dq);			
e_pacientdata frontdata(struct e_queue dq);			
void resetqueue(struct e_queue dq);
e_pacientdata finaldata(struct e_queue dq);			
entero finalposition(struct e_queue dq);			
entero queuesize(struct e_queue dq);	
void showqueue(struct e_queue dq);		



int main(void) 
{
	front();
		
	return 0;
}



void menu(void){
	e_queue doctorqueue;
	caracter op;
	caracter c[3];
	caracter n[30];
	entero a;
	e_pacientdata pd;
	
	do{
		system("cls");
		cout<<"\n\n\t Q U E U E S";
		cout<<"\n\n\t Inqueue....................................[I]";
		cout<<"\n\n\t Outqueue...................................[O]";
		cout<<"\n\n\t Queue empty................................[E]";
		cout<<"\n\n\t Queue noempty..............................[N]";
		cout<<"\n\n\t Front data.................................[T]";
		cout<<"\n\n\t Reset queue................................[R]";
		cout<<"\n\n\t Finaldata..................................[D]";
		cout<<"\n\n\t Final position.............................[P]";
		cout<<"\n\n\t Queue size.................................[S]";
		cout<<"\n\n\t Finish.....................................[F]";
		cout<<"\n\n\t\t Choose an option: ";
		fflush(stdin);
		cin>>op; 	
		op = toupper(op);
		
		switch(op){
			case 73:
				system("CLS");
				cout<<"\n\n\tI N Q U E U E";
				cout<<"\nEnter patient data: ";
				cout<<"\nCode: ";
				fflush(stdin);
				cin>>c;
				cout<<"\nName: ";
				fflush(stdin);
				cin>>n;
				cout<<"\nAge: ";
				fflush(stdin);
				cin>>a;
				strcpy(pd.code,c);
				strcpy(pd.name,n);
				pd.age=a;
				inqueue(doctorqueue, pd);
				cout<<endl;
				system("pause");				
				break;
				
			case 79:
				system("CLS");
				cout<<"\n\n\tO U T Q U E U E";
				
				cout<<endl;
				system("pause");				
				break;
				
			case 69:
				system("CLS");
				cout<<"\n\n\tQ U E U E  E M P T Y";
				
				cout<<endl;
				system("pause");				
				break;
				
			case 78:
				system("CLS");
				cout<<"\n\n\tQ U E U E  N O E M P T Y";
				
				cout<<endl;
				system("pause");				
				break;
				
			case 84:
				system("CLS");
				cout<<"\n\n\tF R O N T  D A T A";
				
				cout<<endl;
				system("pause");				
				break;
				
			case 82:
				system("CLS");
				cout<<"\n\n\tR E S E T  D A T A";
				
				cout<<endl;
				system("pause");				
				break;
				
			case 68:
				system("CLS");
				cout<<"\n\n\tF I N A L  D A T A";
				
				cout<<endl;
				system("pause");				
				break;
				
			case 80:
				system("CLS");
				cout<<"\n\n\tF I N A L  P O S I T I O N";
				
				cout<<endl;
				system("pause");				
				break;
				
			case 83:
				system("CLS");
				cout<<"\n\n\tQ U E U E  S I Z E";
				
				cout<<endl;
				system("pause");				
				break;
				
			case 70:
				system("CLS");				
				break;
			
			default:
				system("CLS");
				cout<<"Incorrect option";
				cout<<endl;
				system("pause");
				break;
		}
	}while(op!=70);
	return;
}



void front(void){
	cout<<"\t\t\n                                    UNIVERSIDAD DE GUADALAJARA";
	cout<<endl;
	cout<<"\t\t\n                               Centro Universitario de los Lagos";
	cout<<endl;
	cout<<"\t\t\n              Division de Estudios de la Biodiversidad e Innovacion Tecnologica";
	cout<<endl;
	cout<<"\t\t\n                         Departamento de Ciencias Exactas y Tecnologia";
	cout<<endl;
	cout<<"\t\t\n                                          Period 22B";
	cout<<endl;
	cout<<"\t\t\n                             Career: Ingenieria Mecatronica IMEC";
	cout<<endl;
	cout<<"\t\t\n                                  Subject: Estructura de datos";
	cout<<endl;
	cout<<"\t\t\n                                        Project 5. Queue";
	cout<<endl;
	cout<<"\t\t\n                                 Codes and name's of the students :";
	cout<<"\t\t\n                              Padilla Sandoval Valeria \t\t 218480301";
	cout<<"\t\t\n                           Vazquez Padilla Anahi Montserrat \t 221944033";
	cout<<endl;
	cout<<"\t\t\n                                Lagos de Moreno, nNvember 24 of 2022";
	cout<<endl<<endl<<endl;
	system ("pause");	
	menu();
	
	return;
}



void inqueue(struct e_queue& dq, e_pacientdata x){
	if(dq.front == -1)
		dq.front ++;
	
	dq.back++;
	dq.pacients[dq.back]=x;
	return;
}



void outqueue(struct e_queue dq){
	int i;
	
	for(i=0; i<dq.back; i++)
		dq.pacients[i] = dq.pacients[i+1];
		
	dq.back--;
	return;
}



entero queueempty(struct e_queue dq){
	if(dq.front==-1)
		return 1;
	else
		return 0;
}



entero queuenoempty(struct e_queue dq){
	if(dq.back==MAX-1)
		return 1;
	else
		return 0;
}



e_pacientdata frontdata(struct e_queue dq){
	return dq.pacients[dq.front];
}



void resetqueue(struct e_queue& dq){
	dq.front=-1;
	dq.back=-1;
	return;
}



e_pacientdata finaldata(struct e_queue dq){
	return dq.pacients[dq.back];
}



entero finalposition(struct e_queue dq){
	return dq.back;
}



entero queuesize(struct e_queue dq){
	return dq.back+1;
}



void showqueue(struct e_queue dq){
	int i;
	
	if(dq.back > -1){
		for(i = 0; i <= dq.back; i++){
			cout<<"\t|"<< dq.pacients[i].id<<"\t\t|"<<dq.pacients[i].name<<"\t\t|"<< dq.pacients[i].age<<endl;
		}
	}
	return;
}











