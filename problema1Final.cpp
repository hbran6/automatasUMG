#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <Windows.h>
#include<algorithm>

using namespace std;

enum class Status {q0, q1, q2, q3, q4, q5, q6, q7, q8};
Status actualStatus, inicialStatus,rejectedStatus, acceptedStatus;

Status readerHead(int, int, string);
string result;

int main (){
	cout<<"MAQUINA DE TURING"<<endl;
	cout<<"Esta maquina multiplica n * pi(3.14)"<<endl;
	cout<<endl<<endl;
	int n;
	string entryLenguage = "0001";
	
	cout<<"n:";
	cin>>n;
	for(int i = 0; i < n; i++){
		entryLenguage += "0";
	}
	entryLenguage += "1B";
	
	inicialStatus = Status::q0;
	acceptedStatus = Status::q7;
	rejectedStatus = Status::q8;
	actualStatus = Status::q0;
	Status lastStatus = readerHead(-1, 1, entryLenguage);
	cout<<endl;
	
	result.erase(remove(result.begin(), result.end(), 'B'), result.end());
	int integer;
	
	integer = result.length();
	
//	delete result;
	
	//para decimal
	int decimal;
	string entryLenguageDecimal = "000000000000001";
	
	for(int i = 0; i < n; i++){
		entryLenguageDecimal += "0";
	}
	entryLenguageDecimal += "1B";
	cout<<"decimal:"<<entryLenguageDecimal<<endl;
	inicialStatus = Status::q0;
	acceptedStatus = Status::q7;
	rejectedStatus = Status::q8;
	actualStatus = Status::q0;
	Status lastStatusDecimal = readerHead(-1, 1, entryLenguageDecimal);
	
	result.erase(remove(result.begin(), result.end(), 'B'), result.end());
	decimal = result.length();
	
	cout<<"Resultado es: "<<integer<<"."<<decimal<<endl;
	
	system("pause");
	system("cls");
	main();
}
Status readerHead(int initialPosition, int movePosition, string entryLanguage){//movePosition: 1 = right, -1 = left	
	int actualPosition;
	actualPosition = initialPosition + movePosition;
	if(actualPosition == -1)
		entryLanguage[actualPosition] = ' ';
//	cout<<"leemos:"<<entryLanguage[actualPosition]<<endl;
	
	switch (actualStatus){
		case Status::q0:
			if(entryLanguage[actualPosition] == '0'){
				// cout<<"q0 0->B,R,q1"<<endl;
				entryLanguage[actualPosition] = 'B';
				actualStatus = Status::q1;
				return readerHead(actualPosition, 1, entryLanguage);
			}else if(entryLanguage[actualPosition] == '1'){
				// cout<<"q0 1->B,R,q6"<<endl;
				entryLanguage[actualPosition] = 'B';
				actualStatus = Status::q6;
				return readerHead(actualPosition, 1, entryLanguage);
			}
			break;
		case Status::q1:
			if(entryLanguage[actualPosition] == '0'){
				// cout<<"q1 0->0,R,q1"<<endl;
				entryLanguage[actualPosition] = '0';
				actualStatus = Status::q1;
				return readerHead(actualPosition, 1, entryLanguage);
			}else if(entryLanguage[actualPosition] == '1'){
				// cout<<"q1 1->1,R,q2"<<endl;
				entryLanguage[actualPosition] = '1';
				actualStatus = Status::q2;
				return readerHead(actualPosition, 1, entryLanguage);
			}
			break;
		case Status::q2:
			if(entryLanguage[actualPosition] == '0'){
				// cout<<"q2 0->X,R,q1"<<endl;
				entryLanguage[actualPosition] = 'X';
				actualStatus = Status::q3;
				return readerHead(actualPosition, 1, entryLanguage);
			}else if(entryLanguage[actualPosition] == '1'){
				// cout<<"q2 1->1,L,q5"<<endl;
				entryLanguage[actualPosition] = '1';
				actualStatus = Status::q5;
				return readerHead(actualPosition, -1, entryLanguage);
			}
			break;
		case Status::q3:
			if(entryLanguage[actualPosition] == '0'){
				// cout<<"q3 0->0,R,q3"<<endl;
				entryLanguage[actualPosition] = '0';
				actualStatus = Status::q3;
				return readerHead(actualPosition, 1, entryLanguage);
			}else if(entryLanguage[actualPosition] == '1'){
				// cout<<"q3 1->1,R,q3"<<endl;
				entryLanguage[actualPosition] = '1';
				actualStatus = Status::q3;
				return readerHead(actualPosition, 1, entryLanguage);
			}else if(entryLanguage[actualPosition] == 'B'){
				// cout<<"q3 B->0,L,q1"<<endl;
				entryLanguage[actualPosition] = '0';
				char fin = 'B';//caracter de finalizacion para el cabezal
				entryLanguage += fin;
				// cout<<"agregando a entry:"<<entryLanguage<<endl;
				actualStatus = Status::q4;
				return readerHead(actualPosition, -1, entryLanguage);
			}
			break;
		case Status::q4:
			if(entryLanguage[actualPosition] == '1'){
				// cout<<"q4 1->1,L,q4"<<endl;
				entryLanguage[actualPosition] = '1';
				actualStatus = Status::q4;
				return readerHead(actualPosition, -1, entryLanguage);
			}else if(entryLanguage[actualPosition] == '0'){
				// cout<<"q4 0->0,L,q4"<<endl;
				entryLanguage[actualPosition] = '0';
				actualStatus = Status::q4;
				return readerHead(actualPosition, -1, entryLanguage);
			}else if(entryLanguage[actualPosition] == 'X'){
				// cout<<"q4 X->X,R,q2"<<endl;
				entryLanguage[actualPosition] = 'X';
				actualStatus = Status::q2;
				return readerHead(actualPosition, 1, entryLanguage);
			}
			break;
		case Status::q5:
			if(entryLanguage[actualPosition] == 'X'){
				// cout<<"q5 X->0,L,q5"<<endl;
				entryLanguage[actualPosition] = '0';
				actualStatus = Status::q5;
				return readerHead(actualPosition, -1, entryLanguage);
			}else if(entryLanguage[actualPosition] == '1'){
				// cout<<"q5 1->1,L,q5"<<endl;
				entryLanguage[actualPosition] = '1';
				actualStatus = Status::q5;
				return readerHead(actualPosition, -1, entryLanguage);
			}else if(entryLanguage[actualPosition] == '0'){
				// cout<<"q5 0->0,L,q5"<<endl;
				entryLanguage[actualPosition] = '0';
				actualStatus = Status::q5;
				return readerHead(actualPosition, -1, entryLanguage);
			}else if(entryLanguage[actualPosition] == 'B'){
				// cout<<"q5 B->B,R,q0"<<endl;
				entryLanguage[actualPosition] = 'B';
				actualStatus = Status::q0;
				return readerHead(actualPosition, 1, entryLanguage);
			}
			break;
		case Status::q6:
			if(entryLanguage[actualPosition] == '0'){
				// cout<<"q6 0->B,R,q6"<<endl;
				entryLanguage[actualPosition] = 'B';
				actualStatus = Status::q6;
				return readerHead(actualPosition, 1, entryLanguage);
			}else if(entryLanguage[actualPosition] == '1'){
				// cout<<"q6 1->B,R,q7"<<endl;
				entryLanguage[actualPosition] = 'B';
				actualStatus = Status::q7;
				result = entryLanguage;
				return actualStatus;
			}
			break;
		case Status::q7:
			// cout<<"q7"<<endl;
			break;
			
	}
	return actualStatus;
}
