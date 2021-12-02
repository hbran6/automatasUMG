//AUTOMATAS Y LENGUAJES FORMALES
//MAQUINA DE TURING PARA EL EJEMPLO DADO EN CLASE
//DONDE EL LENGUAJE ACEPTADO ES 0^n, 1^n
//GRUPO #1
//LOS ESTADOS NO DECLARADOS VAN AL ESTADO REJECTED POR CONVENIENCIA
//ES DECIR, SI EN q0 SE RECIBE 1, AUTOMATICAMENTE ES RECHAZADO
//SE COLOCA UN ESPACIO AL FINAL DEL LENGUAJE DE ENTRADA PARA QUE EL CABEZAL SEPA DONDE TERMINA EL LENGUAJE
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
	cout<<"Esta maquina acepta un lenguaje donde existe la misma cantidad de 0 seguido de la misma cantidad de 1"<<endl;
	cout<<endl<<endl;
	string entryLanguage;
	
	cout<<"Lenguaje de entrada:";
	cin>>entryLanguage;
	
	int sizeLanguage;
	sizeLanguage = entryLanguage.length() + 1;
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
	Sleep(1000);
	cout<<endl;
	cout<<"string:"<<entryLanguage<<endl;	
	int actualPosition;
	actualPosition = initialPosition + movePosition;
	cout<<"leemos:"<<entryLanguage[actualPosition]<<endl;
	
	switch (actualStatus){
		case Status::q0:
			if(entryLanguage[actualPosition] == '0'){
				cout<<"q0 0->X,R q1"<<endl;
				entryLanguage[actualPosition] = 'X';
				actualStatus = Status::q1;
				return readerHead(actualPosition, 1, entryLanguage);
			}
			if(entryLanguage[actualPosition] == 'Y'){
				entryLanguage[actualPosition] = 'Y';
				cout<<"q0 Y->Y,R q3"<<endl;
				actualStatus = Status::q3;
				return readerHead(actualPosition, 1, entryLanguage);
			}
			if(entryLanguage[actualPosition] == '1'){
				actualStatus = Status::q5;
				return readerHead(actualPosition, 1, entryLanguage);
			}
			break;
		case Status::q1:
			if(entryLanguage[actualPosition] == '0'){
				cout<<"q1 0->0,R q1"<<endl;
				entryLanguage[actualPosition] = '0';
				actualStatus = Status::q1;
				return readerHead(actualPosition, 1, entryLanguage);
			}
			if(entryLanguage[actualPosition] == 'Y'){
				cout<<"q1 Y->Y,R q1"<<endl;
				entryLanguage[actualPosition] = 'Y';
				actualStatus = Status::q1;
				return readerHead(actualPosition, 1, entryLanguage);
			}
			if(entryLanguage[actualPosition] == '1'){
				cout<<"q1 1->Y,L q2"<<endl;
				entryLanguage[actualPosition] = 'Y';
				actualStatus = Status::q2;
				return readerHead(actualPosition, -1, entryLanguage);
			}
			if(entryLanguage[actualPosition] == ' '){
				actualStatus = Status::q5;
				return readerHead(actualPosition, 1, entryLanguage);
			}
			break;
		case Status::q2:
			if(entryLanguage[actualPosition] == '0'){
				cout<<"q2 0->0,L q2"<<endl;
				entryLanguage[actualPosition] = '0';
				actualStatus = Status::q2;
				return readerHead(actualPosition, -1, entryLanguage);
			}
			if(entryLanguage[actualPosition] == 'Y'){
				cout<<"q2 Y->Y,L q2"<<endl;
				entryLanguage[actualPosition] = 'Y';
				actualStatus = Status::q2;
				return readerHead(actualPosition, -1, entryLanguage);
			}
			if(entryLanguage[actualPosition] == 'X'){
				cout<<"q2 X->X,R q0"<<endl;
				entryLanguage[actualPosition] = 'X';
				actualStatus = Status::q0;
				return readerHead(actualPosition, 1, entryLanguage);
			}
			break;
		case Status::q3:
			if(entryLanguage[actualPosition] == 'Y'){
				cout<<"q3 Y->Y,R q3"<<endl;
				entryLanguage[actualPosition] = 'Y';
				actualStatus = Status::q3;
				return readerHead(actualPosition, 1, entryLanguage);
			}
			if(entryLanguage[actualPosition] == '1'){
				actualStatus = Status::q5;
				return readerHead(actualPosition, 1, entryLanguage);
			}
			if(entryLanguage[actualPosition] == '0'){
				actualStatus = Status::q5;
				return readerHead(actualPosition, 1, entryLanguage);
			}
			if(entryLanguage[actualPosition] == ' '){
				cout<<"q3 _->_,R q4"<<endl;
				entryLanguage[actualPosition] = ' ';
				actualStatus = Status::q4;
				return actualStatus;
			}
			break;
	}
	return actualStatus;
}


