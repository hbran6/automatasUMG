//AUTOMATAS Y LENGUAJES FORMALES
//PROYECTO MAQUINA DE TURING 
//DONDE EL LENGUAJE ACEPTADO ES a^n, b^n
//LOS ESTADOS NO DECLARADOS VAN AL ESTADO REJECTED POR CONVENIENCIA
//SE COLOCA UN ESPACIO AL INICIO Y AL FINAL DEL LENGUAJE DE ENTRADA PARA QUE EL CABEZAL SEPA DONDE TERMINA EL LENGUAJE
//SE COLOCO SLEEP(1000) PARA PODER DETENIDAMENTE EL PROCESO QUE SE SIGUE

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <Windows.h>

using namespace std;

enum class Status {q0, q1, q2, q3, q4, q5};
Status actualStatus, inicialStatus,rejectedStatus, acceptedStatus;

Status readerHead(int, int, string);

int main (){
	cout<<"MAQUINA DE TURING"<<endl;
	cout<<"Esta maquina acepta un lenguaje donde existe la misma cantidad de a que de b(L = a^n b^n | n >= 1)"<<endl;
	cout<<endl<<endl;
	string entryLanguage;
	
	cout<<"Lenguaje de entrada:";
	cin>>entryLanguage;
	
	char fin = ' ';//caracter de finalizacion para el cabezal
	entryLanguage += fin;
	
	inicialStatus = Status::q0;
	acceptedStatus = Status::q4;
	rejectedStatus = Status::q5;
	actualStatus = Status::q0;
	Status lastStatus = readerHead(-1, 1, entryLanguage);
	cout<<endl;
	if(lastStatus == acceptedStatus){
		cout<<"Lenguaje Aceptado"<<endl<<endl;
	}
	if(lastStatus == rejectedStatus){
		cout<<"Lenguaje Rechazado"<<endl<<endl;
	}
	
	system("pause");
	system("cls");
	main();
}

Status readerHead(int initialPosition, int movePosition, string entryLanguage){//movePosition: 1 = right, -1 = left
//	Sleep(100);
	cout<<endl;
	cout<<"string:"<<entryLanguage<<endl;	
	int actualPosition;
	actualPosition = initialPosition + movePosition;
	if(actualPosition == -1)
		entryLanguage[actualPosition] = ' ';
	cout<<"leemos:"<<entryLanguage[actualPosition]<<endl;
	
	switch (actualStatus){
		case Status::q0:
			if(entryLanguage[actualPosition] == 'a'){
				cout<<"q0 a->X,R q1"<<endl;
				entryLanguage[actualPosition] = 'X';
				actualStatus = Status::q1;
				return readerHead(actualPosition, 1, entryLanguage);
			}else if(entryLanguage[actualPosition] == ' '){
				cout<<"q0 _->_,R q4"<<endl;
				actualStatus = Status::q4;
				return actualStatus;
			}else if(entryLanguage[actualPosition] == 'b'){
				cout<<"q0 b->X,R q2"<<endl;
				entryLanguage[actualPosition] = 'X';
				actualStatus = Status::q2;
				return readerHead(actualPosition, 1, entryLanguage);
			}else if(entryLanguage[actualPosition] == 'X'){
				cout<<"q0 b->X,R q2"<<endl;
				entryLanguage[actualPosition] = 'X';
				actualStatus = Status::q0;
				return readerHead(actualPosition, 1, entryLanguage);
			}else{
				actualStatus = Status::q5;
				return actualStatus;
			}
			break;
		case Status::q1:
			if(entryLanguage[actualPosition] == 'b'){
				cout<<"q1 b->X,L q1"<<endl;
				entryLanguage[actualPosition] = 'X';
				actualStatus = Status::q3;
				return readerHead(actualPosition, -1, entryLanguage);
			}else if(entryLanguage[actualPosition] == 'X'){
				cout<<"q1 X->X,R q1"<<endl;
				entryLanguage[actualPosition] = 'X';
				actualStatus = Status::q1;
				return readerHead(actualPosition, 1, entryLanguage);
			}else if(entryLanguage[actualPosition] == 'a'){
				cout<<"q1 a->a,D q1"<<endl;
				entryLanguage[actualPosition] = 'a';
				actualStatus = Status::q1;
				return readerHead(actualPosition, 1, entryLanguage);
			}else{
				actualStatus = Status::q5;
				return actualStatus;
			}
			break;
		case Status::q2:
			if(entryLanguage[actualPosition] == 'b'){
				cout<<"q2 b->b,R q2"<<endl;
				entryLanguage[actualPosition] = 'b';
				actualStatus = Status::q2;
				return readerHead(actualPosition, 1, entryLanguage);
			}else if(entryLanguage[actualPosition] == 'X'){
				cout<<"q2 X->X,r q2"<<endl;
				entryLanguage[actualPosition] = 'X';
				actualStatus = Status::q2;
				return readerHead(actualPosition, 1, entryLanguage);
			}else if(entryLanguage[actualPosition] == 'a'){
				cout<<"q2 a->X,L q3"<<endl;
				entryLanguage[actualPosition] = 'X';
				actualStatus = Status::q3;
				return readerHead(actualPosition, -1, entryLanguage);
			}else{
				actualStatus = Status::q5;
				return actualStatus;
			}
			break;
		case Status::q3:
			if(entryLanguage[actualPosition] == 'a'){
				cout<<"q3 a->a,L q3"<<endl;
				entryLanguage[actualPosition] = 'a';
				actualStatus = Status::q3;
				return readerHead(actualPosition, -1, entryLanguage);
			}else if(entryLanguage[actualPosition] == 'b'){
				cout<<"q3 b->b,L q3"<<endl;
				entryLanguage[actualPosition] = 'b';
				actualStatus = Status::q3;
				return readerHead(actualPosition, -1, entryLanguage);
			}else if(entryLanguage[actualPosition] == 'X'){
				cout<<"q3 X->X,L q3"<<endl;
				entryLanguage[actualPosition] = 'X';
				actualStatus = Status::q3;
				return readerHead(actualPosition, -1, entryLanguage);
			}else if(entryLanguage[actualPosition] == ' '){
				cout<<"q3 _->_,R q0"<<endl;
				entryLanguage[actualPosition] = ' ';
				actualStatus = Status::q0;
				return readerHead(actualPosition, 1, entryLanguage);
			}else{
				actualStatus = Status::q5;
				return actualStatus;
			}
			break;
	}
	return actualStatus;
}


